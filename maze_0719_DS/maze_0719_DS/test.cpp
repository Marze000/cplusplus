#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#if 1
typedef int(*Cmp)(int, int);


// 冒泡排序(升）
void BubbleSort(int* array,int n) {
	// 最外层代表的是一共需要多少次排序
	for (int i = 0; i < n - 1; ++i) {
		int flag = 0;
		for (int j = 0; j < n - 1 - i; ++j) {
			// 这里特别注意的是  越界访问
			if (array[j + 1] < array[j]) {
				swap(array[j], array[j + 1]);
				flag = 1;
			}
		}
		//这一轮根本就没有比较，说明已经排好序了,直接返回函数
		// 没必要进行外层循环了
		if (flag == 0) {
			return;
		}
	}
}


int BubbleSortCmp(int* arr, int size, Cmp cmp) {
	for (int bound = 0; bound < size; ++bound) {
		for (int cur = size - 1; cur > bound; --cur) {
			if (cmp(arr[cur-1], arr[cur]) == 0) {
				swap(arr[cur - 1], arr[cur]);
			}
		}
	}
}

// 升序/降序函数
int Less(int x, int y) {
	if (x > y) {
		return 1;
	}
	else {
		return 0;
	}
}

void TestBubble() {
	int arr[10] = { 2,4,6,8,0,1,3,5,7,9 };
	BubbleSort(arr, 10);
	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int arr1[10] = { 2,4,6,8,0,1,3,5,7,9 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	BubbleSortCmp(arr1, len, Less);
	for (int i = 0; i < 10; ++i) {
		cout << arr1[i] << " ";
	}
	cout << endl;

}
#endif 


int main() {


	system("pause");
	return 0;
}

