#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void MergeData(int* arr, int left, int mid, int right, int* temp) {
	int begin1 = left;
	int begin2 = mid;
	int end1 = mid;
	int end2 = right;
	int index = left;
	while (begin1 < end1 && begin2 < end2) {
		if (arr[begin1] < arr[begin2]) {
			temp[index++] = arr[begin1++];
		}
		else{
			temp[index++] = arr[begin2++];
		}
	}
	while (begin1 < end1) {
		temp[index++] = arr[begin1++];
	}
	while (begin2 < end2) {
		temp[index++] = arr[begin2++];
	}
}

void MergeSort(int *arr, int left, int right, int* temp) {
	if (right - left <= 1) {
		return;
	}
	int mid = left + (right - left) / 2;
	MergeSort(arr, left, mid, temp);
	MergeSort(arr, mid,right, temp);
	MergeData(arr, left, mid, right, temp);
	memcpy(arr + left, temp + left, sizeof(arr[0])*(right - left));
}
int main() {
	int arr[10] = { 0,2,4,6,8,1,3,5,7,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int* temp = new int[sizeof(arr)];
	MergeSort(arr, 0, size, temp);
	for (auto&e : arr) {
		cout << e << ' ';
	}
	cout << endl;
	delete[] temp;

	system("pause");
	return 0;
}
