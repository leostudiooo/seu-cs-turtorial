#include <iostream>
using namespace std;
class A
{
public:
	A(int a)
	{
		x = a;
		cout << "x=" << x << '\t' << "class_A" << '\n';
	}
	~A() { cout << "class_~A" << '\n'; }

private:
	int x;
};

class B
{
	A y, z;
	int s;

public:
	B(int a, int b, int c) : z(a + b + c), y(3 - a)
	{
		s = c - b;
		cout << "s=" << s << '\t' << "class_B" << '\n';
	}
	~B() { cout << "class_~B" << '\n'; }
};
int main()
{
	B s(1, 2, 3);
}
