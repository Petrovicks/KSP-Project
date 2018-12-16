#ifndef ROCKETPART_H
#define ROCKETPART_H

#include <string>

class RocketPart {
public:
	RocketPart();
	virtual ~RocketPart() {};

	double getMass();
	virtual void setMass(double inMass) = 0;

	virtual std::string partType() = 0; //Returns the type of part being implemented
	virtual double calcDrag() = 0;
protected:
	double mass;	//part mass in kilograms
};

#endif
