/*
1. 创建一个带有圆心平面坐标的圆类，该圆类具有以下功能：（1）圆属性（圆心和半径）的设置和获取；（2）圆的面积；（3）圆的周长；（4）添加默认构造函数和构造函数重载；（5）添加复制构造函数；（6）添加析构函数；（提示：在构造函数和析构函数中添加一些输出信息的语句帮助理解在定义和释放对象时调用的哪些函数）
2. 在main函数中定义上述圆类的对象，并对其所有功能进行测试，特别测试不同情况下系统对构造函数的调用；
3. 在主文件中添加普通函数，用于判断两个圆的关系（包含、内切、外切、相交、相离） ，在main函数中进行测试，输出两圆的关系。
4. 使用多文件结构。
*/

#include <iostream>

class Circle
{
private:
	double x, y, radius;

public:
	Circle(double X = 0, double Y = 0, double radius = 0);
	Circle(const Circle &c);
	void setCenterRadius(double X, double Y, double Radius);
	double *getCenterRadius();
	double getArea();
	double getPerimeter();
	~Circle();
};

Circle::Circle(double X, double Y, double Radius)
{
	x = X;
	y = Y;
	radius = Radius;
	std::cout << "Circle constructor called" << std::endl;
}

Circle::~Circle()
{
}
