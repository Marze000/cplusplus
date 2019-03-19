#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//typedef struct SeqList
//{
//	int* array;		//保存指向堆上的空间的地址
//	int capacity;	//数组的容量
//	int size;		//有效数据的个数
//}SeqList;

//静态顺序表（大小固定，编译期间决定的）
typedef struct SeqList
{
	int array[100];	//容量是100
	int size;		//顺序表里的有效数据个数
					//同时也可以表示从后数下一个可用位置的下标
}	SeqList;

typedef int SLDataType;

//动态顺序表（在程序运行期间可以动态控制容量的大小）
typedef struct SeqList
{
	SLDataType *array;	//指向堆上的空间，存放数据
	int capacity;		//容量
	int size;			//有效个数
}	SeqList;

void SeqListInit(SeqList *pSeqList)//创建
{
	//期望传进来的是一个变量的地址
	//变量的地址肯定不是NULL
	assert(pSeqList != NULL);

	//开辟空间，设置容量和size
	pSeqList->capacity = 10;
	pSeqList->array = 
		(int*)malloc(sizeof(SLDataType)*pSeqList->capacity);
	//assert(pSeqList->array != NULL);
	pSeqList->size = 0;
}

void SeqListDestroy(SeqList *pSeqList)//销毁
{
	assert(pSeqList != NULL);
	assert(pSeqList->array != NULL);
	free(pSeqList->array);

	pSeqList->array = NULL;
	pSeqList->capacity = 0;
	pSeqList->size = 0;
}

//链接属性：从外部链接属性 到 内部链属性
static void CheckCapacity(SeqList *ps)
{
	//不需要扩容的情况
	if (ps->size < ps->capacity)
	{
		return;
	}

	//需要扩容。且一般情况要扩容到2倍
	int newCapacity = ps->capacity * 2;
	SLDataType *newArray =
		(SLDataType *)malloc(sizeof(SLDataType)* newCapacity);
	asset(newArray != NULL);

	//搬家
	for (int i = 0; i < ps->size; ++i)
	{
		newArray[i] = ps->array[i];
	}

	//释放原来的空间，绑定新空间
	free(ps->array);
	ps->array = newArray;
	ps->capacity = newCapacity;
}

//增删查改
void SeqListPushBack(SeqList *pSeqList, SLDataType value)//尾插
{
	CheckCapacity(pSeqList);
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}

void SeqListPushFront(SeqList *pSeqList, SLDataType value)	//头插
{
	CheckCapacity(pSeqList);
	//i 是空间的下标
	for (int i = pSeqList->size; i >= 1; --i)
	{
		pSeqList->array[i] = pSeqList->array[i-1];
	}

	pSeqList->array[0] = value;
	pSeqList->size++;
}

void SeqListPopInsert(SeqList *ps, int pos, SLDataType value)
{//根据下标pos做插入
	CheckCapacity(ps);
	//pos[0,size]  i 是数据的下标
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->array[i + 1] = ps->array[i];
	}

	ps->array[pos] = value;
	ps->size++;
}

void SeqListPopBack(SeqList *ps)
{//尾删
	assert(ps->size > 0);
	ps->size--;
}

void SeqListPopFront(SeqList *ps)
{//头删
	assert(ps->size > 0);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

void SeqListErase(SeqList *ps, int pos)
{//删除pos下标所对应的值
	assert(ps->size > 0);
	//[0,size-1]

	for (int i = pos + 1; i < ps->size; i++)
	{
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

int SeqListSearch(const SeqList *ps, SLDataType value)//查找
{
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->array[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void SeqListModify(SeqList *ps, int pos, SLDataType value)
{
	//修改 pos 下标所在的值为 value
	assert(pos >= 0 && pos < ps->size);
	ps->array[pos] = value;
}

void SeqListRemove(SeqList *ps, SLDataType value)
{
	//删除遇到的第一个value
	int pos = SeqListSearch(ps, value);
	if (pos != -1)
	{
		SeqListErase(ps, pos);
	}
}


void SeqListRemoveAll(SeqList *ps, SLDataType value)
{
	//删除遇到的所有的value
	int i = 0; 
	int j = 0;
	for (; i < ps->size; ++i)
	{
		if (ps->array[i] != value)
		{
			ps->array[j] = ps->array[i];
			j++;
		}
	}
	ps->size = j;
}


int main()
{
	//线性表L是n个相同的类型数据元素构成的有限序列，当n==0是为空表
	//有限序列是知道长度的，并且固定；
	//在线性表中除了第一个和最后一个，其他元素都有仅有一个前驱和后驱
	//例如：An的前驱是n-1,后驱是n+1，驱代表的是元素；

	system("pause");
	return 0;
}