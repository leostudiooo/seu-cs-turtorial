#include "complex.h"
#include "bubble_sort.h"
#include "money.h"

#include <iostream>
#include <ctime>
#include <algorithm>

// Size of arrays, set by const uint
const unsigned int SIZE = 10;

template <typename T>
inline void Print(const T arr[], const unsigned int RANGE)
{
	for (unsigned int i = 0; i < RANGE; i++)
	{
		std::cout << i << '\t' << arr[i] << std::endl;
	}
}

int main()
{
	std::srand(std::time(0));

	static int int_arr[SIZE];
	static Money money_arr[SIZE];
	static Complex complex_arr[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		int_arr[i] = std::rand();
		money_arr[i] = Money(std::rand() / 100.);
		complex_arr[i] = Complex(std::rand() / 100., std::rand() / 100.);
	}

	std::cout << "Before sorting:" << std::endl;
	std::cout << std::endl << "int_arr:" << std::endl;
	Print(int_arr, SIZE);
	std::cout << std::endl << "money_arr:" << std::endl;
	Print(money_arr, SIZE);
	std::cout << std::endl << "complex_arr:" << std::endl;
	Print(complex_arr, SIZE);

	// Sort
	BubbleSort(int_arr, SIZE);
	BubbleSort(money_arr, SIZE);
	BubbleSort(complex_arr, SIZE);

	std::cout << std::endl << "After sorting:" << std::endl;
	std::cout << std::endl << "int_arr:" << std::endl;
	Print(int_arr, SIZE);
	std::cout << std::endl << "money_arr:" << std::endl;
	Print(money_arr, SIZE);
	std::cout << std::endl << "complex_arr:" << std::endl;
	Print(complex_arr, SIZE);

	return 0;
}

/*
Output:
Before sorting:

int_arr:
0       23298
1       5785
2       26072
3       27923
4       23844
5       4448
6       18890
7       21895
8       16786
9       24497

money_arr:
0       CNY 2.33
1       CNY 57.71
2       CNY 46.14
3       CNY 60.61
4       CNY 39.06
5       CNY 66.79
6       CNY 134.28
7       CNY 15.93
8       CNY 99.24
9       CNY 225.49

complex_arr:
0       202.14 + 10.66i
1       213.89 + 259.4i
2       60.07 + 139.52i
3       228.53 + 58.26i
4       62.42 + 81.69i
5       236.33 + 51.32i
6       3.1 + 24.05i
7       116.72 + 21.46i
8       218.61 + 204.74i
9       282.14 + 133.74i

After sorting:

int_arr:
0       4448
1       5785
2       16786
3       18890
4       21895
5       23298
6       23844
7       24497
8       26072
9       27923

money_arr:
0       CNY 2.33
1       CNY 15.93
2       CNY 39.06
3       CNY 46.14
4       CNY 57.71
5       CNY 60.61
6       CNY 66.79
7       CNY 99.24
8       CNY 134.28
9       CNY 225.49

complex_arr:
0       3.1 + 24.05i
1       62.42 + 81.69i
2       116.72 + 21.46i
3       60.07 + 139.52i
4       202.14 + 10.66i
5       228.53 + 58.26i
6       236.33 + 51.32i
7       218.61 + 204.74i
8       282.14 + 133.74i
9       213.89 + 259.4i
*/