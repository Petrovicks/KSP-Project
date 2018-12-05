#include "Thruster.h"

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