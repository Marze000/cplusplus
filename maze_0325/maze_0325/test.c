#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


////头插
//void PushFront(Node* head, Node* node)
//{
//	assert(head != NULL);
//	assert(node != NULL);
//
//	node->next = head
//	head = node;
//
//}
//
////尾插
//void PushBack(Node* head, Node* node)
//{
//	assert(head != NULL);
//	assert(node != NULL);
//	node->next = NULL;
//	if(head == NULL)
//	{
//		head = node;
//	}
//	else
//	{
//		Node* last = GetLastNode(head);
//		last->next = node;
//	}
//}
//
//
//Node* Reverse(Node* head)
//{
//	Node* cur = head;
//	Node* result = NULL;
//	while (cur != NULL)
//	{
//		Node* next = cur->next;
//
//		cur->next = result;
//		result = cur;
//
//		cur = next;
//	}
//	return result;
//}

//==================================================
//栈

typedef struct Stack
{
	int array[100];
	int size;
}	Stack;

//插入,压栈
void StackPush(	Stack *s ,int v)
{
	s->array[s->size++] = v;
}

//删除,弹出,弹栈
void StackPop(Stack* s)
{
	s->size--;
}

void StackTop()
{

}


//队列
void QueneInit(satc)
{

}



int main()
{
	//链表的头插/头删/尾插/尾删		1
	//逆置							2
	//删除重复系结点/复制复杂链表	3



	system("pause");
	return 0;
}
