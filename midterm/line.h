#pragma once // line.h

#include <iostream>
#include <cmath>

using namespace std;

enum Relation
{
	INTERSECT = 0,
	PARALLEL,
	SAME
};

class Line
{
	double a, b, c;

public:
	Line();
	Line(double, double, double);
	Line(Line &);

	double solve_intersection_area() const;
	Relation judge_relation(Line &) const;
	
	// reload operator++ to move the line 1 unit to the right
	Line operator++(int)
	{
		c -= a;
		return *this;
	}
	friend istream& operator>>(istream &, Line &);
	friend ostream& operator<<(ostream &, Line &);
};

Line::Line()
{
	cout << "Default constructor called." << endl;
	a = 0;
	b = 0;
	c = 0;
}

Line::Line(double a, double b, double c)
{
	cout << "Constructor (double, double, double) called." << endl;
	this->a = a;
	this->b = b;
	this->c = c;
}

Line::Line(Line &another)
{
	a = another.a;
	b = another.b;
	c = another.c;
}

double Line::solve_intersection_area() const
{
	if (a == 0 || b == 0)
		return -1;
	else
		return 0.5 * fabs(c / a) * fabs(c / b);
}

Relation Line::judge_relation(Line &another) const
{
	if (fabs(a * another.b - b * another.a) < __DBL_EPSILON__)
	{
		if (fabs(a * another.c - c * another.a) < __DBL_EPSILON__)
			return SAME;
		else
			return PARALLEL;
	}
	else
		return INTERSECT;
}


istream& operator>>(istream &is, Line &l)
{
	is >> l.a >> l.b >> l.c;
	return is;
}

ostream& operator<<(ostream &os, Line &l)
{
	os << l.a << "x + " << l.b << "y + " << l.c << " = 0";
	return os;
}