//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
////1. 熟悉顺序表的概念
////2. 熟悉顺序表的分类？静态顺序表和动态顺序表的区别？
////3. 实现动态顺序表的以下基本操作：
//typedef int DataType;
//
//typedef struct SeqList
//{
//	DataType* _array; // 保存顺序表中有效元素个数 
//	int _capacity; // 空间总大小 
//	int _size; // 有效元素个数 
//}SeqList, *PSeqList;
//
////初始化顺序表
//void SeqListInit(PSeqList ps)
//{
//	assert(ps != NULL);
//	ps->_capacity = 10;//容量
//	//开辟空间
//	ps->_array = (int*)malloc(sizeof(DataType)*ps->_capacity);
//	//size为有效个数,所以起初为0
//	ps->_size = 0;
//}
//
//void SeqListDestroy(PSeqList ps)
//{
//	ps->_size = 0;
//	ps->_capacity = 0;
//	free(ps->_array);
//}
//
//// 尾插 
//void SeqListPushBack(PSeqList ps, DataType data)
//{
//	ps->_array[ps->_size] = data;
//	ps->_size++;
//}
//// 尾删 
//void SeqListPopBack(PSeqList ps)
//{
//	ps->_size--;
//}
//
//// 头插 
//void SeqListPushFront(PSeqList ps, DataType data)
//{
//	assert(ps);
//	ps->_size++;
//	for (int i = 0; i < ps->_size; ++i)
//	{
//		ps->_array[i+1] = ps->_array[i];
//	}
//	ps->_array[0] = data;
//}
//
//// 头删 
//void SeqListPopFront(PSeqList ps)
//{
//	if()
//
//}
//
//// 任意位置插入 
//void SeqListInsert(PSeqList ps, int pos, DataType datda);
//
//// 任意位置删除 
//void SeqListErase(PSeqList ps, int pos);
//
//// 检测data释放在顺序表中 
//int SeqListFind(PSeqList ps, DataType data);
//
//// 移除顺序表中第一个值为data的元素 
//void SeqListRemove(PSeqList ps, DataType data);
//
//// 移除顺序表中所有值为data的元素 
//void SeqListRemoveAll(PSeqList ps, DataType data);
//
//// 获取顺序表有效元素个数 
//int SeqListSize(PSeqList ps);
//
//// 获取顺序表的容量 
//int SeqListCapacity(PSeqList ps);
//
//// 检测顺序表是否为空 
//int SeqListEmpty(PSeqList ps);
//
//// 获取顺序表中第一个元素 
//DataType SeqListFront(PSeqList ps);
//
//// 获取顺序表中最后一个元素 
//DataType SeqListBack(PSeqList ps);
//
////4. 熟悉顺序表的优缺点
