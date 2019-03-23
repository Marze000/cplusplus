#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDataType;

typedef struct ListNode 
{
	SListDataType value;
	struct ListNode *next;
}	Node;

typedef struct SList
{
	Node *first;
}	SList;



//反转链表
//      1 -> 2 -> 3 -> 4 -> 8 -> 5 -> 4 -> NULL
// pre  cur
//
Node* Reverse(Node *head)
{
	assert(head != NULL);
	Node *pre = NULL;
	Node *cur = head;

	while (cur->next != NULL)
	{
		cur->next = pre;
		pre = cur;
		cur = cur->next;
	}
	cur->next = pre;
	return cur;
}

//反转链表
struct ListNode* reverseList(struct ListNode * head)
{
	assert(head != NULL);
	struct ListNode* NewHead = NULL;
	struct ListNode* cur = head;

	while (cur != NULL);
	{
		struct ListNode* node = cur;
		cur = cur->next;

		node->next = NewHead;
		NewHead = node;
	}
	return NewHead;
}

//删除v所对应的结点
void SListRemove(SList *s, SListDataType v)
{
	assert(s != NULL);
	if (s->first == NULL)
	{
		return;
	}
	//头结点是v
	if (s->first->value == v)
	{
		Node* next = s->first->next;
		free(s->first);
		s->first = next;
		return;
	}

	Node *node = s->first;
	while (node->next != NULL)
	{
		if (node->next->value == v)
		{
			Node* next = node->next->next;
			free(node->next);
			node->next = next;
			return;
		}
		node = node->next;
	}

	//Node* node = s->first->next;
	//while (node != NULL)
	//{
	//	if (node->value == v)
	//	{
	//		Node* cur = node->next;
	//		node->next = cur;
	//		free(node);
	//		return;
	//	}
	//	node = node->next;
	//}
}

//删除v对应的所有结点
struct ListNode* removeElements(struct ListNode* head, int val)
{
	assert(head != NULL);
	if (head == NULL)
	{
		return;
	}

	struct ListNode* cur = head;
	while (cur->next != NULL)
	{
		if (cur->next->value == val)
		{
			struct ListNode* node = cur->next->next;
			free(cur->next);
			cur->next = node;
		}
		cur = cur->next;
	}
	if (head->value == val)
	{
		Node* newhead = head->next;
		free(head);
		return newhead;
	}
}

int main()
{



	system("pause");
	return 0;
}