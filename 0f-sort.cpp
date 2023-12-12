#include <iostream>
#include <algorithm>

int alloc = 0;

void BubbleSort(auto *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		bool isSorted = true;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				isSorted = false;
				double temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			alloc++;
		}
		if (isSorted)
			break;
	}
}

void InsertionSort(auto *array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i, temp = array[i];
		while (j > 0 && temp < array[j - 1])
		{
			array[j] = array[j - 1];
			j--;
			alloc++;
		}
		array[j] = temp;
	}
}

void SelectionSort(auto *array, int size){
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i+1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
			alloc++;
		}
		double temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

int main()
{
	int array[5] = {2, 5, 1, 0, 8};
	SelectionSort(array, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Alloc: " << alloc << std::endl;
}