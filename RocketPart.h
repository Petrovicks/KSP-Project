#ifndef ROCKETPART_H
#define ROCKETPART_H

#include <string>

class RocketPart {
public:
	RocketPart();
	~RocketPart();

	double getMass();
	void setMass(double inMass);

	virtual std::string partType() = 0; //Returns the type of part being implemented
	virtual double calcDrag() = 0;
private:
	double mass;	//part mass in kilograms
};

#endif
