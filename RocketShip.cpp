#include "RocketShip.h"
#include "Thruster.h"
#include "FuelTank.h"
#include "CommandModule.h"
#include "Planets.h"
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
	return *this;
}

double RocketShip::calculateTWR() {
	return thrust / (mass * 9.81); //total Thrust over total Weight on Earth
}

double RocketShip::calculateDeltaV() {
	return 0.0;//see Tsiolkovsky rocket equation
}

//"dynamic_cast" allows you to cast a pointer to derived from base and vice versa.
//I know it defeats the purpose of virtual functions for the most part but since
//parts have unique functionality I figured this was alright for a solution.
//It was a tossup between this or creating more virtual functions. 
//NOTE: No memory leak here, the pointers die once the { } block of each case 
//finishes. 
void RocketShip::constructRocket() {
	for(int i = 0; i < parts.size(); i++) {
		switch (hashPartNames(parts[i]->partType())) {
			case _Thruster:
			{
				Thruster* t = dynamic_cast<Thruster*>(parts[i]);
				thrust+=t->getThrust();
				mass+=t->getMass();
				drag+=t->calcDrag();
				efficiency+=t->getEfficiency();
				break;
			}
			case _CommandModule:
			{
				CommandModule* c = dynamic_cast<CommandModule*>(parts[i]);
				efficiency+=c->getPathEfficiency(); //This should probably be changed. Could just wrap pathefficiency into efficiency with a scaler. 
				mass+=c->getMass();
				drag+=c->calcDrag();
				break;
			}
			case _FuelTank:
			{
				FuelTank* f = dynamic_cast<FuelTank*>(parts[i]);
				mass+=f->getMass();
				fuelDensity = f->getFuelDensity();
				fuelCapacity += f->getCapacity();
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
void RocketShip::takeAJourney() {
	// //================
	// // File processing
	// //================
	ifstream testFile;
	testFile.open("Planets.ini");
	planetParameters::getPlanetParams(testFile);
	// cout << "Number of planets: " << planetParameters::planetCount << endl;
	// cout << "Planet one: " << planetParameters::planetList.planetName[1] << endl;
	// cout << "Position: " << planetParameters::planetList.position[1] << endl;
	// cout << "Atmospheric Density: " << planetParameters::planetList.atmosphericDensity[1] << endl;
	// cout << "Gravity: " << planetParameters::planetList.gravity[1] << endl;

	cout << "Choose an origin by entering a number corresponding with the planet: " << endl;
	for(int i = 1; i <= planetParameters::planetCount; i++) {
		cout << "Planet ID " << i << ": " << planetParameters::planetList.planetName[i] << endl;
	}

	int originID;
	cin >> originID;

	cout << "Choose a destination by entering a number corresponding with the planet: " << endl;
	for(int i = 1; i <= planetParameters::planetCount; i++) {
		cout << "Planet ID " << i << ": " << planetParameters::planetList.planetName[i] << endl;
	}

	int destinationID;
	cin >> destinationID;

	double distance = abs(planetParameters::planetList.position[originID] - planetParameters::planetList.position[destinationID]);
	cout << "Distance from " << planetParameters::planetList.planetName[originID] << " to "
		 << planetParameters::planetList.planetName[destinationID] << " is " << distance << "." << endl;
}