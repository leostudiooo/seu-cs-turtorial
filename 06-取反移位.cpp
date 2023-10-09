#include<iostream>
using namespace std;
int main()
{
	unsigned char bits = 0o233;
	cout << sizeof(bits << 8) << '\t' << (bits << 8) << endl;
	cout << sizeof(bits << 31) << '\t' << (bits << 31) << endl;
	cout << sizeof(bits >> 3) << '\t' << (bits >> 3) << endl;
	cout << sizeof(~bits) << '\t' << (~bits) << endl;
	return 0;
}