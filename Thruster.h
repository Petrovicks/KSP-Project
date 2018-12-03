#pragma once
#include "RocketPart.h"

class Thruster : public RocketPart{
public:
	double thrust;		
	double efficiency;

	double getThrust();
	double getEfficiency();

	void setThrust(double inThrust);
	void setEfficiency(double inEff);
};