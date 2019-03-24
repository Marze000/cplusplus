#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct DNode
{
	int value;
	struct DNode *prev;//qian
	struct DNode *next;//hou
}	DNode;

//初始化
void DListInit(DNode **node)
{
	//创建头结点
	DNode* head = (DNode*)malloc(sizeof(DNode));
	head->next = head;
	head->prev = head;

	*node = head;
}

//头插
void DListPushFront(DNode* head, int v)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;

	node->next = head->next;
	node->prev = head;
	head->next->prev = node;
	head->next = node;
}

//尾插
void DListPushBack(DNode* head,int v)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;

	node->prev = head->prev;
	node->next = head;
	head->prev->next = node;
	head->prev = node;
}

//在指定位置的后面插入
void DListInsertAfter(DNode* head, DNode* pos, int v)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;

	node->prev = pos;
	node->next = pos->next;
	pos->next->prev = node;
	pos->next = node;
}

//在指定位置的前面插入
void DListInsertBefore(DNode* head, DNode* pos, int v)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;

	node->prev = pos->prev;
	node->next = pos;
	pos->prev->next = node;
	pos->prev = node;
}


//头删
void DListDelectFront(DNode*s)
{
	assert(s != NULL);
	DNode* node = s->next;
	s->next = s->next->next;
	free(node);
}

//尾删
void DListDeleteBack(DNode*head)
{
	assert(head != NULL);
	DNode* node = head->prev;

	head->prev = head->prev->prev;
	free(node);
}

//在指定pos的位置后面删除head
void DList_Delete_Pop_After(DNode* head, DNode* pos)
{
	assert(head != NULL);
	assert(pos != NULL);

	DNode* node = pos->next;
	pos->next = pos->next->next;
	pos->next->next->prev = pos;
	free(node);
}

//在指定pos的位置前面删除head
void DList_Delete_Pop_Before(DNode*head, DNode* pos)
{
	assert(head != NULL);
	assert(pos != NULL);
	
	DNode* node = pos->prev;
	pos->prev = pos->prev->prev;
	pos->prev->prev->next = pos;
	free(node);
}


int main()
{

	DNode* p;
	DListInit(&p);
	
	//头插
	DListPushFront(p, 10);
	DListPushFront(p, 20);
	DListPushFront(p, 30);
	DListPushFront(p, 40);
	//尾插
	DListPushBack(p, 50);
	DListPushBack(p, 60);
	DListPushBack(p, 70);
	DListPushBack(p, 80);
	
	//在指定位置的后面插入
	//void DListInsertAfter(p, DNode* pos, int v)

	////在指定位置的前面插入
	//void DListInsertBefore(DNode* head, DNode* pos, int v)

	////头删
	//void DListDelectFront(DNode*s)

	////尾删
	//void DListDeleteBack(DNode*head)

	////在指定pos的位置后面删除head
	//void DList_Delete_Pop_After(DNode* head, DNode* pos)

	////在指定pos的位置前面删除head
	//void DList_Delete_Pop_Before(DNode*head, DNode* pos)
	
	system("pause");
	return 0;
}