#include "test.h"

//1. 熟悉堆的概念以及特性
//2. 总结数据结构中堆与内存堆区的区别
//3. 实现堆的以下操作
//4. 用函数指针对堆进行扩展，使用户根据需要去创建大堆还是小堆

int main()
{
	Heap hp;
	int a[] = { 15,16,47,78,65,41,23,65,52,85 };
	int len = sizeof(a) / sizeof(a[0]);
	InitHeap(&hp, a, len);
	//AdjustDown(&hp, a[0], len);

	system("pause");
	return 0;
}