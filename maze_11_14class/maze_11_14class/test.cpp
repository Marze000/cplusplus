#include <iostream>
#include <stdlib.h>

using namespace std;

class Base {
public:
	int getBase(){
		printf("调用了getBase函数");
		return 0;
	}
protected:
	int base;
private:
	int baseTemp;
};
class Derived1 :public Base {
public:
	int getDrv1() {
		printf("调用了getDriv函数");
		return 0;
	}
};
class Derived2 :protected Base {
public:
	int getDrv2() {
		printf("调用了getDrv2()函数");
		return 0;
	}
};
class Derived3 :private Base {
public:
	int getDrv3() {
		printf("调用了getDrv3()函数");
		return 0;
	}
};

int main() {
	Base b, *bp;
	Derived1 d1;
	Derived2 d2;
	Derived3 d3, *dp3;
	dp3 = &b;

	system("pause");
	return 0;
}