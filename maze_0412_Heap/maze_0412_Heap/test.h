#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
typedef int DataType;

//函数指针
typedef int(*Cmp)(DataType, DataType);
typedef struct Heap
{
	DataType* array;
	int capacity;
	int size;
}	Heap;

int Less(DataType x, DataType y)//如果x<y返回真
{
	return x < y ? 1 : 0;
}

int Greater(DataType x, DataType y)//如果x>y则返回真
{
	return x > y ? 1 : 0;
}

void AdjustDown(int* array, int parent, int size,Cmp cmp);
void Swap(DataType* left, DataType* right);
//扩容
void checkcapacity(Heap* hp)
{
	if (hp->capacity > hp->size){return;}

	int newcapacity = hp->capacity * 2;
	DataType* newarray = 
		(int*)malloc(sizeof(DataType)*newcapacity);

	for (int i = 0; i < hp->size; ++i)
	{
		newarray[i] = hp->array[i];
	}

	free(hp->array);
	hp->array = newarray;
	hp->capacity = newcapacity;
}

//堆的初始化
void InitHeap(Heap* hp, DataType* a, int len)
{
	assert(hp && a);
	hp->array = (DataType*)malloc(sizeof(DataType)*len);
	assert(hp->array);
	hp->capacity = len;

	for (int i = 0; i < len; ++i)
	{
		hp->array[i] = a[i];
	}
	hp->size = len;
	int parent = (len-2)>>1;
	for (; parent >= 0; --parent)
	{
		AdjustDown(hp->array, parent,len, Greater);
	}
}


void AdjustUp(int* array, int size, int child, Cmp cmp)
{
	int parent = (child - 1) >> 1;
	while (child)
	{
		if (cmp(array[child] , array[parent])==0)
		{
			Swap(&array[parent], &array[child]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else { return; }
	}
}

// 向堆中插入值为data的元素 
void InsertHeap(Heap* hp, DataType data)
{
	assert(hp);
	checkcapacity(hp);
	hp->array[hp->size++] = data;
	AdjustUp(hp->array, hp->size, hp->size - 1,Less);
}

void Swap(DataType* left, DataType* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

//堆元素 向下调整
void AdjustDown(int* array,int parent,int size,Cmp cmp)
{
	int child = parent * 2 + 1;

	while (child < size)//检测左孩子的存在
	{
		if (child + 1 < size && array[child + 1] > array[child])
		{
			++child;//右孩子的存在
		}

		if (cmp(array[parent] , array[child])==0)
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else { return; }
	}
}

// 删除堆顶元素 
void EraseHeap(Heap* hp)
{
	assert(hp->size > 0);
	Swap(&hp->array[0],&hp->array[hp->size-1]);
	hp->size--;
	AdjustDown(hp->array, hp->array[hp->size - 1],hp->size, Greater);
}

// 获取堆中有效元素个数 
int SizeHeap(Heap* hp)
{
	int num = hp->size;
	return num;
}

// 检测堆是否为空 
int EmptyHeap(Heap* hp)
{
	if (hp->size == 0)
	{
		return 1;
	}
	else {return 0;}
}

// 获取堆顶元素 
DataType TopHeap(Heap* hp)
{
	assert(hp->size > 0);
	return hp->array[0];
}

// 销毁堆 
void DestroyHeap(Heap* hp)
{
	free(hp->array);
	hp->array = NULL;
	hp->size = 0;
	hp->capacity = 0;
}
void print(Heap* hp)
{
	for (int i = 0; i < hp->size; ++i)
	{
		printf("%d ", hp->array[i]);
	}
	printf("\n");
}

void Test()
{
	Heap hp;
	int a[] = { 1,2,3,4,5,6,7,8,9,0};
	int len = sizeof(a) / sizeof(a[0]);

	InitHeap(&hp, a, len);//创建堆。。。
	print(&hp);//0 1 3 4 2 6 7 8 9 5
		//		0
		//	 1  	3
		//  4     2  6   7
		//8   9  5
	//5 2 6 8 1 3 7 4 9 0
			



	//EraseHeap(&hp);
	//print(&hp);//85 16 23 52 65 41 47 65 78

	//// 向堆中插入值为data的元素 
	//InsertHeap(&hp, 90);
	//print(&hp);
	//printf("%d",SizeHeap(&hp));
	//printf("%d", TopHeap(&hp));
	//DestroyHeap(&hp);
	//// 检测堆是否为空 
	//if (EmptyHeap(&hp))
	//{
	//	printf("堆是空的！");
	//}
	//else { printf("不为空！"); }

}