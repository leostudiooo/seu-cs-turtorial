#include "area.h"
#include <iostream>
using namespace std;

int main(){
	cout<<"Area of point is "<<area()<<endl;
	cout<<"Area of square is "<<area(1,1)<<endl;
	cout<<"Area of circle is "<<area(0.5)<<endl;
	cout<<"Area of trapezium is "<<area(1, 0.5,1)<<endl;
	cout<<"Area of triangle is "<<area(1,sqrt(1+0.5*0.5),sqrt(1+0.5*0.5),0)<<endl;
	return 0;
}
/*
Area of point is 0
Area of square is 1
Area of circle is 0.785397
Area of trapezium is 0.75
Area of triangle is 0.5
*/