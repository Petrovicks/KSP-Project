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

/*double FuelTank::getFuelDensity() {
	return fuelDensity;
}*/

void FuelTank::setCapacity(double inCapacity) {
	capacity = inCapacity;
}

/*void FuelTank::setFuelDensity(double inFuelDensity) {
	fuelDensity = inFuelDensity;
}*/
