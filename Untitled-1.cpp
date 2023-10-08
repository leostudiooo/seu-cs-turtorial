#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	int d = b * b - 4 * a * c;

	if (d < 0)
		cout << "No real roots" << endl;
	else if (d == 0)
		cout << "Two same roots x=" << -b / (2 * a) << endl;
	else
		cout << "Two different roots x1=" << (-b + sqrt(d)) / (2 * a) << " , x2=" << (-b - sqrt(d)) / (2 * a) << endl;

	return 0;
}