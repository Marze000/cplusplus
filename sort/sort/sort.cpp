#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#if 0
void Bubble(int *arr, int size) {
	for (int i = 0; i < size-1; ++i) {
		for (int j = 1; j < size - i; ++j) {
			// 降序
			if (arr[j] > arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}

void BubbleSort(int* arr, int size) {
	int bound = 0;
	for (; bound < size - 1; ++bound) {
		for (int cur = size - 1; cur > bound; --cur) {
			//升序
			if (arr[cur - 1] > arr[cur]){
				swap(arr[cur - 1], arr[cur]);
			}
		}
	}
}

void AdjustDown(int *array, int size, int last) {
	int child = last * 2 + 1;
	while (child < size) {
		if (child + 1 < size && \
			array[child] > array[child + 1]) {
			++child;
		}
		if (array[child] < array[last]) {
			swap(array[child], array[last]);
			last = child;
			child = 2 * last + 1;
		}
		else { return; }
	}
}
//堆排序
void HeapSort(int* array, int size) {
	int last = (size-2)/2;
	for (; last >= 0; --last) {
		AdjustDown(array, size, last);
	}
	//堆删除
	int end = size - 1;
	while (end) {
		swap(array[end], array[0]);
		AdjustDown(array, end, 0);
		end--;
	}
}
#endif


int Partion2(int *array, int left, int right) {
	int key = array[right - 1];
	int begin = left;
	int end = right - 1;
	while (begin < end) {
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		array[end] = array[begin];
		end--;
		while (begin < end && array[end] >= key) {
			--end;
		}
		array[begin] = array[end];
		begin++;
	}
	array[begin] = key;
	return begin;
}

void QuickSort(int* array, int left, int right) {
	if (right - left <= 1) {
		return;
	}
	int div = Partion2(array, left, right);
	// 然后分别对 [left,div] 和 [div+1,right] 中的元素排序
	QuickSort(array, left, div);
	QuickSort(array, div + 1, right);
}

int main() {
	int arr[] = { 1,3,4,6,2,7,9,0,8,5 };
	QuickSort(arr, 0, 10);
	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}