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

	cout << "Original intList: " << intList << endl;
	cout << "Original complexList: " << complexList << endl;
	cout << "Original moneyList: " << moneyList << endl;

	intList.Sort(ASCENDING, BUBBLE);
	complexList.Sort(DESCENDING, SELECTION);
	moneyList.Sort(ASCENDING, INSERTION);

	cout << "Sorted intList: " << intList << endl;
	cout << "Sorted complexList: " << complexList << endl;
	cout << "Sorted moneyList: " << moneyList << endl;

	cout << "intList.Find(5): " << intList.Find(5) << endl;
	cout << "complexList.Find(Complex(5, 5)): " << complexList.Find(Complex(1, 1)) << endl;
	cout << "moneyList.Find(Money(5.5)): " << moneyList.Find(Money(5.5)) << endl;

	cout << "Inserting 5 at 5th position in intList: ";
	intList.Insert(5, 5);
	cout << intList << endl;

	cout << "moneyList is " << (moneyList.IsFull() ? "" : "not ") << "full" << endl;

	cout << "The 2nd element in complexList is " << complexList.Get(2) << ". That is to say, complexList[1] is " << complexList[1] << endl;

	cout << "Remove the 3rd element in moneyList: ";
	moneyList.Remove(3);
	cout << moneyList << endl;

	cout << "Let's assign comlexList to a new complexList_1: " << endl;
	Seqlist<Complex, 10> complexList_1 = complexList;
	cout << "complexList_1: " << complexList_1 << endl;

	return 0;
}
/*
Original intList: 5
6
6
7
0
0
7
0
4
1

Original complexList: 6 + 0i
5 + 6i
1 + 5i
1 + 3i
3 + 2i
5 + 7i
7 + 0i
6 + 3i
9 + 9i
5 + 1i

Original moneyList: CNY 0.13
CNY 9.35
CNY 5.3
CNY 4.71
CNY 9.34
CNY 1.58
CNY 5.72
CNY 9.67
CNY 5.85
CNY 1.6

Sorted intList: 0
0
0
1
4
5
6
6
7
7

Sorted complexList: 9 + 9i
5 + 7i
5 + 6i
7 + 0i
6 + 3i
6 + 0i
1 + 5i
5 + 1i
3 + 2i
1 + 3i

Sorted moneyList: CNY 0.13
CNY 1.58
CNY 1.6
CNY 4.71
CNY 5.3
CNY 5.72
CNY 5.85
CNY 9.34
CNY 9.35
CNY 9.67

intList.Find(5): 5
complexList.Find(Complex(5, 5)): -1
moneyList.Find(Money(5.5)): -1
Inserting 5 at 5th position in intList: 0
0
0
1
4
5
6
6
7
7

moneyList is full
The 2nd element in complexList is 5 + 6i. That is to say, complexList[1] is 5 + 7i
Remove the 3rd element in moneyList: CNY 0.13
CNY 1.58
CNY 1.6
CNY 4.71
CNY 5.3
CNY 5.72
CNY 5.85
CNY 9.34
CNY 9.35
CNY 9.67

Let's assign comlexList to a new complexList_1:
complexList_1: 9 + 9i
5 + 7i
5 + 6i
7 + 0i
6 + 3i
6 + 0i
1 + 5i
5 + 1i
3 + 2i
1 + 3i
*/