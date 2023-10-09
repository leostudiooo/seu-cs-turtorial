#include <iostream>
using namespace std;

void forLoop()
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}
}

void whileLoop()
{
	int i = 0;
	while (i < 10)
	{
		cout << i << endl;
		i++;
	}
}

void doWhileLoop()
{
	int i = 0;
	do
	{
		cout << i << endl;
		i++;
	} while (i < 10);
}

void ifStatement()
{
	int x = 10;
	if (x == 10)
	{
		cout << "x is 10" << endl;
	}
	else if (x == 5)
	{
		cout << "x is 5" << endl;
	}
	else
	{
		cout << "x is not 5 or 10" << endl;
	}
}

void switchStatement()
{
	int x = 10;
	switch (x)
	{
	case 10:
		cout << "x is 10" << endl;
		break;
	case 5:
		cout << "x is 5" << endl;
		break;
	default:
		cout << "x is not 5 or 10" << endl;
		break;
	}
}

void ternaryOperator()
{
	int x = 10;
	string result = (x == 10) ? "x is 10" : "x is not 10";
	cout << result << endl;
}

void breakStatement()
{
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			break;
		}
		cout << i << endl;
	}
}

void continueStatement()
{
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			continue;
		}
		cout << i << endl;
	}
}

void gotoStatement_Deprecated()
{
	int i = 0;
loop:
	cout << i << endl;
	i++;
	if (i < 10)
	{
		goto loop;
	}
}

void lambdaExpression()
{
	auto f = [](int x, int y)
	{
		return x + y;
	};
	cout << f(5, 10) << endl;
}

int main()
{
	forLoop();
	whileLoop();
	doWhileLoop();
	ifStatement();
	switchStatement();
	ternaryOperator();
	breakStatement();
	continueStatement();
	gotoStatement_Deprecated();
	lambdaExpression();
	return 0;
}