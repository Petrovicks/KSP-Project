#include "RocketPart.h"
#include "CommandModule.h"
#include "RocketShip.h"
#include <iostream>

using namespace std;

int main() {
	CommandModule c1;
	cout << "A rocketship has three components: the command module up top, then a fuel tank, then a thruster at the bottom." << endl;
	cout << "First, enter the number of passengers that will be inside the command module: ";
	cin >> c1.numPassengers;
	return 0;
}