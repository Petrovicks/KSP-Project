#ifndef FUELTANK_H
#define FUELTANK_H

#include "RocketPart.h"
#include <string>

class FuelTank : public RocketPart {
public:
	FuelTank();

	double getCapacity();
	double getFuelDensity();
	void setCapacity(double inCapacity);
	void setFuelDensity(double inFuelDensity);

	std::string partType();
	double calcDrag();
	void setMass(double inMass);
private:
	double capacity;	// how much fuel by mass there is
	double fuelDensity;	// how heavy the fuel is (unit mass per unit fuel)
};

#endif
