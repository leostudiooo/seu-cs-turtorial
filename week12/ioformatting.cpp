#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	// 38 -
	// width 6 "N"| width 13 "square root"| width 13 "fourth root"|
	// ....10|fixed 4|precision 5|
	// .
	// 100

	for (int i = 0; i < 34; i++)
	{
		cout << "-";
	}
	cout << "+" << endl;

	cout << setw(6) << "N" << "|" << setw(13) << "square root" << "|" << setw(13) << "fourth root" << "|" << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << "-";
	}
	cout << "|";
	for (int i = 0; i < 13; i++)
	{
		cout << "-";
	}
	cout << "|";
	for (int i = 0; i < 13; i++)
	{
		cout << "-";
	}
	cout << "|" << endl;

	for (int i = 10; i <= 100; i+=10)
	{
		cout << setfill('.') << setw(6) << i << "|" << setfill(' ') << setw(13) << fixed << setprecision(5) << sqrt(i) << "|" << setw(13) << pow(i, 0.25) << "|" << endl;
	}
	
	return 0;
}