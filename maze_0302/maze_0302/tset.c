#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//函数的返回值表示字符串切分之后能切分的个数
int Split(char* input,const char* split_char,char* output[])
{
	int output_index = 0;
	char* p = strtok(input, split_char);
	while (p != NULL)
	{
		output[output_index] = p;
		++output_index;
		p = strtok(NULL, split_char);
	}
	return output_index;
}

int main()
{

	char str[1024] = "aaa bbb ccc ddd";
	char* result[10] = { 0 };

	int n = Split(str, " ",result);
	for (int i = 0; i < n; ++i)
	{
		printf("%s\n", result[i]);
	}
	//strtok使用注意事项：
	//1.strtok会破坏原来的字符串
	//	例如：char str[1024] = "aaa bbb ccc ddd";//正确的定义
	//		  char* str = "aaa bbb ccc ddd";//错误的定义
	//2.strtok内部有个static变量来记录上次切分的位置
	//  但是有一个致命隐患：“线程不安全”
	//3.strtok返回值如果是空指针说明切分完毕
	//4.如果有多个分割符相邻，会被当做一个

	//char* p = strtok(str, " ");
	//while (p != NULL)
	//{
	//	printf("%s\n", p);
	//	p = strtok(NULL, " ");
	//}

	//char str[1024] = "aaa bbb ccc ddd";
	//char* p = strtok(str, " ");
	//while (p != NULL)
	//{
	//	printf("%s\n", p);
	//	p = strtok(NULL, " ");
	//}

	//char str[] = "- This, a sample string.";
	//char * pch;
	//printf("Splitting string \"%s\" into tokens:\n", str);
	//pch = strtok(str, " ,.-");
	//while (pch != NULL)
	//{
	//	printf("%s\n", pch);
	//	pch = strtok(NULL, " ,.-");
	//}

	//  1、int(*p)[4]; ------ptr为指向含4个元素的一维整形数组的指针变量（是指针）
	//	2、int *p[4]; ------ - 定义指针数组p，它由4个指向整型数据的指针元素组成（是数组）
	//	3、int(*)[4]; --------实际上可以看作是一种数据类型。也就是第一个（int(*p)[4]; ）



	system("pause");
	return 0;
}
