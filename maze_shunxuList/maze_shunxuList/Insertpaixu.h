#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertSort(int *array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		int key = array[i];
		int end = i - 1;
		while (end >= 0 && array[end] > key)
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}

void printSort(int *array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

//1 5 6 8 7 2 4 9 0 3
  
void XierSort(int *array, int size)
{
	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i <= size; i += 3)
		{
			if (array[i] < array[i + 3])
			{
				;
			}
			else
			{
				int tmp = array[i];
				array[i] = array[i + 3];
				array[i + 3] = tmp;
			}
		}
	}



}

//void InsertSortGap(int arr[], int size, int gap)
//{
//	//预排序过程
//	for (int i = gap; i < size; i++)
//	{
//		int k = arr[i];
//		int j = 0;
//		for (j = i - gap; j >= 0; j -= gap)
//		{
//			if (arr[j] <= k)
//			{
//				break;
//			}
//			else
//			{
//				arr[j + gap] = arr[j];
//			}
//		}
//		arr[j + gap] = k;
//	}
//}
//
//void ShellSort(int arr[], int size)
//{
//	//降序
//	int gap = size;
//	while (1)
//	{
//		gap = gap / 3 + 1;//gap比较大的数->小->1停止；
//		InsertSortGap(arr, size, gap);
//		if (gap == 1) 
//		{
//			break;
//		}
//	}
//}




void SortTest()
{
	int array[] = { 1,5,6,8,7,2,4,9,0,3 };
	int len = sizeof(array) / sizeof(array[0]);

	printSort(array, len);//1 5 6 8 7 2 4 9 0 3
	InsertSort(array, len);
	printSort(array, len);//0 1 2 3 4 5 6 7 8 9
}
