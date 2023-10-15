#include <stdio.h>
#include <stdlib.h>

double max(double a,double b,double c)
{
	double t;
	if (a>b){
	 t=a;
	}
	else {
	   t=b;
	}
	if (t>c){
		return t;
	}
	else return c;
}

double min(double a,double b,double c)
{
	double t;
	if (a<b){
		t=a;
	}
	else {
		t=b;
	}
	if (c<t){
		t=c;
		return t;
	}
	else return t;
}

double* convert(int R, int G, int B){
	double red, green, blue;
	double value, saturation, hue;
	double maximum, minimum;

	// 数据预处理
	red = R/255.0;
	green = G/255.0;
	blue = B/255.0;
	maximum = max(red, green, blue);
	value = maximum;
	minimum = min(red, green, blue);
	// 计算 RGB -> HSV	
	if (value == 0){
		saturation = 0;
	}
	else {
			saturation = (maximum - minimum) / maximum;
	}
	if (maximum == red){
		hue = 60 * ((green - blue) / (maximum - minimum));
	}
	if (maximum == green){
		hue = 60 * (2 + (blue - red) / (maximum - minimum));
	}
	if (maximum == blue){
		hue = 60 * (4 + (red - green) / (maximum - minimum));
	}
	if (hue < 0){
		hue = hue + 360;
	}
	saturation = saturation * 100;
	value = value * 100;

	double* hsv = (double*) malloc(3 * sizeof(double));
	hsv[0] = hue;
	hsv[1] = saturation;
	hsv[2] = value;
	return hsv;
	return hsv;
}

int main()
{
	int R, G, B;
	double* hsv;
	scanf("%d%d%d",&R,&G,&B);
	hsv = convert(R, G, B);
	printf("%.4lf,%.4lf%%,%.4lf%%",hsv[0],hsv[1],hsv[2]);
	return 0;
}