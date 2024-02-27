#include <iostream>
#include <math.h>

const double PI = 3.14159265358979323;

class circle {
	private:
		double radius;
	public:	
		circle() { radius = 0; }
		circle(double R) { radius = R; }
		void setR(double R) { radius = R; }
		double getR() { return radius; }
		double getS() { return PI * std::pow(radius, 2); }
		double getC() { return PI * radius * 2; }
};
