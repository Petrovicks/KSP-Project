#include "Thruster.h"

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