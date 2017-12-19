#ifndef HIRATRANSFORMATION_H
#define HIRATRANSFORMATION_H
#include "TVector3.h"
#include <iostream>

class HiraTransformation
{
public:
	HiraTransformation(	const TVector3& t_pos1, 
				const TVector3& t_pos2, 
				const TVector3& t_pos3, 
				const TVector3& t_pos4	) :
	strip_front_num_(32.),                                          			
        strip_back_num_(32.),
        strip_length_front_(64.), // mm
        strip_length_back_(64.), // mm
        width_per_strip_front_(2.),//strip_length_front_ / (double) strip_front_num_ ),
        width_per_strip_back_(2.)//strip_length_back_ / (double) strip_back_num_)
	{
		pos_ = (t_pos1 + t_pos2 + t_pos3 + t_pos4) *(1. / 4.);
		hira_x_ = t_pos4 - t_pos2;
		hira_x_ = hira_x_.Unit();
		hira_z_ = pos_.Unit();
		hira_y_ = hira_z_.Cross(hira_x_);
	};

	TVector3 TransformCoordinates(const TVector3& t_vec)
	{
		return pos_ + hira_x_*t_vec[0] + hira_y_*t_vec[1] + hira_z_*t_vec[2];	
	}

	// transform strip numbers to hit position
	TVector3 TransformStripNum(unsigned int t_strip_front, unsigned int t_strip_back)
	{
		double x = width_per_strip_front_*(0.5 + (double) t_strip_front) - 0.5*strip_length_front_;
		double y = width_per_strip_back_*(0.5 + (double) t_strip_back) - 0.5*strip_length_back_;
		return pos_ + hira_x_*x + hira_y_*y;
	}
private:
	// 3 unit vectors of Hira coordinates in lab frame
	TVector3 hira_x_, hira_y_, hira_z_;
	// Position vector of hira
	TVector3 pos_;
	// constants about silicon strips
	const unsigned int strip_front_num_;
	const unsigned int strip_back_num_;
	const double strip_length_front_; // mm
	const double strip_length_back_; // mm
	const double width_per_strip_front_;
	const double width_per_strip_back_;
};

#endif
