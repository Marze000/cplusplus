#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct test
{
	int m1;
	char m2;
	float m3;
	union uu
	{
		char u1[5];
		int u2[2];
	}ua;
}myaa;

void change(int* a,int &b,int c)
{
	c = *a;
	b = 30;
	*a = 20;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	
	change(&a, b, c);
	printf("%d %d %d", a, b, c);//20 30 30
	//这个题目考的是函数传参的形式，它包括三种：传值、传指针、传引用；
	//其中传值不会改变变量的值，传指针和传引用会改变变量的值。 

	//传值的情况，函数的参数会产生临时空间，函数结束就会释放空间，
	//因此不会改变主函数中变量的值；

	//传指针即传递的是地址，将主函数中变量的地址传到函数中，
	//而不会产生临时变量，因此会改变量的值；

	//传引用的情况，就是传递的变量的别名，因此也会改变变量的值。
	
	
	
	
	//char c = 'A';
	//if ('0' <= c <= '9')
	//{
	//	printf("YES!");
	//}
	//else
	//{
	//	printf("NO!");
	//}
	
	
	
	//char* p1 = "hello";
	//char* p2 = "world";
	//char* p3 = "a piece of cake";
	//char* str[] = { p1,p2,p3 };
	//printf("%c", *(str[0] + 1));

	////printf("%d", sizeof(struct test));//20
	//char* str[3] = { "stra","strb","strc" };
	//char* p = str[0];
	//int i = 0;
	//while (i < 3)
	//{
	//	printf("%c ", p++);//stra  tra  ra													

	//	i++;
	//}
	//char *str[3] = { "stra","strb","strc" }; 是一个指针数组； 
	//char *p = str[0]；实际上p指向第一个字符串，所以字符串加1，
	//则指向字符串的下一个字母，而并非是下一个字符串


	//int x, y;
	//int count = 0;
	//for (x = 0, y = 0; (y = 123) && (x < 4); x++)
	//{
	//	count++;
	//}
	//printf("%d", count);
	

	system("pause");
	return 0;
}