#include "CommandModule.h"

double CommandModule::getNumberPassengers() {
	return numPassengers;
}


double CommandModule::getPathEffiency() {
	return pathEfficiency;
}

void CommandModule::setNumberPassengers(double inPassengers) {
	numPassengers = inPassengers;
}

void CommandModule::setPathEfficiency(double inPathEff) {
	pathEfficiency = inPathEff;
}