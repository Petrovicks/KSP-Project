#include <fstream>
#ifndef DESTINATIONS_H
#define DESTINATIONS_H
//********************************************************
//
// This is a skeleton header file for parsing ini files.
// Basic string parsing for grabbing the string name and
// subsequent numeric values is done, as well as enum matching.
//
// Generic planet struct created to be used for generating
// a source and destination with respective parameters read
// in from the ini file.
//
//********************************************************

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Planet {
	int position;
	string name;
};

Planet destination;
// Planet origin;

enum planetCode {
	MARS,
	MOON,
};

planetCode hashPlanetString(string const& inString) {
	if (inString == "MOON")
		return MOON;
	if (inString == "MARS")
		return MARS;
}

string getPlanetFromLine(string inString) {
	int firstSpace = inString.find(" ");
	return inString.substr(0, firstSpace);
}

int getValueFromLine(string inString) {
	inString.erase( remove(inString.begin(), inString.end(), ' '), inString.end() );
	int equalSign = inString.find('=');
	string valueString = inString.substr(equalSign+1);
	return stoi(valueString); //COMPILED WITH C++11
}

//TODO: Merge this with origin as well. Rename to change reflected behavior.
namespace destinationParameters
{
	void getDestinationParams(ifstream& inFile) {
		string line;
		if (inFile.is_open()) {
			while (getline (inFile, line)) {
				string planetString = getPlanetFromLine(line);
				switch (hashPlanetString(planetString)) {
					case MOON:
						destination.position = getValueFromLine(line);
						destination.name = planetString;
						break;
					case MARS:
						destination.position = getValueFromLine(line);
						destination.name = planetString;
						break;
				}
			}
			inFile.close();

			// For debugging visibility.
			cout << "\nDestination" << endl;
			cout << "Name: " << destination.name << endl;
			cout << "Position: " << destination.position << endl;
		}
	}
}

#endif
