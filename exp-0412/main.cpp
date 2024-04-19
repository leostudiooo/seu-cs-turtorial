#include "linked_list.h"
#include "../exp-0407/my_string.h"
#include <iostream>

using namespace std;

int main()
{
	LinkedList<float> F_ls;
	LinkedList<MyString> S_ls;

	F_ls.insertRear(1.1);
	F_ls.insertRear(2.2);
	F_ls.insertRear(3.3);
	F_ls.insertFront(0.0);
	F_ls.insertOrder(1.5);

	S_ls.insertRear("Hello");
	S_ls.insertRear("World");

	cout << F_ls << endl;
	cout << S_ls << endl;

	S_ls.inverse();

	cout << S_ls << endl;

	cout << F_ls.find(1)->data << endl;
	cout << F_ls.find(float(2.2))->data << endl;
	cout << S_ls.find("World")->data << endl;

	return 0;
}
/*
0 1.1 1.5 2.2 3.3 
Hello World
World Hello
1.1
2.2
World
*/