#pragma once
#include <iostream>

using namespace std;

class Integral
{
protected:
	double lowerLimit, upperLimit, stepSize, result;
	int iteration;
	double (*targetFunction)(double);

public:
	// 给每种积分每个函数都要造一个类也太麻烦了我直接拿指针传了
	Integral(double (*fn)(double), double a, double b, int n): targetFunction(fn), lowerLimit(a), upperLimit(b), iteration(n), stepSize((b-a)/n), result(0) {}

	virtual double integrate() { cout << "Integral::integrate()" << endl; return result; }

	double getResult() { return result; }
};

class RectangleIntegral: public Integral
{
public:
	RectangleIntegral(double (*fn)(double), double a, double b, int n): Integral(fn, a, b, n) {}
	
	double integrate() override
	{
		cout << "RectangleIntegral::integrate()" << endl;
		double x = lowerLimit;
		for (int i = 0; i < iteration; i++)
		{
			result += targetFunction(x) * stepSize;
			x += stepSize;
		}
		return result;
	}
};

class TrapezoidalIntegral: public Integral
{
public:
	TrapezoidalIntegral(double (*fn)(double), double a, double b, int n): Integral(fn, a, b, n) {}

	double integrate() override
	{
		cout << "TrapezoidalIntegral::integrate()" << endl;
		double x = lowerLimit;
		for (int i = 0; i < iteration; i++)
		{
			result += (targetFunction(x) + targetFunction(x+stepSize)) * stepSize / 2;
			x += stepSize;
		}
		return result;
	}
};

class SimpsonIntegral: public Integral
{
public:
	SimpsonIntegral(double (*fn)(double), double a, double b, int n): Integral(fn, a, b, n) {}

	double integrate() override
	{
		cout << "SimpsonIntegral::integrate()" << endl;
		double x = lowerLimit;
		for (int i = 0; i < iteration; i++)
		{
			result += (targetFunction(x) + 4*targetFunction(x+stepSize/2) + targetFunction(x+stepSize)) * stepSize / 6;
			x += stepSize;
		}
		return result;
	}
};