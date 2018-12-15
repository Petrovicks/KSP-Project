#include "RocketShip.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

RocketShip::RocketShip() {}

RocketShip& RocketShip::operator=(const RocketShip& r) {
	this->parts = r.parts;
	return *this;
}

RocketShip& RocketShip::operator+=(RocketPart* p) {
	this->parts.push_back(p);
}

double RocketShip::calculateTWR() {
	return thrust / (mass * 9.81); //total Thrust over total Weight on Earth
}

double RocketShip::calculateDeltaV() {
	return 0.0;//see Tsiolkovsky rocket equation
}

//all parts
void RocketShip::returnAllParts() {
	cout << "Constructed rocket: " << endl;
	for (int i = 0; i < parts.size(); i++) {
		cout << parts[i]->partType() << " with ID " << i << endl;
	}
}

//specific part information exmaple
string RocketShip::getPartType(int ID) {
	return parts[ID]->partType();
}

double RocketShip::getPartMass(int ID) {
	return parts[ID]->getMass();
}
