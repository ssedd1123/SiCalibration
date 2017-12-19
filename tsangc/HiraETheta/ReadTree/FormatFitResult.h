#ifndef FORMATFITRESULT_H
#define FORMATFITRESULT_H
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include "TF1.h"

template<class T>
std::string to_string(const T& t_value)
{
	std::stringstream ss;
	ss << t_value;
	return ss.str();
}

enum BadFitFix{ throwaway, average };

class FormatFitResult
{
public:
	FormatFitResult(const std::string& t_side = "EF", BadFitFix t_fix = throwaway)
	{
		// get average slope and intercept
		std::ifstream ave_par(("tsangc/HiraETheta/ReadTree/FitResult/average_parameter_" + t_side + ".dat").c_str());
		std::string line;
		ave_par >> line;
		double ave_slope, ave_intercept;
		ave_par >> ave_slope >> ave_intercept;

		std::ofstream output(("SiCalibrationForSpectal" + t_side + ".dat").c_str());
		for(int i = 0; i < 12; ++i)
		{
			std::ifstream input(("tsangc/HiraETheta/ReadTree/FitResult/CalTele" + t_side + "_" + to_string(i) + ".dat").c_str());
			if(!input.is_open()) 
			{
				std::cerr << "File for tele" << t_side << " " << i << " is not found!\n";
				continue;
			}
			// first line is the header, always discard
			std::getline(input, line);
	
			int strip_num, cal_num;
			double intercept, slope, intercept_error, slope_error, chisquare;
			while(std::getline(input, line))
			{
				std::string side_lower = (t_side == "EF")? "ef": "eb";
				std::stringstream ss(line);
				if(ss >> strip_num >> cal_num >> intercept >> slope >> intercept_error >> slope_error >> chisquare)
				{
					StripIndex name(i, strip_num);
					if(chisquare < 5 && cal_num == 4)
						list_calibration_[name] = LineEquation(slope, intercept);
					else
					{
						switch(t_fix)
						{
							case throwaway: break;
							case average: list_calibration_[name] = LineEquation(ave_slope, ave_intercept); break;
								
						}
					}
					//if(chisquare > 50 || cal_num != 5)
						//list_bad_fit.insert(StripIndex(i, strip_num));
				}
				else
				{
					std::cerr << "Cannot read line " << line << "\n";
					continue;
				}
				
			}
		}
	};

	double CalibrateEnergy(int t_tele_no, int t_strip_no, double channels)
	{
		std::map<StripIndex, LineEquation>::iterator it = list_calibration_.find(StripIndex(t_tele_no, t_strip_no));
		if(it == list_calibration_.end()) return 0;
		else return it->second.Eval(channels);
	};

private:
	struct StripIndex
	{
		int tele_no, strip_no;

		StripIndex(int t_tele_no, int t_strip_no) : tele_no(t_tele_no), strip_no(t_strip_no) {};
		StripIndex() : tele_no(0), strip_no(0) {};
		bool operator < (const StripIndex& compare) const 
		{
			if(this->tele_no < compare.tele_no) return true;
			else if (this->tele_no > compare.tele_no) return false;
			else if (this->strip_no < compare.strip_no) return true;
			else return false;
		};
		bool operator == (const StripIndex& compare) const 
		{
			return (compare.tele_no == this->tele_no) && (compare.strip_no == this->strip_no);
		};
	};
	
	struct LineEquation
	{
		LineEquation() : slope(0), intercept(0) {};
		LineEquation(double t_slope, double t_intercept) : slope(t_slope), intercept(t_intercept) {};
		double slope, intercept;
		double Eval(double x) { return x*slope + intercept;};
	};
	//std::set<StripIndex> list_bad_fit_;
	std::map<StripIndex, LineEquation> list_calibration_;	
};

#endif
