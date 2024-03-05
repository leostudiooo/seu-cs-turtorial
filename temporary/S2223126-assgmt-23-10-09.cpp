#include <iostream>

using namespace std;

void capitalConverter()
{
	auto convert = [](char ch)
	{
		char output;
		output = ch;
		if (ch >= 'A' && ch <= 'Z')
		{
			output = ch + 32;
			return output;
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			output = ch - 32;
			return output;
		}
		else
			return output;
	};
	char input;
	cout << "Enter an ASCII character: ";
	cin >> input;
	cout << convert(input) << endl;
}

void simpleRound()
{
	double input;
	cin >> input;
	cout << (int)(input + 0.5) << endl;
}

void outputDataTypeAndSize()
{
	cout << "Size of char:\t" << sizeof(char) << endl;
	cout << "Size of int:\t" << sizeof(int) << endl;
	cout << "Size of float:\t" << sizeof(float) << endl;
	cout << "Size of double:\t" << sizeof(double) << endl;
	cout << "Size of bool:\t" << sizeof(bool) << endl;
}

void calcSphere()
{
	const double PI = 3.14159265358979323846, density = 7.8 * 1000; // 7.8 kg/dm^3 converted to kg/m^3
	double radius, surfaceArea, volume, mass;
	cout << "Radius(m): ";
	cin >> radius;
	surfaceArea = 4 * PI * radius * radius;
	volume = 4 / 3 * PI * radius * radius * radius;
	mass = density * volume;
	// Output with 5 sig. fig.
	cout.precision(5);
	cout << "Area:\t" << surfaceArea << " m^2" << endl;
	cout << "Volume:\t" << volume << " m^3" << endl;
	cout << "Mass:\t" << mass << " kg" << endl;
}

int main()
{
	cout << "1. Capital Converter" << endl;
	cout << "-----------------------------" << endl;
	capitalConverter();
	cout << endl;

	cout << "2. Simple Round" << endl;
	cout << "-----------------------------" << endl;
	simpleRound();
	cout << endl;

	cout << "3. Output Data Type and Size" << endl;
	cout << "-----------------------------" << endl;
	outputDataTypeAndSize();
	cout << endl;

	cout << "4. Calculate Sphere" << endl;
	cout << "-----------------------------" << endl;
	calcSphere();
	cout << endl << "Finished." << endl;

	return 0;
}