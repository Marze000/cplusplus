#include <iostream>
#include <stdlib.h>
using namespace std;

class A
{
public:
	A() { ++_scount; }
	A(const A& t) { ++_scount; }
	static int GetACount() { return _scount; }
private:
	static int _scount;
};

int A::_scount= 0;

void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}

class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//
private:
	int _year;
	int _month;
	int _day;
};
// 以下测试函数能通过编译吗？
void Test()
{
	Date d1;
	Date d2(2019, 5, 16);
}

int main()
{
	Test();

	system("pause");
	return 0;
}


class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;

		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
private:
	// 基本类型(内置类型)
	int _year;
	int _month;
	int _day;

	// 自定义类型
	Time _t;
};

int main()
{
	Date d;

	system("pause");
	return 0;
}
	

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 5, 18);
	Date d2;
	d2 = d1;
	

	system("pause");
	return 0;
}

class A
{
public:
	//构造函数
	A(int a = 10, int b = 20)
	{
		_a = a;
		_b = b;
	}
	//赋值操作符重载
	A& operator=(const A& c)
	{
		if (this != &c)
		{
			//这里同样也是 省略了this指针
			_a = c._a;
			_b = c._b;
		}
		return *this;
	}
private:
	int _a;
	int _b;
};

int main()
{
	A a1(100, 200);
	A a2;
	a2 = a1;

	system("pause");
	return 0;
}

class B
{
public:
	//构造函数
	B(int a = 10 ,int b = 20)
	{
		_a = a;
		_b = b;
	}
	//取地址运算符重载
	B* operator&()
	{
		return this;
	}
private:
	int _a;
	int _b;
};

int main()
{
	B b1(100, 200);
	&b1;

	system("pause");
	return 0;
}

class Date
{
public:
	void Display()
	{
		cout << "Display ()" << endl;
		cout << "year:" << _year << endl;
	}
private:
	int _year; // 年
};

int main()
{
	const Date d2;
	d2.Display();
	return 0;
}


class A
{
public:
	void display()const
	{
		
	}
private:
	int a;
};

int main()
{
	A a1;
	a1.display();

	system("pause");
	return 0;
}