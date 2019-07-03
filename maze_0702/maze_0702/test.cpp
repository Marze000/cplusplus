#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Person {
public:
	void Print() {
		cout << "name" << _name << endl;
		cout << "id" << _id << endl;
	}
protected:
	string _name;
	int _id;
private:
	char _str;
};

class Student :public Person {
protected:
	int _num;
};

class Person {
protected:
	string _name;
	string _sex;
	int _age = 10;
};

class Student :public Person {
public:
	void Print() {
		cout << "age:" << _age << endl;
		cout << "age:" << Person::_age << endl;
	}
public:
	int _age = 99;
};

class Person {
public:
	Person(int name = 20)
		:_name()
	{}
	
	Person(const Person & p)
		:_name(p._name)
	{}

	Person& operator = (const Person& p) {
		if (this != &p) {
			_name = p._name;
		}
		return *this;
	}
	int _name;
};

class Student : public Person {
public:
	Student(int id,int name) 
		:_id(id)
		,Person(name)
	{}

	Student(const  Student & s)
		:_id(s._id)
		, Person(s)
		这样写的话调用的是基类的构造函数
		 Person(s._name)
	{}

	Student& operator = (const Student& s) {
		if (this != &s) {
			Person::operator = (s);
			_id = s._id;
		}
		return *this;
	}

protected:
	int _id;
};

class A {

private:
	A()
	{}
};

class B :public A {

};

class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};

 C++11给出了新的关键字final禁止继承
class NonInherit final
{};


class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name = "hehe"; // 姓名
};

class Student : public Person {
protected:
	int _stuNum; // 学号
};

void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	下面这条语句无法通过编译，因为并没有继承
	cout << s._stuNum << endl;
}


void test()
{
	Person p;
	Student s;
	Display(p, s);
}


class Person{
public:
	Person() {
		++_count;
	}
protected:
	string _name; // 姓名
protected:
	static int _count; // 统计人的个数。
};

int Person::_count = 0;

class Student : public Person{
protected:
	int _stuNum; // 学号
};

class Graduate : public Student{
protected:
	string _seminarCourse; // 研究科目
};

void TestPerson() {
	Person p1;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;
}

class Tire {
protected:
	string _brand = "Michelin"; // 品牌
	size_t _size = 17; // 尺寸
};
class Car {
protected:
	string _colour = "白色"; // 颜色
	string _num = "陕ABIT00"; // 车牌号
	Tire _t; // 轮胎
};
void Test() {
	TestPerson(); 
	Student t1(10,20);
	Student t2(t1);
	Student t3(10,30);
	t1 = t3;
	

	s1.Print();

	Student s1;
	Person p1 = s1;
	Person* p2 = &s1;
	Person& p3 = s1;

	Person p4;
		Student s2 = p4;
	Student* s3 =(Student*) &p4;
	Student* s3 = &p4;
	Student& s4 = p4;
	

	Student s1;
	s1._id = 10;
	
	子类对象可以赋值给父类对象，引用，指针
	Person* p1 = &s1;
	Person& p2 = s1;
	Person p3 = s1;

	Person p1;
	s1 = (Student)p1;

	Student sobj;
	 1.子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;
	2.基类对象不能赋值给派生类对象
	sobj = pobj;
	pp = &sobj;
	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
	pp = &pobj;
	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
}

int main() {

	Test();

	system("pause");
	return 0;
}