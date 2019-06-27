#include "queue.h"
#include <stdlib.h>

int main()
{
	Queue<int> q1;
	q1.QueuePush(1);
	q1.QueuePush(2);
	q1.QueuePush(3);
	q1.QueuePush(4);
	q1.QueuePush(5);
	q1.QueueSize();
	q1.QueueBack();
	q1.QueueEmpty();
	q1.QueueFront();
	q1.QueuePop();
	system("pause");
	return 0;
}