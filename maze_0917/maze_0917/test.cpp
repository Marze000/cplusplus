#include "head.h"



#if 1
int main() {
	const char* p = "Heelo World1";

	char a[] = "Hello World2";

	cout << p[2] << endl;

	a[2] = 'A';
	cout << a << endl;

	const char* p1 = "Hello World1";
	// 16384 字节
	//cout << sizeof(a) / 1024 << endl;
	system("pause");
	return 0;
}
class BOOK  {
private:
	string _bookISBN;  //书的ISBN号
	float _price;    //书的价格

public:
	//定义了一个成员函数，这个函数即是那个“期待一个实参为类类型的函数”
	//这个函数用于比较两本书的ISBN号是否相同
	bool isSameISBN(const BOOK & other) {
		return (other._bookISBN == _bookISBN);
	}

	//类的构造函数，即那个“能够用一个参数进行调用的构造函数”
	//（虽然它有两个形参，但其中一个有默认实参，只用一个参数也能进行调用）
	BOOK(string ISBN, float price = 0.0f)
		:_bookISBN(ISBN)
		, _price(price) 
	{}
};

int main(){
	BOOK A("A-A-A");
	BOOK B("B-B-B");

	cout << A.isSameISBN(B) << endl;   //正经地进行比较，无需发生转换

	cout << A.isSameISBN(string("A-A-A")) << endl; 
	//此处即发生一个隐式转换：string类型-->BOOK类型，
	//借助BOOK的构造函数进行转换，以满足isSameISBN函数的参数期待。

	cout << A.isSameISBN(BOOK("A-A-A")) << endl; 
	//显式创建临时对象，也即是编译器干的事情。

	system("pause");
	return 0;
}

class A {
public:
	A() {
		cout << "hehe" << endl;
	}
	~A() {
		cout << "~hehe" << endl;
	}
	void dispaly()const {
		cout << "display()" << endl;
	}
	void dis() {
		cout << "haha" << endl;
	}

	void dis()const {
		cout << "haha" << endl;
	}
private:
	int a;
};


int main() {

	//A a;
	//a.dispaly();
	//A const a1;
	//a1.dispaly();
	//a.~A();

	system("pause");
	return 0;
}
int main() {
	const char * arr = "123";
	char * brr = "123";
	const char crr[] = "123";
	char drr[] = "123";

	system("pause");
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int isbig(string s1, string s2) {
	if (s1 == "") {
		return -1;
	}
	if (s2 == "") {
		return 1;
	}
	for (int i = 0; i < s1.size()&& s2.size(); ++i) {
		while (s1[i] != s2[i] && i < s1.size() && i<s2.size()) {
			if (s1[i] > s2[i]) {
				return 1;
			}
			if (s1[i] < s2[i]) {
				return -1;
			}
			++i;
		}
		if (s1[i] == s2[i]) {
			return 0;
		}
	}
}

int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		int s = isbig(str1, str2);
		if(s > 0){}
		cout << s << endl;
	}
	return 0;
}

__attribute((constructor))void before(){
	printf("before main\n");
}

int main() {
	//dis();
	cout << "this is main()\n" << endl;
	system("pause");
	return 0;
}

class A {
public:
	A() {
		cout << "A()" << endl;
	}
	~A() {
		cout << "~A()" << endl;
	}
};
class B :public A{
public:
	B() {
		cout << "B()" << endl;
	}
	~B() {
		cout << "~B()" << endl;
	}
};
extern int a;
void test() {
	cout << a << endl;
}
int a = 10;
int main() {
	//dis();
	test();
	cout << a << endl;
	system("pause");
	return 0;
}
#endif
