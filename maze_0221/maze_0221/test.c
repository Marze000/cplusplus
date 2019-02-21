#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//void* ZuoXuan(char *p, int n)
//{
//	char *p1 = p;//创建一个新的指针变量
//	int len = strlen(p1) - 1;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; ++i)
//	{
//		char tmp = p1[0];//创建一个临时变量并把第一个字符赋值到tmp中
//		for (j = 0; j < len; ++j)
//		{
//			p1[j] = p1[j + 1];//字符依次前进一个位置
//		}
//		p1[len] = tmp;//将临时变量赋值到最后一个位置
//	}
//	printf("%s\n", p1);
//}

//int judge(char str1[], char str2[])
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(str1);
//
//	for (j = 1; j <= len; ++j)
//	{
//		int tmp = str1[0];
//		for (i = 0; i < len - 1; ++i)
//		{
//			str1[i] = str1[i + 1];
//		}
//		str1[len - 1] = tmp;
//		if (strcmp(str1, str2) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}

char* my_strncat(char *stc)//复制源字符串接在目的字符串后面
{
	char *cp = stc ;//cp = ABCD
	int len = strlen(stc);//4
	char *cpp = stc;
	while (*cpp)
	{
		++cpp;
	}
	while (*cp !='\0'&& (len--))
	{
		*cpp++ = *cp++;		
	}
	*cpp = '\0';
	return cpp;
}



int main()
{
	char str1[20] = "ABCD";
	char str2[20] = "BACD";
	char *ret = NULL;
	my_strncat(str1);
	ret = strstr(str1, str2);
	if (ret)
	{
		printf("字符串str2是str1字符串旋转之后的字符串!");
	}
	else
	{
		printf("字符串str2不是str1字符串旋转之后的字符串!");
	}

	//判断一个字符串是否为另外一个字符串旋转之后的字符串。 
	//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.

	//	AABCD左旋一个字符得到 ABCDA
	//	AABCD左旋两个字符得到 BCDAA
	//	AABCD右旋一个字符得到 DAABC

	//char s1[10] = "AABCD";
	//char s2[10] = "BCDAA";
	//char s1[10] = "abcd";
	//char s2[10] = "ACBD";

	//printf("s1 = %s\n", s1);
	//printf("s2 = %s\n", s2);

	//if (judge(s1, s2))
	//{
	//	printf("字符串旋转之后可以等于指定字符串!");
	//}
	//else
	//{
	//	printf("字符串旋转之后不会等于指定字符串!");
	//}


	////1.实现一个函数，可以左旋字符串中的k个字符。 
	////ABCD左旋一个字符得到BCDA
	////ABCD左旋两个字符得到CDAB
	//int k = 0;
	//char a[] = "ABCD";
	//printf("字符为%s\n", a);
	//printf("请输入左旋几个字符？(输入的数字小于4)\n");
	//scanf("%d", &k);
	//ZuoXuan(a, k);

	system("pause");
	return 0;
}