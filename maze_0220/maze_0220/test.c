#include <stdio.h>
#include <stdlib.h>
#define N 9

//union myun//联合体变量
//{
//	struct { int x, y, z; }u;//u为结构体类型变量
//	int k;//整形变量
//}a;

//int fun(int a[], int n)
//{
//	int i, j;
//	j = 0;
//	for (i = 0; i < n; ++i)
//	{
//		if (a[i] % 2 == 1)
//		{
//			a[j] = a[i];
//			j++;
//		}
//	}
//	return j;
//}

//int fun(int x)
//{
//	int countx = 0;
//	while (x)
//	{
//		countx++;
//		x = x & (x - 1);
//	}
//	printf("%d", countx);
//	return countx;
//}

//class parent
//{
//	public:
//	virtual void output();
//};

int main()
{
=	//int x = 500;
	//fun(x);

	//int b[N] = { 9,1,4,2,3,6,5,8,7 };
	//int i = 0;
	//int n;
	//printf("\nThe original data:\n");
	//for (i = 0; i < N; i++)
	//{
	//	printf("%4d", b[i]);
	//}
	//n = fun(b, N);
	//printf("\nThe number of odd:%d\n",n);
	//printf("\nThe odd number:\n");
	//for (i = 0; i < n; i++)
	//{
	//	printf("%4d", b[i]);
	//}

	//a.u.x = 4;
	//a.u.y = 5;
	//a.u.z = 6;
	//a.k = 0;
	//printf("%d\n", a.u.x);
	//	a.u.x	相当于	a.k		因为公用同一块内存
	//联合体内存大小就是结构体内存大小，那么其他成员变量的存储地址
	//就会和结构体重叠，都是int型的话，先和x重叠

	//int a[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//int* p[4];
	//int i;
	//for (i = 0; i < 4; i++)
	//{
	//	p[i] = &a [i * 3];		
	//}
	//printf("%d\n", p[3][2]);////p[3][2]== p[3]+2
	 

	system("pause");
	return 0;
}