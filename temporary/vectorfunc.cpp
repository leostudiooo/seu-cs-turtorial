#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
struct ValuePos
{
	T value;
	std::vector<int> pos;
	/* data */
};

template <typename T>
ValuePos<T> getMinimum(T *array){
	ValuePos<T> min;
	min.value = array[0];
	min.pos.push_back(0);
	for (int i = 1; i < sizeof(array); i++)
	{
		if (array[i] < min.value)
		{
			min.value = array[i];
			min.pos.clear();
			min.pos.push_back(i);
		}
		else if (array[i] == min.value)
		{
			min.pos.push_back(i);
		}
	}
	return min;
}

int main(){
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 1, 1, 1};
	ValuePos<int> min = getMinimum(array);
	std::cout << "Min: " << min.value << std::endl;
	std::cout << "Pos: ";
}