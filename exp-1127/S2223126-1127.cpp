// （a）编写函数求二维数组的一个鞍点（二维数组的鞍点是指该数组元素在所在行中最大，在所在列元素中最小），若有则返回该鞍点的位置（行列下标，通过指针的方式）以及元素的值（通过return的方式），若无则将行列下标均设置为-1；（b）编写函数通过引用参数传递的方式实现(a)的功能；（c）在主函数中进行测试；
// 提示：二维数组作为函数参数传递时，形参的低维（列的大小）不能省略，高纬（行的大小）可以省略，数组的行列可以通过参数传递；实参为二维数组的数组名。

#include <iostream>
#include <algorithm>
#include <ctime>

#define _DEBUG

using namespace std;

const int LINE = 3;
const int ROW = 3;

void ptrFindPoint(int arr[LINE][ROW], int *line, int *row, int *value);
void refFindPoint(int arr[LINE][ROW], int &line, int &row, int &value);
void printResult(int line, int row, int value);
void printArray(int arr[LINE][ROW]);

int main()
{
	srand((unsigned)time(0));
	int array[LINE][ROW] = {{0, 4, 0}, {-4, 0, -4}, {0, 4, 0}};
	int line, row, value;

/*
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			array[i][j] = (int)rand();
		}
	}
*/

#ifdef _DEBUG
	printArray(array);
#endif
	ptrFindPoint(array, &line, &row, &value);
	printResult(line, row, value);
	refFindPoint(array, line, row, value);
	printResult(line, row, value);
}

void ptrFindPoint(int arr[LINE][ROW], int *line, int *row, int *value)
{
	int maxInRow[ROW]={arr[0][0],arr[0][1],arr[0][2]}, minInLine[LINE]={arr[0][0],arr[1][0],arr[2][0]};
	int maxAtLine[LINE]={0,0,0}, minAtRow[ROW]={0,0,0};
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LINE; j++)
		{
			if (arr[i][j] > maxInRow[i])
			{
				maxInRow[i] = arr[i][j];
				maxAtLine[i] = j;
			}
		}
		
	}
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (arr[i][j] < minInLine[i])
			{
				minInLine[i] = arr[i][j];
				minAtRow[i] = j;
			}
		}
	}
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (maxInRow[i] == minInLine[j])
			{
				*line = i;
				*row = j;
				*value = arr[i][j];
				return;
				// todo: each point -> line[], row[], value[]
			}
		}
	}
	*line = -1;
	*row = -1;
}

void refFindPoint(int arr[LINE][ROW], int &line, int &row, int &value)
{
	int maxInRow[ROW]={arr[0][0],arr[0][1],arr[0][2]}, minInLine[LINE]={arr[0][0],arr[1][0],arr[2][0]};
	int maxAtLine[LINE]={0,0,0}, minAtRow[ROW]={0,0,0};
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LINE; j++)
		{
			if (arr[i][j] > maxInRow[i])
			{
				maxInRow[i] = arr[i][j];
				maxAtLine[i] = j;
			}
		}
		
	}
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (arr[i][j] < minInLine[i])
			{
				minInLine[i] = arr[i][j];
				minAtRow[i] = j;
			}
		}
	}
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (maxInRow[i] == minInLine[j])
			{
				line = i;
				row = j;
				value = arr[i][j];
				return;
			}
		}
	}
	line = -1;
	row = -1;
}

void printResult(int line, int row, int value)
{
	if (line == -1 && row == -1)
	{
		cout << "No point" << endl;
	}
	else
	{
		cout << "Point: " << line << " " << row << " " << value << endl;
	}
}

void printArray(int arr[LINE][ROW])
{
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

/*
Result:
0 -4 0 
4 0 4
0 -4 0
Point: 0 1 -4
Point: 0 1 -4

0 4 0
-4 0 -4
0 4 0
No Point
No Point
*/

// 实在是想不清楚了，脑子不太清醒，回头再看看