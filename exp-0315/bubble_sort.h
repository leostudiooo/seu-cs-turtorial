#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

template <typename T>
void BubbleSort(T *arr, int RANGE) {
	for (int i = 0; i < RANGE - 1; i++) {
		for (int j = 0; j < RANGE - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

#endif // BUBBLE_SORT_H_