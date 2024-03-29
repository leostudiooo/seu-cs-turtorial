#include "../exp-0315/complex.h"
#include "../exp-0315/bubble_sort.h"
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

const char BASEPAIRS[4] = {'A', 'C', 'G', 'T'};

int UI();
void basepairFn(int, int default_SIZE = 5);

int main()
{
	srand(time(0));

	unsigned int SIZE;
	cout << "Enter the number of complex numbers you want to enter: ";
	cin >> SIZE;

	Complex *p = new Complex[SIZE];

	cout << "Enter 5 complex numbers, one each line:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cin >> p[i];
	}
	
	cout << "You entered:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << p[i] << endl;
	}

	BubbleSort(p, SIZE);

	cout << "After sorting:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << p[i] << endl;
	}

	cout << "Max: " << p[SIZE - 1] << endl;

	delete[] p;

	int choice = UI();
	basepairFn(choice, SIZE);

	return 0;
}

int UI()
{
	cout << "Basepair Matrix" << endl;
	cout << "1. Known lines, type in columns for each line" << endl;
	cout << "2. Known columns, type in lines" << endl;
	cout << "3. Manually type in lines and columns for each line" << endl;
	cout << "> ";
	int choice;
	cin >> choice;
	return choice;
}

void basepairFn(int choice, int default_SIZE)
{
	if (choice == 1)
	{
		int lines_I = default_SIZE;
		int *columns_I = new int[lines_I];
		char **basepairMatrix_I = new char *[lines_I];

		cout << "Enter the number of columns for each line: ";
		for (int i = 0; i < lines_I; i++)
		{
			cin >> columns_I[i];
			basepairMatrix_I[i] = new char[columns_I[i]];
			for (int j = 0; j < columns_I[i]; j++)
			{
				basepairMatrix_I[i][j] = BASEPAIRS[rand() % 4];
			}
		}

		for (int i = 0; i < lines_I; i++)
		{
			for (int j = 0; j < columns_I[i]; j++)
				cout << basepairMatrix_I[i][j] << " ";
			cout << endl;
		}

		delete[] columns_I;
	}
	
	else if (choice == 2)
	{
		int columns_II;
		int lines_II;
		
		columns_II = default_SIZE;
		cout << "Enter the number of lines: ";
		cin >> lines_II;

		char **basepairMatrix_II = new char *[lines_II];

		for (int i = 0; i < lines_II; i++)
		{
			basepairMatrix_II[i] = new char[columns_II];
			for (int j = 0; j < columns_II; j++)
				basepairMatrix_II[i][j] = BASEPAIRS[rand() % 4];
		}

		for (int i = 0; i < lines_II; i++)
		{
			for (int j = 0; j < columns_II; j++)
				cout << basepairMatrix_II[i][j] << " ";
			cout << endl;
		}

		delete[] basepairMatrix_II;
	}
	
	else if (choice == 3)
	{
		int lines_III;
		cout << "Enter the number of lines: ";
		cin >> lines_III;

		int *columns_III = new int[lines_III];
		char **basepairMatrix_III = new char *[lines_III];
		cout << "Enter the number of columns for each line: ";
		for (int i = 0; i < lines_III; i++)
		{
			cin >> columns_III[i];
			basepairMatrix_III[i] = new char[columns_III[i]];
			for (int j = 0; j < columns_III[i]; j++)
				basepairMatrix_III[i][j] = BASEPAIRS[rand() % 4];
		}

		for (int i = 0; i < lines_III; i++)
		{
			for (int j = 0; j < columns_III[i]; j++)
				cout << basepairMatrix_III[i][j] << " ";
			cout << endl;
		}

		delete[] columns_III;
	}
	
	else
	{
		cout << "Invalid choice" << endl;
	}
}

/* Output in output.txt */