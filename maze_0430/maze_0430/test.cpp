#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int &add(int a, int b)
{
	static int c = a + b;
	return c;
}

struct A
{
	int a[10000];
};

A a;

A TestFunc1(){return a;}

A& TestFunc2(){return a;}

void TestRefAndValue()
{

	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc1();
	}
	size_t end1 = clock();


	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc2();
	}
	size_t end2 = clock();
	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
}

int main()
{





	//int a = 10;
	//int& ra = a;
	//ra = 20;
	//int* pa = &a;
	//*pa = 20;

	//printf("%d\n", a);
	//printf("%d\n", ra);
	//printf("%d\n", *pa);
	//printf("%p\n", &a);
	//printf("%p\n", &ra);
	//printf("%p\n", pa);
	//for (int i = 0; i < 10; ++i)
	//{
	//	TestRefAndValue();
	//}

	//int& ret = add(1, 2);
	//add(3, 4);
	//cout << "add(1,2) is :" << ret << endl;


	system("pause");
	return 0;
}



