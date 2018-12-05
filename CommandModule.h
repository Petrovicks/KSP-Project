#pragma once
#include "RocketPart.h"

class CommandModule : public RocketPart {
public:
	CommandModule();
	int numPassengers;	// will add mass to rocket
	double pathEfficiency;	// linear efficiency term to represent deviation from optimal path

	int getNumberPassengers();
	double getPathEffiency();
	double calcDrag();

	void setNumberPassengers(int inPassengers);
	void setPathEfficiency(double inPathEff);
};