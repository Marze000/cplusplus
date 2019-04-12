#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//1. 熟悉顺序表的概念
//2. 熟悉顺序表的分类？静态顺序表和动态顺序表的区别？
//3. 实现动态顺序表的以下基本操作：
typedef int DataType;

typedef struct SeqList
{
	DataType* _array; // 保存顺序表中有效元素个数 
	int _capacity; // 空间总大小 
	int _size; // 有效元素个数 
}	SeqList,*PSeqList;

//初始化顺序表
void SeqListInit(PSeqList ps)
{
	assert(ps != NULL);
	ps->_capacity = 10;//容量
	//开辟空间
	ps->_array = (int*)malloc(sizeof(DataType)*ps->_capacity);
	//size为有效个数,所以起初为0
	ps->_size = 0;
}

void SeqListDestroy(PSeqList ps)
{
	assert(ps != NULL);
	assert(ps->_array != NULL);	
	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}

void SeqListCheck(PSeqList ps)//扩容
{
	if (ps->_capacity > ps->_size)
	{
		return;
	}

	int newcapacity = 2 * ps->_capacity; 
	DataType* new_array = (int*)malloc(sizeof(DataType)*newcapacity);
	for (int i = 0; i < ps->_size; ++i)
	{
		new_array[i] = ps->_array[i];
	}

	ps->_capacity = newcapacity;
	ps->_array = new_array;
}

// 尾插 
void SeqListPushBack(PSeqList ps, DataType data)
{
	SeqListCheck(ps);//扩容
	ps->_array[ps->_size] = data;
	ps->_size++;
}
// 尾删 
void SeqListPopBack(PSeqList ps)
{
	assert(ps->_size > 0);
	ps->_size--;
}

// 头插 
void SeqListPushFront(PSeqList ps, DataType data)
{
	SeqListCheck(ps);//扩容
	for (int i = ps->_size-1; i >=0 ; --i)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	ps->_array[0] = data;
	ps->_size++;
}

// 头删 
void SeqListPopFront(PSeqList ps)
{
	if (ps->_array == 0) { return; }

	for (int i = 1; i < ps->_size; ++i)
	{
		ps->_array[i-1] = ps->_array[i];
	}
	ps->_size--;
}

// 任意位置插入 
void SeqListInsert(PSeqList ps, int pos, DataType datda)
{
	assert(ps);
	SeqListCheck(ps);//扩容
	for (int i = ps->_size-1; i > pos-2; --i)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	//2 3 4 5 6 7
	//2 3 4 9 5 6 7
	ps->_array[pos-1] = datda;
	ps->_size++;
}

// 任意位置删除 
void SeqListErase(PSeqList ps, int pos)
{
	assert(ps);
	for (int i = pos; i < ps->_size; ++i)
	{
		ps->_array[i-1] = ps->_array[i];
	}
	//2347567
	ps->_size--;
}

// 检测data是否在顺序表中 
int SeqListFind(PSeqList ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] == data)
		{
			return 1;
		}
	}
	return 0;
}

// 移除顺序表中第一个值为data的元素 
void SeqListRemove(PSeqList ps, DataType data)
{
	assert(ps->_array>0);

	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] == data)
		{
			for (int j = i + 1; j < ps->_size; ++j)
			{
				ps->_array[j - 1] = ps->_array[j];
			}
			ps->_size--;
		}
	}
}

// 移除顺序表中所有值为data的元素 
void SeqListRemoveAll(PSeqList ps, DataType data)
{
	assert(ps);
	int i = 0;
	int j = 0;
	for (; i < ps->_size; ++i)
	{
		if (ps->_array[i] != data)
		{
			ps->_array[j] = ps->_array[i];
			++j;
		}
	}
	ps->_size = j;
}

// 获取顺序表有效元素个数 
int SeqListSize(PSeqList ps)
{
	int size = ps->_size;
	return size;
}

// 获取顺序表的容量 
int SeqListCapacity(PSeqList ps)
{
	int capacity = ps->_capacity;
	return capacity;
}

// 检测顺序表是否为空 
int SeqListEmpty(PSeqList ps)
{
	if (ps == NULL)
	{
		return 1;
	}
	return 0;
}

// 获取顺序表中第一个元素 
DataType SeqListFront(PSeqList ps)
{
	assert(ps->_size > 0);
	DataType size = ps->_array[0];
	return size;
}

// 获取顺序表中最后一个元素 
DataType SeqListBack(PSeqList ps)
{
	assert(ps);
	DataType a = ps->_array[ps->_size-1];
	return a;
}


//打印顺序表的存储数据
void print(SeqList *ps)
{
	for (int i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

int main()
{
	SeqList ps;//初始化的类型如果是一个指针类型的话，必须要初始化；
	SeqListInit(&ps);
	SeqListPushFront(&ps, 4);//头插
	SeqListPushFront(&ps, 3);
	SeqListPushFront(&ps, 2);
	SeqListPushFront(&ps, 1);
	SeqListPushBack(&ps, 5);//尾插
	SeqListPushBack(&ps, 6);
	SeqListPushBack(&ps, 7);
	SeqListPushBack(&ps, 8);
	print(&ps);			//12345678

	printf("%d\n", SeqListSize(&ps));//获取顺序表中的有效个数
	
	printf("%d\n", SeqListCapacity(&ps));// 获取顺序表的容量 

	if (SeqListEmpty(&ps))// 检测顺序表是否为空 如果为空返回1
	{
		printf("顺序表为空！\n");
	}
	else { printf("不为空\n"); }

	
	printf("%d\n",SeqListFront(&ps));//获取顺序表中第一个元素 

	printf("%d\n", SeqListBack(&ps));// 获取顺序表中最后一个元素 
	

	SeqListPopBack(&ps);//尾删
	print(&ps);			//1234567

	SeqListPopFront(&ps);//头删
	print(&ps);			//234567

	SeqListInsert(&ps, 4, 7);	// 任意位置插入 
	print(&ps);//2347567

	SeqListErase(&ps, 1);	// 任意位置删除 
	print(&ps);//347567

	SeqListErase(&ps, 4);	// 任意位置删除 
	print(&ps);//34767

	(SeqListFind(&ps, 8) == 1) ? printf("ok\n") : printf("no\n");
	(SeqListFind(&ps, 4) == 1) ? printf("ok\n") : printf("no\n");

	SeqListRemove(&ps, 4);//移除顺序表中值为data的第一个元素 
	print(&ps);
	SeqListRemoveAll(&ps, 7);//移除顺序表中所有值为data的元素 
	print(&ps);
	printf("\n");
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	print(&ps);//_capacity == 20
	
	SeqListDestroy(&ps);//销毁顺序表
	print(&ps);

	system("pause");
	return 0;
}


//4. 熟悉顺序表的优缺点