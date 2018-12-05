#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

#include "RocketPart.h"

class RocketShip {
public:
	// RocketPart RP;
	// RocketShip(RocketPart &inRP);

	double calculateTWR();
	double calculateDeltaV();
private:
	double mass;
	double thrust;
	double drag;
	double dV;
	double TWR;
};

#endif
