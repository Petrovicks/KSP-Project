#ifndef FUELTANK_H
#define FUELTANK_H

#include "RocketPart.h"

class FuelTank : public RocketPart {
public:
	FuelTank();
	//double fuelDensity;	// energy density of the fuel, Megajoules per kg
						// for refrence, liquid Hydrogen has 142MJ/kg
						// this makes the math harder, might not be worth considering

	double getCapacity();
	//double getFuelDensity();

	void setCapacity(double inCapacity);
	//void setFuelDensity(double inFuelDensity);
private:
	double capacity;	// how much fuel by mass there is
};

#endif
