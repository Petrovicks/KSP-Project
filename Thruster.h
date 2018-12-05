#ifndef THRUSTER_H
#define THRUSTER_H

#include "RocketPart.h"

class Thruster : public RocketPart{
public:
	Thruster();

	double getThrust();
	double getEfficiency();

	void setThrust(double inThrust);
	void setEfficiency(double inEff);
private:
	double thrust;
	double efficiency;
};

#endif
