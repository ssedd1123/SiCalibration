#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include "TTree.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "tsangc/HiraETheta/HiraParser.h"
#include "tsangc/HiraETheta/HiraTransformation.h"
#include "tsangc/HiraETheta/ReadTree/FormatFitResult.h"
#include "tsangc/HiraETheta/ReadTree/ExtrapolateEnergy.h"

#include "/projects/e16042/ribbitHiRA/detectors/RBHiRA/RBHiRATelescope.h"

// Why??? Why can't I use c++11 for this root file!!!????
/*
template<class T>
std::string to_string(const T& t_value)
{
	std::stringstream ss;
	ss << t_value;
	return ss.str();
}*/

void DrawETheta()
{
	FormatFitResult fit_result("EF", average);
	ExtrapolateEnergy tot_energy;
	const int num_tele = 12;
	const int num_strip = 32;
	TFile *file = new TFile("~/HiraETheta/ReadTree/run-0013-00.root");
	TTree *tree = (TTree*) file->Get("E16042");

	HiraParser parser("tsangc/HiraETheta/hiraU_cal_final_orphans_5.detector");
	HiraTransformation *transformation[num_tele];


	int ik = 0;
	while(parser.FindNextDetector("HiraTelescope") && ik < num_tele)
	{
		transformation[parser.GetValue<int>("Tele_no")] = new HiraTransformation(parser.GetTVector3("B"), parser.GetTVector3("C"), parser.GetTVector3("D"), parser.GetTVector3("A")); 
		ik++;
	}

	TH2F* E_vs_Theta = new TH2F("E_vs_Theta", "E vs Theta", 1000, 0, 70, 1000, 0, 13);
	TH2F* Tot_vs_Theta = new TH2F("Tot_vs_Theta", "Tot vs Theta", 1000, 0, 70, 1000, 100, 500);
	TH2F* Phi_vs_Theta = new TH2F("Phi_vs_Theta", "Phi vs Theta", 1000, 0, 50, 1000, -200, 200);

	RBHiRATelescope* det[num_tele];
	for(int i = 0; i < num_tele; ++i)
	{
		det[i] = new RBHiRATelescope;
		tree->SetBranchAddress(("tele" + to_string(i)).c_str(), &det[i]);
	}

	unsigned int entries = tree->GetEntries();

	for(int i = 0; i < 100000/*entries*/; ++i)
	{
		tree->GetEntry(i);
		for(int j = 0; j < num_tele; ++j)
		{
			bool has_EF = false, has_EB = false;
			int iEF, iEB;
			for(int k = 0; k < num_strip; ++k)
				if(det[j]->EF.ERawHi[k] > 10) 
				{
					has_EF = true;
					iEF = k;
				}
			for(int k = 0; k < num_strip; ++k)
				if(det[j]->EB.ERawHi[k] > 10) 
				{
					has_EB = true;
					iEB = k;
				}
			if(has_EF && has_EB) 
			{
				//std::cout << "tele " << j << " strip " << iEF << " " << iEB << " channel " << det[j]->EF.ERawHi[iEF] << endl;
				double calibrated_energy = fit_result.CalibrateEnergy(j, iEF, (double) det[j]->EF.ERawHi[iEF]);
				if(calibrated_energy > 0) 
				{
					TVector3 position = transformation[j]->TransformStripNum(iEF, iEB);
					E_vs_Theta->Fill(position.Theta()*180/M_PI, calibrated_energy);
					Tot_vs_Theta->Fill(position.Theta()*180/M_PI, tot_energy.SiEnergyToTotalEnergy(calibrated_energy));
					Phi_vs_Theta->Fill(position.Theta()*180/M_PI, -position.Phi()*180/M_PI);
				}
			}
		}
		std::cout << "Processing percentage " << (double) i/ (double) entries << "\r";
	}

	TFile *output = new TFile("E_vs_Theta.root", "RECREATE");
	E_vs_Theta->Write();
	Phi_vs_Theta->Write();
	Tot_vs_Theta->Write();
	output->Write();

}
