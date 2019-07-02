#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Person {
public:
	void Print() {
		cout << "name" << _name << endl;
		cout << "age" << _age << endl;
	}
protected:
	string _name = "Jack";
private:
	int _age = 18;
};

class Student :public Person {
protected:
	int _num = 100;
};

class Teacher :public Person {
protected:
	int _Tnum;
};

class Person {
protected:
	string _name;
	string _gender;
	int _age;
};

class Student :public Person {
public:
	int _id;
};

class Person {
protected:
	string _name = "Jack";
	int _num = 11;
};

class Student :public Person {
public:
	void Print() {
		cout << "姓名" << _name << endl;
		如果不加Person访问的是Student
		这种现象叫做隐藏
		cout << "省份证号" <<Person::_num << endl;
		cout << "学号" << _num << endl;
	}
protected:
	int _num = 99;
};

class A {
public:
	void Fun() {
		cout << "Fun()" << endl;
	}
};

class B :public A {
public:
	void Fun(int i) {
		A::Fun();
		cout << "Fun(int i)" << i << endl;
	}
};

class Person {
public:
	Person(const char* name = "Jack")
		:_name(name) {
		cout << "这是基类的构造函数" << endl;
	}

	Person(const Person& s)
		: _name(s._name)
	{
		cout << "这是基类的拷贝构造函数" << endl;
	}

	Person operator=(const	Person s) {
		cout << "这是基类的赋值操作函数" << endl;
		if (this != &s) {
			_name = s._name;
		}
		return *this;
	}

	~Person() {
		cout << "这是基类的析构函数" << endl;
	}

protected:
	string _name;
};

class Student : public Person{
public:
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "这是派生类的构造函数"<< endl;
	}

	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "这是派生类的拷贝构造函数" << endl;
	}

	Student& operator = (const Student& s){
		cout << "这是派生类的赋值操作符函数" << endl;
		if (this != &s){
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}

	~Student(){
		cout << "派生类的析构函数" << endl;
	}
protected:
	int _num; //学号
};

void Test(){
	Student s1("jack", 18);
	这是基类的构造函数
	这是派生类的构造函数
	Student s2(s1);
		这是基类的拷贝构造函数
		这是派生类的拷贝构造函数
	Student s3("rose", 17);
		这是基类的构造函数
		这是派生类的构造函数
	s1 = s3;
		这是派生类的赋值操作符函数
		这是基类的拷贝构造函数
		这是基类的赋值操作函数
		这是基类的拷贝构造函数
		这是基类的析构函数
		这是基类的析构函数
	cout << endl;
		派生类的析构函数
		这是基类的析构函数
		派生类的析构函数
		这是基类的析构函数
		派生类的析构函数
		这是基类的析构函数
}

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

class A :public NonInherit {

};
 
 C++11给出了新的关键字final禁止继承
class NonInherit final
{};

int main() {
	Test();
	B b1;
	b1.Fun(10);

	Student s1;
	s1.Print();

	派生类是可以给基类的指针，引用对象赋值的

	Student s1;
	Person p1 = s1;
	Person* p2 = &s1;
	Person& p3 = s1;


	Student s1;
		
	Teacher t1;
	cout << sizeof(class Teacher) << endl;
	cout << sizeof(class Student) << endl;

	s1.Print();
	t1.Print();
	
	system("pause");
	return 0;
}