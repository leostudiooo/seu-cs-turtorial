#include <bits/stdc++.h>

using namespace std;

void triangle()
{
	double length[3];
	cout << "输入三角形的三条边长：";
	cin >> length[0] >> length[1] >> length[2];
	sort(length, length + 3);

	double sqSum = pow(length[0], 2) + pow(length[1], 2);
	double sqMax = pow(length[2], 2);

	// 浮点数和输入损失精度，引入误差范围 Epsilon
	const double EPSILON = 1e-2;

	if (length[0] + length[1] <= length[2])
	{
		cout << "不能构成三角形" << endl;
		return;
	}
	
	if (length[0] == length[1] && length[1] == length[2])
	{
		cout << "等边三角形" << endl;
	}
	
	else if (length[0] == length[1] || length[1] == length[2])
	{
		if (length[1] == length[2])
			cout << "等腰锐角三角形" << endl;
		else if (abs(sqSum - sqMax) < EPSILON)
			cout << "等腰直角三角形" << endl;
		else
			cout << "等腰钝角三角形" << endl;
	}
	
	else{
		if (abs(sqSum - sqMax) < EPSILON)
			cout << "一般直角三角形" << endl;
		else if (sqSum > sqMax + EPSILON)
			cout << "一般锐角三角形" << endl;
		else
			cout << "一般钝角三角形" << endl;
	}
	return;
}

void dateCalc(){
	// 2023.1.1 是星期日
	int monthArr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int month, day;
	cout << "输入月份和日期：";
	cin >> month >> day;
	string daysArr[7] = {"周日", "周一", "周二", "周三", "周四", "周五", "周六"};
	int count = 0;
	if (month > 1)
		for (int i = 0; i < month - 1; i++)
			count += monthArr[i];
	count += day;
	cout  << "这一天是" << daysArr[count % 7 - 1] << endl;
	return;
}

int main(){
	triangle();
	dateCalc();
	return 0;
}