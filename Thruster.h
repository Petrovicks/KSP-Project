#ifndef THRUSTER_H
#define THRUSTER_H

#include "RocketPart.h"
#include <string>

class Thruster : public RocketPart{
public:
	Thruster();

	double getThrust();
	double getEfficiency();

	std::string partType();

	void setThrust(double inThrust);
	void setEfficiency(double inEff);
private:
	double thrust;
	double efficiency;
};

#endif
