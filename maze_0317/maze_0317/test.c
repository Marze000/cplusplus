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
//typedef struct SeqList
//{
//	int array[100];	//容量是100
//	int size;		//顺序表里的有效数据个数
//					//同时也可以表示从后数下一个可用位置的下标
//}	SeqList;

typedef int SLDataType;

//动态顺序表（在程序运行期间可以动态控制容量的大小）
typedef struct SeqList
{
	SLDataType *array;	//指向堆上的空间，存放数据
	int capacity;		//容量
	int size;			//有效个数
}	SeqList;

//创建
void SeqListInit(SeqList *pSeqList)
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

void SeqListInit2(SeqList *p)
{
	assert(p != NULL);

	p->capacity = 10;
	p->array = (int*)malloc(sizeof(SLDataType) * 10);
	p->size = 0;
}

//销毁
void SeqListDestroy(SeqList *pSeqList)
{
	assert(pSeqList != NULL);
	assert(pSeqList->array != NULL);
	
	free(pSeqList->array);
	pSeqList->array = NULL;
	pSeqList->capacity = 0;
	pSeqList->size = 0;
}

void SeqListDestroy2(SeqList *p)
{
	assert(p != NULL);
	free(p->array);
	p->array = NULL;
	p->capacity = 0;
	p->size = 0;
}
//链接属性：从外部链接属性 到 内部链属性
static void CheckCapacity(SeqList *ps)
{
	//不需要扩容的情况
	if (ps->size <= ps->capacity)
	{
		return;
	}

	//需要扩容。且一般情况要扩容到2倍
	int newCapacity = ps->capacity * 2;
	SLDataType *newArray =
		(SLDataType *)malloc(sizeof(SLDataType)* newCapacity);
	assert(newArray != NULL);

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

void CheckCapacity2(SeqList *p)
{
	if (p->size < p->capacity)
	{
		return;
	}
	int NewCapacity = p->capacity * 2;
	int *NewArray = (int*)malloc(sizeof(int)*NewCapacity);

	for (int i = 0; i < p->size; ++i)
	{
		NewArray[i] = p->array[i];
	}

	free(p->array);
	p->array = NewArray;
	p->capacity = NewCapacity;
}
//增删查改
//尾插
void SeqListPushBack(SeqList *pSeqList, SLDataType value)
{
	CheckCapacity(pSeqList);
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}

void SeqListPushBack2(SeqList *p, SLDataType val)
{
	if (p->size = p->capacity)
	{
		CheckCapacity2(p);
	}

	p->array[p->size] = val;
	p->size++;
}
//头插
void SeqListPushFront(SeqList *pSeqList, SLDataType value)	
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

void SeqListPushFront2(SeqList *p, SLDataType val)
{
	if (p->size = p->capacity)
	{
		CheckCapacity2(p);
	}

	for (int i = p->size; i >0 ; --i)
	{
		p->array[i + 1] = p->array[i];
	}
	p->array[0] = val;
	p->size++;
}
//根据下标pos做插入
void SeqListPopInsert(SeqList *ps, int pos, SLDataType value)
{
	CheckCapacity(ps);
	//pos[0,size]  i 是数据的下标
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->array[i + 1] = ps->array[i];
	}

	ps->array[pos] = value;
	ps->size++;
}

//  sd   f   fd	   da    e     l     w
//   0   1   2     3     4     5     6      7
void SeqListPopInsert2(SeqList *p, int pos, SLDataType val)
{
	if (p->size = p->capacity)
	{
		CheckCapacity2(p);
	}
	assert(p != NULL);
	for (int i = p->size - 1; i > pos + 1; --i)
	{
		p->array[i + 1] = p->array[i];
	}

	p->array[pos] = val;
	p->size++;
}

//尾删
void SeqListPopBack(SeqList *ps)
{
	assert(ps->size > 0);
	ps->size--;
}

void SeqListPopBack2(SeqList *p)
{
	assert(p != NULL);
	assert(p->size >= 0);

	p->size--;
}

//头删
void SeqListPopFront(SeqList *ps)
{
	assert(ps->size > 0);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}


//  sd   f   fd	   da    e     l     w
//   0   1   2     3     4     5     6      7
void SeqListPopFront2(SeqList *p)
{
	assert(p != NULL);
	assert(p->size > 0);

	for (int i = 1; i < p->size + 1; ++i)
	{
		p->array[i - 1] = p->array[i];
	}

	p->size--;
}

//删除pos下标所对应的值
void SeqListErase(SeqList *ps, int pos)
{
	assert(ps->size > 0);
	//[0,size-1]

	for (int i = pos + 1; i < ps->size; i++)
	{
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

//  sd   f   fd	   da    e     l     w
//   0   1   2     3     4     5     6      7
void SeqListErase2(SeqList *p, int pos)
{
	//pos = 3
	assert(p != NULL);

	for (int i = pos + 1; i < p->size ; ++i)
	{
		p->array[i - 1] = p->array[i];
	}
	p ->size--;
}

//查找
int SeqListSearch(const SeqList *ps, SLDataType value)
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

int SeqListFind(const SeqList *p, SLDataType val)
{
	assert(p != NULL);

	for (int i= 0;i<p->size;++i)
	{
		if (p->array[i] == val)
		{
			return i;
		}
	}
	return -1;
}
//修改 pos 下标所在的值为 value
void SeqListModify(SeqList *ps, int pos, SLDataType value)
{
	assert(pos >= 0 && pos < ps->size);
	ps->array[pos] = value;
}

void SeqListModify2(SeqList *s, int pos, SLDataType val)
{
	assert(s != NULL);
	assert(pos >= 0 && pos < s->size);
	s->array[pos] = val;
}

//删除遇到的第一个value
void SeqListRemove(SeqList *ps, SLDataType value)
{
	int pos = SeqListSearch(ps, value);
	if (pos != -1)
	{
		SeqListErase(ps, pos);
	}
}

int SeqListRemove2(SeqList *p, SLDataType val)
{
	assert(p != NULL);
	for (int i = 0; i < p->size; ++i)
	{
		if (p->array[i] = val)
		{
			for (int j = i + 1; i < p->size + 1; ++j)
			{
				p->array[j - 1] = p->array[j];
			}
			p->size--;
			return 1;
		}
	}
	return 0;
}
//删除遇到的所有的value
void SeqListRemoveAll(SeqList *ps, SLDataType value)
{
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

void SeqListRemoveAll2(SeqList *p, SLDataType val)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < p->size; ++i)
	{
		if (p->array[i] != val)
		{
			p->array[j] = p->array[i];
		}
		++j;
	}
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