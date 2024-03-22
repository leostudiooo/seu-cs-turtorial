#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int min, max;
	cout << "Enter the minimum and maximum values: ";
	cin >> min >> max;
	while (min == max)
	{
		cout << "The minimum and maximum values cannot be the same. Please re-enter the values: ";
		cin >> min >> max;
	}
	if (min > max)
	{
		int temp = min;
		min = max;
		max = temp;
	}
	if (max - min >= 10000)
	{
		cout << "The difference between the minimum and maximum values large and may take a long time to compute. Are you sure you want to continue? (y/n): ";
		char choice;
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			cout << "Continuing..." << endl;
		}
		else return 0;
	}
	int count = 0;
	for (int i = min; i <= max; i++)
	{
		bool isPrime = true;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			cout << i << " is prime." << endl;
			count++;
		}
	}
	if (count == 0)
	{
		cout << "There are no prime numbers between " << min << " and " << max << "." << endl;
	}
	else
	{
		cout << "There are " << count << " prime numbers between " << min << " and " << max << "." << endl;
	}
}