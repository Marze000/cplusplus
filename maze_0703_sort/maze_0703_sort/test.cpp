#include "sort.h"

void test() {
	int array[10] = { 3,5,1,8,4,9,7,2,0,6 };
	//≤Â»Î≈≈–Ú
	//InsertSort(array, 10);
	//QuickSort(array, 0,10);
	QuickSortNor(array, 10);


	for (int i = 0; i < 10; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main() {
	test();

	system("pause");
	return 0;	
}