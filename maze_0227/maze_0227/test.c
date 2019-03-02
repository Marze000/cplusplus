#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//void* memcpy(void* dest, const void* src, size_t n);函数原型
//			指向目标内存指针，指向源内存的指针，拷贝字节数
//返回一个目标内存区的指针dest
//
//void* my_memcpy(void* dest, const void* src, size_t n)
//{
//	//参数第一种判断
//	//if (dest == NULL || src == NULL || n > 0)
//	//{
//	//	fprintf(stderr, "error\n");
//	//	return NULL;
//	//}
//	//参数第二种判断
//	assert(dest != NULL);//断言判断该指针是否是空指针
//	assert(src != NULL);//因为空指针不能解引用
//	void* result = dest;//这个也可以不写
//	//循环拷贝直到第n个值
//	while (--n)
//	{
//		*(char*)dest = *(char*)src;//强制类型转换，n为字节个数
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return result;//返回result指向目标空间的起始地址
//} 
//void* show(int* arr2, int* arr1, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; ++i)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//}

void* my_memmove(void* dest, const void* src, int n)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* pdest = (char*)dest;//强制类型转换
	const char* psrc = (const char*)src;//强制类型转换
	int count = 0;
	//正常情况下从头部开始拷贝
	if (pdest < psrc )
	{
		count = 1;
		while (n--)
		{
			*pdest = *psrc;
		}
	}
	else//当出现内存覆盖时，从尾部开始向前拷贝
	{
		count = 2;
		while (n--)
		{
			*(pdest + n) = *(psrc + n);
		}
	}
	printf("%d\n", count);
	return dest;
}


int main()
{
	//memmove
	int i = 0;
	char arr1[15] = { 0 };
	char arr[10] = { 1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_memmove(arr1, arr , sz);
	for (i = 0; i < sz; ++i)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");





	//memcpy从源内存地址的起始位置开始拷贝若干个字节到目标内存地址
	//char arr1[20] = "hello world";
	//char arr2[20];
	//int sz = sizeof(arr1) / sizeof(arr1[0]);
	//memcpy(arr2, arr1,sz );
	//printf("%s", arr2);
	//char arr1[11] = { 1,2,3,4,5,6,7,8,9,10};
	//char arr2[11] = { 0 };
	//char sz = sizeof(arr1) / sizeof(arr1[0]);
	//my_memcpy(arr2, arr1, sz);
	//for (int i = 0; i < sz-1; ++i)
	//{
	//	printf("%d ", arr2[i]);
	//}
	//printf("\n");
	//
	//show(&arr2, &arr1, sz);
	//printf("%d", sz);//20

	//for (int i = 0; i < sz; ++i)
	//{
	//	printf("%d ", arr2[i]);
	//}







	//memset
	//memcmp





	//char str1[20];
	//char str2[20];
	//strcpy(str1, "To be ");//复制到str1
	//strcpy(str2, "or not to be");//同上
	//strncat(str1, str2, 6);//把str2的前6个字符串连接到str1后面去,并且返回str1
	//puts(str1);//输出str1



	system("pause");
	return 0;
}