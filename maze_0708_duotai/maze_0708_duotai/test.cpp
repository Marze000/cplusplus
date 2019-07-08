#include <iostream>
#include <stdlib.h>
using namespace std;

class Base {
public:
	virtual void TestFunc1() {
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2() {
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc6() {
		cout << "Base::TestFunc3()" << endl;
	}
	virtual void TestFunc5() {
		cout << "Base::TestFunc3()" << endl;
	}
	virtual void TestFunc3() {
		cout << "Base::TestFunc3()" << endl;
	}

	int _b;
};

class Derive :public Base {
public:
	virtual void TestFunc1() {
		cout << "Derive::TestFunc1()" << endl;
	}

	virtual void TestFunc3() {
		cout << "Derive::TestFunc3()" << endl;
	}
	
	virtual void TestFun4() {
		cout << "Derive::TestFunc4()" << endl;
	}
	int _d;
};

//函数指针的类型
typedef void (*PVFT)(); 

void PrintVFT(Base& b) {
	//取出对象前四个地址
	PVFT* pVFT = (PVFT*) *(int*)&b;
	while (*pVFT) {
		(*pVFT)();
		pVFT++;
	}
}

int main() {
	cout << sizeof(Base) << endl;
	Base b;
	b._b = 10;
	
	Derive d;
	d._d = 20;
	d._b = 10;

	PrintVFT(d);
	
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
	char ch;
	while ((ch = getchar())!= EOF){
		if (ch>='A' && ch <='Z') {
			if (ch < 'E') {
				ch = ch + 21;
			}
			else {
				ch = ch - 5;
			}
		}
		putchar(ch);
	}
	return 0;
}