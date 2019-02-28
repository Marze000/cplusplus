#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//int my_strcat(char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//	char* ret = p1;
//	while (*p1)
//	{
//		++p1;
//	}
//	while(*p2)
//	{
//		*p1++ = *p2++;
//	}
//	*p1 = '\0';
//	return* p1;
//}

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
//		int flag = 1;
//		while (*str2 !='\0')
//		{
//			if (*str2 == *str1)
//			{
//				flag = 0;
//				break;
//			}
//			else
//			{
//				++str1;
//				++str2;
//			}
//		}
//		if (1 == flag)
//		{
//			return (char*)str1;
//		}
//		++str1;
//	}
//	return NULL;
//}

char* my_strstr(const char*str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	if (*str2 == '\0')
	{
		return (char*)str1;
	}
	while (*str1 != '\0')
	{
		const char* p1 = str1;
		const char* p2 = str2;
		while (*p2 != '\0')
		{
			if (*p1 != *p2)
			{
				break;
			}
			else
			{
				p1++;
				p2++;
			}		
		}	
		if ('\0' == *p2)
		{
			return (char*)p1;
		}
		++p1;
	}
	return NULL;
}

int main()
{
	//3.实现strstr（str1，str2）; 用于判断str2是否是str1的子串（子字符串）
	//char* str1 = "hello world";
	//char* str2 = "llo";
	////strstr(str1, str2);
	//printf("%s", strstr(str1, str2));




	//4.实现strchr
	//char *strchr(const char* _Str,char _Val)
	//char *strchr(char* _Str, char _Ch)
	//	头文件：#include <string.h>
	//	功能：查找字符串_Str中首次出现字符_Val的位置
	//	说明：返回首次出现_Val的位置的指针，
	//	返回的地址是被查找字符串指针开始的第一个与Val相同字符的指针，
	//	如果Str中不存在Val则返回NULL。
	//	返回值：成功则返回要查找字符第一次出现的位置，失败返回NULL
	char _Str[20] = "abcdefabc";
	char _Val[20] = "bc";





	//5.实现strcmp
	//6.实现memcpy
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