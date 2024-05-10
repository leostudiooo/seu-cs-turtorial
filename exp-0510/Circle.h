#pragma once

#include "Point.h"

using namespace std;

// With the way class Rectangle is defined, the class Circle is much easier to understand.
class Circle: public Point
{
protected:
	double radius;
public:
	Circle(Point p = Point(0, 0), double r = 0): Point(p), radius(r) {}
	Circle(double x, double y, double r): Point(x, y), radius(r) {}
	Circle(const Circle& c): Point(c), radius(c.radius) {}

	// Reload assignment operator, as we done in Rectangle.h
	Circle& operator=(const Circle& c)
	{
		Point::operator=(c);
		radius = c.radius;
		return *this;
	}

	bool operator==(const Circle& c) const
	{
		return Point::operator==(c) && radius == c.radius;
	}

	void setCenter(Point p) { Point::operator=(p); }
	void setRadius(double r) { radius = r; }

	Point getCenter() const { return *this; }
	double getRadius() const { return radius; }

	// Friend functions.
	friend double area(const Circle&);
	friend double perimeter(const Circle&);

	friend intersectionType intersectWith(const Circle&, const Circle&);
	friend intersectionType pointInShape(const Point&, const Circle&);
};