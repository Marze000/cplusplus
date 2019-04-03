#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int SListDataType;

//定义的不是链表的结构体，而是链表中一个节点的结构体
typedef struct ListNode
{
	SListDataType value;	//保存的值
	struct ListNode *next;  //保存下一结点的地址
}	Node;

typedef struct SList
{
	Node *first;//Node *head;
}	SList;

//初始化
void SListInit(SList *s)
{
	assert(s != NULL);
	s->first = NULL;
}

void SListInit2(SList *s)
{
	assert(s != NULL);
	s->first = NULL;
}

void Test()
{
	SList list;
	SListInit(&list);
}

//头插
void SListPushFront(SList *s, SListDataType v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = s->first;
	s->first = node;
}


void SListPushFront2(SList *p, SListDataType v)
{
	assert(p != NULL);
	Node * node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = p->first;
	p ->first = node;

	if (p->first == NULL)
	{
		p->first = node;
	}
}
//尾插
void SListPushBack(SList *s, SListDataType v)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;

	if (s->first == NULL)
	{
		s->first = node;
		return;
	}

	//链表中至少有一个结点
	Node* cur = s->first;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = node;
}


void SListPushBack2(SList *p, SListDataType v)
{
	assert(p != NULL);
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;

	if (p->first == NULL)
	{
		p->first = node;
	}

	Node* cur = p->first;
	while (cur != NULL)
	{
		cur = cur->next;
	}
	cur->next = node;
}
//头删
void SListPopFront(SList *s)
{
	assert(s != NULL);		 //不能没有链表
	assert(s->first != NULL);//不能没有结点
	Node *next = s->first->next;
	free(s->first);
	s->first = next;
}

void SListPopFront(SList *p)
{
	assert(p != NULL);
	if (p->first == NULL)
	{
		return;
	}

	if (p->first->next == NULL)
	{
		free(p->first);
		return;
	}

	Node* cur = p->first->next;
	free(p->first);
	p->first = cur;
}

//尾删
void SListPopBack3(SList *s)
{
	assert(s != NULL);
	assert(s->first != NULL);

	if (s->first->next == NULL)//链表中只有一个结点
	{
		free(s->first);
		s->first = NULL;
		return;
	}

	// 1 -> 5 -> 6 -> 2 -> 4 -> NULL
	// 1    2    3    4    5    6  
	Node *cur = s->first;
	for (; cur->next->next != NULL;cur = cur->next)
	{
		;
	}
	//cur 就是倒数第二个结点
	//cur->next->next = NULL
	free(cur->next);
	cur->next = NULL;
}

//尾删
void SListPopBack2(SList *s)
{
	//只有一个结点
	if (s->first->next == NULL)
	{
		free(s->first);
		s->first = NULL;
	}

	//至少一个结点
	else
	{
		Node* cur = s->first;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void SListPopBack(SList *p)
{
	assert(p != NULL);
	if (p->first == NULL)
	{
		return;
	}

	Node* cur = p->first;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

//反转链表
//   1  ->  5  ->  4  ->  6  ->  8  ->  9  -> NULL
//           ->              cur
//       ->          node
//   1  <-  5  <-  4  <-  6  <-  8  <-  9  <- node

struct ListNode* reverseList2(struct ListNode * head)
{
	assert(head != NULL);


}
//1.操作的是cur结点，实际更改的地方一般是cur 的前驱结点；
//2.往往第一个结点是特殊情况


//查找
Node* SListFind(SList *s, SListDataType v)
{
	for (Node *cur = s->first; cur != NULL; cur = cur->next)
	{
		if (cur->value == v)
		{
			return cur;
		}
	}
	return NULL;
}

Node* SListSearch(SList *s, SListDataType val)
{
	assert(s != NULL);

	Node* cur = s->first;
	while (cur->next != NULL)
	{
		if (cur->value == val)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//在pos的后面插入一个结点，pos 一定是链表中的结点
void SListInsertAfter(SList *s , Node* pos,SListDataType v)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}

void SeqListInsertAfter2(SList *p, Node* pos, SListDataType val)
{
	assert(p != NULL);
	assert(pos != NULL);

	Node* node = (Node*)malloc(sizeof(Node));
	node->value = val;
	node->next = pos->next;
	pos->next = node;
}
//pos 一定是链表中的结点，并且 pos 不是链表的最后一个结点
//删除 pos 后面的结点
void SListEraseAfter(SList *s, Node *pos)
{
	Node *next = pos->next;//先做一个标记
	pos->next = pos->next->next;
	free(next);
}

void SListEraseAfter2(SList *p, Node *pos)
{
	assert(p != NULL);
	assert(pos != NULL);
	//  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
	Node* cur = pos->next;
	pos->next = pos->next->next;
	free(cur);
}
//销毁整个链表
void SListDestroy(SList *s)
{
	Node *next;
	for (Node* cur = s->first; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	s->first = NULL;
}

void SListDestroy2(SList *p)
{
	assert(p != NULL);
	Node* cur = p->first;
	Node* s;
	while (cur != NULL)
	{
		s = cur->next;
		free(cur);
		cur = s;
	}
}
// 反转单链表，定义三个指针的方法，进行翻转
// 反转链表
//   NULL -> 1  ->  5  ->  4  ->  6  ->  8  ->  9  -> NULL
//   NULL <- 1  <-  5  ->  4  ->  6  ->  8  <-  9  -> NULL
//                                             pre 
//	                                                  cur   
//                                                    next
Node * Reverse(Node *head)
{
	Node *prev = NULL;
	Node *cur = head;

	while (cur != NULL)
	{
		Node *next = cur->next;

		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

struct ListNode* reverseList(struct ListNode * head)
{
	struct ListNode *newHead = NULL;
	struct ListNode *cur = head;
	while (cur != NULL)
	{
		struct ListNode* node = cur;
		cur = cur->next;

		//把node 插入到新链表 newHead
		node->next = newHead;
		newHead = node;
	}
	return newHead;
}

//删除v所对应的结点
void SListRemove(SList *s, SListDataType v)
{
	if (s->first == NULL)
	{
		//链表为空
		return;
	}

	if (s->first->value == v)
	{
		//v就是第一个结点的情况
		Node *next = s->first->next;
		free(s->first);
		s->first = next;
		return;
	}
	Node *cur = s->first;
	while (cur->next != NULL)
	{
		if (cur->next->value == v)
		{
			Node *next = cur->next->next;
			free(cur->next);
			cur->next = next;
			return;
		}
		cur = cur->next;
	}
}

//删除v对应的所有结点
struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
	{
		return NULL;
	}

	//先不管第一个结点的情况
	struct ListNode* cur = head;
	while (cur->next != NULL)
	{
		if (cur->next->value == val)
		{
			struct ListNode* next = cur->next->next;
			free(cur->next);
			cur->next = next;
		}
		cur = cur->next;
	}

	if(head->value == val)
	{
		Node* newHead = head->next;
		free(head);
		return newHead;
	}
	return head;
}


