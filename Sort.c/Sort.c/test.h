#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void InsertSort(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{//0, 5, 1, 7, 6, 3, 4, 2, 9, 8 
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

void ShellSort(int* array, int size)
{
	int gap = 3;
	while (gap)
	{
		for (int i = gap; i < size; ++i)
		{
			int key = array[i];
			int end = i - gap;
			while (end >= 0 && array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		gap--;
	}
}

void Swap(int *left, int *right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

typedef int(*Cmp)(int, int);

int Less(int x, int y)
{
	return x > y ? 1 : 0;
}

int Great(int x, int y)
{
	return x > y ? 0 : 1;
}

void SelectSort(int *array, int size,Cmp cmp)
{
	for (int i = 0; i < size-1; ++i)
	{
		//0, 5, 1, 7, 6, 2, 4, 3, 9, 8
		int maxPos = 0;
		for (int j = 1; j < size-i; ++j)
		{
			 if(cmp(array[j], array[maxPos])==0)
			 {
				maxPos = j;
			 }
		}
		//这条if语句可写或不写
		//意思是：如果最大的元素下标正好在它的正确位置就不交换
		if (maxPos != size - i - 1)
		{
			Swap(&array[maxPos], &array[size - i - 1]);
		}
	}
}

//选择排序法
void SelectSort2(int *array, int size)
{
	int begin = 0;
	int end = size - 1;
	int j = 0;

	while (begin<end)
	{
		//3, 5, 1, 9, 6, 2, 4, 7, 8, 0 
		int maxPos = begin;
		int minPos = begin;
		for(j = begin;j<=end;j++)
		{
			if (array[j]>array[maxPos])
			{
				maxPos = j;
			}

			if (array[j]< array[minPos])
			{
				minPos = j;
			}
		}

		if (maxPos != end)
		{
			Swap(&array[maxPos], &array[end]);
		}

		if (minPos == end)
		{
			minPos = maxPos;
		}

		if (minPos != begin)
		{
			Swap(&array[minPos], &array[begin]);
		}
		end--;
		begin++;
	}
}

void AdjustDown(int *array, int size, int last)
{
	int child = last * 2 + 1;
	while (child < size)
	{
		if(child + 1 < size && array[child] > array[child + 1])
		{
			++child;
		}

		if (array[child] < array[last])
		{
			Swap(&array[child], &array[last]);
			last = child;
			child = 2 * last + 1;
		}
		else { return; }
	}
}
//堆排序
void HeapSort(int* array, int size)
{
	int last = (size - 2) / 2;
	for (; last > 0; last)
	{
		AdjustDown(array, size, last);
	} 

	//堆删除
	int end = size - 1;
	while (end>1)
	{
		Swap(&array[end], &array[0]);
		AdjustDown(array, end,0);
		end--;
	}
}

void printSort(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Test()
{
	int array[] = { 3, 5, 1, 9, 6, 2, 4, 7, 8, 0 };
	int len = sizeof(array) / sizeof(array[0]);
	printSort(array, len);
	//InsertSort(array, len);
	//ShellSort(array, len);
	//SelectSort2(array, len);

	HeapSort(array, len);
	printSort(array, len);
}