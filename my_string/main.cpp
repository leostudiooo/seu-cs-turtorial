#include "my_string.h"
#include <iostream>

using namespace std;

int main()
{
	MyString str1(3);
	MyString str2("HELLO");
	MyString str3(str2);

	cout << str1 << endl
		<< str2 << endl
		<< str3 << endl;
}