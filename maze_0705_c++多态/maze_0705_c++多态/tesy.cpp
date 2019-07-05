#include <iostream>
#include <stdlib.h>
using namespace std;

class Person {
public:
	virtual void BuyTicket() {
		cout << "买票-全价" << endl;
	}
};

class Student : public Person {
public:
	virtual void BuyTicket() {
		cout << "买票-半价" << endl;
	}
};

void fun(Person& p) {
	p.BuyTicket();
}


class A {};
class B : public A {};
class Person {
public:
	//基类对象返回基类的指针
	virtual A* f() { 
		return new A; 
	}
};

class Student : public Person {
public:
	virtual B* f() { 
		return new B;
	}
};

class Perosn {
public:
	virtual ~Perosn() {
		cout << "~Person" << endl;
	}
};

class Student :public Perosn {
public:
	virtual ~Student() {
		//这里重写了基类的析构函数，所以还会调用一次基类的析构函数
		cout << "~Student" << endl;
	}
};


class Car{
public:
	//由final修饰的函数不能被继承
	virtual void Drive() final {}
};

class Benz :public Car{
public:
	//无法重写基类函数中的Drive
	virtual void Drive() {
		cout << "Benz-舒适" << endl;
	}
};


class Car {
public:
	virtual void Drive() {}
};

class Benz :public Car {
public:
	//override 检查这个虚函数是否重写了基类的某个虚函数
	//如果没有发生重写则编译出错
	virtual void Drive() override { 
		cout << "Benz-舒适" << endl;
	}
};


class Car{
public:
	//包含重虚函数的类叫抽象类（接口类）不能实例化出对象
	virtual void Drive() = 0;
	//重虚函数
};

class Benz :public Car{
public:
	virtual void Drive(){
		cout << "Benz-舒适" << endl;
	}
};

class BMW :public Car{
public:
	virtual void Drive(){
		cout << "BMW-操控" << endl;
	}
};

void Test(){
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;
	pBMW->Drive();
}


class Base{
public:
	virtual void Func1(){
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;
};

int main() {
	cout << sizeof(Base) << endl;

	Test();
	Perosn* p1 = new Student;
	Perosn* p2 = new Perosn;
	delete p1;
	delete p2;

	Person p1;
	Student t1;

	fun(p1);
	fun(t1); 

	system("pause");
	return 0;
}