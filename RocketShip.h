#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

#include "RocketPart.h"
#include <string>
#include <vector>

class RocketShip {
public:
	RocketShip();

	RocketShip& operator=(const RocketShip& r);
	RocketShip& operator+=(RocketPart* p);

	double calculateTWR();
	double calculateDeltaV();

	void returnAllParts();
	RocketPart& returnSpecificPart(int);
	std::string getPartType(int);
	double getPartMass(int);
private:
	double mass;
	double thrust;
	double drag;
	double dV;
	double TWR;

	std::vector<RocketPart*> parts;
};

#endif
