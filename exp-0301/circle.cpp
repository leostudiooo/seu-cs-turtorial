#include "circle.h"

Circle::Circle(double X, double Y, double Radius)
{
	x = X;
	y = Y;
	radius = Radius;
	std::cout << "Circle constructor called" << std::endl;
}

Circle::Circle(const Circle &c)
{
	x = c.x;
	y = c.y;
	radius = c.radius;
	std::cout << "Circle copy constructor called" << std::endl;
}

void Circle::setCenterRadius(double X, double Y, double Radius)
{
	x = X;
	y = Y;
	radius = Radius;
	std::cout << "Circle setCenterRadius() called" << std::endl;
}

double *Circle::getCenterRadius()
{
	std::cout << "Circle getCenterRadius() called" << std::endl;
	double CenterRadius[3] = {x, y, radius};
	return CenterRadius;
}

double Circle::getArea()
{
	std::cout << "Circle getArea() called" << std::endl;
	return PI * pow(radius, 2);
}

double Circle::getPerimeter()
{
	std::cout << "Circle getPerimeter() called" << std::endl;
	return 2 * PI * radius;
}

Circle::~Circle()
{
	std::cout << "Circle destructor called" << std::endl;
}
