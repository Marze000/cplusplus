#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void change(int* a, int &b, int c)
//{
//	c = *a;
//	b = 30;
//	*a = 20;
//}

struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;

};

enum sex
{
	MALE,
	FEMALE,
	UNKNOWN,
};


int main()
{
	//unsigned int a = 20;
	//signed int b = -20;
	//printf("%u\n", b);

	//if (a > b)
	//{
	//	printf("a>b\n");
	//}
	//else
	//{
	//	printf("a<b\n");
	//}

	//int a = 10;
	//int b = 5;
	//double c = (double)a / b;
	//printf("%f", c);

	//float f = 5.75;
	//printf("f = %d,f = %f\n", (int)f, f);

	//printf("%d", '12');

	int i = -1;
	unsigned int a = 65535; 
	unsigned int b = i;
	int j = a;

	printf("(unsigned )%u->(int)%d\n", a, j);
	printf("(int )%u->(unsigned)%u\n", i, b);
	//(unsigned)65535->(int)65535
	//(int)4294967295->(unsigned)4294967295


	//int c = a + b;
	//printf("%d", c);



	//printf("%d", sizeof(A));
	//enum sex s = 3;

	//int a = 10;
	//int b = 20;
	//int c = 30;
	//change(&a, b, c);
	//printf("a = %d\nb = %d\nc = %d ", a, b, c);

	//signed char a = 0xe0;
	//unsigned int b = a;
	//unsigned char c = a;//c的位存储形式还是0xe0

	////A:a>0&&c>0为真（是错的）
	//printf("%x", b);

	//B：a==c(错)
	//C: b的十六进制表示为0xffffffe0

	//char s[] = "\\123456\123456\t";
	//printf("%d\n", sizeof(s));
	//printf("%d\n", strlen(s));
	////转义字符有     \\ 表示:'\'   \123 表示 :'{'   \t表示：制表符

	//  1、int(*p)[4];ptr为指向含4个元素的一维整形数组的指针变量（是指针）
	//	2、int *p[4]; 定义指针数组p，它由4个指向整型数据的指针元素组成（是数组）
	//	3、int(*)[4]; 实际上可以看作是一种数据类型。也就是第一个（int(*p)[4]; ）

	system("pause");
	return 0;
}