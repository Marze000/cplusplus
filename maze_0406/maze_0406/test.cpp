#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
//
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		if (A == NULL)
		{
			return false;
		}
		if (A->next == NULL)
		{
			return true;
		}

		ListNode* fast = A;
		ListNode* slow = A;
		//目的是使:慢指针走到中点的下一个的位置上
		//1->2->3->4->5->5->4->3->2->1->NULL
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		//此时fast在NULL，slow在第二个5的位置上
		ListNode* p = slow->next;
		ListNode* pp = p->next;
		//然后将5->4->3->2->1->NULL  反转并且指针指向1  
		//得到的链表是1->2->3->4->5
		while (p != NULL)
		{
			p->next = slow;
			slow = p;
			p = pp;
			pp = pp->next;
		}
		//1 ->2 ->3 ->4 ->5 ->5 <-4 <-3 <-2 <-1
		while (A !=slow)
		{
			if (A->val != slow->val)
			{
				return false;
			}
			else if (A->next == slow)
			{
				return true;
			}
			A = A->next;
			slow = slow->next;
		}
		return true;
	}
};

void print(ListNode *a1)
{
	while (a1 != NULL)
	{
		printf("%d->", a1->val);
		a1 = a1->next;
	}
	printf("\n");
}

int chkPalindrome(ListNode* A) {
	if (A == NULL)
	{
		return 0;
	}
	if (A->next == NULL)
	{
		return 1;
	}

	ListNode* pHead = A;
	ListNode* fast = pHead;
	ListNode* slow = pHead->next;
	ListNode* pp = pHead;

	//目的是使:慢指针走到中点的下一个的位置上
	//1->2->3->4->5->5->4->3->2->1->NULL
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		pp = pp->next;
	}
	//此时fast在NULL，low在第二个4的位置上

	//然后将5->4->3->2->1->NULL  反转并且指针指向1  
	//得到的链表是1->2->3->4->5
	ListNode* cur = slow;
	ListNode* p = cur->next;
	while (cur != NULL)
	{
		cur->next = pp;
		pp = cur;
		cur = p;
		p = p->next;
	}
	//1 ->2 ->3 ->4 ->5 ->5 <-4 <-3 <-2 <-1
	while (pHead != cur)
	{
		if (cur->val != pHead->val)
		{
			return 0;
		}
		else if (pHead->next == cur)
		{
			return 1;
		}
		cur = cur->next;
		pHead = pHead->next;
	}
	return 1;
}

class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		if (A == NULL)
		{
			return false;
		}
		if (A->next == NULL)
		{
			return true;
		}
		//1->2->3->4->5->5->4->3->2->1->NULL
		//递归实现：

		chkPalindrome(A->next);
		if()

	}
};

class PalindromeList {
public:
	bool chkPalindrome(ListNode* A)
	{
		int fuck = 0;
		ListNode *p = A;
		while (p->next) {
			fuck += p->val - p->next->val;
			p = p->next;
		}
		if (fuck == 0)
		{
			return 1;
		}
	}
};
//1->2->3->4->5->5->4->3->2->1->NULL
//
//public void Palindrome(ListNode head)
//{
//	//第一遍
//	p1 = head;    //用于第一遍遍历使用的指针
//	while (p != null) {
//		s.push(p.val);
//	} //第二遍
//	p2 = head;
//	while (p != null) {
//		if (p.val = s.pop()) {
//		}
//		else {
//			return false;
//		}
//		return true;
//	}
//}
#include <queue>
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		ListNode* B = A;
		int v;
		stack<int>S;
		while (B)
		{
			S.push(B->val);
			B = B->next;
		}
		while (A)
		{

			if (A->val != S.top())
			{
				return false;
			}
			A = A->next;
			S.pop();
		}
		return true;
	}
};

class Solution
{
public:
	bool isPalindrome(ListNode* head)
	{
		return isPalindrome(head, head);
	}
	bool isPalindrome(ListNode* tail, ListNode* &head)
	{
		if (NULL == tail)
		{
			return true;
		}
	}
	bool flag = isPalindrome(tail->next, head);
	if (false == falg)
	{
		return false;
	}
	if (tail->val != head->val)
	{
		return false;
	}
	head = head->next;
	return falg;
};

int main()
{
	ListNode* a1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a3 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a4 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a5 = (ListNode*)malloc(sizeof(ListNode));

	ListNode* a6 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a7 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a8 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a9 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a0 = (ListNode*)malloc(sizeof(ListNode));

	a1->next = a2; a2->next = a3; a3->next = a4; a4->next = a5; a5->next = a6;
	a6->next = a7; a7->next = a8; a8->next = a9; a9->next = a0; a0->next = NULL;

	a1->val = 1; a2->val = 2; a3->val = 3; a4->val = 4; a5->val = 5;
	a6->val = 5; a7->val = 4; a8->val = 3; a9->val = 2; a0->val = 1;


	print(a1);
	if (chkPalindrome(a1) == 0)
	{
		printf("ok!\n");
	}
	else
	{
		printf("no\n");
	}
	print(a1);

	//printf("hello");
	//Sleep(3000);

	system("pause");
	return 0;
}