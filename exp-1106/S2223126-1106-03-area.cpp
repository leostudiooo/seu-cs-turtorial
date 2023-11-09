#include <cmath>
#define PI 3.14159

double area(double radius){
	return PI * radius * radius;
}
double area(double a, double b){
	return a * b;
}
double area(double a, double b, double h){
	return (a + b) * h / 2;
}
double area(double a, double b, double c, int){
	double p = (a + b + c) / 2;
	return std::sqrt(p * (p - a) * (p - b) * (p - c));
}