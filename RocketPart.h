#ifndef ROCKETPART_H
#define ROCKETPART_H

#include <string>

class RocketPart {
public:
	RocketPart();

	//Virtual destructor to ensure derived classes have their own propr destructors.
	virtual ~RocketPart() {};

	double getMass();

	//Each part has their own ways of creating mass.
	virtual void setMass(double inMass) = 0;

	virtual std::string partType() = 0; //Returns the type of part being implemented as a string.
	virtual double calcDrag() = 0; //Each part has different drag calculations.
protected:
	double mass;	//part mass in kilograms
};

#endif
