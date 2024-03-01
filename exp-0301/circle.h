#ifndef CIRCLE_H_
#define CIRCLE_H_

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
	// Pass in an array of size 3 to store the center and radius
	void getCenterRadius(double arr[3]);
	double getArea();
	double getPerimeter();
	~Circle();
};

#endif