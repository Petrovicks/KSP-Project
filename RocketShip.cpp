#include "RocketShip.h"

// RocketShip::RocketShip(RocketPart &inRP){

// }

double RocketShip::calculateTWR() {
	return thrust / (mass * 9.81); //total Thrust over total Weight on Earth
}

double RocketShip::calculateDeltaV() {
	return 0.0;//see Tsiolkovsky rocket equation
}
