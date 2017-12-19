#ifndef HIRAPARSER_H
#define HIRAPARSER_H
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <cctype>
#include "TVector3.h"

std::string RemoveSpace(const std::string& t_string)
{
	std::string line(t_string);
	//line.erase(std::remove_if(line.begin(), line.end(), ' '), line.end());
	line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
	return line;
};

class HiraParser
{
public:
	HiraParser(const std::string& t_filename) : 
		configuration_(t_filename.c_str())
	{
		if(!configuration_.is_open())
			throw std::runtime_error("HiraParser cannot open configuration file " + t_filename);
	};

	void BackToBeginning()
	{
		configuration_.clear();
		configuration_.seekg(0, ios::beg);
	};

	// look for the designated detector name by reading the file in order
	bool FindNextDetector(const std::string& t_detector)
	{
		// Read from detector
		
		bool detector_found = false;
		std::string line;
		// remove space from detector names
		std::string detector = RemoveSpace(t_detector);
		while(std::getline(configuration_, line))
		{
			// remove space from the line read
			line = RemoveSpace(line);
			if(line == detector)
			{
				detector_found = true;
				break;
			}
		}
		if(!detector_found) return detector_found;

		while(std::getline(configuration_, line))
		{
			// if the first characher is not space, then break
			if(line.empty()) break;
			// check for comment first
			line = line.substr(0, line.find("%"));
			// if there's nothing before comment, skip
			if(line.find_first_not_of(' ') == std::string::npos) continue;
			std::size_t found = line.find("=");
			if(found != std::string::npos)
			{
				//keys_.push_back(RemoveSpace(line.substr(0, found)));
				std::string val = RemoveSpace(line.substr(0, found));
				internal_data_[val] = line.substr(found + 1);
				keys_.push_back(val);
			}
			else 
				break; 
		}

		return true;
	};

        std::vector<std::string> GetAllToken()
        {
                return keys_;
        };

	TVector3 GetTVector3(const std::string& t_token)
	{
		if(internal_data_.count(t_token) == 0)
                        throw std::runtime_error("The given token " + t_token + " is not found!");
                std::stringstream ss(internal_data_.at(t_token));
                double x, y, z;
                if(ss >> x >> y >> z)
                        return TVector3(x, y, z);
                else
                        throw std::runtime_error("The given token " + t_token + " does not corresponds to a vector!");
	};

       template <class T>
        T GetValue(const std::string& t_token)
        {
                if(internal_data_.count(t_token) == 0)
                        throw std::runtime_error("The given token " + t_token + " is not found!");
                std::stringstream ss(internal_data_.at(t_token));
                T output;
                ss >> output;
                return output;
        };

private:
	std::ifstream configuration_;
	std::vector<std::string> keys_;
        std::map<std::string, std::string> internal_data_;

};

#endif
