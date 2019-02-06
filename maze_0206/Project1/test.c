#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* find(int* pr1, int pr2, int n, int m)
{
	int* p1;
	int* p2;
	p1 = pr1;
	p2 = pr2;
	while (p1 < pr1 + n && p2 < pr2 + m)
	{
		if (*p1 < *p2)
		{
			++p1;
		}
		else if (*p1 > *p2)
		{
			++p2;
		}
		else
		{
			return p1;
		}
	}
}

int main()
{
	int* p;
	//int arr[20] = { 0 };
	//int* p1 = arr;
	//int** p2 = &p1;
	//
	//printf("输入数据\n");
	//for (int i = 0; i < 10; ++i)
	//{
	//	scanf("%d", &arr[i]);
	//}
	//for (int j = 0; j < 10; ++j)
	//{
	//	if (j % 5 == 0)
	//	{
	//		printf("\n");
	//	}
	//	printf("%d ", *(*p2 + j));
	//}
	 
	//int a[10];
	//int* p1;
	//int** p2;
	//p1 = a;//p1 - a == 0
	//printf("%d", ++p1 - a);//1

	int a[10];
	int b[10];
	printf("输入a数组的数据值\n");
	int i = 0;
	for (; i < 10; ++i)
	{
		scanf("%d", &a[i]);
	}
	printf("输入b数组的数据值\n");
	for (i = 0; i < 10; ++i)
	{
		scanf("%d", &b[i]);
	}
	p = find(a, b, 10, 10);
	if (p)
	{
		printf("%d\n", *p);
	}
	else
	{
		printf("no find!\n");
	}

	system("pause");
	return 0;
}