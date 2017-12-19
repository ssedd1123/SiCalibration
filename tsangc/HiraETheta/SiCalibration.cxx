// test and see if the fitting is working as expected
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>
#include "TTree.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TSpectrum.h"

#include "/projects/e16042/ribbitHiRA/detectors/RBHiRA/RBHiRATelescope.h"
#include "ReadTree.cxx"

#define strip_no 32 // there are 32 silicon strips in 1 telescope
#define max_peaks 10 // maximum no of peaks allowed by tspectrum
#define threshold 0.3 // fraction of height of the max peak below which the peak is rejected
#define gaus_width 25 // initial guess of the width of the gaussian curve
#define fit_no 4 // repeat fits of peaks to be safe
#define lin_fit_no 3 // number of fitting from channel to energy

// const array storing all energy info;rmation
const static double energy[] = {8.5327, 6.4778, 5.9713, 5.3475};

// return index from the array where the value is closest to the input value
int index_closest(vector<double>&, double);

void SiCalibration_ind(std::vector<TH1F*>& hist, /*const string& path = "/mnt/analysis/e16042/rootfilesHiRA/run-0010-00.root",*/ int tele_no = 0, const std::string& t_side = "EF")
{
	TCanvas *c1 = new TCanvas;

	// finding maximum of each histogram
	TSpectrum *s = new TSpectrum(max_peaks);
	// vector storing fitted result
	vector< vector<double> > peaks_center(strip_no);
	vector< vector<double> > peaks_sigma(strip_no);
	for(int i = 0; i < strip_no; ++i)
	{
		int nfound = s->Search(hist[i], 2, "", threshold);
		float *xpeaks = s->GetPositionX();
		float *ypeaks = s->GetPositionY();
		// gaussian curve for fitting
		std::vector<TF1*> f1;
		for(int j = 0; j < nfound; ++j)
		{
			string peak = "peak" + to_string(j) + "_" + to_string(i);
			f1.push_back(new TF1(peak.c_str(), "gaus", 600., 2000.));
			// initial guess of the parameters
			f1.back()->SetParameters(ypeaks[j], xpeaks[j], gaus_width);
			// fit the peaks multiple times just to be safe
			for(int k = 0; k < fit_no; ++k)
			{
				hist[i]->Fit(	peak.c_str(), 
						"q", 
						"", 
						f1.back()->GetParameter(1) - 1.5*f1.back()->GetParameter(2), 
						f1.back()->GetParameter(1) + 1.5*f1.back()->GetParameter(2));
				if(fabs(f1.back()->GetParameter(1) - xpeaks[j]) > f1.back()->GetParameter(2))
					f1.back()->SetParameter(1, xpeaks[j]);
			}
			peaks_center[i].push_back(f1.back()->GetParameter(1));
			peaks_sigma[i].push_back(f1.back()->GetParameter(2));
			f1.back()->Draw("same");
		}
		if(peaks_center[i].size() != 0)
		{
			std::vector<double>::iterator it_min = std::min_element(peaks_center[i].begin(), peaks_center[i].end());
			int index_to_be_erased = it_min - peaks_center[i].begin();
			peaks_center[i].erase(peaks_center[i].begin() + index_to_be_erased, peaks_center[i].begin() + index_to_be_erased + 1);
			peaks_sigma[i].erase(peaks_sigma[i].begin() + index_to_be_erased, peaks_sigma[i].begin() + index_to_be_erased + 1);
			delete f1[index_to_be_erased];
			f1.erase(f1.begin() + index_to_be_erased, f1.begin() + index_to_be_erased + 1);
		}
		/*
		for(unsigned k = 0; k < peaks_center[i].size(); k++)
		{
			std::cout << peaks_center[i][k] << " " << peaks_sigma[i][k] << "\n";
		}*/
		c1->Update();
		c1->Modified();		
		c1->SaveAs(("~/HiraETheta/PeakFit/Peak_tele" + t_side + "_" + to_string(tele_no) + "_strip_" + to_string(i) + ".png" ).c_str());		

//		for(int k = 0; k < f1.size(); k++) delete f1[k];
	}
	
	// assign peaks with max x as energy[1]
	// find the other 4 peaks by finding the closest x ratios to that of energy ratios
	// array that stories the centers of the calibrated data
	int size_energy = sizeof(energy)/sizeof(double);
	// I don't want to use pointers, but for god know why reasons, fitting won't work if they are not pointers
	vector<TF1*> linear;
	// file to which the result is written to
	std::ofstream output_file(("/user/tsangc/HiraETheta/CalFit/CalTele" + t_side + "_" + to_string(tele_no) + ".dat").c_str());
	if(!output_file.is_open()) std::cerr << " Output file not opened!\n";
	output_file << "StripNum\tfit_point\tintercept\tslope\terror_intercept\terror_slope\tChiSquare\tin Channel vs MeV graph\n";
	for(int i = 0; i < strip_no; ++i)
	{
		if(peaks_center[i].size() == 0)
		{
			std::cerr << "Warning, empty historgram for tele " << tele_no << " at strip " << i << "\n";
			output_file << i << "\t" << 0 << "\t" << 0 << "\t" << 0 << "\t" << 0 << "\t" << 0 << "\t" << 10000 <<  "\n";
			continue;
		}
		TH2D hist2d("hist2d", "hist",  1000, 600., 2000., 100, 4., 10.);
		hist2d.SetMarkerStyle(20);
		string name = "linear" + to_string(i);
		linear.push_back(new TF1(name.c_str(), "pol1", 600., 2000.));
		std::vector<double>::iterator max_x = max_element(peaks_center[i].begin(), peaks_center[i].end());
		//int index = distance(begin(peaks_center[i]), min_x);
		// initial guess for the curve
		linear.back()->SetParameters(0., energy[0]/(*max_x));
		//hist2d.Fill(energy[0], *max_x);
		// find the closest channel to interpolation using min_x only
		for(int k = 0; k < lin_fit_no; ++k)
		{
			hist2d.Reset();
			vector<double> peaks_single_strip = peaks_center[i];
			for(int j = 0; j < size_energy && peaks_single_strip.size() > 0; ++j)
			{
				double intercept = linear.back()->GetParameter(0);
				double slope = linear.back()->GetParameter(1);
				int index = index_closest(peaks_single_strip, (energy[j] - intercept) / slope);
				hist2d.Fill(peaks_single_strip[index], energy[j]);
				peaks_single_strip.erase(peaks_single_strip.begin() + index);
			}
			hist2d.SetTitle(("For strip number " + to_string(i)).c_str());
			hist2d.Fit(name.c_str(), "q");
			hist2d.GetXaxis()->SetTitle("Calibrated energy (MeV)");
			hist2d.GetYaxis()->SetTitle("Si Channel number");
		}
		c1->SaveAs(("~/HiraETheta/CalFit/Calibration_tele" + t_side + "_" + to_string(tele_no) + "_strip_" + to_string(i) + ".png" ).c_str());
		c1->Update();
		c1->Modified();
		output_file << i << "\t" << peaks_center[i].size() << "\t" << linear.back()->GetParameter(0) << "\t" << linear.back()->GetParameter(1) << "\t" << linear.back()->GetParError(0) << "\t" << linear.back()->GetParError(1) << "\t" << linear.back()->GetChisquare() <<  "\n";
	}	

	delete c1;


}

struct myclass{
	double target;
	bool operator()(double x, double y) 
	{
		return fabs(x - target) < fabs(y - target);
	}	
} diff;

int index_closest(vector<double>& v, double value)
{
	diff.target = value;
	vector<double>::iterator i = min_element(v.begin(), v.end(), diff);

    	return std::distance(v.begin(), i);
}

void SiCalibration()
{
	std::vector< std::vector<TH1F*> > EF, EB;
	if(!ReadTreeFromFile(EF, EB))
	{
		std::cout << "No files for all histograms, will make again from scratch. Please wait\n";
		ReadTree(EF, EB);
	}
	for(int i = 0; i < 12; ++i)
	{
		SiCalibration_ind(EF[i], i);
		SiCalibration_ind(EB[i], i, "EB");
	}
}
