#include <iostream>
#include <stdlib.h>
using namespace std;

//void swap(int& a, int& b)
//{
//	int tem = a;
//	a = b;
//	b = tem;
//}
//
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}

void reverse_array(int a[], int cnt)
{
	int first = 0;
	int last = cnt - 1;
	for (; first <= last; first++, last--)
	{
		int temp = a[first];
		a[first] = a[last];
		a[last] = temp;
	}
}

int main()
{
	int a[] = { 1,2,3,4,5 };
	int len = sizeof(a) / sizeof(a[0]);
	reverse_array(a, len);
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", a[i]);
	}

	//int& ret = Add(1, 2);
	//Add(3, 4);
	//cout << "Add(1, 2) is :" << ret << endl;


	//int aa = 10;
	//int bb = 20;
	//cout << aa << "  " << bb << endl;
	//swap(aa, bb);
	//cout << aa << "  " << bb << endl;

	system("pause");
	return 0;
}