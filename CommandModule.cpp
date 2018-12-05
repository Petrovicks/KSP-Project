#include "CommandModule.h"

CommandModule::CommandModule() {
	numPassengers = 1;
	pathEfficiency = 1.00;
}

int CommandModule::getNumberPassengers() {
	return numPassengers;
}

double CommandModule::getPathEffiency() {
	return pathEfficiency;
}

double CommandModule::calcDrag(){
	return 1 - (numPassengers / (2*(numPassengers+1)));		// diminishing returns: 0.750 , 0.667, 0.625, 0.60, 0.583
}

void CommandModule::setNumberPassengers(int inPassengers) {
	numPassengers = inPassengers;
}

void CommandModule::setPathEfficiency(double inPathEff) {
	pathEfficiency = inPathEff;
}