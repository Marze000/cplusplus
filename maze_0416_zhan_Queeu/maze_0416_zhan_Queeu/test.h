#pragma once
//1. 熟悉栈的概念以及特性
//		（0）它是一种运算符受限的线性表，因为（2）
//		（1）像水桶呈东西一样，先进后出，后进先出	
//		（2）栈顶是可以操作的一端，栈底不可操作！
//		push压入，top弹出
//		栈具有记忆作用，对栈的插入与删除操作中，不需要改变栈底指针
//		
//2. 数据结构中栈与程序中栈有什么不同？
//@1数据结构的栈：管理数据的一种手段或者是方法！可以用来存放数据和地址；
//@2内存中的栈：是确切存在的物理结构，是用来存放不同数据的内存空间；
//				由系统自动分配和释放的，由高地址向低地址扩展的数据机构
//				是一段连续的内存区域，是对数据结构栈这种手段的实现！
//		一般来说：栈存放的是常量，栈中分配局部变量空间

//3. 实现栈的以下接口：
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;
	int _capacity;
	int _top; // 标记栈顶位置 
}Stack;

// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_capacity = 10;
	ps->_top = 0;
	ps->_array = 
		(SDataType*)malloc(sizeof(SDataType)*ps->_capacity);
}

// 入栈 
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);

	ps->_array[ps->_top++] = data;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	ps->_array[ps->_top--];
	
}

// 获取栈顶元素 
SDataType StackTop(Stack* ps)
{
	SDataType a = ps->_array[ps->_top-1];
	return a;
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	int count = 0;
	for (int i = 0; i < ps->_top; ++i)
	{
		++count;
	}
	return count;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return 1;
	}
	else{return 0;}
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->_array == NULL){return;}
	ps->_capacity = 0;
	ps->_top = 0;
	free(ps->_array);
	ps->_array = NULL;
	ps = NULL;
}

void print(Stack *ps)
{
	assert(ps);
	for (int i = 0; i < ps->_top; ++i)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void Test()
{
	Stack s;
	StackInit(&s);

	//压栈
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPush(&s, 7);
	StackPush(&s, 8);
	print(&s);
	if (StackEmpty(&s) == 0) 
	{ 
		printf("不为空!");
	}
	else { printf("为空！"); }
	printf("\n");
	
	StackPop(&s);// 出栈 
	//StackPop(&s);
	//StackPop(&s);
	//StackPop(&s);
	print(&s);

	//获取栈顶元素 
	printf("%d\n", StackTop(&s));

	//获取栈中有效元素个数 
	printf("%d\n", StackSize(&s));

	// 销毁栈 
	StackDestroy(&s);
	
	// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
	if (StackEmpty(&s) == 0)
	{
		printf("不为空!");
	}
	else { printf("为空！"); }

}

//4. 栈的应用：括号匹配、逆波兰表达式、栈与递归
//5. 熟悉队列的概念以及特性
//6. 熟悉循环队列，并分析循环队列如何判断队列满
//7. 实现队列的以下基本操作
//typedef int * QDataType;
//
//// 链式结构：表示队列 
//typedef struct QListNode
//{
//	struct QListNode* _pNext;
//	QDataType _data;
//}QNode;
//
//// 队列的结构 
//typedef struct Queue
//{
//	QNode* _front;
//	QNode* _rear;
//}Queue;
//
//// 初始化队列 
//void QueueInit(Queue* q);
//
//// 队尾入队列 
//void QueuePush(Queue* q, QDataType data);
//
//// 队头出队列 
//void QueuePop(Queue* q);
//
//// 获取队列头部元素 
//QDataType QueueFront(Queue* q);
//
//// 获取队列队尾元素 
//QDataType QueueBack(Queue* q);
//
//// 获取队列中有效元素个数 
//int QueueSize(Queue* q);
//
//// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
//int QueueEmpty(Queue* q);
//
//// 销毁队列 
//void QueueDestroy(Queue* q);

//8. 总结栈和队列的区别
//9. 栈和队列部分的在线OJ题目
//10. 将本次作业写成博客
