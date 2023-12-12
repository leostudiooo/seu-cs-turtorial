// 2. Define a 2-dimensional double array[M][N].
// The elements are random doubles from [-10, 20].
// Find the max and min value with corresponding [row][line] and output.

#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;

const int M = 10, N = 20;

int main() {

	// Initialize the array
	double array[M][N] = {};
	srand(time(0));
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			array[i][j] = (rand() / (double)RAND_MAX) * 30 - 10;

// Switch to Debug in compile options.
#ifdef _DEBUG
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << array[i][j] << " ";
		cout << endl;
	}
#endif

	// Data structure for value, line and row of max and min
	struct MyStruct
	{
		double value;
		int line, row;
	};
	MyStruct max, min;
	
	// Initialize max and min
	max.value = array[0][0];
	min.value = array[0][0];
	
	// Scan the array for max and min
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (array[i][j] > max.value) {
				max.value = array[i][j];
				max.line = i;
				max.row = j;
			}
			if (array[i][j] < min.value) {
				min.value = array[i][j];
				min.line = i;
				min.row = j;
			}
		}
	}

	cout << "Maximum: array[" << max.line << "][" << max.row << "] = " << max.value << endl;
	cout << "Minimum: array[" << min.line << "][" << min.row << "] = " << min.value << endl;
}

/*
Run #1:
Maximum: array[3][10] = 19.9661
Minimum: array[6][8] = -9.98077
------
Run #2:
Maximum: array[5][6] = 19.7812
Minimum: array[2][6] = -9.96338
------
Run #3:
Maximum: array[7][13] = 19.9918
Minimum: array[1][0] = -9.96063
*/
