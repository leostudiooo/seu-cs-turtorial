#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <iostream>
#include <string>

class MyString
{
	int size;
	char *myString;

public:
	/* Constructors and Destructor */

	MyString(int size = 0);
	MyString(const char *);
	MyString(const MyString &);
	~MyString();

	bool isEmpty() const { return size == 0; }
	int Length() const { return size - 1; } // Or the position of the first '\0'?

	/* Operators +, +=, =, ==, !=, >, < */
	
	MyString operator+(const MyString &) const;
	MyString operator+(const char *) const;
	friend MyString operator+(const char *, const MyString &);

	MyString &operator+=(const MyString &);
	MyString &operator+=(const char *);

	MyString &operator=(const MyString &);
	MyString &operator=(const char *);

	bool operator==(const MyString &) const;
	bool operator==(const char *) const;

	bool operator!=(const MyString &) const;
	bool operator!=(const char *) const;

	bool operator<(const MyString &) const;
	bool operator<(const char *) const;

	bool operator>(const MyString &) const;
	bool operator>(const char *) const;

	/* I/O Stream Operators << and >> */
	
	friend std::ostream &operator<<(std::ostream &, const MyString &);
	friend std::istream &operator>>(std::istream &, MyString &);

	/* Others */
	
	int SubString(const MyString &) const;
	int SubString(const char *) const;

	bool Remove(int, int);
};

MyString::MyString(int size)
{
	size += 1;
	myString = new char[size];
	for (int i = 0; i < size; i++)
		myString[i] = '\0';
	this->size = size;
}

MyString::MyString(const char *inString)
{
	size = 0;
	const char *inStringCopy = inString;
	while (*(inStringCopy++))
		size++;
	size += 1; // for '\0'
	myString = new char[size];
	char *myStringCopy = myString;
	inStringCopy = inString;
	while (*inStringCopy)
		*(myStringCopy++) = *(inStringCopy++);
	*myStringCopy = '\0';
}

MyString::MyString(const MyString &another)
{
	size = another.size;
	myString = new char[size];
	char *anotherStrPtr = another.myString;
	char *myStringCopy = myString;
	while (*anotherStrPtr)
		*(myStringCopy++) = *(anotherStrPtr++);
	*myStringCopy = '\0';
}

MyString::~MyString()
{
	delete[] myString;
}

MyString MyString::operator+(const MyString &another) const
{
	MyString temp(size + another.size - 1);
	char *tempStrPtr = temp.myString;
	char *myStrPtr = myString;
	while (*myStrPtr)
		*(tempStrPtr++) = *(myStrPtr++);
	char *anotherStrPtr = another.myString;
	while (*anotherStrPtr)
		*(tempStrPtr++) = *(anotherStrPtr++);
	*tempStrPtr = '\0';
	return temp;
}

MyString MyString::operator+(const char *another) const
{
	int anotherSize = 0;
	const char *anotherCopy = another;
	while (*(anotherCopy++))
		anotherSize++;
	anotherSize += 1; // for '\0'
	MyString temp(size + anotherSize - 1);
	char *tempStrPtr = temp.myString;
	char *myStrPtr = myString;
	while (*myStrPtr)
		*(tempStrPtr++) = *(myStrPtr++);
	anotherCopy = another;
	while (*anotherCopy)
		*(tempStrPtr++) = *(anotherCopy++);
	*tempStrPtr = '\0';
	return temp;
}

MyString operator+(const char *another, const MyString &oString)
{
	int anotherSize = 0;
	const char *anotherCopy = another;
	while (*(anotherCopy++))
		anotherSize++;
	anotherSize += 1; // for '\0'
	MyString temp(oString.size + anotherSize - 1);
	char *tempStrPtr = temp.myString;
	char *oStrPtr = oString.myString;
	while (*another)
		*(tempStrPtr++) = *(another++);
	while (*oStrPtr)
		*(tempStrPtr++) = *(oStrPtr++);
	*tempStrPtr = '\0';
	return temp;
}

MyString &MyString::operator+=(const MyString &another)
{
	MyString temp = *this + another;
	delete[] myString;
	size = temp.size;
	myString = new char[size];
	char *tempStrPtr = temp.myString;
	char *myStrPtr = myString;
	while (*tempStrPtr)
		*(myStrPtr++) = *(tempStrPtr++);
	*myStrPtr = '\0';
	return *this;
}

MyString &MyString::operator+=(const char *another)
{
	MyString temp = *this + another;
	delete[] myString;
	size = temp.size;
	myString = new char[size];
	char *tempStrPtr = temp.myString;
	char *myStrPtr = myString;
	while (*tempStrPtr)
		*(myStrPtr++) = *(tempStrPtr++);
	*myStrPtr = '\0';
	return *this;
}

MyString &MyString::operator=(const MyString &another)
{
	if (this == &another)
		return *this;
	delete[] myString;
	size = another.size;
	myString = new char[size];
	char *anotherStrPtr = another.myString;
	char *myStringCopy = myString;
	while (*anotherStrPtr)
		*(myStringCopy++) = *(anotherStrPtr++);
	*myStringCopy = '\0';
	return *this;
}

MyString &MyString::operator=(const char *another)
{
	delete[] myString;
	size = 0;
	const char *anotherCopy = another;
	while (*(anotherCopy++))
		size++;
	size += 1; // for '\0'
	myString = new char[size];
	char *myStringCopy = myString;
	anotherCopy = another;
	while (*anotherCopy)
		*(myStringCopy++) = *(anotherCopy++);
	*myStringCopy = '\0';
	return *this;
}

bool MyString::operator==(const MyString &another) const
{
	char *myStrPtr = myString;
	char *anotherStrPtr = another.myString;
	while (*myStrPtr && *anotherStrPtr)
	{
		if (*myStrPtr != *anotherStrPtr)
			return false;
		myStrPtr++;
		anotherStrPtr++;
	}
	return *myStrPtr == *anotherStrPtr;
}

bool MyString::operator==(const char *another) const
{
	const char *anotherCopy = another;
	char *myStrPtr = myString;
	while (*myStrPtr && *anotherCopy)
	{
		if (*myStrPtr != *anotherCopy)
			return false;
		myStrPtr++;
		anotherCopy++;
	}
	return *myStrPtr == *anotherCopy;
}

bool MyString::operator!=(const MyString &another) const
{
	if(*this == another)
		return false;
	else
	{
		char *myStrPtr = myString;
		char *anotherStrPtr = another.myString;
		while (*myStrPtr && *anotherStrPtr)
		{
			if (*myStrPtr != *anotherStrPtr)
				return true;
			myStrPtr++;
			anotherStrPtr++;
		}
		return false;
	}
}

bool MyString::operator!=(const char *another) const
{
	if(*this == another)
		return false;
	else
	{
		const char *anotherCopy = another;
		char *myStrPtr = myString;
		while (*myStrPtr && *anotherCopy)
		{
			if (*myStrPtr != *anotherCopy)
				return true;
			myStrPtr++;
			anotherCopy++;
		}
		return false;
	}
}

bool MyString::operator<(const MyString &another) const
{
	char *myStrPtr = myString;
	char *anotherStrPtr = another.myString;
	while (*myStrPtr && *anotherStrPtr)
	{
		if (*myStrPtr < *anotherStrPtr)
			return true;
		else if (*myStrPtr > *anotherStrPtr)
			return false;
		myStrPtr++;
		anotherStrPtr++;
	}
	return *myStrPtr < *anotherStrPtr;
}

bool MyString::operator<(const char *another) const
{
	const char *anotherCopy = another;
	char *myStrPtr = myString;
	while (*myStrPtr && *anotherCopy)
	{
		if (*myStrPtr < *anotherCopy)
			return true;
		else if (*myStrPtr > *anotherCopy)
			return false;
		myStrPtr++;
		anotherCopy++;
	}
	return *myStrPtr < *anotherCopy;
}

bool MyString::operator>(const MyString &another) const
{
	char *myStrPtr = myString;
	char *anotherStrPtr = another.myString;
	while (*myStrPtr && *anotherStrPtr)
	{
		if (*myStrPtr > *anotherStrPtr)
			return true;
		else if (*myStrPtr < *anotherStrPtr)
			return false;
		myStrPtr++;
		anotherStrPtr++;
	}
	return *myStrPtr > *anotherStrPtr;
}

bool MyString::operator>(const char *another) const
{
	const char *anotherCopy = another;
	char *myStrPtr = myString;
	while (*myStrPtr && *anotherCopy)
	{
		if (*myStrPtr > *anotherCopy)
			return true;
		else if (*myStrPtr < *anotherCopy)
			return false;
		myStrPtr++;
		anotherCopy++;
	}
	return *myStrPtr > *anotherCopy;
}

std::ostream &operator<<(std::ostream &os, const MyString &oString)
{
	std::cout << oString.myString;
	return os;
}

std::istream &operator>>(std::istream &is, MyString &iString)
{
	char temp[255]; // TODO: use VL data structures like vector to improve exception handling
	is >> temp;
	iString = temp;
	return is;
}

int MyString::SubString(const MyString &subStr) const
{
	char *myStrPtr = myString;
	char *subStrPtr = subStr.myString;
	int subStrLen = subStr.Length();
	int i = 0;
	while (*myStrPtr)
	{
		if (*myStrPtr == *subStrPtr)
		{
			int j = 0;
			while (*(myStrPtr + j) == *(subStrPtr + j))
			{
				if (j == subStrLen - 1)
					return i;
				j++;
			}
		}
		myStrPtr++;
		i++;
	}
	return -1;
}

int MyString::SubString(const char *subStr) const
{
	const char *subStrCopy = subStr;
	char *myStrPtr = myString;
	int subStrLen = 0;
	while (*(subStrCopy++))
		subStrLen++;
	int i = 0;
	while (*myStrPtr)
	{
		if (*myStrPtr == *subStr)
		{
			int j = 0;
			while (*(myStrPtr + j) == *(subStr + j))
			{
				if (j == subStrLen - 1)
					return i;
				j++;
			}
		}
		myStrPtr++;
		i++;
	}
	return -1;
}

bool MyString::Remove(int pos, int len)
{
	if (pos < 0 || pos >= size - 1 || len < 0 || pos + len > size - 1)
		return false;
	char *myStrPtr = myString + pos;
	char *myStrPtrCopy = myStrPtr + len;
	while (*myStrPtrCopy)
		*(myStrPtr++) = *(myStrPtrCopy++);
	*myStrPtr = '\0';
	return true;
}

#endif /* MY_STRING_H_ */