#include "test.h"

int main()
{
	SList list1;
	list1.SListPushBack(10);
	list1.SListPushBack(20);
	list1.SListPushBack(30);
	list1.SListPushBack(40);	
	list1.SListPushBack(50);
	list1.SListPushBack(50);
	list1.SListPushFront(4);
	list1.SListPushFront(3);
	list1.SListPushFront(2);
	list1.SListPushFront(1);
	list1.SListPushFront(0);
	list1.Print();
	list1.SListEraseV(50);
	list1.Print();
	//list1.SListPopBack();
	//list1.SListPopFront();
	//list1.Print();

	system("pause");
	return 0;
}