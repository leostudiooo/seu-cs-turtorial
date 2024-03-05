// find all integers 1-500 that %3==2, %5==3, %7==2.

#include <iostream>

using namespace std;

int main() {
	for (int i = 1; i <= 500; i++) {
		if (i % 3 == 2 && i % 5 == 3 && i % 7 == 2) {
			cout << i << endl;
		}
	}
	return 0;
}