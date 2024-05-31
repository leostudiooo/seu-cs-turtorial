#include "Inventory.h"
#include "ArrayList.h"

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	ArrayList<Inventory> mylist;
	Inventory temp;
	char choice;
	cout << "Enter new item? (y/n): ";
	cin >> choice;
	while (choice == 'y' || choice == 'Y')
	{
		cin >> temp;
		mylist.orderedInsert(temp);
		cout << "Continue? (y/n): ";
		cin >> choice;
	}
	cout << mylist;
	return 0;
}