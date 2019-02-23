#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void find(int arr[], int n, int *sum1, int *sum2)
//{
//	int sum = arr[0];//
//	int j = 0;
//	int sum0 = 0;
//	for (int i = 1; i < n; ++i)
//	{
//		sum = sum ^ arr[i];
//		sum0 = sum;
//	}
//	for (j = 0; j < 32; j++)
//	{
//		if (sum & 1 == 0)
//		{
//			sum >>= 1;
//		}
//		else if(sum & 1==1)
//		{
//			break;
//		}
//	}
//	for (int s = 0; s < n; s++)
//	{
//		int tmp = 0;
//		tmp = arr[s] >> j;
//		if (tmp & 1 == 1)
//		{
//			int x = 0;
//			if (x == 0)
//			{
//				*sum1 = arr[s];
//			}
//			else
//			{
//				*sum1 = arr[s] ^ *sum1;
//			}
//		}
//	}
//}

void sort(int arr[], int n)//冒泡法的排序（从小到大）
{
	int i, j;
	for (i = 0; i < n - 1; ++i)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void func(int arr[], int n, int *num1, int *num2)
{
	int tmp = 0;//创建一个临时变量
	for (int i = 0; i < n; i = i + 2)
	{
		if (arr[i] == arr[i + 1])
		{
			continue;
		}
		else
		{
			if (tmp == 0)
			{
				*num1 = arr[i];
				i = i + 1;
			}
			else if (tmp == 1)
			{
				*num2 = arr[i];
				i = i + 1;
			}				
			tmp++;
		}
	}
}

int main()
{
	//1.一个数组中只有两个数字是出现一次， 
	//  其他所有数字都出现了两次。
	//	找出这两个数字，编程实现。
	int a[10] = { 1,4,5,8,56,4,8,5,7,1 };//56  7
	int num1, num2;

	sort(a, 10);

	for (int i = 0; i < 10; i++)//打印出已经排好序的数组
	{
		printf("%d ", a[i]);
	}

	func(a, 10, &num1, &num2);
	printf("%d %d", num1, num2);




	//	2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
	//	给20元，可以多少汽水。
	//	编程实现。

	//	3.模拟实现strcpy
	//	4.模拟实现strcat



	system("pause");
	return 0;
}