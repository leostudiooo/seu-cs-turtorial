#include "Employee.h"
#include <iostream>

using namespace std;

int main()
{
	Technician t("Alice", "T001", L2, 10., 168., 10.);
	Salesman s("Bob", "S001", L3, 10000., 0.05);

	DevManager dm("Carl", "DM001", L4, 10, 130, 10., 0.1, 0.1);
	SalesManager sm("Daniel", "SM001", L4, 100000., 0.005, 10., 0.1);

	cout << "Alice's monthly salary: " << t.pay(0) << endl;
	cout << "Bob's monthly salary (Absent 1 day): " << s.pay(1) << endl;
	cout << "Carl's monthly salary: " << dm.pay(0) << endl;
	cout << "Daniel's monthly salary: " << sm.pay(0) << endl;
}

/*
Output:
Alice's monthly salary: 31800
Bob's monthly salary (Absent 1 day): 20400
Carl's monthly salary: 31500
Daniel's monthly salary: 25250.5
*/