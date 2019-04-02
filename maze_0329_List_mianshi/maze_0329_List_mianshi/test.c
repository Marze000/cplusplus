#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef struct ListNode 
{
    int val;
	struct ListNode* next;
}	ListNode;
 
//删除链表中等于给定值 val 的所有节点。
//输入: 1->2->6->3->4->5->6, val = 6
//输出 : 1->2->3->4->5

//ListNode* removeElements(ListNode* head, int val)
//{
//	assert(head != NULL);
//	if (head == NULL)
//	{
//		return NULL;
//	}
//
//	ListNode* cur = head;
//	ListNode* newhead = NULL;
//	while (cur != NULL)
//	{
//		if (cur->val != val)
//		{
//			//尾插到newhead;
//			ListNode* node = cur->next;
//			while (node->next != NULL)
//			{
//				node = node->next;
//			}
//			node->next = node;
//		}
//		cur = cur->next;
//	}
//	return newhead;
//}
//ListNode* removeElements(ListNode* head, int val)
//{
//	if (head != NULL)
//	{
//		return head;
//	}
//3
//	struct ListNode* node = head;
//	while (node->next != NULL)
//	{
//		if (node->next->val == val)
//		{
//			struct ListNode* cur = node->next->next;
//			free(node->next);
//			node->next = cur;		
//		}
//		node = node->next;
//	}
//	
//	if (head->val == val)
//	{
//		ListNode* newhead = head->next;
//		free(head);
//		return newhead;
//	}
//	return head;
//}



////输入 : 1->2->3->4->5->NULL
////输出 : 5->4->3->2->1->NULL
//ListNode* reverseList(ListNode* head)//定义三个指针的方法
//{
//	struct ListNode* pre = NULL;
//	struct ListNode* cur = head;
//
//	while (cur != NULL)
//	{
//		ListNode* next = cur->next;
//		cur->next = pre;
//
//		pre = cur;
//		cur = next;
//	}
//	return pre;
//}

////输入 : 1->2->3->4->5->NULL
////输出 : 5->4->3->2->1->NULL
//ListNode* reverseList(ListNode* head)
//{
//	struct ListNode* newhead = NULL;
//	ListNode* cur = head;
//
//	while (cur != NULL)
//	{
//		ListNode* next = cur->next;
//		cur->next = newhead;
//		newhead = cur;
//		cur = next;
//	}
//	return newhead;
//}
//

//输入 : 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL

//ListNode* reverseList(ListNode* head)
//{
//	if (head == NULL || head->next == NULL)
//	{
//		return head;
//	}
//
//	struct ListNode* h = reverseList(head->next);
//	head->next->next = head;
//	head->next = NULL;
//	return h;
//}

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
//ListNode* middleNode(ListNode* head)
//{
//	;
//}

//删除链表中等于给定值 val 的所有节点。
//输入: 1->2->6->3->4->5->6, val = 6
//输出 : 1->2->3->4->5
ListNode* removeElements(ListNode* head, int val)
{
	if (head == NULL)
	{
		return NULL;
	}

	head->next = removeElements(head->next, val);

	if (head->val == val)
	{
		return head->next;
	}
	else
	{
		return head;
	}
}

void print(ListNode* a1)
{
	ListNode *cur = a1;
	while (cur != NULL)
	{
		printf("%d", cur->val);
		cur = cur->next;		
	}
	printf("\n");
}

int main()
{
	ListNode* a1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a3 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a4 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a5 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a6 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a7 = (ListNode*)malloc(sizeof(ListNode));
	a1->val = 1, a2->val = 2, a3->val = 6, a4->val = 3;
	a5->val = 4, a6->val = 5, a7->val = 6;
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = a6;
	a6->next = a7;
	a7->next = NULL;
	print(a1);
	removeElements(a1, 6);
	print(a1);

	
	//ListNode* p = NULL;
	//int v = 0;
	////removeElements(head, int val)
	//removeElements(p,v);
	////int* p = "1,2,6,3,4,5,6";

	//printf("%s", p);


	system("pause");
	return 0;
}