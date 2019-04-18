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
//		一种特殊的线性表---只允许在前端（队头）删除，后端（队尾）插入
//													---受限制的线性表

//6. 熟悉循环队列，并分析循环队列如何判断队列满
//	顺序队列结构必须要静态或动态分配一块连续的内存空间，设置两个指针管理
//  ---一个指针指向对头，一个指向队尾
// 顺序队列是溢出现象：
	//（1）下溢：当队列为空时，做出队运算溢出的现象，常用作程序控制转移的条件--正常现象
	//（2）真上溢：当队列满时，队列无法进行插入--作进栈运算产生的空间溢出现象--要避免这种现象
	//（3）假上溢：由于入队和出队操作中，头指针只增不减，导致被删除的空间无法利用，
	//			 当队列实际个数远远小于向量空间规模时，也可能由于尾指针已经超越向量空间
	//			 的上界而不能做入队操作--
//循环队列
//	作用：  为了使已经删除的队列空间重复使用
//	方法是：无论插入或者删除操作，一旦两个指针超出了所分配的队列空间，
//	     	就让他指向这片连续空间的起始位置

//当队列为空的时候：rear=front
//当队列全占满时候：rear=front
//因此为了区别两种情况，循环队列中只能有MAXsize-1个元素；当循环队列只剩下
//一个的时候就满了，因此判空条件是，front=rear,队列满的条件是：front=(rear+1)%MaxSIZE

//判断循环队列满的方法：
//（1）另设一个布尔变量
//（2）少用一个元素空间，当入队是看尾指针是否和等于头指针，如果相等则队满
//（3）用一个计数器记录队列中元素的总数，只要队列元素等于向量空间就是队列已满


//7. 实现队列的以下基本操作
//typedef int * int ;

// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _pNext;
	int  _data;
}	QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}	Queue;

// 初始化队列 
void QueueInit(Queue* q)
{
	q->_front = q->_rear = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, int  data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));

	node->_data = data;
	node->_pNext = NULL;
	if (q->_front == NULL)
	{
		q->_front = node;
		q->_rear = node;
	}
	else
	{
		q->_rear->_pNext = node;
		q->_rear = node;
	}
}

// 队头出队列 
void QueuePop(Queue* q)
{
	QNode* second = q->_front->_pNext;
	free(q->_front);
	q->_front = second;

	if (q->_front == NULL)
	{
		q->_rear = NULL;
	}
}

// 获取队列头部元素 
int  QueueFront(Queue* q)
{
	if (q->_front == NULL)
	{
		return 0;
	}

	return q->_front->_data;
}

// 获取队列队尾元素 
int  QueueBack(Queue* q)
{
	if (q->_rear == NULL)
	{
		return 0;
	}

	return q->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	if (q->_front == NULL || q->_rear == NULL)
	{
		return 0;
	}
	int size = 0;
	for (QNode* cur = q->_front; cur != NULL; cur = cur->_pNext)
	{
		++size;
	}
	return size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	if (q->_front == NULL)
	{
		return 1;
	}
	else { return 0; }
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	QNode* cur = q->_front;
	QNode* next;
	for (; cur != NULL; cur = next)
	{
		next = cur->_pNext;
		free(cur);
	}
	q->_front = q->_rear = NULL;
}

void print1(Queue *m ,int num)
{
	QNode* cur = m->_front;
	for (; cur!=NULL;cur = cur->_pNext)
	{
		printf("%d ", cur->_data);
	}
	printf("\n");
}

void Test1()
{

	Queue m;
	QueueInit(&m);

	QueuePush(&m, 1);
	QueuePush(&m, 2);
	QueuePush(&m, 3);
	QueuePush(&m, 4);
	QueuePush(&m, 5);
	QueuePush(&m, 6);
	
	int num = QueueSize(&m);
	printf("队列里共有%d个元素\n", num);
	printf("分别是：");
	print1(&m,num);

	QueuePop(&m);
	print1(&m, num);
	
	printf("%d\n",QueueFront(&m));

	printf("%d\n", QueueBack(&m));

	if (QueueEmpty(&m))
	{
		printf("队列是空的!\n");
	}
	else { printf("不为空!\n"); }
	
	QueueDestroy(&m);
	if (QueueEmpty(&m))
	{
		printf("队列是空的!\n");
	}
	else { printf("不为空！\n"); }
}


//8. 总结栈和队列的区别
//不同点：
//（1）队列是先进先出，栈是先进后出；
//（2）队列是只能在表的后端插入，在前端删除；而栈是只能在一端进行插入删除；
//（3）遍历数据的速度不同，由于栈只能在一端取出数据，如果是最先放入的就要遍历
//	 整个栈，另外在遍历数据的时候还要开辟临时空间，保持数据在遍历前的一致性；
//	 
//	 队列是基于地址指针进行遍历，而且可以从头部或者尾部遍历，但不能同时遍历
//	 不需要开辟临时空间，
//相同点：
//（1）操作受限的线性表

//9. 栈和队列部分的在线OJ题目
//10. 将本次作业写成博客
