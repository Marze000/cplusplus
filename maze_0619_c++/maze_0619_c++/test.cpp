#include <assert.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Mystring {
public:
	Mystring(const char* str = "")
		:_str(new char[strlen(str)]+1)
	{
		if (str == nullptr) {
			assert(false);
			return;
		}
		strcpy(_str, str);
	}

	~Mystring() {

	}


	Mystring(const Mystring&s) 
		:_str(new char[strlen(s._str) + 1])
	{
		//拷贝构造函数，必须得先申请一块内存
		//然后再把对应的值拷贝，并没有拷贝地址
		strcpy(_str, s._str);
	}

private:
	char* _str;
};

int main(){



	system("pause");
	return 0;
}