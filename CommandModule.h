#ifndef COMMANDMODULE_H
#define COMMANDMODULE_H

#include "RocketPart.h"
#include <string>

class CommandModule : public RocketPart {
public:
	CommandModule();

	int getNumberPassengers();
	double getPathEfficiency();

	void setNumberPassengers(int inPassengers);
	void setPathEfficiency(double inPathEff);

	std::string partType();
	double calcDrag();
	void setMass(double inMass);
private:
	int numPassengers;	// will add mass to rocket
	double pathEfficiency;	// linear efficiency term to represent deviation from optimal path
};

#endif
