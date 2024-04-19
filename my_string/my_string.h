#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <iostream>

class MyString
{
	int size;
	char* myString;
public:
	MyString(int size = 0);
	MyString(const char*);
	MyString(const MyString&);
	~MyString();

	friend std::ostream& operator<<(std::ostream&, const MyString&);
};

MyString::MyString(int size)
{
	size += 1;
	myString = new char[size];
	for (int i = 0; i < size; i++)
		myString[i] = '\0';
	this -> size = size;
}

MyString::MyString(const char* inString)
{
	size = 0;
	const char* inStringCopy = inString;
	while(*(inStringCopy++))
		size++;
	size += 1; // for '\0'
	myString = new char[size];
	char* myStringCopy = myString;
	inStringCopy = inString;
	while(*inStringCopy)
		*(myStringCopy++) = *(inStringCopy++);
	*myStringCopy = '\0';
}

MyString::MyString(const MyString& another)
{
	size = another.size;
	myString = new char[size];
	char* anotherStrPtr = another.myString;
	char* myStringCopy = myString;
	while(*anotherStrPtr)
		*(myStringCopy++) = *(anotherStrPtr++);	
	*myStringCopy = '\0';
}

MyString::~MyString()
{
	delete[] myString;
}

std::ostream& operator<<(std::ostream& os, const MyString& oString)
{
	std::cout << oString.myString;
	return os;
}

#endif /* MY_STRING_H_ */