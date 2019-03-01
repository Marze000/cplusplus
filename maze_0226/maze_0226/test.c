#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


//char* my_strstr(const char*str1, const char* str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	if (*str2 == '\0')
//	{
//		return (char*)str1;
//	}
//
//	while (*str1 != '\0')
//	{
//		const char* p1 = str1;
//		const char* p2 = str2;
//		while (*p2)
//		{
//			if (*p2 != *p1)
//			{
//				++p1;
//			}
//		}
//
//
//	}
//	return NULL;
//}

//char* my_strstr(const char*str1, const char* str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	if (*str2 == '\0')
//	{
//		return (char*)str1;
//	}
//	while (*str1 != '\0')
//	{
//		const char* p1 = str1;
//		const char* p2 = str2;
//		while (*p2 != '\0')
//		{
//			if (*p1 != *p2)
//			{
//				break;
//			}
//			else
//			{
//				p1++;
//				p2++;
//			}
//		}
//		if ('\0' == *p2)
//		{
//			return (char*)str1;
//		}
//		++str1;
//	}
//	return NULL;
//}

//int my_strncmp(const char* str1, const char* str2, int n)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	int m = 1;		
//	while ((*str1 != '\0')&&(*str2 != '\0')&& (m<=n-1))
//	{
//		if (*str1 < *str2)
//		{
//			return -1;
//		}
//		else if (*str1 > *str2)
//		{
//			return 1;
//		}
//		else
//		{
//			++str1;
//			++str2;
//			m++;
//		}
//	}
//
//	if (*str1 < *str2)
//	{
//		return -1;
//	}
//	else if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

//int my_strcmp(const char* str1,const char* str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	while (*str1 != '\0' && *str2 != '\0')
//	{
//		if (*str1 > *str2)
//		{
//			return 1;
//		}
//		else if (*str1 < *str2)
//		{
//			return -1;
//		}
//		else
//		{
//			++str1;
//			++str2;
//		}
//	}
//	//如果是str1或者str2到结尾使循环结束，则还需进行一下判定
//	if (*str1 < *str2)
//	{
//		return -1;
//	}
//	else if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

//int my_strchr()
//{
//	
//}

//char* my_strchr(const char* str1, const char str2)
//{
//	assert(str1 != NULL);
//	while (*str1 != '\0'&& *str1 !=(char) str2)
//	{
//		++str1;
//	}
//	if (*str1 == (char)str2)
//	{
//		return (char*)str1;
//	}
//	return NULL;
//}



int main()
{
	//char* str1 = "hello world";
	//char* str2 = "llo";
	//printf("%s", my_strstr(str1, str2));

	//4.实现strchr
	//char *strchr(const char* _Str,char _Val)
	//char *strchr(char* _Str, char _Ch)
	//	头文件：#include <string.h>
	//	功能：查找字符串_Str中首次出现字符_Val的位置
	//	说明：返回首次出现_Val的位置的指针，
	//	返回的地址是被查找字符串指针开始的第一个与Val相同字符的指针，
	//	如果Str中不存在Val则返回NULL。
	//	返回值：成功则返回要查找字符第一次出现的位置，失败返回NULL
	//char str1[20] = "abcdecfabc";
	//char str2 = 'c';
	//char* ret = strchr(str1, str2);
	//printf("%s", ret);


	////5.实现strcmp
	//char str1[10] = "aaabbbaa";
	//char str2[10] = "aaabbbab";
	//int ret = my_strncmp(str1, str2, 8);
	////int n = my_strcmp(a, b);3
	//if (ret == 0)
	//{
	//	printf("相等！\n");
	//}
	//else if(ret>0)
	//{
	//	printf("str1>str2\n");
	//}
	//else
	//{
	//	printf("str1<str2!\n");
	//}
	//

	//6.实现memcpy
	//内存拷贝函数，功能是：从源内存地址的起始位置开始拷贝若干个字节到目标内存地址中

	//void* memcpy(void* dest, const void* src, size_t n);
	////从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中
	//char* src = "aaabbbcccddd";
	//char* dest = NULL;
	//int n = 6;
	//char* ret = memcpy(dest,src,6);
	//printf("%s", ret);



	//7.实现memmove

	//长度不受限制的字符串函数
	//	strcpy 复制/覆盖
	//	strcat 的功能是：连接两个char类型的字符串
	//char a[20] = "abc";
	//char b[20] = "def";
	//my_strcat(a, b);
	////strcat(a, b);
	////printf("%s\n", strcat(a, b));
	//printf("%s\n", a);
	//printf("%d", sizeof(a));



	system("pause");
	return 0;
}