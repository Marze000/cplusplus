#include <iostream>
#include <stdlib.h>
using namespace std;

namespace A
{
	int a = 10;
}

namespace B
{
	int a = 20;
}

//int a = 30;
using A::a;

int main()
{
	printf("%d\n", a);


	//printf("%d\n", A::a);
	//printf("%d\n", B::a);
	//printf("%d\n", a);
	system("pause");
	return 0;
}

int c = 10;

void print(int a = c)
{
	printf("%d ", a);
}

int main()
{

	print();

	system("pause");
	return 0;
}


extern "C" void func1(int a);

int main()
{
	func1(10);

	system("pause");
	return 0;
}






