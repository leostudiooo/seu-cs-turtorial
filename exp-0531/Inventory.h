#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Inventory
{
	string description;
	string partNumber;
	int quantity;
	double costPrice;
	double retailPrice;

public:
	Inventory(string description = "#", string partNumber = "#", int quantity = 0, double costPrice = 0.0, double retailPrice = 0.0) : description(description), partNumber(partNumber), quantity(quantity), costPrice(costPrice), retailPrice(retailPrice) {}

	friend ostream &operator<<(ostream &, const Inventory &);
	friend istream &operator>>(istream &, Inventory &);

	bool operator==(const Inventory &inv) const
	{
		return partNumber == inv.partNumber;
	}
	bool operator<=(const Inventory &inv) const
	{
		return partNumber <= inv.partNumber;
	}
};

ostream &operator<<(ostream &destination, const Inventory &inv)
{
	destination << left << setw(20) << inv.description << setw(10) << inv.partNumber << setw(10) << inv.quantity << setw(10) << inv.costPrice << setw(10) << inv.retailPrice << endl;
	return destination;
}

istream &operator>>(istream &source, Inventory &inv)
{
	if (&source == &cin)
	{
		cout << "Enter description: ";
		source >> inv.description;
		cout << "Enter part number: ";
		source >> inv.partNumber;
		cout << "Enter quantity: ";
		source >> inv.quantity;
		cout << "Enter costPrice: ";
		source >> inv.costPrice;
		cout << "Enter retailPrice: ";
		source >> inv.retailPrice;
	}
	else
	{
		source >> inv.description >> inv.partNumber >> inv.quantity >> inv.costPrice >> inv.retailPrice;
	}
	return source;
}
