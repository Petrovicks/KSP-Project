#include "FuelTank.h"
#include <string>


FuelTank::FuelTank() {
	capacity = 100.0;
}

std::string FuelTank::partType() {
	return "Fuel Tank";
}

double FuelTank::getCapacity() {
	return capacity;
}

double FuelTank::getFuelDensity() {
	return fuelDensity;
}

void FuelTank::setCapacity(double inCapacity) {
	capacity = inCapacity;
}

void FuelTank::setFuelDensity(double inFuelDensity) {
	fuelDensity = inFuelDensity;
}

double FuelTank::calcDrag() {
	return 1 - (capacity / (20000+capacity));	// only becomes significant at huge amounts of fuel
}

void FuelTank::setMass(double inMass) {
	mass = capacity * fuelDensity + inMass;
}
