#include <iostream>

using namespace std;

class C1
{
	public:
	void a() { cout << "C1::a()" << endl; }
	virtual void b() { cout << "C1::b()" << endl; }
};

class C2: public C1
{
	public:
	void a() { cout << "C2::a()" << endl; }
	void b() { cout << "C2::b()" << endl; }
};

int main()
{
	C1 *pc1;
	C2 *pc2, c2;
	pc1 = &c2;
	pc2 = &c2;
	pc1->a();
	pc1->b();
	pc2->a();
	pc2->b();
	return 0;
}