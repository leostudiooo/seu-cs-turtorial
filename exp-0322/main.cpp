#include "seqlist.h"
// complex.h and money.h are in last week's assignment
#include "../exp-0315/complex.h"
#include "../exp-0315/money.h"

#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
	srand(time(0));

	Seqlist<int, 10> intList;
	Seqlist<Complex, 10> complexList;
	Seqlist<Money, 10> moneyList;

	for (int i = 0; i < 10; i++)
	{
		intList.Insert(rand() % 10, i);
		complexList.Insert(Complex(rand() % 10, rand() % 10), i);
		moneyList.Insert(Money(rand() % 1000 / 100.), i);
	}

	cout << "Original intList: " << endl << intList << endl;
	cout << "Original complexList: " << endl << complexList << endl;
	cout << "Original moneyList: " << endl << moneyList << endl;

	intList.Sort(ASCENDING, BUBBLE);
	complexList.Sort(DESCENDING, SELECTION);
	moneyList.Sort(ASCENDING, INSERTION);

	cout << "Sorted intList: " << endl << intList << endl;
	cout << "Sorted complexList: " << endl << complexList << endl;
	cout << "Sorted moneyList: " << endl << moneyList << endl;

	cout << "intList.Find(5): " << intList.Find(5) << endl;

	cout << "Inserting 5 at [5] in intList: " << endl;
	cout << "Insert " << (intList.Insert(5, 5) ? "succeed" : "failed") << endl;
	cout << intList << endl;

	cout << "moneyList is " << (moneyList.IsFull() ? "" : "not ") << "full" << endl << endl;

	cout << "The [1] element in complexList is " << complexList.Get(1) << ". That is to say, complexList[1] is " << complexList[1] << "." << endl << endl;

	cout << "Remove 3.14 in moneyList: " << endl;
	cout << "Remove " << (moneyList.Remove(3.14) ? "succeed" : "failed") << endl;
	cout << moneyList << endl;

	cout << "Let's assign comlexList to a new complexList_1: " << endl;
	Seqlist<Complex, 10> complexList_1 = complexList;
	cout << "complexList_1: " << endl << complexList_1 << endl;

	return 0;
}
/*
Original intList: 
0
9
5
4
8
2
8
0
8
8

Original complexList:
8 + 0i
1 + 2i
4 + 7i
4 + 9i
4 + 1i
1 + 4i
8 + 3i
3 + 2i
1 + 6i
4 + 1i

Original moneyList:
CNY 3.78
CNY 9.42
CNY 8.52
CNY 7.59
CNY 1.77
CNY 1.45
CNY 6.98
CNY 9.05
CNY 1.59
CNY 6.41

Sorted intList:
0
0
2
4
5
8
8
8
8
9

Sorted complexList:
4 + 9i
8 + 3i
4 + 7i
8 + 0i
1 + 6i
1 + 4i
4 + 1i
4 + 1i
3 + 2i
1 + 2i

Sorted moneyList:
CNY 1.45
CNY 1.59
CNY 1.77
CNY 3.78
CNY 6.41
CNY 6.98
CNY 7.59
CNY 8.52
CNY 9.05
CNY 9.42

intList.Find(5): 4
Inserting 5 at 5th position in intList:
0
0
2
4
5
8
8
8
8
9

moneyList is full
The [1] element in complexList is 8 + 3i. That is to say, complexList[1] is 8 + 3i.

Remove the 3rd element in moneyList:
CNY 1.45
CNY 1.59
CNY 1.77
CNY 3.78
CNY 6.41
CNY 6.98
CNY 7.59
CNY 8.52
CNY 9.05
CNY 9.42

Let's assign comlexList to a new complexList_1:
complexList_1:
4 + 9i
8 + 3i
4 + 7i
8 + 0i
1 + 6i
1 + 4i
4 + 1i
4 + 1i
3 + 2i
1 + 2i
*/