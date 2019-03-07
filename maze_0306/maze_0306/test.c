#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr));//(2)
//}
//
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));//(4)
//}

int main()
{



	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//int *p = arr; //指针存放数组首元素的地址
	//int sz = sizeof(arr) / sizeof(arr[0]);//10
	//int i = 0;
	//for (i = 0; i < sz; i++)
	//{
	//	printf("%d ", *(p + i));//1 2 3 4 5 6 7 8 9 0
	//}


	//int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	//int *p = arr; //指针存放数组首元素的地址
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < sz; i++)
	//{
	//	printf("&arr[%d] = %p  p+%d = %p\n", i, &arr[i], i, p + i);
	//}


	//int n = 0x11223344;
	//char *pc = (char *)&n;
	//char *pi = &n;
	//*pc = 0x55;//重点在调试的过程中观察内存的变化。
	//*pi = 0;  //重点在调试的过程中观察内存的变化。


	//int n = 10;
	//char* pc = (char*)&n;
	//int* pi = &n;
	//printf("%p\n", &n);		//00CFF708
	//printf("%p\n", pc);		//00CFF708
	//printf("%p\n", pc + 1);	//00CFF709
	//printf("%p\n", pi);		//00CFF708
	//printf("%p\n", pi + 1);	//00CFF70C


	//char c = 1;
	//printf("%u\n", sizeof(c));//1
	//printf("%u\n", sizeof(+c));//4
	//printf("%u\n", sizeof(!c));//1
	//printf("%u\n", sizeof(1.0));


	//char a = 0xb6;
	//short b = 0xb600;
	//int c = 0xb6000000;

	//if (a != 0xb6)
	//{
	//	printf("%x\n", a);//	ffffffb6
	//}
	//if (b != 0xb600)
	//{
	//	printf("%x\n", b);//	ffffb600
	//}
	//if (c == 0xb6000000)
	//{
	//	printf("%x\n", c);//	b6000000
	//}



	//int a = 1;	printf("%x", a);
	//int b = 2;
	//int c = (a > b, a = b + 10, a, b = a + 1);//逗号表达式
	////int c = (0, 12, 1, 13);
	//printf("%d", c);
	
	//int i = 0, a = 0, b = 2, c = 3, d = 4;
	//i = a++ && ++b && d++;
	////i = a++||++b||d++;
	//printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
	////a = 1
	//b = 2 
	//c = 3
	//d = 5

	//char ch[1] = { 0 };
	//test2(ch);
	//int arr[10] = { 0 };
	////char ch[10] = { 0 };
	//printf("%d\n", sizeof(arr));//(1)：40
	////printf("%d\n", sizeof(ch));//(3)：10
	//test1(arr);
	//test2();
	//char ch;
	//printf("%d", sizeof(ch));
	//int num = 10;
	//int count = 0;//计数
	//while (num)
	//{
	//	if (num % 2 == 1)
	//		count++;
	//	num = num / 2; //等价于：num = num >> 1;
	//}
	//printf("二进制中1的个数为：%d\n", count);
	////1010




	//int num = -1;
	//int i = 0;
	//int count = 0;//计数
	//for (i = 0; i < 32; i++)
	//{
	//	if (((num >> i) & 1) == 1)
	//		count++;
	//}
	//printf("二进制中1的个数 = %d\n", count);


	//int num = -1;
	//int i = 0;
	//int count = 0;//计数
	//while (num)
	//{
	//	count++;
	//	num = num & (num - 1);
	//}
	//printf("二进制中1的个数 = %d\n", count);


	//int a = -10;
	//int *p = NULL;
	////printf("%d\n", !2);
	////printf("%d\n", !0);
	//a = -a;
	//p = &a;
	////printf("%d\n", sizeof(a));
	////printf("%d\n", sizeof(int));
	//printf("%d\n", sizeof a);//这样写行不行？
	//printf("%d\n", sizeof int);//不行；







	system("pause");
	return 0;
}