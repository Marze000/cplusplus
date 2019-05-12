#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int* p = a; p < a + sizeof(a) / sizeof(a[0]); ++p)
	{
		cout << *p << " ";
	}

	for (auto e : a)
	{
		cout << e << " ";
	}
	system("pause");
	return 0;
}



struct A
{
	int a[10000];
};

A a;
A& func1()
{
	return a;
}

A func2()
{
	return a;
}

void test()
{
	size_t begin1 = clock();
	for (int i = 0; i < 100000; ++i)
	{
		func1();
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (int i = 0; i < 100000; ++i)
	{
		func2();
	}
	size_t end2 = clock();

	cout << "传引用：" << end1 - begin1 << endl;
	cout << "传值  ：" << end2 - begin2 << endl;


}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		test();
	}

	system("pause");
	return 0;
}
void func1(A& a) {}

void func2(A a) {}

void test()
{
	A a;
	int max = 10000;
	size_t begin = clock();
	for (int i = 0; i < max; ++i)
	{
		func1(a);
	}
	size_t end = clock();

	size_t begin2 = clock();
	for (int i = 0; i < max; ++i)
	{
		func2(a);
	}
	size_t end2 = clock();

	cout << "传引用所用的时间为：" << end - begin << endl;
	cout << "传值所用的时间为  ：" << end2 - begin2 << endl;

}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		test();

	}

	system("pause");
	return 0;
}