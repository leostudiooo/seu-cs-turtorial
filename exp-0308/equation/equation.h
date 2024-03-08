#ifndef EQ_H_
#define EQ_H_

#include <iostream>

class Equation
{
private:
	double a, b, c;
public:
	Equation();
	Equation(double a, double b, double c);
	Equation(const Equation &other);
	~Equation();

	void setA(double);
	void setB(double);
	void setC(double);

	double returnDelta();
	bool returnRoots(double[2]);
};

#endif