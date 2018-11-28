#pragma once
#include "RocketPart.h"

class RocketShip {
public:
	RocketPart RP;
	RocketShip(RocketPart &inRP);

	double calculateTWR();
	double calculateDeltaV();
};