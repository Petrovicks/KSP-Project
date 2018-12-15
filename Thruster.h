#ifndef THRUSTER_H
#define THRUSTER_H

#include "RocketPart.h"
#include <string>

class Thruster : public RocketPart{
public:
	Thruster();

	double getThrust();
	double getEfficiency();

	void setThrust(double inThrust);
	void setEfficiency(double inEff);

	std::string partType();
	double calcDrag();
	void setMass(double inMass);
private:
	double thrust;
	double efficiency;
};

#endif
