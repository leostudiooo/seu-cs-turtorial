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
		cin >> inv.description;
		cout << "Enter part number: ";
		source >> inv.partNumber;
		cout << "Enter quantity: ";
		source >> inv.quantity;
		cout << "Enter cost price: ";
		source >> inv.costPrice;
		cout << "Enter retail price: ";
		source >> inv.retailPrice;
	}
	else
	{
		source >> inv.description >> inv.partNumber >> inv.quantity >> inv.costPrice >> inv.retailPrice;
	}
	return source;
}
/* Console output:
➜  exp-0531 git:(main) ✗ ./main
Element already exists
Enter new item? (y/n): y
Enter description: apple
Enter part number: ap01
Enter quantity: 10
Enter cost price: 5
Enter retail price: 20
maxCurrentIndex: 0 capacity: 2
Continue? (y/n): y
Enter description: banana
Enter part number: ba02
Enter quantity: 22
Enter cost price: 1
Enter retail price: 5
maxCurrentIndex: 1 capacity: 2
Continue? (y/n): y
Enter description: amen
Enter part number: am01
Enter quantity: 12
Enter cost price: 5
Enter retail price: 30
ArrayList is full
maxCurrentIndex: 2 capacity: 4
Continue? (y/n): n
amen                am01      12        5         30        
apple               ap01      10        5         20        
banana              ba02      22        1         5         
*/

/* data.txt:

*/