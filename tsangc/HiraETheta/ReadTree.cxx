#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include "TTree.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"

#include "/projects/e16042/ribbitHiRA/detectors/RBHiRA/RBHiRATelescope.h"

const int num_tele = 12;
const int num_strip = 32;

// Why??? Why can't I use c++11 for this root file!!!????
template<class T>
std::string to_string(const T& t_value)
{
	std::stringstream ss;
	ss << t_value;
	return ss.str();
}

void ReadTree(std::vector< std::vector<TH1F*> >& t_EF, std::vector< std::vector<TH1F*> >& t_EB)
{
	t_EF.clear();
	t_EB.clear();
	TFile *file = new TFile("~/HiraETheta/ReadTree/run-0010-00.root");
	TTree *tree = (TTree*) file->Get("E16042");

	t_EF.resize(num_tele);
	t_EB.resize(num_tele);
	for(int i = 0; i < num_tele; ++i)
		for(int j = 0; j < num_strip; ++j)
		{
			t_EF[i].push_back(new TH1F(("tele_EF_" + to_string(i) + "_strip_" + to_string(j)).c_str(), "title", 200, 600, 2000.));
			t_EB[i].push_back(new TH1F(("tele_EB_" + to_string(i) + "_strip_" + to_string(j)).c_str(), "title", 200, 600, 2000.));
		}

	RBHiRATelescope* det[num_tele];
	for(int i = 0; i < num_tele; ++i)
	{
		det[i] = new RBHiRATelescope;
		tree->SetBranchAddress(("tele" + to_string(i)).c_str(), &det[i]);
	}

	unsigned int entries = tree->GetEntries();

	for(int i = 0; i < entries; ++i)
	{
		tree->GetEntry(i);
		for(int j = 0; j < num_tele; ++j)
		{
			bool got_EF = false;
			bool got_EB = false;
			for(int k = 0; k < num_strip; ++k)
				if(det[j]->EF.ERawHi[k] > 10)
				{
					got_EF = true;
			//		cout << "Fill " << det[j]->EF.ERawHi[k] << endl;
					t_EF[j][k]->Fill(det[j]->EF.ERawHi[k]);
				}
			for(int k = 0; k < num_strip; ++k)
				if(det[j]->EB.ERawHi[k] > 10)
				{
					got_EB = true;
			//		cout << ij << " " << k << endl;
					t_EB[j][k]->Fill(det[j]->EB.ERawHi[k]);
				}
		}
		std::cout << "Processing percentage " << (double) i/ (double) entries << "\r";
	}

	TFile *output = new TFile("AllEFEBHist.root", "RECREATE");
	for(int j = 0; j < num_tele; ++j)
		for(int k = 0; k < num_strip; ++k)
		{
			t_EB[j][k]->Write();
			t_EF[j][k]->Write();
		}
	output->Write();
	

}

bool ReadTreeFromFile(std::vector< std::vector<TH1F*> >& t_EF, std::vector< std::vector<TH1F*> >& t_EB, const std::string& t_filename = "AllEFEBHist.root")
{
	t_EF.clear();
	t_EB.clear();

	TFile *input = new TFile(t_filename.c_str());
	if(!input->IsOpen()) return false;

	t_EF.resize(num_tele);
	t_EB.resize(num_tele);
	for(int i = 0; i < num_tele; ++i)
		for(int j = 0; j < num_strip; ++j)
		{
			TH1F* EF = (TH1F*) input->Get(("tele_EF_" + to_string(i) + "_strip_" + to_string(j)).c_str());
			TH1F* EB = (TH1F*) input->Get(("tele_EB_" + to_string(i) + "_strip_" + to_string(j)).c_str());
			if(!EF) std::cerr << " Cannot load EF for tele " << i << " strip " << j << "\n";
			if(!EB) std::cerr << " Cannot load EB for tele " << i << " strip " << j << "\n";
			t_EF[i].push_back(EF);
			t_EB[i].push_back(EB);
		}
	
	return true;

}
