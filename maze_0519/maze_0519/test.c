#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//using namespace std;

//void swap(int *a, int*b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//int main()
//{
//	int n,a_i;
//	int arr[] = { 0 };
//	cin >> n;
//	int i;
//	for(i = 0;i< 3 * n;++i)
//	{
//		cin >> a_i;
//		arr[i] = a_i;
//	}
//
//	for (int i = 0; i < 3 * n; ++i)
//	{
//		for (int j = 1; j < i - 1; ++j)
//		{
//			if (arr[j] > arr[i])
//			{
//				swap(&arr[i], &arr[j]);
//			}
//		}
//	}
//
//	int sum = 0;
//	int result = 0;
//	for (int i = 0; i < 3 * n; i+=2)
//	{
//		sum = arr[i+1];
//		result = sum + result;
//	}
//	cout << result;
//
//	system("pause");
//	return 0;
//}

int main()
{
	char str1[] = { 0 };
	char str2[] = { 0 };
	scanf("%s\n", &str1);
	scanf("%s\n", &str2);

	//hello world   orl
	//while (str2++)
	//{
	//	p1 = str1;
	//	while (p1)
	//	{
	//		if (*p1 == *str2)
	//		{
	//			p1 = '\0';
	//		}
	//		++p1;
	//	}
	//}
	//printf("%s\n", *str1);

	system("pause");
	return 0;
}