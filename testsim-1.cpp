/*编写程序 1：包含所需使用的头文件（10分）*/
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cmath>

using namespace std;

#define M 10
#define N 101

void rand_even(int a, int b, int *p, int n);
void split(int a[], int b[][N], int n);
int is_prime(int a);
void display(int a[], int b[][N], int n);

int main()
{
	int a, b;
	cout << "请输入随机数的范围【a,b】" << endl;
	cin >> a >> b;
	int x[M], y[M][N] = {0};
	rand_even(a, b, x, M);
	split(x, y, M);
	display(x, y, M);
	return 0;
}
/*编写程序 2：请在此处给出函数 rand_even的定义（20分）*/
void rand_even(int a, int b, int *p, int n)
{
	if (a == b) return;
	srand((unsigned)time(0));
	for (int i = 0; i < n; i++)
	{
		p[i] = rand() % (b - a) + a;
		if (p[i] % 2 != 0)
		{
			p[i] = p[i] + 1 > b ? p[i] - 1 : p[i] + 1;
		}
	}
}
/*编写程序 3 ：请在此处给出函数 split的定义（30分）*/
void split(int a[], int b[][N], int n)
{
	// split a even number into two primes
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		for (int k = 2; k <= a[i] / 2; k++)
		{
			if (is_prime(k) && is_prime(a[i] - k))
			{
				b[i][j++] = k;
				b[i][j++] = a[i] - k;
			}
		}
	}
}
/*编写程序 4：请在此处给出函数 is_prime的定义（20分）*/
int is_prime(int a)
{
	if (a == 2) return 1;
	if (a % 2 == 0) return 0;
	for (int i = 3; i <= sqrt(a); i += 2)
	{
		if (a % i == 0) return 0;
	}
	return 1;
}
/*编写程序 5 ：请在此处给出函数 display的定义（20分）*/
void display(int a[], int b[][N], int n)
{
/*
Example output:
被测数	组合总数	拆分表达式
160	8	3+157	11+149	23+137	47+113	53+107	59+101	71+89
*/
	cout << "被测数\t组合个数\t拆分表达式" << endl;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		cout << a[i] << "\t";
		int count = 0;
		while (b[i][j] != 0)
		{
			count++;
			j++;
		}
		count /= 2;
		cout << count << "\t";
		// if count > 5 display 5 sets each line
		while (count)
		{
			if (count < 5)
			{
				for (int k = 0; k < count; k++)
				{
					cout << b[i][2 * k] << "+" << b[i][2 * k + 1] << "\t";
				}
				cout << endl;
				count = 0;
			}
			else
			{
				for (int k = 0; k < 5; k++)
				{
					cout << b[i][2 * k] << "+" << b[i][2 * k + 1] << "\t";
				}
				cout << endl;
				count -= 5;
			}
		}
	}
}