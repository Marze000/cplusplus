#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Max(int a, int b)
{
	return (a > b) ? a : b;
	//if(a>b)
	//{
	//	return a;
	//}
	//else
	//{
	//	return b;
	//}
}

void exchange(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	////1. 写一个函数可以判断一个数是不是素数。
	//int n = 0;
	//scanf("%d", &n);
	//if (n == 1)
	//{
	//	printf("1不是素数");
	//}
	//if (n == 2)
	//{
	//	printf("2是素数");
	//}

	//for (int i = 2; i < n; ++i)
	//{
	//	if (n % i == 0)
	//	{
	//		printf("%d不是素数\n",n);
	//		break;
	//	}
	//	else
	//	{
	//		printf("%d是素数\n",n);
	//		break;
	//	}
	//}



	////2. 写一个函数判断一年是不是闰年。

	//int year = 0;
	//scanf("%d", &year);
	//if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	//{
	//	printf("%d是闰年", year);
	//}
	//else
	//{
	//	printf("%d不是闰年",year);
	//}


	//3. 写一个函数，实现一个整形有序数组的二分查找。


	//4. 写一个函数，每调用一次这个函数，就会将num的值增加1。






	//int a = 10;
	//int b = 20;
	//exchange(&a,&b);
	//printf("a = %d\nb = %d\n", a, b);

	//int a = 0;
	//int b = 0;
	//scanf("%d %d", &a, &b);
	//int c= Max(a, b);
	//printf("%d", c);

	////1. 计算 n的阶乘
	//int n = 0;
	//printf("请输入需要计算的数：");
	//scanf("%d", &n);
	//int i = 1;
	//int sum = 1;
	//for (; i <= n; ++i)
	//{
	//	sum = sum * i; 
	//}
	//printf("%d", sum);


	////2. 计算 1!+ 2!+ 3!+ …… + 10!
	//int n = 3;
	//int sum = 1;
	//int num = 1;
	//int s = 0;
	//for (int num = 0; num < n ; ++num)
	//{
	//	sum = 1;
	//	for (int i = 1; i < num + 2; ++i)
	//	{
	//		sum = sum * i;
	//	}
	//	s = s + sum;
	//}
	//printf("%d\n", s);


	//3. 在一个有序数组中查找具体的某个数字n。
	//编写int binsearch(int x, int v[], int n); 功能：在v[0] <= v[1]
	//	<= v[2] <= …. <= v[n - 1]的数组中查找x.


	system("pause");
	return 0;
}