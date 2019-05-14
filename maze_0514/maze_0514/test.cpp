#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

class A
{
	int b;
	static int a;
	void display();
};


class A
{

};


class B
{
public:
	char a;
	int b;

	struct A{//8
		int a;
		char c;
	}bb;
};

class Date
{
public:
	void setA(int a)
	{
		cout << this << " ";
		this = nullptr;
		this->_a = a;

	}
	void print()
	{
		cout << this->_a << endl;
	}
private:
	int _a;
};

struct A
{
	int a;
	int b;
};

void set(A* p,int t)
{
	p->a = t;
}

int main()
{
	Date a1;
	a1.setA(10);
	cout << &a1 << endl;





{
	/*Date a1;
	a1.setA(10);
*/
	
	A aa;
	set(&aa, 10);


	a2.setA(20);
	a3.setA(30);





	cout << endl;
	cout << &a1 <<" "<< &a2 <<" "<< &a3 << endl;


	a1.print();
	a2.print();
	a3.print();

	cout << offsetof(B, b);
	
	cout << (unsigned int)&(((B*)0)->b);

	cout << sizeof(B) << endl;//12

	cout << sizeof(A) << endl;


	int aa = 10;
	int bb = 20;

	printf("aa=%d\nbb=%d\n", aa,bb);

 
 	system("pause");
 	return 0;
}