#include <iostream>
using namespace std;

// Legendre polynomial
// ``` wolfram
// P[n, x]:= Piecewise[{{1, n==0},{x, n==1},{((2n-1) x P[n-1,x] - (n-1) P[n-2,x])/n, n>1}}]
// ```
double LegendreP(int n, double x, int &count){
	count ++;
	if (n == 0) return 1;
	if (n == 1) return x;
	return ((2 * n - 1) * x * LegendreP(n - 1, x, count) - (n - 1) * LegendreP(n - 2, x, count)) / n;
}

int main(){
	int n, x, count = 0;
	cout << "For Legendre polynomial P(n, x), input n, x: ";
	cin >> n >> x;
	cout << "P(" << n << ", " << x << ") = " << LegendreP(n, x, count) << endl;
	cout << "Called the function LegendreP " << count << " time(s)." << endl;
}

/*
Run 1:
For Legendre polynomial P(n, x), input n, x: 0 0 
P(0, 0) = 1
Called the function Legendre 1 time(s).
------
Run 2:
For Legendre polynomial P(n, x), input n, x: 1 1
P(1, 1) = 1
Called the function Legendre 1 time(s).
------
For Legendre polynomial P(n, x), input n, x: 5 5
P(5, 5) = 23525
Called the function Legendre 15 time(s).
*/