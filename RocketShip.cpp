#include "RocketShip.h"
#include "Thruster.h"
#include "FuelTank.h"
#include "CommandModule.h"
#include "Planets.h"
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

RocketShip::RocketShip() {}

RocketShip& RocketShip::operator=(const RocketShip& r) {
	this->parts = r.parts;
	return *this;
}

RocketShip& RocketShip::operator+=(RocketPart* p) {
	this->parts.push_back(p);
	return *this;
}

double RocketShip::calculateTWR(double inG) {
	return thrust / (mass * inG); //total Thrust over total Weight on Earth
}

double RocketShip::calculateDeltaV() {
	//Dry mass
	double dryMass = this->mass - this->fuelCapacity;
	double dV = this->thrust * log(this->mass / dryMass);
	return dV;
}

//"dynamic_cast" allows you to cast a pointer to derived from base and vice versa.
//I know it defeats the purpose of virtual functions for the most part but since
//parts have unique functionality I figured this was alright for a solution.
//It was a tossup between this or creating more virtual functions. If more part types
//were to be added with special functionality this implementation would still be generic enough
//to handle it without virtual functions.
//NOTE: Shouldn't be a memory leak here, the pointers die once the { } block of each case
//finishes since destructors are explicit in RocketPart and its derived classes.
void RocketShip::constructRocket() {
	for(int i = 0; i < parts.size(); i++) {
		mass+=parts[i]->getMass();
		drag*=parts[i]->calcDrag();
		switch (hashPartNames(parts[i]->partType())) {
			case _Thruster:
			{
				Thruster* t = dynamic_cast<Thruster*>(parts[i]);
				thrust += t->getThrust(); //Treating this as escape velocity.
				efficiency *= t->getEfficiency(); //Multiplicatively combine efficiencies.
				break;
			}
			case _CommandModule:
			{
				CommandModule* c = dynamic_cast<CommandModule*>(parts[i]);
				efficiency *= c->getPathEfficiency(); //Wrapping this into overall effiency.
				break;
			}
			case _FuelTank:
			{
				FuelTank* f = dynamic_cast<FuelTank*>(parts[i]);
				fuelCapacity += f->getCapacity(); //Need this for deltaV.
				break;
			}
		}
	}
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


//Moved file procesing here. This is where the success and failure will be calculated.
bool RocketShip::takeAJourney() {
	// //================================
	// // File processing
	// //================================
	ifstream testFile;
	testFile.open("Planets.ini");
	planetParameters::getPlanetParams(testFile);

	// //================================
	// // Get origin
	// //================================
	cout << "Choose an origin by entering a number corresponding with the planet: " << endl;
	for(int i = 1; i <= planetParameters::planetCount; i++) {
		cout << "Planet ID " << i << ": " << planetParameters::planetList.planetName[i] << endl;
	}

	int originID = planetParameters::planetCount+1;

	//Light trap for invalid numbers.
	while (originID > planetParameters::planetCount || originID < 0) {
		cin >> originID;
	}

	// //================================
	// // Get destination
	// //================================
	cout << "Choose a destination by entering a number corresponding with the planet: " << endl;
	for(int i = 1; i <= planetParameters::planetCount; i++) {
		cout << "Planet ID " << i << ": " << planetParameters::planetList.planetName[i] << endl;
	}

	int destinationID = planetParameters::planetCount + 1;

	//Light trap for invalid numbers.
	while (destinationID > planetParameters::planetCount || destinationID < 0) {
		cin >> destinationID;
	}

	// //================================
	// // Trip success math
	// //================================

	bool failure = false;
	double gConstant = 6.67e-11; //Universal graviational constant used in escape velocity.
	double delVDifference = 0;

	double distance = abs(planetParameters::planetList.position[originID] - planetParameters::planetList.position[destinationID]);

	cout << "Distance from " << planetParameters::planetList.planetName[originID] << " to "
		 << planetParameters::planetList.planetName[destinationID] << " is " << distance << "." << endl;

	cout << "Calculating dV of the rocket... " << endl;
	dV = this->calculateDeltaV();

	cout << "The rocket's maximum change of velocity is " << dV << "." << endl;
	
	// //================================
	// // Here comes the math. I have no idea what I'm doing.
	// //================================

	double Ve = sqrt(2*gConstant*planetParameters::planetList.mass[originID]
					 / planetParameters::planetList.radius[originID]); //Escape velocity of the origin.

	// Holmann orbit transfer I guess? Sum total of these two should be the required delV total.
	double delV1 = Ve*(sqrt(2*planetParameters::planetList.orbit[destinationID]
							/planetParameters::planetList.orbit[destinationID]
							+planetParameters::planetList.orbit[originID]) - 1);

	double delV2 = 	sqrt(2*gConstant*planetParameters::planetList.mass[originID]
					 	 / planetParameters::planetList.radius[destinationID])
					*(sqrt(2*planetParameters::planetList.orbit[originID]
							/planetParameters::planetList.orbit[destinationID]
							+planetParameters::planetList.orbit[originID])-1);

	if (dV < Ve || this->calculateTWR(planetParameters::planetList.gravity[originID]) < 1) {
		cout << "Rocket failed to escape the origin's gravity." << endl;
		cout << "Please see generated text file for details." << endl;
		failure = true;
	}

	if (dV < delV1 + delV2) {
		delVDifference = dV - (delV1 + delV2);
		cout << "Failed to make the journey by" << delVDifference << endl;
	}

	else {
		cout << "The rocket journey was a sucess." << endl;
	}

	ofstream outFile;
	outFile.open("Rocket_postmortem.txt");
	if(failure) {
		outFile << "There's always next time.\n\n\n";
	}
	else {
		outFile << "Congratulations on the sucecssful launch.\n\n\n";
	}

	outFile << "Origin planet: " << planetParameters::planetList.planetName[originID] << "\n"
			<< "Gravity: " << planetParameters::planetList.gravity[originID] << " m/s^2\n"
			<< "Orbit: " << planetParameters::planetList.orbit[originID] << " km\n"
			<< "Mass: " << planetParameters::planetList.mass[originID] << " kg\n"
			<< "Radius: " << planetParameters::planetList.radius[originID] << " km\n\n"
			<< "Destination planet: " << planetParameters::planetList.planetName[destinationID] << "\n"
			<< "Gravity: " << planetParameters::planetList.gravity[destinationID] << " m/s^2\n"
			<< "Orbit: " << planetParameters::planetList.orbit[destinationID] << " km\n"
			<< "Mass: " << planetParameters::planetList.mass[destinationID] << " kg\n"
			<< "Radius: " << planetParameters::planetList.radius[destinationID] << " km\n"
			<< "\n\n\n"
			<< "Delta V potential of rocket: " << dV << " m/s\n"
			<< "Delta V required to make the journey: " << delV1+delV2 << " m/s\n"
			<< "Delta V difference: " << delVDifference << " m/s\n";

	outFile.close();

	return !failure;
}
