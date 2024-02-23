/*编写程序 1：包含所需使用的头文件（5 分）*/
#include <iostream>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <cstring>

using namespace std;

#define N 100

void create_string(char str[]);
int is_even(char str[]);
int get_str(char strings[][11], char result[][11]);

int main()
{
	char strings[N][11], result[N][11];
	int n = 0, i;

	/*编写程序 2：创建文件流对象，并打开 txt 文件（5 分）*/
	ofstream fout;
	fout.open("testsim-2.txt");

	/*编写程序 3：调用函数为数组 strings 中的各行赋值为随机字符串，再将数组内容分别
	输出到 console 窗口和 txt 文件（5 分）*/
	srand((unsigned)time(0));

	for (int i = 0; i < N; i++)
		create_string(strings[i]);
	for (int i = 0; i < N; i++)
	{
		cout << strings[i] << endl;
		fout << strings[i] << endl;
	}
	cout << endl;
	fout << endl;

	/*调用函数，在函数内统计符合条件的字符串的个数，并将字符串存入数组 result 中*/	
	/*编写程序 4：将统计结果分别输出到 console 窗口和 txt 文件（5 分）*/
	n = get_str(strings, result);

	cout << "There are " << n << " strings with even A-E-I-O-Us." << endl;
	fout << "There are " << n << " strings with even A-E-I-O-Us." << endl;

	for (int i = 0; i < n; i++)
	{
		cout << result[i] << endl;
		fout << result[i] << endl;
	}
		
	/*编写程序 5：关闭文件流（5 分）*/
	fout.close();

	return 0;
}

/*编写程序 6：请在此处给出函数 create_string 的定义（25 分）*/
void create_string(char str[])
{
	for (int i = 0; i < rand() % 5 + 5; i++)
		*(str++) = rand() % 26 + 'A';
	*str = '\0';
}

/*编写程序 7：请在此处给出函数 get_str 的定义（25 分）*/
int get_str(char strings[][11], char result[][11])
{
	// initialize a var n for counting
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (is_even(strings[i]))
		{
			strcpy(result[n], strings[i]);
			n++;
		}
		
	}
	return n;
}
/*编写程序 8：请在此处给出函数 is_even 的定义（25 分）*/
int is_even(char str[])
{
	int count = 0;
	while (*str)
	{
		if (*str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U')
			count++;
		str++;
	}
	if (count % 2)
		return 0;
	else
		return 1;
}