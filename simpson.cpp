#include <iostream>
#include <math.h>

#define Pi (acos(-1))

using namespace std;

double SimpsonIntegrate(double (*fn)(double), double lower, double upper, int steps)
{
	double h = (upper - lower) / steps;
	double sum = 0;
	for (int i = 0; i < steps; i++)
	{
		sum += fn(lower + i * h) + 4 * fn(lower + (i + 0.5) * h) + fn(lower + (i + 1) * h);
	}
	return sum * h / 6;
}

int main()
{
	double (*f)(double);
	f = sin;
	cout << SimpsonIntegrate(f, 0, Pi, 1000) << endl;
	return 0;
}