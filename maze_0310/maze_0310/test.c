#include <stdio.h>
#include <stdlib.h>

//#define ADD(x,y) (x+y)

//void test()
//{
//	int i = 0;
//	int *p = (int *)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//当i是10的时候越界访问
//	}
//	free(p);
//}
//

int main()
{






	//void test()
	//{
	//	int *p = (int *)malloc(100);
	//	if (NULL != p)
	//	{
	//		*p = 20;
	//	}
	//}
	//int main()
	//{
	//	test();
	//	while (1);
	//}



	//int *p = (int *)malloc(100);
	//free(p);
	//free(p);
	//int *p = (int*)malloc(100);
	//free(p);
	//free(p);
	//int *p = (int *)malloc(100);
	//p++;
	//free(p);//p不再指向动态内存的起始位置


	//int a = 10;
	//int *p = &a;
	//free(p);


//  动态内存开辟
//	malloc

	//void* malloc(size_t size);
	//这个函数向内存申请一块连续可用的空间，并返回指向这块空间的指针。
	//如果开辟成功，则返回一个指向开辟好空间的指针。
	//如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查。
	//返回值的类型是 void* ，所以malloc函数并不知道开辟空间的类型，
	//具体在使用的时候使用者自己来决定。
	//如果参数 size 为0，malloc的行为是标准是未定义的，取决于编译器。

	//void free(void* ptr);
	//free函数用来释放动态开辟的内存。
	//如果参数 ptr 指向的空间不是动态开辟的，那free函数的行为是未定义的。
	//如果参数 ptr 是NULL指针，则函数什么事都不做。
	//int num = 4;
	//int* ptr = NULL;
	//ptr = (int*)malloc(num * sizeof(int));
	//if (NULL != ptr)//判断ptr指针是否为空
	//{
	//	int i = 0;
	//	for (i = 0; i < num; i++)
	//	{
	//		*(ptr + i) = 0;
	//	}
	//}
	//free(ptr);//释放ptr所指向的动态内存

	//int*p = NULL;
	//p = realloc(ptr, 1000);
	//if (p != NULL)
	//{
	//	ptr = p;
	//}
	////业务处理
	//free(ptr);
	//return 0;


//	free
//	calloc
//	realloc
	



	//int aa[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11 };
	////1 2 3 4 5
	////6 7 8 9 10
	//int *ptr1 = (int *)(&aa + 1);
	//int *ptr2 = (int *)(*(aa + 2));
	//printf("%d\n%d\n", *(ptr1 - 1), *(ptr2 ));
 


	//char *a[] = { "work","at","alibaba" };
	//char**pa = a;
	//pa++;
	//pa++;
	//printf("%s\n", *pa);



	//char *c[] = { "ENTER","NEW","POINT","FIRST" };
	//char**cp[] = { c + 3,c + 2,c + 1,c };
	//char***cpp = cp;
	//printf("%s\n", **++cpp);
	//printf("%s\n", *--*++cpp + 3);
	//printf("%s\n", *cpp[-2] + 3);
	//printf("%s\n", cpp[-1][-1] + 1);
	//
	
	//POINT
	//ER
	//ST
	//EW




	//printf("%s", __DATE__);
	//printf("%d", __STDC__);
	//printf("%s", __FILE__);


	system("pause");
	return 0;
}