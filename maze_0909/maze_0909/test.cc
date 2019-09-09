#include <iostream>
#include <stdlib.h>
using namespace std;

//¿ìËÙÅÅĞò

int partion(int* array,int left,int right) {
	int cur = left;
	int pre = cur - 1;
	int key = array[right - 1];
	while (cur < right) {
		if (array[cur] > key && ++pre != cur) {
			swap(array[cur], array[pre]);
		}
		++cur;
	}
	if (++pre != right-1) {
		swap(array[pre], array[right-1]);
	}
	return pre;
}

void QucikSort(int* array, int start, int end) {
	if (end - start > 1) {
		int div = partion(array, start, end);
		QucikSort(array, start, div);
		QucikSort(array, div+1, end);
	}
}

int main() {
	int arr[10] = { 4,1,6,3,7,5,2,9,8,0 };
	QucikSort(arr, 0, 10);
	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}