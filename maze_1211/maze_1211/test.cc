#include <iostream>
#include <stdlib.h>
using namespace std;

#if 0
class Caculator{
public:
	int a;int b;
	int getResult(char fun) {
		if (fun == '+') {
			return a + b;
		}
		else if(fun == '-') {
			return a - b;
		}else if(fun == '*') {
			return a * b;
		}
		/*
		...
		增加计算方式时  需要手动增删源代码 
		...
		*/
	}
};

int main(){
	char fun;
	Caculator x;
	x.a=5;
	x.b=10;
	cin >>fun;
	cout << x.getResult(fun);
	
	system("pause");
	return 0;
}

//父类计算器 
class Caculator{
public:
	virtual int getResult(){
		return 0;
	}
	int a;
	int b;
};
//子类：加法器
class Add :public Caculator{
public:
	int getResult(){
		return a+b;
	}
};

//此处省略减法器、乘法器等。
int main() {
	Caculator* c = new Caculator;
	c->a = 1;
	c->b = 2;
	cout << c->getResult() << endl;

	system("pause");
	return 0;
}

class Car{
public:
	virtual void Drive() final {}
};

class Benz :public Car{
public:
	virtual void Drive() { cout << "Benz-舒适" << endl; }
};

class Car {
public:
	virtual void Drive()=0 {}
};

class Benz :public Car {
public:
	virtual void Drive() override {
		cout << "Benz-舒适" << endl;
	}
};

int main() {
	Car *p = new Benz;
	p->Drive();

	system("pause");
	return 0;
}


class Car{
public:
	virtual void Drive() = 0;
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

void Test() {
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;
	pBMW->Drive();
}




#endif

class Base{
public:
	virtual void Func1(){
		cout << "Func1()" << endl;
	}
private:
};

int main() {
	printf("%d\n",sizeof(Base));

	system("pause");
	return 0;
}
