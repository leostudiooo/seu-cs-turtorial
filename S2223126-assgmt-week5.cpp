#include <bits/stdc++.h>

using namespace std;

void triangle()
{
	double length[3];
	cout << "输入三角形的三条边长：";
	cin >> length[0] >> length[1] >> length[2];

	sort(length, length + 3);

	double sq12 = pow(length[0], 2) + pow(length[1], 2);
	double sq3 = pow(length[2], 2);

	// 输入精度有限，引入误差范围 Epsilon，否则不可能出现等腰直角三角形等情况
	const double EPSILON = 0.01;

	if (length[0] + length[1] <= length[2])
	{
		cout << "不能构成三角形" << endl;
		return;
	}

	// core algorithm
	if (length[0] == length[1] && length[1] == length[2])
	{
		cout << "等边三角形" << endl;
	}

	else if (length[0] == length[1] || length[1] == length[2])
	{
		if (length[1] == length[2])
			cout << "等腰锐角三角形" << endl;
		else if (abs(sq12 - sq3) < EPSILON)
			cout << "等腰直角三角形" << endl;
		else
			cout << "等腰钝角三角形" << endl;
	}

	else
	{
		if (abs(sq12 - sq3) < EPSILON)
			cout << "一般直角三角形" << endl;
		else if (sq12 > sq3 + EPSILON)
			cout << "一般锐角三角形" << endl;
		else
			cout << "一般钝角三角形" << endl;
	}
	return;
}

void sumCalc()
{
	int type, n;
	cout << "输入计算类型（1，2，3，4，5）和 n（正整数）：";
	cin >> type >> n;
	double sum = 0;
	switch (type)
	{
	case 1:
		for (int i = 1; i <= n; i++)
		{
			int tmp = 1;
			for (int j = 1; j <= i; j++)
				tmp *= j;
			sum += tmp;
		}
		break;
	case 2:
		for (int i = 1; i <= n; i += 2)
			sum += i;
		break;
	case 3:
		for (int i = 2; i <= n; i += 2)
			sum += i;
		break;
	case 4:
		for (int i = 1; i <= n; i++)
			sum += pow(i, 2);
		break;
	case 5:
		for (int i = 1; i <= n; i++)
			sum += pow(i, -1);
		break;
	default:
		cout << "输入错误" << endl;
		return;
	}
	cout << "结果为：" << sum << endl;
	return;
}

void dateCalc()
{
	// switch 太麻烦了，直接打表
	int monthArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// 2023 年 1 月 1 日是周日
	string daysArr[7] = {"周日", "周一", "周二", "周三", "周四", "周五", "周六"};
	int month, day;
	cout << "输入月份和日期：";
	cin >> month >> day;
	int count = 0;
	if (month > 1)
		for (int i = 0; i < month - 1; i++)
			count += monthArr[i];
	count += day;
	cout << "这一天是" << daysArr[count % 7 - 1] << endl;
	return;
}

int main()
{
	triangle();
	sumCalc();
	dateCalc();
	return 0;
}