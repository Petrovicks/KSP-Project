#pragma once
class RocketPart {
public:
	RocketPart();
	double mass;	//part mass in kilograms

	double getMass();
	void setMass(double inMass);

	virtual double calcDrag() const = 0;
};