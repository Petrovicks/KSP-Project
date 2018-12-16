#include "RocketPart.h"
#include "CommandModule.h"
#include "FuelTank.h"
#include "Thruster.h"
#include "RocketShip.h"
// #include "Planets.h"
#include <iostream>

using namespace std;

int main() {
	RocketShip plutoisaplanet;

	// ****************************************
	//				Command Module
	// ****************************************
	int num_passengers;
	double cHull_mass;
	CommandModule* c1;
	c1 = new CommandModule();

	cout << "A rocketship has three components: the command module up top, then a fuel tank, then a thruster at the bottom." << endl;
	cout << "First, enter the number of passengers that will be inside the command module: ";
	cin >> num_passengers;
	c1->setNumberPassengers(num_passengers);
	cout << "\nNumber of passengers set to " << c1->getNumberPassengers() << endl;

	cout << "Set the hull mass of the command module (passenger weight added separately): ";
	cin >> cHull_mass;
	c1->setMass(cHull_mass);

	plutoisaplanet += c1;	
	cout << "Part type: " << plutoisaplanet.getPartType(0) << endl;
	cout << "Part mass: " << plutoisaplanet.getPartMass(0) << endl << endl;


	// ****************************************
	//				Fuel Tank
	// ****************************************
	double fCapacity;
	double fDensity;
	double fHull_mass;

	FuelTank* f1;
	f1 = new FuelTank();

	cout << "Next, enter the amount of fuel in the fuel tank: ";
	cin >> fCapacity;
	f1->setCapacity(fCapacity);
	cout << "\nFuel Capacity set to " << f1->getCapacity() << endl;

	cout << "Enter the density of the fuel (unit weight per unit fuel): ";
	cin >> fDensity;
	f1->setFuelDensity(fDensity);
	cout << "\nFuel Density set to " << f1->getFuelDensity() << endl;

	cout << "Set the hull mass of the fuel tank (fuel weight added separately): ";
	cin >> fHull_mass;
	f1->setMass(fHull_mass);

	plutoisaplanet += f1;
	cout << "Part type: " << plutoisaplanet.getPartType(1) << endl;
	cout << "Part mass: " << plutoisaplanet.getPartMass(1) << endl << endl;

	// ****************************************
	//				Thruster
	// ****************************************
	double tThrust;
	double tEfficiency;
	double tHull_mass;

	Thruster* t1;
	t1 = new Thruster();

	cout << "Next, enter the amount of thrust the engine puts out nominally: ";
	cin >> tThrust;
	t1->setThrust(tThrust);
	cout << "\nThrust set to " << t1->getThrust() << endl;

	cout << "Enter the efficiency of the thruster (0.00 to 1.00): ";
	cin >> tEfficiency;
	t1->setEfficiency(tEfficiency);
	cout << "\nEfficiency set to " << t1->getEfficiency() << endl;

	cout << "Set the mass of the thruster: ";
	cin >> tHull_mass;
	t1->setMass(tHull_mass);

	plutoisaplanet += t1;
	cout << "Part type: " << plutoisaplanet.getPartType(2) << endl;
	cout << "Part mass: " << plutoisaplanet.getPartMass(2) << endl << endl;

	cout << "All parts: " << endl;
	plutoisaplanet.returnAllParts();
	cout << endl;

	//This new function sets changes the values of the member variables. 
	plutoisaplanet.constructRocket();
	plutoisaplanet.takeAJourney();

	return 0;
}
