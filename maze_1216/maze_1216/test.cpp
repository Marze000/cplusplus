#include <iostream>
#include <stdlib.h>
using namespace std;

#if 0
class B {
public:
	B() {
		cout << "调用了构造函数" << endl;
	}
private:
	~B() {
		cout << "调用了析构函数" << endl;
	}
};

class A{
public:
	A() {
		cout << "调用了构造函数" << endl;
	}
	void destory() {
		delete this;
	}
private:
	~A() {
		cout << "调用了析构函数" << endl;
	}
};

#endif

class A{
protected:
	A() {
		cout << "调用了构造函数" << endl;
	}
	~A() {
		cout << "调用了析构函数" << endl;
	}
public:
	static A* create(){
		return new A();
	}
	void destory(){
		delete this;
	}
};

int main() {
	A a;
	a.create();
	a.destory();

	system("pause");
	return 0;
}