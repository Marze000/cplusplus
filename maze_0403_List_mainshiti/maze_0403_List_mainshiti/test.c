#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode 
{
	int val;
	struct ListNode* next;
}	ListNode;

//编写代码，以给定值x为基准将链表分割成两部分，
//所有小于x的结点排在大于或等于x的结点之前
//给定一个链表的头指针 ListNode* pHead，
//请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。
// 1->2->5->7->3->9->4    int x = 5


//ListNode* partition(ListNode* pHead, int x)
//{
//	ListNode* cur = pHead;
//	ListNode* last_small = NULL;
//	ListNode* last_big = NULL;
//	ListNode* first_small = NULL;
//	ListNode* first_big = NULL;
//	
//	while (cur != NULL)
//	{
//		if (cur->val < x)//x=5 
//		{
//			if (last_small == NULL)
//			{
//				first_small = last_small = cur;
//			}
//			else
//			{
//				last_small->next = cur;
//				last_small = cur;
//			}
//		}
//		else
//		{
//			if (last_big == NULL)
//			{
//				first_big = last_big = cur;
//			}
//			else
//			{
//				last_big->next = cur;
//				last_big = cur;
//			}
//		}
//		cur = cur->next;
//	}
//
//	if (last_big != NULL)
//	{
//		last_big->next = NULL;
//	}
//	if (last_small != NULL)
//	{
//		last_small->next = first_big;
//	}
//	else
//	{
//		first_small= first_big;
//	}
//	return first_small;
//}
//
////// 1->2->5->7->3->9->4    int x = 5
////ListNode* partition(ListNode* pHead, int x)
////{        
////	ListNode* beforeStart=NULL;
////	ListNode* beforeEnd=NULL;
////	ListNode* afterstart = NULL;
////	ListNode *afterEnd = NULL;
////	ListNode* headval;
////	while(pHead)
////	{            
////		headval=pHead->next;
////		if(pHead->val<x) 
////		{                
////			if (beforeEnd == NULL)
////			{
////				beforeEnd = beforeStart = pHead;
////			}
////			else
////			{                    
////				beforeEnd->next=pHead;
////				beforeEnd=pHead;
////			}            
////		}           
////		else
////		{                
////			if(afterstart==NULL)
////			{                    
////				afterstart = afterEnd = pHead;
////			}                
////			else
////			{                    
////				afterEnd->next=pHead;
////				afterEnd=pHead;
////			}            
////		}            
////		pHead=headval;
////	}        
////	if (afterEnd)
////	{
////		afterEnd->next = NULL;
////	}
////	if (beforeEnd != NULL)
////	{
////		beforeEnd->next = afterstart;
////	}
////	else
////	{
////		beforeStart = afterstart;
////	}
////	return beforeStart;
////}
//
//void print(ListNode* p)
//{
//	while (p != NULL)
//	{
//		printf("%d->", p->val);
//		p = p->next;
//	}
//	printf("NULL\n");
//}

////在一个排序的链表中，存在重复的结点，
////请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
////例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
//ListNode* deleteDuplication(ListNode* pHead)
//{
//	ListNode* cur = pHead;
//	ListNode* res = pHead + 1;
//	while (res != NULL)
//	{
//		if (cur->val == res->val)
//		{
//
//
//
//		}
//		cur = cur->next;
//		res = res->next;
//	}
//
//
//
//
//}

////在一个排序的链表中，存在重复的结点，
////请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
////例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	if (pHead != NULL && pHead->next == NULL)
	{
		return pHead;
	}

	ListNode* current;
	if (pHead->next->val == pHead->val)
	{ 
		current = pHead->next->next; 
		while (current != NULL && current->val == pHead->val)
		{
			current = current->next;
			return deleteDuplication(current);
		}
	} 
	else
	{
		current = pHead->next; 
		pHead->next = deleteDuplication(current);
		return pHead; 
	}
}

//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，
//判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。
//保证链表长度小于等于900。
//测试样例： 1->2->2->1
//返回：true
chkPalindrome(ListNode* A)
{
	
}

Node* buildTree2(char postorder[], char inorder[], int size)
{

}

int main()
{
	////1->2->5->7->3->9->4    int x = 5
	//ListNode* a1 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* a2 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* a3 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* a4 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* a5 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* a6 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* a7 = (ListNode*)malloc(sizeof(ListNode));
	//a1->next = a2, a1->val = 1;
	//a2->next = a3, a2->val = 2;
	//a3->next = a4, a3->val = 5;
	//a4->next = a5, a4->val = 7;
	//a5->next = a6, a5->val = 3;
	//a6->next = a7, a6->val = 9;
	//a7->next = NULL, a7->val = 4;

	////1->2->5->7->3->9->4    int x = 5
	//print(a1);
	//ListNode* p1 = partition(a1, 5);

	//while (p1)
	//{
	//	printf("%d->", p1->val);
	//	p1 = p1->next;
	//}
	//printf("NULL");
	////1->2->3->4->5->7->9
	//printf("\n");




	system("pause");
	return 0;
}