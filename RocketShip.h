#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

#include "RocketPart.h"
#include <string>
#include <vector>
#include <iostream>

class RocketShip {

	//This enum-hash function pair allows for the use of switch statements with strings.
	enum partType {
		_Thruster,
		_CommandModule,
		_FuelTank,
	};

	partType hashPartNames(std::string const& inString) {
		if (inString == "Command Module") {
			return _CommandModule;
		}
		if (inString == "Fuel Tank") {
			return _FuelTank;
		}
		if (inString == "Thruster") {
			return _Thruster;
		}
	}

public:
	RocketShip();
	~RocketShip() {};

	RocketShip& operator=(const RocketShip& r);
	RocketShip& operator+=(RocketPart* p);

	double calculateTWR(double);
	double calculateDeltaV();

	void constructRocket();
	void returnAllParts();
	RocketPart& returnSpecificPart(int);
	std::string getPartType(int);
	double getPartMass(int);

	//Getting from origin to destination.
	bool takeAJourney();
private:
	double mass;
	double thrust;
	double drag = 1.00;
	double dV;
	double TWR;
	double efficiency;
	double fuelCapacity;

	//Vector of base class pointers.
	std::vector<RocketPart*> parts;
};

#endif
