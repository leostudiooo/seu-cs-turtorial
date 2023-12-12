#include <iostream>

using namespace std;

// MSVC does not support standard VLA. Define a large number to avoid using malloc().
const int VERY_LARGE_NUMBER = 100;

int GetStrLen(char*);
char *StrNCat(char*, char*, int n = 0);
int SrcCh(char*, char);
void del(char*, int);
bool DelAtK(char*, int);
int StrDel(char*, char*);

int main()
{
	char str1[VERY_LARGE_NUMBER] = "abcdef", str2[] = "cdefghi";
	cout
		<< "str1: " << str1
		<< endl
		<< "str2: " << str2
		<< endl;
	// GetStrLen()
	cout
		<< "Length(str1, str2): "
		<< "(" << GetStrLen(str1) << ", " << GetStrLen(str2) << ")"
		<< endl;
	// StrNCat()
	StrNCat(str1, str2);
	cout << str1 << endl;
	StrNCat(str1, str2, 3);
	cout << str1 << endl;
	// SrcCh()
	cout
		<< "Search 'a' in str1: "
		<< SrcCh(str1, 'a')
		<< endl;
	cout
		<< "Search '0' in str2: "
		<< SrcCh(str2, '0')
		<< endl;
	// DelAtK()
	cout
		<< (DelAtK(str1, 100) ? "Deleted" : "No deletion")
		<< endl;
	cout
		<< (DelAtK(str1, 5) ? "Deleted" : "No deletion")
		<< endl;
	cout
		<< str1
		<< endl;
	// StrDel()
	int count = StrDel(str1, str2);
	cout
		<< "Deleted " << count << " characters, result: "
		<< str1
		<< endl;
	return 0;
}

int GetStrLen(char *str)
{
	int len = 0;
	while (*str) {
		len++;
		str++;
	}
	return len;
}

char *StrNCat(char *str1, char *str2, int n)
{
	char *result = str1;
	while (*str1)
	{
		str1++;
	}
	int str2Len = GetStrLen(str2);
	for (int i = 0; i < ((n == 0 || n >= str2Len) ? str2Len : n); i++)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return result;
}

int SrcCh(char *str, char ch)
{
	const int NOT_FOUND = -1;
	for (int i = 0; *str;)
	{
		if (*str == ch)
			return i;
		str++;
		i++;
	}
	return NOT_FOUND;
}

void del(char *str, int index)
{
	char *left = str, *right = str;
	left += index;
	right += index + 1;
	while (*right)
	{
		*left++ = *right++;
	}
	*left = '\0';
}

bool DelAtK(char *str, int k)
{
	if (k >= GetStrLen(str) || k < 0)
		return false;
	del(str, k);
	return true;
}

int StrDel(char *s1, char *s2)
{
	int count = 0;
	while (*s2) {
		while (DelAtK(s1, SrcCh(s1, *s2)))
			count++;
		s2++;
	}
	return count;
}

/*
Result:
str1: abcdef
str2: cdefghi
Length(str1, str2): (6, 7)
abcdefcdefghi
abcdefcdefghicde
Search 'a' in str1: 0
Search '0' in str2: -1
No deletion
Deleted
abcdecdefghicde
Deleted 13 characters, result: ab
*/