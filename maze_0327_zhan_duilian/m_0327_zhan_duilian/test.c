#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


////头插
//void PushFront(Node* head, Node* node)
//{
//	node->next = head;
//	head = node;
//}


//static Node* GetLastNode(Node * head)
//{
//	Node* last = head;
//	while (last->next != NULL)
//	{
//		last = last->next;
//	}
//	return last;
//}
//
////尾插
//void PushBack(Node* head, Node* node)
//{
//	node->next = NULL;
//	if (head == NULL)
//	{
//		head = node;
//	}
//	else
//	{
//		Node* last = GetLastNode(head);
//		last->next = node;
//	}
//}

//Node* Reverse(Node* head)
//{
//	Node* cur = head;//遍历链表
//	Node* result = NULL;//结果链表
//
//	while (cur != NULL)
//	{
//		Node* p = cur->next;
//
//		cur->next = result;
//		result = cur;
//
//		cur = p;
//	}
//	return result;
//}

//=================================================================//

//栈和队列
//静态顺序表
typedef struct Stack
{
	int array[100];
	int size;//数据个数，下标
}	Stack;

//初始化
void StackInit(Stack *s)
{
	s->size = 0;
}

//销毁
void StackDestroy(Stack *s)
{
	s->size = 0;
}

//插入,压栈
void StackPush(Stack* s,int v)
{
	s->array[s->size++] = v;
}

//删除,弹出，弹栈
void StackPop(Stack* s)
{
	s->size--;
}

//返回栈顶元素，不需要删除栈顶元素
int StackPop(Stack* s)
{
	return s->array[s->size - 1];
}

//返回栈内元素个数
int StackTop(Stack* s)
{
	return s->size;
}

//返回栈内是否是空栈，返回0表示不是空，返回非0表示是空
int StackEmpty(Stack* s)
{
	return !(s->size);
}

//==================================================================
//队列

typedef struct Node
{
	int value;
	struct Node* next;
}	Node;

typedef struct Queue
{
	Node* head;//链表的第一个结点
	Node* last;//链表的最后一个结点
}	Queue;

void QueueInit(Queue *q)
{
	q->head = q->last = NULL;
}

void QueueDestroy(Queue *q)
{
	Node* cur, *next;
	for (cur = q->head; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	q->head = q->last = NULL;
}


void QueuePush(Queue *q, int v)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	if (q->head == NULL)
	{
		q->head = node;
		q->last = node;
	}
	else
	{
		q->last->next = node;
		q->last = node;
	}
}

//删除
void QueuePop(Queue *q)
{
	Node* second = q->head->next;
	free(q->head);
	q->head = second;
	// last需要变更

	//因为可能链表只有一个结点，
	if(q->head == NULL)
	{
		q->last = NULL;
	}
}

int QueueFront(Queue* q)
{
	return q->head->value;
}

int QueueSize(Queue* q)
{
	int size = 0;
	for (Node* c = q->head; c != NULL; c = c->next)
	{
		size++;
	}
	return size;
}

int QueueEmpty(Queue *q)
{
	if (q->head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//=============================================================
//面试题1.

int main()
{


	system("pause");
	return 0;
}