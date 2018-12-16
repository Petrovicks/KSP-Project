#include <fstream>
#ifndef PLANETS_H
#define PLANETS_H
//********************************************************
//
// This is a skeleton header file for parsing ini files.
// Basic string parsing for grabbing the string name and
// subsequent numeric values is done, as well as enum matching.
//
// Generic planet struct created to be used for generating
// a source and planet with respective parameters read
// in from the ini file.
//
//********************************************************

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Allow for a maximum of 20 planets.
template <typename T>
struct Planets {
	T position[20], atmosphericDensity[20], gravity[20];
	vector<string> planetName = vector<string>(20);
};

enum parameterCode {
	Position,
	Atmospheric,
	Gravity,
};

string sanitizeLine(string const& inString) {
	string sanitized = inString;
	sanitized.erase( remove(sanitized.begin(), sanitized.end(), ' '), sanitized.end() );
	transform(sanitized.begin(), sanitized.end(), sanitized.begin(), ::tolower);

	return sanitized;
}

parameterCode hashPlanetParameters(string const& inString) {
	string sanitizedString = sanitizeLine(inString);
	sanitizedString = sanitizedString.substr(0, sanitizedString.find('='));	
	if (sanitizedString == "position")
		return Position;
	if (sanitizedString == "atmosphericdensity")
		return Atmospheric;
	if (sanitizedString == "gravity")
		return Gravity;
}

string getPlanetFromLine(string const& inString) {
	int openBracket = inString.find("[");
	int closeBracket = inString.find("]");
	return inString.substr(openBracket+1, closeBracket-1);
}

string getParamFromLine(string const& inString) {
	string sanitizedString = sanitizeLine(inString);
	return sanitizedString.substr(0, sanitizedString.find('='));
}

double getValueFromLine(string const& inString) {
	string sanitizedString = sanitizeLine(inString);
	int equalSign = sanitizedString.find('=');
	string valueString = sanitizedString.substr(equalSign+1);
	return stod(valueString); //COMPILED WITH C++11
}

static Planets<double> planetList;
static int planetCount = 0;

namespace planetParameters
{
	void getPlanetParams(ifstream& inFile) {
		string line;
		int planetID = 0;
		if (inFile.is_open()) {
			while (getline (inFile, line)) {
				if(line.find("[") != std::string::npos) {
					planetID++;
					planetList.planetName[planetID] = getPlanetFromLine(line);
				}
				else {
					switch (hashPlanetParameters(getParamFromLine(line))) {
						case Position:
							planetList.position[planetID] = getValueFromLine(line);
							break;
						case Atmospheric:
							planetList.atmosphericDensity[planetID] = getValueFromLine(line);
							break;
						case Gravity:
							planetList.gravity[planetID] = getValueFromLine(line);
							break;
					}
				}
			}
		}
		inFile.close();
		planetCount = planetID;
	}
}

#endif
