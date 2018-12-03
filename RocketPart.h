#pragma once
class RocketPart {
public:
	double mass;	//part mass in kilograms

	double getMass();
	void setMass(double inMass);

	virtual double calcDrag() const = 0;
};