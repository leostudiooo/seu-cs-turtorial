#pragma once

#include <iostream>
#include <cmath>

using namespace std;

enum intersectionType
{
	NO_INTERSECTION,
	INTERSECTION,
	CONTAINMENT,
	IDENTICAL,
	TANGENT,
	INTERNAL_TANGENT,
	EXTERNAL_TANGENT
};

class Point
{
protected:
	double coord[2];
public:
	Point(double x = 0, double y = 0)
	{
		coord[0] = x;
		coord[1] = y;
	}

	Point(const Point& p)
	{
		coord[0] = p.coord[0];
		coord[1] = p.coord[1];
	}

	void setX(double x) { coord[0] = x; }
	void setY(double y) { coord[1] = y; }

	double getX() const { return coord[0]; }
	double getY() const { return coord[1]; }

	// I only leave the distance calculation functions here since they are directly related to the class itself.
	double getDistance(const Point& p) const
	{
		double dx = coord[0] - p.coord[0];
		double dy = coord[1] - p.coord[1];
		return sqrt(dx * dx + dy * dy);
	}

	double getDistance(double x, double y) const
	{	return getDistance(Point(x, y)); }

	// Operator overloading
	Point& operator=(const Point& p)
	{
		coord[0] = p.coord[0];
		coord[1] = p.coord[1];
		return *this;
	}

	bool operator==(const Point& p) const
	{
		return coord[0] == p.coord[0] && coord[1] == p.coord[1];
	}
};