#include "equation.h"
#include <iostream>

int main()
{
	Equation eq1;
	Equation eq2(1, 2, 1);
	Equation eq3(eq2);
	double params[3] = {};

	std::cout << "Enter a, b, c: ";
	std::cin >> params[0] >> params[1] >> params[2];
	Equation eq4(params[0], params[1], params[2]);

	double roots[2];
	if (eq4.returnRoots(roots))
	{
		std::cout << "Roots: " << roots[0] << " " << roots[1] << std::endl;
	}
	else
	{
		std::cout << "No roots" << std::endl;
	}
	return 0;
}
/*
Run #1
------
Default constructor called
Constructor double, double, double called
Copy constructor called
Enter a, b, c: 1 1 4
Constructor double, double, double called
No roots
Destructor called
Destructor called
Destructor called
Destructor called

Run #2
------
Default constructor called
Constructor double, double, double called
Copy constructor called
Enter a, b, c: 1 2 1
Constructor double, double, double called
Roots: -1 -1
Destructor called
Destructor called
Destructor called
Destructor called
*/