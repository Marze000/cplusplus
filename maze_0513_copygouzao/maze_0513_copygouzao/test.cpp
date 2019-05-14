#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class Date
{
public:
	Date()
	{
		_year = 2019;
		_month = 5;
		_day = 13;
	}

	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

typedef int DataType;

class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_pData);
		_size = 0;
		_capacity = capacity;
	}

	~SeqList()
	{
		if (_pData)
		{
			free(_pData); // 释放堆上的空间
			_pData = NULL; // 将指针置为空
			_capacity = 0;
			_size = 0;
		}
	}

private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};

class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};

class Person
{
private:
	String _name;
	int _age;
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

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		//若未显示定义，系统生成默认的拷贝构造函数。 
		//默认的拷贝构造函数对象按内存存储按字节序完成拷
		//贝，这种拷贝我们叫做浅拷贝，或者值拷贝。
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

class CExample
{
private:
	int m_nTest;
public:
	CExample(int x) : m_nTest(x)      //带参数构造函数
	{
		cout << "constructor withargument" << endl;
	}
	// 拷贝构造函数，参数中的const不是严格必须的，但引用符号是必须的
	CExample(const CExample & ex)     //拷贝构造函数
	{
		m_nTest = ex.m_nTest;
		cout << "copyconstructor" << endl;
	}
	CExample& operator = (const CExample& ex)   //赋值函数(赋值运算符重载)
	{
		cout << "assignmentoperator" << endl;
		m_nTest = ex.m_nTest;
		return *this;
	}
	void myTestFunc(CExample ex){}
};

class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};

int main()
{
	const char* str = "hello";

	String s1("hello");
	String s2(s1);

	cout << &s1 << endl;
	cout << &s2 << endl;

	CExample aaa(2);//constructorwith argument
	CExample bbb(3);//constructorwith argument

	bbb = aaa;		//assignmentoperator
	CExample ccc = aaa;	//copyconstructor
	bbb.myTestFunc(aaa);//copyconstructor









	Date d1;

	Date d2 = d1;
	
	String N;


	Date d1;
	d1.display();

	system("pause");
	return 0;
}


