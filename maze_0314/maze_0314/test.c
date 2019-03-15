#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//////查找所有在一个给定字符集合中出现的字符
//char* find_char(char const* source, char const* chars)
//{
//	assert(source != NULL);
//	assert(chars != NULL);
//	
//	char* pchars = (char*)chars;//XRCQEF// “初始化”: 不同的“const”限定符
//
//	while (*pchars!= '\0')
//	{
//		char* psource = (char*)source;//ABCDEF	“初始化”: 不同的“const”限定符
//		while (*psource != '\0')
//		{
//			if (*psource != *pchars)
//			{
//				++psource;
//			}
//			else
//			{
//				return psource;//“return”:“char *”与“char”的间接级别不同
//			}
//		}
//		pchars++;
//	}
//	return 0;
//}//“find_char”: 不是所有的控件路径都返回值

//int del_substr(char* str, char const *substr)
//{
//	assert(str != NULL);
//	assert(substr != NULL);
//
//	while (*str != '\0')
//	{
//		char* psubstr = (char*)substr;//CDE//ACD
//		char* pstr = (char*)str;//ABCDEFGH
//		while (*psubstr != '\0')
//		{
//			if (*psubstr != *pstr)
//			{
//				break;
//			}
//			else
//			{
//				++pstr;
//				++psubstr;
//			}
//		}
//		if (*psubstr == '\0')
//		{
//			char* p1 = str - 3;
//			while()
//			{
//				*p1 = *pstr;
//
//			}
//		}
//		++str;
//	}
//
//	return 0;
//}
//
////删除一个字符串；
//int del_substr(char* str, char const *substr)
//{
//	// str : ABCDEFGH		substr: CDE
//	int flag = 0;
//	char* stringStr = str;
//	char* stringResult = NULL;
//	char const *stringSubstr = substr;
//
//	while (*stringStr!= '\0')
//	{
//		if (*stringStr == *stringSubstr)
//		{
//			flag++;
//			stringResult = stringStr;
//			*stringStr++;
//			*stringSubstr++;
//		}
//		else
//		{
//			stringStr++;
//			stringSubstr = substr;
//		}
//
//		if (*(stringSubstr) == '\0')
//		{
//			while (*stringResult)
//			{
//				*(stringResult - flag) = *(++stringResult);
//			}
//			return 1;
//		}
//	}
//	return 0;
//}
//
int del_substr(char *str, char const *substr)
{
	char *stringStr = NULL;
	char *stringResult = NULL;
	char const *stringSubstr = NULL;
	int flag = 0;
	int flagTrue = 0;//判断是否相等过
	if (str == NULL || substr == NULL)
	{
		return 0;
	}
	stringStr = str;
	stringSubstr = substr;
	while (*stringStr != '\0')
	{
		while (*stringSubstr != '\0')
		{
			if (*stringStr == *stringSubstr)
			{
				stringResult = stringStr;
				flag++;
				flagTrue = 1;
				*stringStr++;
				*stringSubstr++;
				continue;
			}
			else
			{
				flag = 0;
				break;
			}
		}

		if (*(stringSubstr) == '\0')
		{
			while (*stringResult)
			{

				*(stringResult - flag) = *(++stringResult);
			}
			return 1;
		}

		if (flagTrue == 1)
		{
			break;
		}
		else
		{
			stringStr++;
		}
	}
	return flag;
}

int main()
{
	char str1[] = "ABCDEFGHJKL";
	char str2[] = "CDEFGHJ";
	char str3[] = "ACD";
	int n = del_substr(str1, str2);
	printf("%d\n%s\n", n, str1);

	//char s1[] = "ABCDEF";
	//char s2[] = "BC";
	//int p = del_substr(s1, s2);
	//printf("%d\n%s\n", p, s1);
	

	////快速排序法：
	int arr[10] = { 0,15,-45,23,45,78,52,49,-12,36 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int k,t;
	for (int i = 0; i < len - 1; ++i)
	{
		k = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[j] < arr[k])
			{
				k = j;
			}
		}
		t = arr[k];
		arr[k] = arr[i];
		arr[i] = t;
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	
	//char ch[] = "abc";
	//if (strcmp(ch,"abc") == 0)
	//{
	//	printf("ok!");
	//}
	//else
	//{
	//	printf("no!");
	//}

	//char arr[100] = { 0 };
	//for (char i = 0; i < 4; ++i)
	//{
	//	scanf("%c", &arr[i]);
	//}
	//printf("%s", arr);
	//char str1[] = "ABGDEF";//“初始化”: 从“char *”到“int *”的类型不兼容
	//char str2[] = "XRCQef"; //“printf”: 格式字符串“%c”需要类型“int”的参数，
	//						//但可变参数 1 拥有了类型“int *”
	//char* p = find_char(str1, str2);
	//printf("%c", *p);
	//

	//char str[] = "This is a sample string";
	//char keys[] = "aeiouh";
	//printf("%s\n", str);
	//char *pch = strpbrk(str, keys);
	
	//while (pch != NULL)
	//{
	//	printf("%c", *pch);//iiaaei
	//	pch = strpbrk(pch + 1, keys);
	//}
	
	//getchar();
	//int *p = NULL;
	//printf("%d", sizeof(p));
	//printf("%d", sizeof(int));
	



	system("pause");
	return 0;
}
