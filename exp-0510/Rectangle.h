#pragma once

#include "Point.h"

using namespace std;

// We define a rectangle by its base point on the top-left corner, and its diagonal point on the bottom-right corner.
class Rectangle: public Point
{
protected:
	Point diagonal;
public:
	Rectangle(Point p1 = Point(0, 0), Point p2 = Point(0, 0)): Point(p1), diagonal(p2) {}
	Rectangle(double x1, double y1, double x2, double y2): Point(x1, y1), diagonal(x2, y2) {}
	Rectangle(const Rectangle& r): Point(r), diagonal(r.diagonal) {}

	// Reload assignment operator (which has a different behavior from the base class)
	Rectangle& operator=(const Rectangle& r)
	{
		Point::operator=(r);
		diagonal = r.diagonal;
		return *this;
	}

	bool operator==(const Rectangle& r) const
	{
		return Point::operator==(r) && diagonal == r.diagonal;
	}

	// This is REALLY confusing for a rectangle class as it should be a rectangle object rather than being an extension to its base point. However, this is still acceptable if we consider a rectangle is a base point (which sets its position) and its diagonal point (which sets its size).
	void setBasePoint(Point p) { Point::operator=(p); }
	void setDiagonalPoint(Point p) { diagonal = p; }

	Point getBasePoint() const { return *this; }
	Point getDiagonalPoint() const { return diagonal; }
	double getWidth() const { return fabs(diagonal.getX() - getX()); }
	double getHeight() const { return fabs(diagonal.getY() - getY()); }

	// Friend functions.
	friend double area(const Rectangle& r);
	friend double perimeter(const Rectangle& r);

	friend intersectionType intersectWith(const Rectangle&, const Rectangle&);
	friend intersectionType pointInShape(const Point&, const Rectangle&);
};
