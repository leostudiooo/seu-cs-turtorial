#include <stdio.h>
#include <stdlib.h>
#include<math.h>
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
 int main()
 {
    double red, green, blue;
    double value, saturation, hue;
    double maximum, minimum;
    scanf("%lf%lf%lf",&red,&green,&blue);
    maximum = max(red, green, blue);
    value = maximum;
    minimum = min(red, green, blue);
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
    printf("%.4lf,%.4lf%%,%.4lf%%",hue,saturation,value);
   return 0;
 }