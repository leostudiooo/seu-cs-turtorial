#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include <cmath>

class Circle
{
private:
	double x, y, radius;
	const double PI = std::acos(-1);

public:
	Circle(double X = 0, double Y = 0, double Radius = 0);
	Circle(const Circle &c);
	void setCenterRadius(double X, double Y, double Radius);
	double *getCenterRadius();
	double getArea();
	double getPerimeter();
	~Circle();
};

#endif