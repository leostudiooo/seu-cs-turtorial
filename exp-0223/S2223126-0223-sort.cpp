#include <iostream>
#include <cstring>

using namespace std;

void bubbleSort(char arr[][10], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0)
			{
				char temp[10];
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], temp);
			}
		}
	}
}

void selectionSort(char arr[][10], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(arr[j], arr[minIndex]) < 0)
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			char temp[10];
			strcpy(temp, arr[i]);
			strcpy(arr[i], arr[minIndex]);
			strcpy(arr[minIndex], temp);
		}
	}
}

void insertionSort(char arr[][10], int n)
{
	for (int i = 1; i < n; i++)
	{
		char key[10];
		strcpy(key, arr[i]);
		int j = i - 1;
		while (j >= 0 && strcmp(arr[j], key) > 0)
		{
			strcpy(arr[j + 1], arr[j]);
			j--;
		}
		strcpy(arr[j + 1], key);
	}
}

int main()
{
	char strings[5][10] = {
		"C++",
		"Python",
		"Java",
		"Pascal",
		"Perl"};

	cout << "Strings:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << strings[i] << endl;
	}

	cout << endl;
	cout << "Select sorting algorithm:" << endl;
	cout << "1. Bubble sort" << endl;
	cout << "2. Selection sort" << endl;
	cout << "3. Insertion sort" << endl;
	
	cout << "> ";
	int choice;
	cin >> choice;
	cout << endl;

	int operations;

	switch (choice)
	{
	case 1:
		bubbleSort(strings, 5);
		break;
	case 2:
		selectionSort(strings, 5);
		break;
	case 3:
		insertionSort(strings, 5);
		break;
	default:
		cout << "Invalid choice" << endl;
		return 1;
	}

	cout << "Sorted strings:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << strings[i] << endl;
	}

	return 0;
}
/*
Run #1
------
Strings:
C++
Python
Java
Pascal
Perl

Select sorting algorithm:
1. Bubble sort
2. Selection sort
3. Insertion sort
> 1

Sorted strings:
C++
Java
Pascal
Perl
Python

Run #2
------
Strings:
C++
Python
Java
Pascal
Perl

Select sorting algorithm:
1. Bubble sort
2. Selection sort
3. Insertion sort
> 2

Sorted strings:
C++
Java
Pascal
Perl
Python

Run #3
------
Strings:
C++
Python
Java
Pascal
Perl

Select sorting algorithm:
1. Bubble sort
2. Selection sort
3. Insertion sort
> 3

Sorted strings:
C++
Java
Pascal
Perl
Python
*/