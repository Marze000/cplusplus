#include "list.h"
using namespace List;

int main()
{
	SeqList list1;
	list1.SeqListPushBack(1);
	list1.SeqListPushBack(2);
	list1.SeqListPushBack(3);
	list1.SeqListPushBack(4);
	list1.SeqListPopBack();

	system("pause");
	return 0;
}