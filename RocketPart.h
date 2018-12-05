#ifndef ROCKETPART_H
#define ROCKETPART_H

class RocketPart {
public:
	RocketPart();

	double getMass();
	void setMass(double inMass);

	virtual double calcDrag() = 0;
private:
	double mass;	//part mass in kilograms
};

#endif
