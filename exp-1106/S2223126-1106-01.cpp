#include <iostream>
using namespace std;

int digit(int num, int k)
{
	int i = 1;
	while (i < k)
	{
		num /= 10;
		i++;
	}
	return num % 10;
}

int main(){
	int num, k;
	cin >> num >> k;
	cout << digit(num, k) << endl;
}
/*
12345 2
4
*/