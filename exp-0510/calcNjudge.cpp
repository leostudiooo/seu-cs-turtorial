/*
About calculation and judgement work

I consider to implement the functions using friend functions. The reasons are as follows:

1. The calculation and judgement functions (e.g. area & perimeter, intersection judgement, etc.) are not directly related to the class itself. They are more like a helper function.
2. The functions shall be able to apply to other shapes (e.g. Circle) as well.
3. We can use function overloading to implement the functions that have the same meaning for different shapes, without defining a function in the shape itself. This also improves the readability of the code.
*/

#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"

#define PI (acos(-1))

using namespace std;

// pointInShape functions
intersectionType pointInShape(const Point& p, const Rectangle& r)
{
	// The rectangle is top-left and bottom-right.
	if (
		p.getX() > r.getX() &&
		p.getX() < r.getDiagonalPoint().getX() &&
		p.getY() > r.getY() &&
		p.getY() < r.getDiagonalPoint().getY()
	)
		return CONTAINMENT;

	else if (
		p.getX() == r.getX() ||
		p.getX() == r.getDiagonalPoint().getX() ||
		p.getY() == r.getY() ||
		p.getY() == r.getDiagonalPoint().getY()
	)
		return TANGENT;

	else
		return NO_INTERSECTION;
}

intersectionType pointInShape(const Point& p, const Circle& c)
{
	if (p.getDistance(c.getCenter()) < c.getRadius())
		return CONTAINMENT;
	else if (fabs(p.getDistance(c.getCenter()) - c.getRadius()) < __DBL_EPSILON__)
		return TANGENT;
	else
		return NO_INTERSECTION;
}

// area functions
double area(const Rectangle& r)
{
	return r.getWidth() * r.getHeight();
}

double area(const Circle& c)
{
	return PI * c.getRadius() * c.getRadius();
}

// perimeter functions
double perimeter(const Rectangle& r)
{
	return 2 * (r.getWidth() + r.getHeight());
}

double perimeter(const Circle& c)
{
	return 2 * PI * c.getRadius();
}

// intersectWith functions
intersectionType intersectWith(const Rectangle& r1, const Rectangle& r2)
{
	if (
		( // This can be very confusing.
			pointInShape(r1, r2) == CONTAINMENT &&
		pointInShape(r1.getDiagonalPoint(), r2) == CONTAINMENT
		) ||
		(
			pointInShape(r2, r1) == CONTAINMENT &&
			pointInShape(r2.getDiagonalPoint(), r1) == CONTAINMENT
		)
	)
		return CONTAINMENT;
	
	else if (
		(
			(
				pointInShape(r1, r2) == CONTAINMENT &&
				pointInShape(r1.getDiagonalPoint(), r2) == NO_INTERSECTION
			) ||
			(
				pointInShape(r1, r2) == NO_INTERSECTION &&
				pointInShape(r1.getDiagonalPoint(), r2) == CONTAINMENT
			)
		) ||
		(
			(
				pointInShape(r2, r1) == CONTAINMENT &&
				pointInShape(r2.getDiagonalPoint(), r1) == NO_INTERSECTION
			) ||
			(
				pointInShape(r2, r1) == NO_INTERSECTION &&
				pointInShape(r2.getDiagonalPoint(), r1) == CONTAINMENT
			)
		)
	)
		return INTERSECTION;
	
	else if (
		pointInShape(r1, r2) == TANGENT ||
		pointInShape(r1.getDiagonalPoint(), r2) == TANGENT ||
		pointInShape(r2, r1) == TANGENT ||
		pointInShape(r2.getDiagonalPoint(), r1) == TANGENT
	)
		return TANGENT;

	else if (r1 == r2)
		return IDENTICAL;
	
	else
		return NO_INTERSECTION;
}

intersectionType intersectWith(const Circle& c1, const Circle& c2)
{
	if (c1.getCenter().getDistance(c2.getCenter()) < c1.getRadius() + c2.getRadius())
		return INTERSECTION;
	
	else if (fabs(c1.getCenter().getDistance(c2.getCenter()) - c1.getRadius() - c2.getRadius()) < __DBL_EPSILON__)
		return INTERNAL_TANGENT;
	
	else if (fabs(c1.getCenter().getDistance(c2.getCenter()) - c1.getRadius() + c2.getRadius()) < __DBL_EPSILON__)
		return EXTERNAL_TANGENT;
	
	else if (c1 == c2)
		return IDENTICAL;
	
	else
		return NO_INTERSECTION;
}

