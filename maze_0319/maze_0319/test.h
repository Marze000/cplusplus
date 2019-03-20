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

//尾插
void SListPushBack2(SList *s, SListDataType v)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;


	//链表中一个结点都没有，第一个结点就是NULL
	//s->first
	if (s->first == NULL)
	{
		s->first = node;
	}
	else
	{
		Node *cur = s->first;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
	}
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

//尾删
void SListPopBack(SList *s)
{
	assert(s != NULL);
	assert(s->first != NULL);

	if (s->first->next == NULL)//链表中只有一个结点
	{
		free(s->first);
		s->first = NULL;
		return;
	}

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

//反转链表
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

//尾插
void PushBack2(SList *s, SListDataType v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	if (s->first == NULL)
	{
		s->first = node;
	}
	else
	{
		//找最后一个结点
		Node *p;
		p = s->first;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = node;
	}
}

//尾删
void PopBack2(SList *s)
{
	//没有结点，直接assert
	//只有一个结点
	//多余一个结点的情况
	if (s->first->next == NULL)
	{
		free(s->first);
		s->first = NULL;
	}
	else
	{
		//删除最后一个结点，找到倒数第二个结点
		Node *p = s->first;
		while (p->next->next != NULL)
		{
			p = p->next;
		}

		free(p->next);
		p->next = NULL;
	}
}

//1.操作的是cur结点，实际更改的地方一般是cur 的前驱结点；
//2.往往第一个结点是特殊情况

/*
一种方法：1->2->3->NULL
		  () ->1->2->3->NULL

	Node *fake_node = malloc(sizeof(Node));
	fack_node->next = first;

//进行需要的操作，所有真实的结点都有前驱结点
	free(fake_node);

*/

//查找
Node *SListFind(SList *s, SListDataType v)
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

//在pos的后面插入一个结点，pos 一定是链表中的结点
void SListInsertAfter(SList *s , Node* pos,SListDataType v)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}

//pos 一定是链表中的结点，并且pos 不是链表的最后一个结点
void SListEraseAfter(SList *s, Node *pos)
{
	Node *next = pos->next;//先做一个标记
	pos->next = pos->next->next;
	free(next);
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

// 反转单链表，定义三个指针的方法，进行翻转
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
		else
		{
			cur = cur->next;
		}
	}
	if (head->value == val)
	{
		Node* newHead = head->next;
		free(head);
		return newHead;
	}
	else
	{
		return head;
	}
}


