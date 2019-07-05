#include <iostream>
#include <stdlib.h>
using namespace std;

//插入排序
void InsertSort(int *array, int size){
	for (int i = 0; i < size; ++i){
		//每次拿到一个数字先把它保存起来
		int key = array[i];
		//end 下标的是和前一个做比较
		int end = i - 1;
		while (end >= 0 && array[end] > key){
			array[end + 1] = array[end];
			end--;
		}
		//由于进入循环会把end减一，但真正的插入是在 end+1 位置
		array[end + 1] = key;
	}
}

void InsertInto(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		int key = array[i];
		int index = i - 1;
		while (index >= 0 && array[index] > key) {
			array[index + 1] = array[index];
			--index;
		}
		array[index + 1] = key;
	}
}

int main() {
	int array[10] = { 3,5,1,8,4,9,7,2,0,6 };
	InsertSort(array, 10);
	//InsertInto(array, 10);


	for (int i = 0; i < 10; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}