#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class String {
public:
	String(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
	{
		String temp(s._str);
		swap(temp._str, _str);
	}

	~String() {
		if (_str) {
			delete[]_str;
		}
	}

	String operator = (const String &s) {
		String temp(s._str);
		swap(temp._str, _str);
		return *this;
	}
	String operator=(String s) {
		swap(s._str, _str);
		return *this;
	}

private:
	char* _str;
};

int main()
{
	String s1 = "hehe";
	String s2(s1);
	String s3 = s2;
	String s4;
	s4 = s1;


	system("pause");
	return 0;
}


class Mystring {
public:
	Mystring(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		str_ = new char[strlen(str) + 1];
		strcpy(str_, str);
	}

	Mystring(const Mystring& s)
		:str_(new char[strlen(s.str_) + 1])
	{
		strcpy(str_, s.str_);
	}

	~Mystring() {
		if (str_) {
			delete[] str_;
		}
	}

	Mystring& operator =(const Mystring& s)
	{
		if (this != &s) {
			char* pstr = new char[strlen(s.str_) + 1];
			strcpy(pstr, s.str_);
			delete str_;
			str_ = pstr;
		}
		return *this;
	}
private:
	char* str_;
};

class String {
public:
	String(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& str)
		:_str(new char[strlen(str._str) + 1])
	{
		strcpy(_str, str._str);
	}

	String& operator = (const String& other) {
		if (this != &other) {
			char *pstr = new char[strlen(other._str) + 1];
			strcpy(pstr, other._str);
			delete _str;
			_str = pstr;
		}
		return *this;
	}

	~String() {
		if (_str) {
			delete[] _str;
		}
	}

private:
	char* _str;
};
int main()
{
	String str("hehehe");
	String  str1(str);
	String  str2;
	str2 = str;


	system("pause");
	return 0;
}

