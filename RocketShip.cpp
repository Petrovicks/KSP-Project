#include "RocketShip.h"

RocketShip::RocketShip(RocketPart &inRP){

}

double RocketShip::calculateTWR() {
	return thrust / (mass * 9.8);//totalThrust over totalWeight 
}

double RocketShip::calculateDeltaV() {
	return 0.0;//see Tsiolkovsky rocket equation
}