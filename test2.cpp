#include <iostream>
using namespace std;
class SomeClass
{
	int One , Two;
public:
	SomeClass(int a = 1, int b = 1)
	{
		One = a;
		Two = b;
		cout << "Structor" << endl;
	}
	SomeClass(SomeClass &obj)
	{
		One = obj.One;
		Two = obj.Two;
		cout << "Copy Structor" << endl;
	}
	void show()
	{
		cout << "One=" << One << ';'
			<< "Two=" << Two << '\n';
	}
	SomeClass operator^(SomeClass c)
	{
		SomeClass Temp(One - c.One , Two * c.Two);
		return Temp;	
	}
	~SomeClass() {	cout <<	"Destructor" << endl;} 
};
int main()
{
	SomeClass obj1,obj2(9 , 4);
	obj2 = obj2 ^ obj1;
	obj2.show();
	return 0;
}
