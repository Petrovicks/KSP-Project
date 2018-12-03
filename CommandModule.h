#pragma once
#include "RocketPart.h"

class CommandModule : public RocketPart {
public:
	double numPassengers;	// will add mass to rocket
	double pathEfficiency;	// linear efficiency term to represent deviation from optimal path

	double getNumberPassengers();
	double getPathEffiency();

	void setNumberPassengers(double inPassengers);
	void setPathEfficiency(double inPathEff);
};