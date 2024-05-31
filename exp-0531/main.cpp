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
/* Console output:
➜  exp-0531 git:(main) ✗ ./main
Enter new item? (y/n): y
Enter description: apple
Enter part number: ap-1
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
apple               ap-1      10        5         20        
banana              ba02      22        1         5   
*/