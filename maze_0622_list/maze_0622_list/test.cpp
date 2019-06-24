#include "test.h"

int main()
{
	SList<int> list1;
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
	list1.SListPopFront();
	list1.SListPopFront();
	list1.Print(); 

	list1.SListPopBack();
	list1.Print();
	if (list1.SListFind(100) == 1) {
		cout << "存在值为100的结点" << endl;
	}else {
		cout << "没有" << endl;
	}

	system("pause");
	return 0;
}