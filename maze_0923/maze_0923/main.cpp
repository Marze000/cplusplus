#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class A {
	A() {
		printf("A()\n");
	}
public:
	static A& get() {
		static A a;
		return a;
	}
};

// 696609771
int main() {
	A::get();
	// 要求1：声明一个指向含有10个元素的数组指针
	// 要球2：其中每一个元素是一个函数指针
	// 要求3：该函数的返回值是 int 
	// 要求4：参数类型是 int*
	// int (*(*p)[10])(int*);

	char s[] = "\\123456\123456\t";
	printf("%d\n", strlen(s));

	int c[4][5] = {
		{0, 1, 2, 3, 8 },
		{4, 7, 6, 7, 9 },
		{10,11,12,13,14},
		{15,16,17,18,19}
	};
	cout << (*c)[1] + 1 << endl;

	int(*pc)[5] = c;
	cout << (*pc[1]+2) << endl;
	cout << *(*(pc+1) + 2) << endl;

	 char str[20];
	str = gets();
	 可以一次性读取输出流的字符，直到遇到回车才结束
	 gets(str);
	 语法错误
	str[] = getch();
	 不接受空格，空格会被放到缓冲区等待下一次被取出
	scanf("%s", str);
	 cout << str << endl;
	char a[80] = "0123\1399";
	cout << sizeof(a) << endl;
	// 看看\后面的数字能否被转移，如果不能被转移则就已经是末尾了
	cout << strlen(a) << endl;

	在 C语言是可以通过编译的，但是C++中不可以，
	 因为sp的类型是char* 但是hello的类型是 const char*
	char* sp;
	char s[10];
	sp = "hello";

	 因为数组名知识数组的首地址，无法作为指针去指向hello
	char* sp, s[10];
	s = "hello";

	char str1[10] = "computer";
	char str2[10];//没有被初始化 “烫烫烫”
	// 由于str1是首地址，内存中的值是computer
	// 所以得需要要一个指针去指向，而str2也是一个数组名，不是指针
	str2 = str1;

	/* 数组初始化错误
	char mark[];
	mark = "program";
	*/

	system("pause");
	return 0;
}

#if 0
struct Goods{
	string _name;
	double _price;
};

struct Compare{
	bool operator()(const Goods& gl, const Goods& gr){
		return gl._price <= gr._price;
	}
};

int main() {
	Goods gds[] = 
	{ 
		{ "苹果", 2.1 }, { "相交", 3 }, 
		{ "橙子", 2.2 }, {"菠萝", 1.5}
	};
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), 
		[](const Goods& l, const Goods& r){
		return l._price <= r._price;
	});
	for (int i = 0; i < sizeof(gds) / sizeof(gds[0]);++i) {
		cout << gds[i]._name <<" "<< gds[i]._price << endl;
	}
	cout << endl;

	Goods gds[] = 
	{ 
		{ "苹果", 2.1 }, { "香蕉", 3 },
		{ "橙子", 2.2 }, {"菠萝", 1.5} 
	};
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());

	for (auto&e : gds) {
		cout << e._price<<' ';
		cout << e._name << endl;
	}
	cout << endl;

	int a[10] = { 1,4,5,2,7,8,0,6,3,9 };
	std::sort(a, a+sizeof(a) / sizeof(a[0]),less<int>());
	for (auto& e : a) {
		cout << e << ' ';
	}
	cout << endl;


	system("pause");
	return 0;
}
int main() {
	int a = 10;
	int &b = a;

	int a = 10;
	int &&b = a + 1;
	cout << b << endl;

	system("pause");
	return 0;
}

int main(){
	cout << "-------下面是引用左值--------" << endl;
	int a = 5;
	int &add_a = a;

	cout << "   a  =" << a << "    " << "    &a = " << &a << endl;
	cout << "add_a =" << add_a << "    " << "&add_a = " << &add_a << endl;

	cout << "-------下面是引用右值--------" << endl;
	int b = 10;
	int &&add_b = b + 1;
	cout << "   b  =" << b << "    " << "    &b = " << &b << endl;
	cout << "add_b =" << add_b << "    " << "&add_b = " << &add_b << endl;
	add_b++;
	cout << "add_b++ =" << add_b << "    " << "&add_b++ = " << &add_b << endl;
	cout << "-----------------------" << endl;

	system("pause");
	return 0;
}

class Person{
public:
	Person(string name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(const Person& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#if 0
	Person(Person&& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#else
	Person(Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}
#endif
private:
	string _name;
	string _sex;
	int _age;
};

Person GetTempPerson(){
	Person p("prety", "male", 18);
	return p;
}

int main() {
	Person p(GetTempPerson());

	system("pause");
	return 0;
}
class String{
public:
	// 构造函数
	String(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& str) {
		_str = new char[strlen(str._str) + 1];
		strcpy(_str, str._str);
	}

	// 赋值运算符重载
	String& operator=(const String& str) {
		if (this != &str) {
			char* temp = new char[strlen(str._str) + 1];
			strcpy(temp, str._str);
			delete[]_str;
			_str = temp;
		}
		return *this;
	}

	//移动构造函数
	String(String&& s) : _str(s._str){
		s._str = nullptr;
	}

	// 析构函数
	~String() {
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}

private:
	char* _str;

};

int main(){
	String s1("hello world");
	/*C++11中，std::move()函数位于 头文件中，这个函数名字具有迷惑性，
		它并不搬移任何东西，唯一的功能就是：将一个左值强制转化为右值引用，
		通过右值引用使用该值，实现移动语义。
		注意：被转化的左值，其声明周期并没有随着左右值的转化而改变，
		即std::move转化的左值变量lvalue不会被销毁。*/
	String s2(move(s1));

	String s3(s2);

	system("pause");
	return 0;
}

int main() {
	int a = 10;
	// int&& ra; // 编译失败，没有进行初始化
	int&& ra = a; // 编译失败，a是一个左值
	// ra是匿名常量10的别名
	//const int&& ra = 10;
	cout << ra << endl;

	system("pause");
	return 0;
}

class String {
public:
	// 构造函数
	String(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& str) {
		_str = new char[strlen(str._str) + 1];
		strcpy(_str, str._str);
	}

	// 赋值运算符重载
	String& operator=(const String& str) {
		if (this != &str) {
			char* temp = new char[strlen(str._str) + 1];
			strcpy(temp, str._str);
			delete[]_str;
			_str = temp;
		}
		return *this;
	}
	// 析构函数
	~String() {
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

String GetString(const char* pStr) {
	return String(pStr);
}

int main() {
	// 给一个匿名对象取别名
	// 延长匿名对象的生命周期
	String&& s = GetString("hello");
	
	system("pause");
	return 0;
}
#endif