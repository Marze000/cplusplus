#include <iostream>
#include <stdlib.h>

using namespace std;

//class Complex
//{
//public:
//	Complex() { real = 0; imag = 0; }
//	Complex(double r, double i) { real = r; imag = i; }
//	//Complex operator+(Complex &c2);
//	Complex complex_add(Complex &c2);
//	void display();
//private:
//	double real;
//	double imag;
//};
//
////Complex Complex::operator+(Complex &c2);
//Complex Complex::complex_add(Complex &c2)
//{
//	Complex c;
//	c.real = real + c2.real;
//	c.imag = imag + c2.imag;
//	return c;
//}
//
//void Complex::display()
//{
//	cout << "(" << real << "," << imag << "i)" << endl;
//}
//
//int main()
//{
//	Complex c1(3, 4);
//	Complex c2(5, -10);
//	Complex c3;
//	//c3 =c1+c2;
//	c3 = c1.complex_add(c2);
//	cout << "c1 = "; c1.display();
//	cout << "c2 = "; c2.display();
//	cout << "c1+c2 = "; c3.display();
//
//	system("pause");
//	return 0;
//}
//
//class Complex
//{
//public:
//	Complex() { real = 0; imag = 0; }
//	Complex(double r, double i) { real = r; imag = i; }
//	friend Complex operator+(Complex &c1, Complex &c2);
//	void display();
//private:
//	double real;
//	double imag;
//};
//
//Complex operator+(Complex &c1, Complex &c2)
//{
//	return Complex(c1.real + c2.real, c1.imag + c2.imag);
//}
//
//void Complex::display()
//{
//	cout << "(" << real << "," << imag << "i)" << endl;
//}
//
//int main()
//{
//	Complex c1(3, 4);
//	Complex c2(5, -10);
//	Complex c3;
//	c3 = c1 + c2;
//	cout << "c1 = "; c1.display();
//	cout << "c2 = "; c2.display();
//	cout << "c1+c2 = "; c3.display();
//
//	system("pause");
//	return 0;
//}

class String
{
public:
	String() {p = NULL;}
	String(char* str);
	friend bool operator>(String &string, String &string2);
	void display();
private:
	char* p;
};

String::String(char *str)
{
	p = str;
}

void String::display()
{
	cout << p;
}

//int main()
//{
//	String string1("Hello");
//	String string2("Book");
//	string1.display();
//	cout << endl;
//	string2.display();
//	cout << endl;
//
//	system("pause");
//	return 0;
//}


class Time
{
public:
	Time() { minute = 0; sec = 0; }
	Time(int m,int s):minute(m),sec(s){}
	Time operator++();
	void display() { cout << minute << ":" << sec << endl; }
private:
	int minute;
	int sec;
};

Time Time::operator++()
{
	if (++sec >= 60)
	{
		sec -= 60;
		++minute;
	}
	return *this;
}

int main()
{
	Time time1(34, 5);
	for (int i = 0; i < 61; ++i)
	{
		++time1;
		time1.display();
	}

	system("pause");
	return 0;
}