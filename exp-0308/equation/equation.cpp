#include "equation.h"
#include <iostream>
#include <cmath>

Equation::Equation()
{
	std::cout << "Default constructor called" << std::endl;
	a = b = c = 0;
}

Equation::Equation(double a, double b, double c)
{
	std::cout << "Constructor double, double, double called" << std::endl;
	this->a = a;
	this->b = b;
	this->c = c;
}

Equation::Equation(const Equation &other)
{
	std::cout << "Copy constructor called" << std::endl;
	a = other.a;
	b = other.b;
	c = other.c;
}

Equation::~Equation()
{
	std::cout << "Destructor called" << std::endl;
}

void Equation::setA(double a)
{
	this->a = a;
}

void Equation::setB(double b)
{
	this->b = b;
}

void Equation::setC(double c)
{
	this->c = c;
}

double Equation::returnDelta()
{
	return b * b - 4 * a * c;
}

bool Equation::returnRoots(double roots[2])
{
	double delta = returnDelta();
	if (delta < 0)
	{
		return false;
	}
	else
	{
		roots[0] = (-b + sqrt(delta)) / (2 * a);
		roots[1] = (-b - sqrt(delta)) / (2 * a);
		return true;
	}
}