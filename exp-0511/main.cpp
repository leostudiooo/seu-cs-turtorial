#include "Integral.h"

#include <iostream>
#include <iomanip>
#include <cmath>

const double PI = acos(-1.);
const double E = exp(1.);
const int ITERATION = 1000;

using namespace std;

/*
```wolfram
Integrate[Sin[x], {x, 0, Pi/2}] -> 1
Integrate[Exp[x], {x, 0, 1}] -> E - 1
Integrate[4/(1+x^2), {x, 0, 1}] -> Pi
```
*/
double validate(double result, double expected)
{
	return abs(result - expected);
}

double customFn(double x)
{
	return 4./(1.+x*x);
}

int main()
{
	cout.precision(20);

	Integral *iptr;
	Integral integral_0(sin, 0, 3.14159265359, 1000);
	iptr = &integral_0;
	cout << iptr->integrate() << endl;

	cout << endl << "--------------------------------" << endl;

	// Rectangular integral, sin, exp, customFn
	RectangleIntegral rectInt_1(sin, 0, PI/2, ITERATION);
	iptr = &rectInt_1;
	cout << iptr->integrate() << endl;

	RectangleIntegral rectInt_2(exp, 0, 1, ITERATION);
	iptr = &rectInt_2;
	cout << iptr->integrate() << endl;

	RectangleIntegral rectInt_3(customFn, 0, 1, ITERATION);
	iptr = &rectInt_3;
	cout << iptr->integrate() << endl;

	cout << endl << "--------------------------------" << endl;

	// Trapezoidal integral, sin, exp, customFn
	TrapezoidalIntegral trapInt_1(sin, 0, PI/2, ITERATION);
	iptr = &trapInt_1;
	cout << iptr->integrate() << endl;

	TrapezoidalIntegral trapInt_2(exp, 0, 1, ITERATION);
	iptr = &trapInt_2;
	cout << iptr->integrate() << endl;

	TrapezoidalIntegral trapInt_3(customFn, 0, 1, ITERATION);
	iptr = &trapInt_3;
	cout << iptr->integrate() << endl;

	cout << endl << "--------------------------------" << endl;

	// Simpson integral, sin, exp, customFn
	SimpsonIntegral simpInt_1(sin, 0, PI/2, ITERATION);
	iptr = &simpInt_1;
	cout << iptr->integrate() << endl;

	SimpsonIntegral simpInt_2(exp, 0, 1, ITERATION);
	iptr = &simpInt_2;
	cout << iptr->integrate() << endl;

	SimpsonIntegral simpInt_3(customFn, 0, 1, ITERATION);
	iptr = &simpInt_3;
	cout << iptr->integrate() << endl;

	// Validate results
	cout << endl;
	cout << "----------------Result Validation---------------" << endl;

	cout << endl;

	cout.precision(2);

	cout << "Rectangular integral for sine function, delta = " << validate(rectInt_1.getResult(), 1) << endl;
	cout << "Rectangular integral for exp function, delta = " << validate(rectInt_2.getResult(), E-1) << endl;
	cout << "Rectangular integral for custom function, delta = " << validate(rectInt_3.getResult(), PI) << endl;

	cout << endl;

	cout << "Trapezoidal integral for sine function, delta = " << validate(trapInt_1.getResult(), 1) << endl;
	cout << "Trapezoidal integral for exp function, delta = " << validate(trapInt_2.getResult(), E-1) << endl;
	cout << "Trapezoidal integral for custom function, delta = " << validate(trapInt_3.getResult(), PI) << endl;

	cout << endl;

	cout << "Simpson integral for sine function, delta = " << validate(simpInt_1.getResult(), 1) << endl;
	cout << "Simpson integral for exp function, delta = " << validate(simpInt_2.getResult(), E-1) << endl;
	cout << "Simpson integral for custom function, delta = " << validate(simpInt_3.getResult(), PI) << endl;
}

/*
Output:
Integral::integrate()
0

--------------------------------
RectangleIntegral::integrate()
0.9992143962198377638
RectangleIntegral::integrate()
1.7174228307349657108
RectangleIntegral::integrate()
3.1425924869231214309

--------------------------------
TrapezoidalIntegral::integrate()
0.99999979438323516323
TrapezoidalIntegral::integrate()
1.7182819716491966044
TrapezoidalIntegral::integrate()
3.1415924869231268701

--------------------------------
SimpsonIntegral::integrate()
1.0000000000000035527
SimpsonIntegral::integrate()
1.7182818284590446467
SimpsonIntegral::integrate()
3.1415926535897913396

----------------Result Validation---------------

Rectangular integral for sine function, delta = 0.00079
Rectangular integral for exp function, delta = 0.00086
Rectangular integral for custom function, delta = 0.001

Trapezoidal integral for sine function, delta = 2.1e-07
Trapezoidal integral for exp function, delta = 1.4e-07
Trapezoidal integral for custom function, delta = 1.7e-07

Simpson integral for sine function, delta = 3.6e-15
Simpson integral for exp function, delta = 4.4e-16
Simpson integral for custom function, delta = 1.8e-15
*/