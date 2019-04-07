#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
  
typedef struct ListNode
{
	int val;
	ListNode *next;
}	ListNode;

//A a1-> a2 -> c1 -> c2 ->c3
//B b1->b2->b3->c1->c2->c3
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	//if (headA == headB)
	//{
	//	return headA;
	//}
	//A a1-> a2 -> c1 -> c2 ->c3
	//B b1->b2->b3->c1->c2->c3

	while (headA != NULL)
	{
		ListNode* headB1 = headB;
		while (headB1 != NULL)
		{
			if (headA == headB1)
			{
				return headB1;
			}
			else
			{
				headB1 = headB1->next;
			}	
		}
		headA = headA->next;
	}
	return NULL;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	/**
	定义两个指针, 第一轮让两个到达末尾的节点指向另一个链表的头部,
	最后如果相遇则为交点(在第一轮移动中恰好抹除了长度差)
	两个指针等于移动了相同的距离, 有交点就返回, 
	无交点就是各走了两条指针的长度
	**/
	if (headA == NULL || headB == NULL) return NULL;
	ListNode* pA = headA;
	ListNode* pB = headB;
	// 在这里第一轮体现在pA和pB第一次到达尾部会移向另一链表的表头,
	//而第二轮体现在如果pA或pB相交就返回交点, 不相交最后就是null==null
	while (pA != pB)
	{
		if (pA== NULL)
		{
			pA= headB;
		}
		else
		{
			pA = pA->next;
		}
		//pA = pA == NULL ? headB : pA->next;
		if (pB== NULL)
		{
			pB= headB;
		}
		else
		{
			pB = pB->next;
		}
		//pB = pB == NULL ? headA : pB->next;
	}
	return pA;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if (headA == NULL || headB == NULL) { return NULL; }

	while (headA->next != NULL) { headA = headA->next; }
	headA->next = headB;
	while (headB->next != NULL) { headB = headB->next; }
	headB->next = headA;
	ListNode* A = headA;
	ListNode* B = headB;
	while (A != NULL && B!=NULL)
	{
		if (A == B)
		{
			return A;
		}
		A = A->next;
		B = B->next;
	}
	return NULL;
}

//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//	auto p = headA;
//	auto q = headB;
//	while (p != q) {
//		p = !p ? headB : p->next;
//		q = !q ? headA : q->next;
//	}
}
//A a1-> a2 -> c1 -> c2 ->c3
//B b1->b2->b3->c1->c2->c3
int main()
{

	getIntersectionNode


	system("pause");
	return 0;
}