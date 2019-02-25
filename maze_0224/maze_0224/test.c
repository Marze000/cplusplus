#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int num(int n)
{
	if (n == 0)//零元返回零瓶
	{
		return 0;
	}
	if (n == 1)//一元返回一瓶
	{
		return 1;
		
	}
	//以上两种情况特殊讨论
	if (n % 2 == 0)
	{
		return n + num(n / 2);
	}
	else//奇数
	{
		return (n + 1) + num((n / 2) - 1);
	}	
}

char *his_strcpy(char *dest, char *src)
{
	char *ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

char *my_strcpy(char *dest, char *src)
{
	char *ret = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return ret;
}

//char *mystrcat(char *dest, char *src)
//{
//	char *destbak = dest;
//	assert(NULL = dest && NULL != src);
//	while ('\0'!= *dest)
//	{
//
//	}
//}

int main()
{
	// 一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
	//找出这两个数字，编程实现。
	//int arr[] = { 4,8,8,4,5,9,3,5,9,3,15,56 };
	//int count = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);//12
	//int i = 0;
	//int j = 0;
	//for(i = 0; i < sz; i++)
	//{
	//	count = 0;//每次执行循环时初始化为0
	//	for (j = 0; j < sz ; j++)
	//	{
	//		if (arr[i] == arr[j])
	//		{
	//			count++;
	//		}
	//	}
	//	if (count == 1)
	//	{
	//		printf("%d\n",arr[i]);
	//	}
	//}
	//printf("%d", sz);//12


	//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
	//	给20元，可以多少汽水。
	//	编程实现。
	
	//int n = 0;
	//printf("请问你要花费多少钱？\n");
	//scanf("%d", &n);
	//printf("%d元可以喝%d瓶汽水！！\n", n, 2 * n - 1);//找规律，n元可以喝2*n-1瓶汽水
	//printf("%d元可以喝%d瓶汽水！！\n", n, num(n));//函数递归


	//	3.模拟实现strcpy
	//首先strcpy的功能是： 将一个字符串的内容复制到另外一个字符数组中，包括字符串的终结符

	//char a[20];
	//char *p = "bfaslkjfcd";
	//printf("%s\n", my_strcpy(a, p));
	//printf("%s\n", his_strcpy(a, p));


	//	4.模拟实现strcat
	//strcat的功能是：
	char array[100] = "hello world !";
	char *p = "abcdef";
	mystrcat(array, p);
	printf("array = %s\n", array);
	printf("hello...\n");






	system("pause");
	return 0;
}