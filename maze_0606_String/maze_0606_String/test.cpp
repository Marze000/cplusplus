#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using namespace std;

//Ç³¿½±´
class String
{
public:
	String(const char* str = ""){
		if (str == nullptr){
			str = "";
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	
	String(const String &s)
		:_str(s._str)
	{}

	String& operator = (const String &s){
		_str = s._str;
		return *this;
	}

	~String(){
		if (_str){
			delete[] _str;
		}
	}
private:
	char* _str;
};

class String
{
public:
	String(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String &s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	String& operator = (const String &s)
	{
		if (this != &s) {
			delete _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}

	String& operator = (const String &s)
	{
		if (this != &s) {
			char* pstr = new char[strlen(s._str) + 1];
			strcpy(pstr, s._str);
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


class String
{
public:
	String(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String &s)
		:_str(nullptr)
	{
		String strTemp(s._str);
		swap(_str, strTemp._str);
	}

	String& operator = (const String &s)
	{
		if (this != &s) 
		{
			String strTemp(s._str);
			swap(_str, strTemp._str);
		}
		return *this;
	}

	String& operator = (String s)
	{
		swap(_str, s._str);
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
	String s1;
	String s2("hello");
	s1 = s2;

	system("pause");
	return 0;
}