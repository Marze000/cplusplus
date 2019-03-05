#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

//static int g_val = 2018;

//main的返回值也就是：进程的退出码
int main()
{
	//int i = 0;
	//char pas[10];
	//char password[10] = "123456789";
	//while (i<3)
	//{
	//	printf("请输入密码：\n");
	//	
	//	scanf("%s", pas);
	//
	//	if (strcmp(pas, password) == 0)
	//	{
	//		printf("密码正确！\n");
	//		break;
	//	}
	//	if (strcmp(pas, password) != 0)
	//	{
	//		++i;
	//		printf("密码错误，请重新输入！\n");
	//	}
	//	if (i == 3)
	//	{
	//		printf("密码输入超过三次，自动退出\n");
	//		break;
	//	}
	//}
	
	char psw[10] = "";
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; ++i)
	{
		printf("please input:");
		scanf("%s", psw);
		if (strcmp(psw, "password") == 0)
			break;
	}
	if (i == 3)
		printf("exit\n");
	else
		printf("log in\n");

	//char arr1[] = "welcome to bit...";
	//char arr2[] = "#################";
	//int left = 0;
	//int right = strlen(arr1) - 1;
	//printf("%s\n", arr2);
	//while循环实现
	//while (left <= right)
	//{
	//	Sleep(200);
	//	arr2[left] = arr1[left];
	//	arr2[right] = arr1[right];
	//	left++;
	//	right--;
	//	system("cls");//清屏函数
	//	printf("%s\n", arr2);	
	//}
	//for语句实现
	//for (left = 0, right = strlen(arr1) - 1; left <= right; left++, right--)
	//{
	//	Sleep(200);
	//	arr2[left] = arr1[left];
	//	arr2[right] = arr1[right];
	//	system("cls");
	//	printf("%s\n", arr2);
	//}

	//for (left = 0, right = strlen(arr1) - 1;
	//	left <= right;
	//	left++, right--)
	//{
	//	Sleep(1000);
	//	arr2[left] = arr1[left];
	//	arr2[right] = arr1[right];
	//	printf("%s\n", arr2);
	//}

	//// '= ' 和'=='的区别
	//int i = 0;
	//int k = 0;
	//int count = 0;
	////特别注意：循环条件'k=0'是一条赋值语句
	////所以永远为假，不进入for语句中
	//for (i = 0, k = 0; k = 0; i++, k++)
	//{
	//	++count;
	//	k++;
	//}
	//printf("%d", count);


	//int x = 0;
	//int y = 0;
	//for (x = 6213, y = 4; x < 2, y < 5; ++x, y++)
	//{
	//	printf("hehe\n");
	//}

	     
	//int ch = 0;
	//while ((ch = getchar()) != EOF)
	//{
	//	if (ch<'0' || ch>'9')
	//		continue;
	//	putchar(ch);
	//}

	//int i = 0;
	//while (i <= 10)
	//{
	//	i = i + 1;
	//	if (i == 5)
	//		continnue;
	//	printf("%d ", i);
	//
	//}


	//int i = 1;
	//while (i <= 10)
	//{
	//	if (i == 5)
	//		break;
	//	printf("%d ", i);
	//	i = i + 1;
	//}



	//1. 判断一个数是否为奇数
	//int i = 0;
	//printf("输入一个数字：");
	//scanf("%d", &i);
	//if (i % 2 == 0)
	//{
	//	printf("不是奇数");
	//}
	//else
	//{
	//	printf("是奇数！");
	//}


	//2. 输出1 - 100之间的奇数
	//int n = 1;
	//for (n = 1; n < 100; n = n + 2)
	//{
	//	printf("%d  ", n);
	//}

	
	//常见关键字：
	//auto  break  case  char  const  continue  default  do
	//double else  enum  extern  float  for  goto  if  int
	//long  register   return  short  signed  sizeof
	//static  struct  switch  typedef union  unsigned  void
	//volatile  while
	

	//char ch = 'w';
	//char* pc = &ch;
	//*pc = 'q';
	//printf("%c\n", ch);//q


	//int num = 10;
	//&num;//取出num的地址
	//printf("%p\n", &num);//%p是打印地址的符号
	////test.c

	//printf("%d\n", g_val);
	//
	
	//int conding = 0;
	//printf("你会敲代码吗?（1or0）");

	//scanf("%d", &conding);
	//if (conding == 1)
	//{
	//	printf("坚持，会有一个号offer!");
	//}
	//if (conding == 0)
	//{
	//	printf("回家卖红薯！");
	//}


	//printf("%d\n", strlen("abcdef"));//6
	//// \32被解析成一个转义字符:全角空格
	//printf("%d\n", strlen("c:\test\32\test.c"));//13
	////  c:	estc	est.
	//printf("c:\test\32\test.c");

	//printf("%c\n", '\'');//打印单引号  \'转义字符
	//printf("%s\n", "\"");//打印双引号  \"转义字符

	//printf("%d\n", sizeof(char));//1
	//printf("%d\n", sizeof(short));//2
	//printf("%d\n", sizeof(int));//4
	//printf("%d\n", sizeof(long));//4
	//printf("%d\n", sizeof(long long));//8
	//printf("%d\n", sizeof(float));//4
	//printf("%d\n", sizeof(double));//8
	//printf("%d\n", sizeof(long double));//8

	//printf("%d\n", sizeof(char *));//4
	//printf("%d\n", sizeof(short *));//4
	//printf("%d\n", sizeof(int *));//4
	//printf("%d\n", sizeof(double *));//4


	
	////程序终止出错，未定义行为，free释放的必须是动态内存的起始位置
	//int* p = (int*)malloc(10);
	//p++;//由于加加，所以free释放的内存不再是起始位置
	//free(p);

	

	////内存泄露
	//int* p = (int*)malloc(4);
	//p = (int*)malloc(4);
	//free(p);//释放的是上一个申请的内存，但是第一个申请的内存就泄露了
	//
	
	
	//thunsand  :	千	   KB
	//million   :	百万   MB
	//billion   :	十亿   G
	//常见的动态内存错误：

	//int* p = (int*)malloc(10 * sizeof(int));
	//if (p == NULL)
	//{
	//	return 1;
	//}
	////访问越界
	//for (int i = 0; i <= 10; ++i)
	//{
	//	p[i] = i;
	//}

	//p 必须为动态分配的内存
	//free(p);
	//free 必须搭配malloc系列函数配套使用

	//int* p = (int*)malloc(10 * sizeof(int));
	//free(p);//释放内存，不修改内存
	////free(p);如果两次释放，则是未定义行为；
	//printf("%p\n", p);


	//int* p = (int*)malloc(INT_MAX * 4);
	//if (p == NULL)
	//{
	//	return 1;
	//}
	//*p = 100;//空指针解引用是未定义行为


	system("pause");
	return 0;
}