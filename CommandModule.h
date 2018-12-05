#ifndef COMMANDMODULE_H
#define COMMANDMODULE_H

#include "RocketPart.h"

class CommandModule : public RocketPart {
public:
	CommandModule();

	int getNumberPassengers();
	double getPathEffiency();
	double calcDrag();

	void setNumberPassengers(int inPassengers);
	void setPathEfficiency(double inPathEff);
private:
	int numPassengers;	// will add mass to rocket
	double pathEfficiency;	// linear efficiency term to represent deviation from optimal path
};

#endif
