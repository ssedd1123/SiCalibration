#ifndef EXTRAPOLATEENERGY_H
#define EXTRAPOLATEENERGY_H
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "TGraph.h"

// range of validity of energy
const double energy_low = 50, energy_high = 1000;

/***************************
This class assumes that the incoming particle have punched through the silicon strip
And incoming particle is always a proton
***************************/

class ExtrapolateEnergy
{
public:
	// choose which model to use and where is the lise file
	ExtrapolateEnergy(unsigned t_model = 0, const std::string t_filename = "tsangc/HiraETheta/ReadTree/LISE/LISE_H_energyloss_Si.txt")
	{
		std::ifstream model(t_filename.c_str());
		if(!model.is_open()) std::cerr << t_filename << " Cannot be opened\n";
		// first line is header
		std::string line;
		model >> line;
		while(std::getline(model, line))
		{
			double energy;
			double Si_energy;
			std::stringstream ss(line);
			// total energy is always the first column
			ss >> energy;
			if(energy < energy_low || energy > energy_high) continue;
			// read model
			for(int i = 0; i <= t_model; ++i)
				ss >> Si_energy;
			// multiply by the thickness of the silicon
			Si_energy *= 1e4;
			model_.SetPoint(model_.GetN(), Si_energy, energy);
		}
	}

	double SiEnergyToTotalEnergy(double t_Si_E)
	{
		return model_.Eval(t_Si_E);
	}

private:
	TGraph model_;
};


#endif
