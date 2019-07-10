#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Base {
public:
	virtual void Test1() {
		cout << "Base::Test()1" << endl;
	}

	virtual void Test2() {
		cout << "Base::Test()2" << endl;
	}

	void Test3() {
		cout << "Base::Test()3" << endl;
	}

	void Test4() {
		cout << "Base::Test()4" << endl;
	}
	int _b;
};

class Drived :public Base {
public:
	virtual void Test1() {
		cout << "Drived::Test1()" << endl;
	}

	void Test2() {
		cout << "Drived::Test2()" << endl;
	}

	virtual void Test3() {
		cout << "Drived::Test3()" << endl;
	}

	void Test4() {
		cout << "Base::Test()4" << endl;
	}
	int _d;
};

void TestVirtual(Base& b) {
	b.Test1();
	b.Test2();
	b.Test3();
	b.Test4();
}

typedef void (*PVFT)();

void PrintPVTF(Base& b,const string& strInfo) {
	cout << strInfo << endl;
	PVFT* pVFT = (PVFT*)*(int*)&b;
	while (*pVFT) {
		(*pVFT)();
		pVFT++;
	}
	cout << endl;
}

int main() {

	Base b;
	Drived d;

	TestVirtual(b);
	TestVirtual(d);

	PrintPVTF(b,"Base");
	PrintPVTF(d,"Drived");

	return 0;
}