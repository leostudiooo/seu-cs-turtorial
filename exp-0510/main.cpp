#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"

#include <iostream>

using namespace std;

const string intersectionTypeStr[] = {
	"NO_INTERSECTION",
	"INTERSECTION",
	"CONTAINMENT",
	"IDENTICAL",
	"TANGENT",
	"INTERNAL_TANGENT",
	"EXTERNAL_TANGENT"
};

int main()
{
	// class Point
	Point p;
	Point p1(1, 1);
	Point p2(p1);
	
	p = Point(2, 2);

	cout << "Distance between p and p2: " << p.getDistance(p2) << endl;

	// class Rectangle
	Rectangle r;
	Rectangle r1(p1, p2);
	Rectangle r2(2, 2, 4, 4);
	Rectangle r3(r2);
	// Confusing feature: you can create a rectangle using two other rectangles since they are inherited from Point. This worsens the readability of the code. To tell the truth, I also used this feature in calcNjudge.cpp.
	Rectangle r4(r, r2);

	r = Rectangle(Point(1, 1), Point(3, 3));
	cout << "Width of r: " << r.getWidth() << endl;
	cout << "Height of r: " << r.getHeight() << endl;
	cout << "Area of r: " << area(r) << endl;
	cout << "Perimeter of r: " << perimeter(r) << endl;
	cout << "The realationship between r and r2: " << intersectionTypeStr[intersectWith(r, r2)] << endl;
	cout << "The relationship between p and r: " << intersectionTypeStr[pointInShape(p, r)] << endl;

	// class Circle
	Circle c;
	Circle c1(p1, 1);
	Circle c2(2, 2, 2);
	Circle c3(c2);
	// And it can be even more confusing: you can create a circle using a rectangle without any errors or warnings. Theoretically it will create a Circle(rectangle, 0).
	Circle c4(r);
	// Or you can do this:
	Circle c5(r2, 5);
	// And you can even create a rectangle using another rectangle and a circle.
	Rectangle r5(r, c5);

	c = Circle(Point(1, 1), 1);
	cout << "Area of c: " << area(c) << endl;
	cout << "Perimeter of c: " << perimeter(c) << endl;
	cout << "The realationship between c and c2: " << intersectionTypeStr[intersectWith(c, c2)] << endl;
	cout << "The relationship between p and c: " << intersectionTypeStr[pointInShape(p, c)] << endl;

	return 0;
}

/*
Output:
Distance between p and p2: 1.41421
Width of r: 2
Height of r: 2
Area of r: 4
Perimeter of r: 8
The realationship between r and r2: INTERSECTION
The relationship between p and r: CONTAINMENT
Area of c: 3.14159
Perimeter of c: 6.28319
The realationship between c and c2: INTERSECTION
The relationship between p and c: NO_INTERSECTION
*/