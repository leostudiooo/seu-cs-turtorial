#include "complex.h"
#include <iostream>
#include <cmath>

Complex::Complex()
{
	real = 0.;
	imag = 0.;
}

Complex::Complex(double real, double imag)
{
	this->real = real;
	this->imag = imag;
}

Complex::Complex(const Complex &c)
{
	real = c.real;
	imag = c.imag;
}

Complex::~Complex()
{
}

// Output in a +/- bi format
void Complex::Print() const
{
	std::cout << real << (std::fabs(imag) < 0 ? " - " : " + ") << fabs(imag) << "i" << std::endl;
}

Complex Complex::operator+(const Complex &c) const
{
	return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator+(double d) const
{
	return Complex(real + d, imag);
}

Complex Complex::operator+=(const Complex &c)
{
	real += c.real;
	imag += c.imag;
	return *this;
}

Complex Complex::operator-(const Complex &c) const
{
	return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator-(double d) const
{
	return Complex(real - d, imag);
}

Complex Complex::operator-=(const Complex &c)
{
	real -= c.real;
	imag -= c.imag;
	return *this;
}

Complex Complex::operator*(const Complex &c) const
{
	return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

Complex Complex::operator*(double d) const
{
	return Complex(real * d, imag * d);
}

Complex Complex::operator/(const Complex &c) const
{
	double denom = c.real * c.real + c.imag * c.imag;
	return Complex((real * c.real + imag * c.imag) / denom, (imag * c.real - real * c.imag) / denom);
}

Complex Complex::operator/(double d) const
{
	return Complex(real / d, imag / d);
}

Complex &Complex::operator=(const Complex &c)
{
	real = c.real;
	imag = c.imag;
	return *this;
}

double Complex::magnitude() const
{
	return real * real + imag * imag;
}

// Comparing two complexes by magnitude
bool Complex::operator>(const Complex &c) const
{
	return magnitude() > c.magnitude();
}

bool Complex::operator<(const Complex &c) const
{
	return magnitude() < c.magnitude();
}

bool Complex::operator==(const Complex &c) const
{
	return (real == c.real) && (imag == c.imag);
}

std::ostream &operator<<(std::ostream &os, const Complex &c)
{
	os << c.real << (std::fabs(c.imag) < 0 ? " - " : " + ") << fabs(c.imag) << "i";
	return os;
}