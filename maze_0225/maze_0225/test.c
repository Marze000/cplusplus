#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	int count = 0;
//
//	while (*str)
//	{
//		count++;
//		*str++;
//	}
//	return count;
//}

//int my_strlen(char* str)
//{
//	assert(str != NULL);
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(str + 1);
//	}
//}

//int my_strlen(char* str)//循环实现
//{
//	assert(str != NULL);
//	char* p1 = str;
//	char* p2 = str;
//	while (*p2 != '\0')
//	{
//		*p2++;
//	}
//	int n = p2 - p1;
//	return n;
//}

char my_strcpy(char* p,const char* p1)//p不能受保护，不可以加const
{
	assert(p != NULL);
	assert(p1 != NULL);
	char* ret = p;
	while ((*p++ = *p1++) != '\0')
	{
		;
	}
	return *ret;
	//while (*p1)
	//{
	//	*p = *p1;
	//	++p;
	//	++p1;
	//}
	//*p = '\0';//或者写成 *p = *p1;
	
}

int main()
{
	//strlen  的模拟实现
	//长度不受限制的字符

	//char a[] = "aaabbbccc";
	//printf("%d", my_strlen(a));

	//	strcpy 赋值字符串

	char str1[20] = { 0 };
	my_strcpy(str1, "aaabbbccc");//自定义函数
	printf("%s\n",str1);
	printf("%s",strcpy(str1, "aaabbbccc"));//c语言标准库的函数



	//	strcat 连接字符串
	//	strcmp 判断字符串的大小

	//	长度受限制的字符串函数介绍
	//	strncpy
	//	strncat
	//	strncmp
	//	字符串查找
	//	strstr
	//	strtok
	//	错误信息报告
	//	strerror
	





	system("pause");
	return 0;
}