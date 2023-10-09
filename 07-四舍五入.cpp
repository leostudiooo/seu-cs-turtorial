// Rounding without using round() function
// https://stackoverflow.com/questions/485525/round-for-float-in-c
#include <iostream>
using namespace std;

int main() {
    float f;
	cin >> f;
    int i = f + 0.5;
    cout << i << endl;
    return 0;
}