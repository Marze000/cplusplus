#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class A
{
public:
	void time();
private:
	int a;
};

class B
{
	void max();
};

class C{};

class Date
{
public:
	Date()
	{
		_year = 2019;
		_month = 5;
		_days = 13;
	}
	Date(int year = 2019, int month = 5, int days = 13)
	{
		_year = year;
		_month = month;
		_days = days;
	}

private:
	int _year;
	int _month;
	int _days;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void display()
	{
		cout << _year << " " << _month << " " << _day << count<<endl;
	}


private:
	int _year;
	int _month;
	int _day;
	int count;
};

int main()
{
	Date d1;
	d1.display();
	Date d2(d1);
	d2.display();


	system("pause");
	return 0;
}

int main()
{
	Date d;

	cout << "A:" <<sizeof(A) << endl;
	cout << "B:" << sizeof(B) << endl;	
	cout << "C:" << sizeof(C) << endl;

	int a = 1;
	int b = 2;
	int c = (a > b, a = b + 10, a, b = a + 1);
	printf("%d\n", c);
	
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	//i = a++ && ++b && d++;
	i = a++||++b||d++;
	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
	 a = 1,b = 2,c = 3 d = 4;

	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
	// a = 1,b = 3, c = 3,d = 4;

	int num1 = 1;
	int num2 = 2;
	//  0001
	//  0010
	printf("%d\n", num1 | num2);//3
	printf("%d\n", num1 & num2);//0
	printf("%d\n", num1 ^ num2);//3

	int num = 10;
	num = num >> -1;
	printf("%d\n", num);

	system("pause");
	return 0;
}