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


//插入法排序的优化---二分查找法
void InsertSort2(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		int key = array[i];
		int end = i - 1;
		int left = 0;
		int mid = 0;
		while (left <= end)
		{
			mid = (left+end) / 2;
			if (key < array[mid])
			{
				end = mid - 1;
			}
			if(key>=array[mid])
			{
				left = mid+1;
			}
		}//0 1 2 2 3 4 4 5 6 7 8 9 12 15 32 45 58 65 85   =>  46
		for (int j = i - 1; j >= end; j--)
		{
			array[j + 1] = array[j];
		}
		array[left] = key;
	}
}

void InsertSort3(int* array, int size)
{
	for (int i = 0; i < size; i++) {
		//记录当前要比较的数
		int min = array[i];
		//左边的界限初始永远是 0
		int left = 0;
		//右边则是当前坐标的左侧一位
		int right = i - 1;
		int mid = 0;
		//while循环的作用是为了确定left 和 right的正确值，计算出要插入的正确区间，直到left和right甚至不符合正确区间的定义，那么就说明区间找到了
		while (left <= right) {
			mid = (left + right) / 2;
			//如果当前要比较的值小于中间值那么，right就是中间值的左侧一位
			if (min < array[mid])
				right = mid - 1;
			else//如果大于中间值，那么left就是中间值的右侧一位
				left = mid + 1;
		}
		//while循环结束后，从left(左侧区间值)到当前i的范围，依次从左侧向右侧赋值
		for (int j = i - 1; j >= left; j--) {
			array[j + 1] = array[j];
		}
		//最后还要记得将left位置的值替换为min
		array[left] = min;
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
		if(child + 1 < size && array[child] < array[child + 1])
		{
			++child;
		}

		if (array[child] > array[last])
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
	for (; last >= 0; --last)
	{
		AdjustDown(array, size, last);
	} 

	//堆删除
	int end = size - 1;
	while (end)
	{
		Swap(&array[end], &array[0]);
		AdjustDown(array, end,0);
		end--;
	}
}


//交换排序----冒泡排序
void BubbleSort(int *array, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 1; j < size-i; ++j)
		{
			if (array[j-1] > array[j])
			{
				Swap(&array[j-1], &array[j]);
			}
		}
	}
}

//交换排序----冒泡排序的优化
void BubbleSort2(int *array, int size)
{
	
	for (int i = 0; i < size - 1; ++i)
	{
		int ischange = 0;
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j - 1] > array[j])
			{
				Swap(&array[j - 1], &array[j]);
				ischange = 1;
			}
		}
		if (!ischange)
		{
			return;
		}
	}
}
//==========================================================================

//快速排序取基准值的优化
int GetMiddleIdx(int* array, int left, int right)
{
	int mid = (left + right) / 2;

	if (array[left] < array[right-1])
	{
		if (array[mid] < array[left])
			return left;

		else if (array[mid] > array[right-1])
			return right-1;

		else
			return mid;
	}

	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}

int Partion1(int* array, int left, int right)
{
	int middle = GetMiddleIdx(array, left, right);
	if (middle != right - 1)
	{
		Swap(&array[middle], &array[right - 1]);
	}
	
	int key = array[right - 1];
	int begin = left;
	int end = right - 1;
	while (begin < end)
	{
		while (begin<end && array[begin] <= key)
		{
			++begin;
		}
		while (begin<end && array[end] >= key)
		{
			--end;
		}

		if (begin<end)
		{
			Swap(&array[end], &array[begin]);
		}
	}

	if (begin != right - 1)
	{
		Swap(&array[end], &array[right - 1]);
	}

	return begin;
}

//挖坑
int Partion2(int *array, int left, int right)
{
	int key = array[right - 1];
	int begin = left;
	int end = right - 1;

	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
		{
			begin++;
		}

		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}

		while (begin < end && array[end] >= key)
		{
			--end;
		}

		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}
	array[begin] = key;
	return begin;

}

int	Partion3(int *array, int left, int right)
{
	int key = array[right - 1];
	int cur = left;
	int pre = cur - 1;

	while (cur < right)
	{
		if (array[cur] < key && ++pre != cur)
		{
			Swap(&array[cur], &array[pre]);
		}
		cur++;
	}
	if (++pre != right - 1)
	{
		Swap(&array[pre], &array[right - 1]);
	}
	return pre;
}

//快速排序法---大致框架
//如果一个序列接近有序---不适合用快速排序----用插入法去排序
//快速排序的最佳场景--数据越随机越好~~~
void QuickSort(int* array, int left, int right)
{
	if (right - left <= 1)
	{
		return;
	}
	
	//div是一个下标
	int div = Partion3(array, left, right);//基准值划分
	QuickSort(array, left, div);
	QuickSort(array, div + 1, right);
}

//#include <stack>	s;
//void QuickSortNor(int* array, int size)
//{
//
//	int left = 0;
//	int right = size;
//
//	stack s;
//	stackInit(&s);
//	stackpush(&s, right);
//	stackpush(&s, left);
//
//	while (!StackEmpty(&s))
//	{
//		left = StackTop(&s);
//		StackPop(&s);
//		right = StackTop(&s);
//		StackPop(&s);
//
//		if (left < right)
//		{
//			int div = Partion3(array, left, right);
//			StackPush(&s,right);
//			StackPush(&s, div + 1);
//			StackPush(&s, div);
//			Stackpush(&s, left);
//			//div 的左侧[left,div)
//			//div 的右侧[div+1,right)
//		}
//	}
//	StackDestrony(&s);
//}
//===========================================================================

//归并
void MergeData(int *array, int left, int mid, int right,int *temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;

	int index = left;

	while (begin1 < end1 && begin2<end2)
	{
		if (array[begin1] < array[begin2])
		{
			temp[index++] = array[begin1++];
		}
		else
		{
			temp[index++] = array[begin2++];
		}
	}

	while (begin1 < end1)
	{
		temp[index++] = array[begin1++];
	}

	while (begin2 < end2)
	{
		temp[index++] = array[begin2++];
	}
}

//空间复杂度O(N)
void _MergeSort(int* array, int left, int right,int* temp)
{
	if (right - left <= 1)
	{
		return;
	}

	int mid = (left+right)/2;
	_MergeSort(array, left, mid,temp);
	_MergeSort(array, mid, right,temp);
	MergeData(array, left, mid, right, temp);
	memcpy(array + left, temp + left, sizeof(array[left]) * (right - left));
}

void MergeSort(int* array, int size)
{
	int* temp = (int*)malloc(size * sizeof(array[0]));
	if (temp == NULL)
	{
		assert(0);
		return;
	}

	_MergeSort(array, 0, size, temp);
	free(temp);
}

//===========================================================================
//归并循环
void MergeSortNor(int* array, int size)
{
	int* temp = (int*)malloc(size * sizeof(array[0]));
	if (NULL == temp)
	{
		assert(0);
		return;
	}

	int gap = 1;
	while (gap<size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			
			if (mid >= size)
			{
				mid = size;
			}

			if (right >= size)
			{
				right = size;
			}

			MergeData(array, left, mid, right, temp);
		}

		memcpy(array, temp, sizeof(array[0])*size);
		gap *= 2;
	}
	free(temp);
}

//=====================================================================
//数据密集集中在某个范围内
void CountSort(int *array, int size)
{
	//选择最小的和最大的数字·O（N）	N代表的是数据个数
	int MaxValue = array[0];
	int MinValue = array[0];

	for (int i = 1; i < size; ++i)
	{
		if (array[i] > MaxValue)
		{
			MaxValue = array[i];
		}
	
		if (array[i] < MinValue)
		{
			MinValue = array[i];
		}
	}

	//申请空间·O（M）[辅助空间]·M代表是数据范围
	int Range = MaxValue - MinValue + 1;
	int* array2 = (int*)malloc(sizeof(int)*Range);
	if (array2 == NULL)
	{
		assert(0);
		return;
	}
	
	//将每一个位置置空
	memset(array2, 0, sizeof(int)*Range);

	//统计元素出现次数·O(N)
	for (int i = 0; i < size; ++i)
	{
		array2[array[i]-MinValue]++;
	}

	//往出搬移元素·O（N）
	int index = 0;
	for (int i = 0; i < Range; ++i)
	{
		while (array2[i]--)
		{
			array[index++] = i + MinValue;
		}
	}

	free(array2);
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
	int array[] = { 0,9,7,1,4,3,6,2,8,5 };
	int len = sizeof(array) / sizeof(array[0]);
	printSort(array, len);
	//InsertSort2(array, len);
	//ShellSort(array, len);
	//SelectSort2(array, len);
	//BubbleSort2(array, len);
	//HeapSort(array, len);
	//QuickSortNor(array, len);
	//BubbleSort(array, len);
	/*MergeSort(array, len);*/
	//MergeSortNor(array, len);
	CountSort(array, len);
	//MergeSortNor(array, len);
	//QuickSort(array, 0,len);
	printSort(array, len);
}

