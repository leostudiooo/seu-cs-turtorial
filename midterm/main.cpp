#include "line.h"
#include <iostream>

using namespace std;

int main()
{
	Line l1;
	cin >> l1;

	Line l2(1,1,1);
	Line l3(l1);

	cout << l3 << endl;

	cout << Line(0,1,0).solve_intersection_area() << " is the area of line 0, 1, 0., which means the triangle does not exist." << endl;
	cout << l1.solve_intersection_area() << " is the area of l1." << endl;

	string relation[3] = {"Intersect", "Parallel", "Same"};
	cout << "The relation between l1 and l2 is: " << relation[int(l1.judge_relation(l2))] << endl;

	cout << "l1++: " << endl;
	l1++;
	cout << l1 << endl;

	return 0;
}

/*
Output:
------
Default constructor called.
1 1 2
Constructor (double, double, double) called.
1x + 1y + 2 = 0
Constructor (double, double, double) called.
-1 is the area of line 0, 1, 0., which means the triangle does not exist.
2 is the area of l1.
The relation between l1 and l2 is: Parallel
l1++:
1x + 1y + 1 = 0
------
Default constructor called.
1 2 3
Constructor (double, double, double) called.
1x + 2y + 3 = 0
Constructor (double, double, double) called.
-1 is the area of line 0, 1, 0., which means the triangle does not exist.
2.25 is the area of l1.
The relation between l1 and l2 is: Intersect
l1++:
1x + 2y + 2 = 0
-----
Default constructor called.
1 1 1
Constructor (double, double, double) called.
1x + 1y + 1 = 0
Constructor (double, double, double) called.
-1 is the area of line 0, 1, 0., which means the triangle does not exist.
0.5 is the area of l1.
The relation between l1 and l2 is: Same
l1++:
1x + 1y + 0 = 0
*/