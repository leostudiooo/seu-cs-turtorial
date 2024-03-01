/*
1. 创建一个带有圆心平面坐标的圆类，该圆类具有以下功能：（1）圆属性（圆心和半径）的设置和获取；（2）圆的面积；（3）圆的周长；（4）添加默认构造函数和构造函数重载；（5）添加复制构造函数；（6）添加析构函数；（提示：在构造函数和析构函数中添加一些输出信息的语句帮助理解在定义和释放对象时调用的哪些函数）
2. 在main函数中定义上述圆类的对象，并对其所有功能进行测试，特别测试不同情况下系统对构造函数的调用；
3. 在主文件中添加普通函数，用于判断两个圆的关系（包含、内切、外切、相交、相离） ，在main函数中进行测试，输出两圆的关系。
4. 使用多文件结构。
*/

#include "circle.h"

const double EPSILON = 1e-6;

/*
`judgeRelation` judges the relation between two circles.
@param c1: circle 1
@param c2: circle 2
@return: -2 for containing, -1 for inscribed, 0 for intersecting, 1 for circumscribed, 2 for disjoint
*/
int judgeRelation(Circle &c1, Circle &c2);

int main()
{

}

int judgeRelation(Circle &c1, Circle &c2)
{
	double *centerRadius1 = c1.getCenterRadius();
	double *centerRadius2 = c2.getCenterRadius();
	double distance = sqrt(pow(centerRadius1[0] - centerRadius2[0], 2) + pow(centerRadius1[1] - centerRadius2[1], 2));
	double radiusSum = centerRadius1[2] + centerRadius2[2];
	double radiusDiff = fabs(centerRadius1[2] - centerRadius2[2]);
	if (distance < EPSILON && radiusDiff < EPSILON)
	{
		return -2;
	}
	else if (distance < radiusDiff)
	{
		return -1;
	}
	else if (fabs(distance - radiusDiff) < EPSILON)
	{
		return 0;
	}
	else if (distance < radiusSum)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}