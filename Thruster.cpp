#include "Thruster.h"
#include <string>

Thruster::Thruster() {
	thrust = 100.0;
	efficiency = 1.00;
}

double Thruster::getThrust() {
	return thrust;
}
double Thruster::getEfficiency() {
	return efficiency;
}

void Thruster::setThrust(double inThrust) {
	thrust = inThrust;
}
void Thruster::setEfficiency(double inEff) {
	efficiency = inEff;
}

std::string Thruster::partType() {
	return "Thruster";
}

double Thruster::calcDrag() {
	return 1 - (thrust / (1000*thrust*efficiency));	// A more efficient thruster is smaller
}

void Thruster::setMass(double inMass) {
	mass = inMass;
}
