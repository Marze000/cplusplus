#include <stdio.h>
#include <stdlib.h>

struct Test//大小为：20
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;

int main()
{
	////笔试1
	//int a[5] = { 1, 2, 3, 4, 5 };
	//int *ptr = (int *)(&a + 1);//此时的指针指向末尾了，5的后面
	//printf("%d,%d", *(a + 1), *(ptr - 1));
	//////2  5

	//笔试2
	//struct Test//大小为：20
	//{
	//	int Num;
	//	char *pcName;
	//	short sDate;
	//	char cha[2];
	//	short sBa[4];
	//}*p;
	//p = NULL;
	//printf("%p\n", p+0x1);//00 00 00 14
	//printf("%p\n", (unsigned long)p + 0x1);//00 00 00 01
	//printf("%p\n", (unsigned int*)p + 0x1);//00 00 00 04

	//100001
	//100001
	//100004


	//笔试题3
	//int a[4] = { 1, 10, 3, 4 };

	//int *ptr1 = (int *)(&a + 1);
	//int *ptr2 = (int *)((int)a + 1);
	//printf("%x,%x", ptr1[-1], *ptr2);
	//////4 , 2000000

	//笔试题4
	//int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	//int *p;
	//p = a[0];
	//printf("%d", p[0]);
	//
	//1 3
	//5 0
	//0 0


	////笔试题5
	//int a[5][5];
	//int(*p)[4];
	//p = a;
	//printf("a_ptr=%#p,p_ptr=%#p\n", &a[4][2], &p[4][2]);
	//printf("%p,%d\n", &a[4][2] - &p[4][2], &a[4][2] - &p[4][2]);

	//笔试题6


	system("pause");
	return 0;
}