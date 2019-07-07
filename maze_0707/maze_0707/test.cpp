#include <iostream>
#include <stdlib.h>
using namespace std;

//派生类重写基类虚函数时，与基类虚函数返回值类型不同。
//
//基类虚函数返回基类对象的指针或者引用，
//派生类虚函数返回派生类对象的指针或者引用时，称为协变
//
//但是该种写法不是很规范，不建议这样使用* /
//
class A {};
class B : public A {};

class Person {
public:
	virtual A* f() { return new A; }
};

class Student : public Person {
public:
	virtual B* f() { return new B; }
};

/*2. 析构函数的重写(基类与派生类析构函数的名字不同)
如果基类的析构函数为虚函数，此时派生类析构函数只要定义，
无论是否加virtual关键字，都与基类的析构函数构成重写，
虽然基类与派生类析构函数名字不同。看起来违背了重写的规则，
其实不然，这里可以理解为编译器对析构函数的名称做了特殊处理，
编译后析构函数的名称统一处理成destructor。
基类的虚函数被继承下来了在派生类依旧保持虚函数属性), 
c*/class Person {
public:
	virtual ~Person(){
		cout << "基类的析构函数" << endl;
	}
};

class Student : public Person {
	virtual ~Student(){
		cout << "派生类的析构函数" << endl;
	}
};

class Base {
public:
	virtual void fun1() {
		cout << "Base::fun1()" << endl;
	}
	virtual void fun2() {
		cout << "Base::fun2()" << endl;
	}
	//上面两个函数地址会被放进虚函数表中
	//fun3()由于不是虚函数，和虚函数没有关系
	void fun3() {
		cout << "Base::fun3()" << endl;
	}
private:
	int _b = 1;
};

class Drive : public Base {
public:
	//下面的fun1()重写了基类中的虚函数fun1()
	//所以它会取代继承下的fun1()
	virtual void fun1() {
		cout << "Drive::fun1()" << endl;
	}
	virtual void fun4() {
		cout << "Drive::fun4()" << endl;
	}

private:
	int d = 2;
};

class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};

class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[]){
	 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i){
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}

int main(){
	Base b;
	Derive d;
	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);
	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);

	system("pause");
	return 0;
}

int main() {
	
	Base b;
	Derive d;

	Person* p1 = new Person;
	//p2 会调用两次析构函数
	Person* p2 = new Student;

	delete p1;
	delete p2;

	return 0;
}

class Person {
public:
	//被调用的函数必须是虚函数
	virtual void buytacket(){
		cout << "全价购票" << endl;
	}
	//被virtual 修饰的成员函数就是虚函数
};

class Student :public Person {
	//派生类的函数必须对基类的函数进行重写
	virtual void buytacket(){	
		cout << "半价购票" << endl;
	}
	//派生类中有一个和基类完全相同的虚函数称之为重写
	//完全相同指的是：返回值类型，函数名，参数列表
};

//构成多态的条件之一就是：必须通过基类的指针或引用调用虚函数
void Func(Person& p) {
	p.buytacket();
}

int main() {
	Person p1;
	Func(p1);

	Student s1;
	Func(s1);

	system("pause");
	return 0;
}