#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//void increment_ints(int p[], int n)
//{
//	assert(p != NULL);//确保p不为空指针
//	assert(n >= 0);//确保n不为负数
//	while (n)
//	{
//		*p++;
//		p++;
//		n--;
//	}
//}

//char *c[] = { "ENTER","NEW","POINT","FIRST" };
//char **cp[] = { c + 3,c + 2,c + 1,c };
//char ***cpp = cp;

//void func(char **p)
//{
//	*p = *p + 1;
//}

//void GetMemeory(char** p)
//{
//	*p = (char *)malloc(100);
//}
//
//void Test()
//{
//	char *str = NULL;
//	GetMemeory(&str);
//	strcpy(str, "Thunder");//字符串复制到str
//	strcat(str+2, "Downloader");//连接字符串
//	puts(str); //ThunderDownloader
//}

int main()
{
	//int x = 3;
	//int y = 0;
	//int *px = &x;
	//y = *px++;
	//
	//printf("%d %d", x, y);
	//
	
	
	
	//Test();

	//char s[] = { '1','2','3','4' };
	//char* s = "1234";
	//func(&s);
	//printf("%c", *s);

	//构造函数：名字必须与类名字完全相同；
	//在c++里，构造函数不可以带返回值；
	//可以不带参数，也可以缺省定义；

	//int a = 21;
	//int b = 11;
	//printf("%d\n%d\n",	--a + b,b+a--);
	//30 32

	//printf("%s\n", **++cpp);
	//printf("%s\n", *--*++cpp + 3);
	//printf("%s\n", *cpp[-2] + 3);
	//printf("%s\n",cpp[-1][-1]+1);
	//	POINT
	//	ER
	//	ST
	//	EW

	//char s[] = "123";
	//char* p;
	//p = s;
	//printf("%c%c%c\n",*p++,*p++,*p++);//321
	////压栈时先压最右边的参数

	//printf("\n");
	//int a[5] = { 1,2,3,4,5 };
	//int* p;
	//int** k;
	//p = a;
	//k = &p;
	//printf("%d\n", *(p++));
	//printf("%d\n", **k);
	////1 
	////2

	//int a = 7;
	//int b = 5;
	//printf("%d\n",  b / a);

	//int N = 0;
	//int sum = 0;
	//scanf("%d", &N);	
	//if(N>0)
	//{
	//for (int i = N; i <= 2*N; ++i)
	//{
	//	sum = sum + i;
	//}I 
	//printf("%d", sum);
	//if(N < 0)
	//{
	//	N = abs(N);
	//	for (int i = N; i <= 2 * N; ++i)
	//	{
	//		sum = sum + i;
	//	}
	//	printf("%d", -sum);
	//}


	//int N = 0;
	//scanf("%d", &N);
	//int sum = 0;
	//if (N > 0)
	//{
	//	for (int i = N; i <= 2 * N; ++i)
	//	{
	//		sum = sum + i;
	//	}
	//	printf("%d", sum);
	//}
	//if (N < 0)
	//{
	//	for (int j = N; j >= 2 * N; --j)
	//	{
	//		sum = sum + j;
	//	}
	//	printf("%d", sum);
	//}

	system("pause");
	return 0;
}