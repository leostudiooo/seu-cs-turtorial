#include "my_string.h"
#include <iostream>

using namespace std;

int main()
{
	MyString s(255);
	MyString s1("Hello");
	MyString s2("World");
	MyString s3(s1);

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;

	cout << "s is " << (s.isEmpty() ? "empty" : "not empty") << endl;

	s3 = "Hi";
	cout << "s3: " << s3 << endl;
	cout << "s1: " << s1 << endl;
	cout << "s1 is " << (s1 == s3 ? "equal" : "not equal") << " to s3" << endl;

	s = s1 + " " + s2;
	cout << "s: " << s << endl;

	s += "!";
	cout << "s: " << s << endl;

	cout << "s > s1: " << (s > s1 ? "true" : "false") << endl;
	cout << "s1 < s2: " << (s1 < s2 ? "true" : "false") << endl;

	cout << "Remove s1 from s: " << (s.Remove(s.SubString(s1), s1.Length()) ? "true" : "false") << endl;

	cout << "s: " << s << endl;

	cout << "Length of s: " << s.Length() << endl;

	cout << "Enter a string: ";
	MyString sIn;
	cin >> sIn;
	cout << "You entered: " << sIn << endl;

	return 0;
}

/*
Output:
s1: Hello
s2: World
s3: Hello
s is not empty
s3: Hi
s1: Hello
s1 is not equal to s3
s: Hello World
s: Hello World!
s > s1: true
s1 < s2: true
Remove s1 from s: true
s:  World!
Length of s: 15
Enter a string: Hello!
You entered: Hello!
*/