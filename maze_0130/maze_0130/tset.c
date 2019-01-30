#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>//字符函数的头文件。
#include <string.h>//字符串函数的头文件。

//void* GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	if (str != NULL)
//	{
//		strcpy(str, "hello world");
//		printf(str);
//	}
//	free(str);
//	str = NULL;
//}


//char* GetMemory()
//{
//	char* p;
//	p = (char*)malloc(100);
//
//	if (p != NULL)
//	{
//		return p;
//	}
//}
//
//void Test(void)
//{
//	char* str = GetMemory();
//	strcpy(str, "hello world!");
//	printf(str);
//	
//	free(str);
//	str = NULL;
//}


int main()
{
	//库函数：
	//1-> abs() int abs(int x)求绝对值
	//2-> long labs()=>求长整形的绝对值
	//3-> double fabs()=>求浮点数的绝对值

	//4-> int isalpha(int ch)检测ch是否是字母，如果是则返回1，否则返回0
	//char ch = 'a';
	//ch = getchar();
	//if (isalpha(ch))
	//{
	//	printf("ok!");
	//}
	//else
	//{
	//	printf("no!");
	//}

	//5-> int isdigit(int ch)检测的是数字，如果是数字则返回非零，否则返回0

	//6-> int isalnum(int ch)检测的是字母或数字，函数返回非零，否则返回0
	
	//int ch = 0;
	//ch = getchar();
	
	//printf("%d", ch);
	//if (isalnum(getchar()))
	//{
	//	printf("输入的为数字或字母\n");
	//}
	//else
	//{
	//	printf("输入的不是字母且不是数字\n");
	//}

	//7-> 
	
	int arr[2][3] = {{1,2,3},{4,5,6}};
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			printf("%3d", arr[j][i]);
		}
		printf("\n");
	}

	//int a = 10000;
	//FILE* pf = fopen("test.txt", "wb");
	//fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
	//fclose(pf);
	//pf = NULL;

	//Test();
	system("pause");
	return 0;
}