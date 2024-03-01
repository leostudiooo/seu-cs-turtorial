/*
1. 创建一个带有圆心平面坐标的圆类，该圆类具有以下功能：（1）圆属性（圆心和半径）的设置和获取；（2）圆的面积；（3）圆的周长；（4）添加默认构造函数和构造函数重载；（5）添加复制构造函数；（6）添加析构函数；（提示：在构造函数和析构函数中添加一些输出信息的语句帮助理解在定义和释放对象时调用的哪些函数）
2. 在main函数中定义上述圆类的对象，并对其所有功能进行测试，特别测试不同情况下系统对构造函数的调用；
3. 在主文件中添加普通函数，用于判断两个圆的关系（包含、内切、外切、相交、相离） ，在main函数中进行测试，输出两圆的关系。
4. 使用多文件结构。
*/

#include "circle.h"
#include <iostream>
#include <cmath>
#include <string>

const double EPSILON = 1e-6;

/*
`judgeRelation` judges the relation between two circles.
@param c1: circle 1
@param c2: circle 2
@return: -2 for containing, -1 for inscribed, 0 for intersecting, 1 for circumscribed, 2 for disjoint
*/
std::string judgeRelation(Circle &c1, Circle &c2);

int main()
{
	Circle c1;
	Circle c2(0,0,1);
	c1.~Circle();
	Circle c3=c2;
	c3.setCenterRadius(1,1,1);

	double arr[3];
	c3.getCenterRadius(arr);

	std::cout << "Area of c3: " << c3.getArea() << std::endl;
	std::cout << "Perimeter of c3: " << c3.getPerimeter() << std::endl;

	std::cout << "Relation between c2 and c3: " << judgeRelation(c2, c3) << std::endl;
}

std::string judgeRelation(Circle &c1, Circle &c2)
{
	double cr1[3], cr2[3];
	c1.getCenterRadius(cr1);
	c2.getCenterRadius(cr2);

	double distance = sqrt(pow(cr1[0] - cr2[0], 2) + pow(cr1[1] - cr2[1], 2));
	double r1 = cr1[2], r2 = cr2[2];

	if (fabs(distance - r1 - r2) < EPSILON)
	{
		return "circumscribed";
	}
	else if (fabs(distance - fabs(r1 - r2)) < EPSILON)
	{
		return "inscribed";
	}
	else if (distance > r1 + r2)
	{
		return "disjoint";
	}
	else if (distance < fabs(r1 - r2))
	{
		return "containing";
	}
	else
	{
		return "intersecting";
	}
}

/*
Output:
PS X:\seu-cs-turtorial\exp-0301> c++ main.cpp circle.cpp circle.h -o main.exe
PS X:\seu-cs-turtorial\exp-0301> ./main.exe
Circle constructor called
Circle constructor called
Circle destructor called
Circle copy constructor called
Circle setCenterRadius() called
Circle getCenterRadius() called
Area of c3: Circle getArea() called
3.14159
Perimeter of c3: Circle getPerimeter() called
6.28319
Relation between c2 and c3: Circle getCenterRadius() called
Circle getCenterRadius() called
intersecting
Circle destructor called
Circle destructor called
Circle destructor called
*/