/********************************************************************
多态性:向不同的对象发送同一个信息,不同的对象会在接收的时候产生不同的行为

c++里的多态性:	具有不同的功能函数可以用同一个函数名,这样就
				可以实现用一个函数名调用不同内容的函数
多态性分为两种
	静态多态性:通过函数重载实现,由函数重载和运算符形成的.
			   要求在编译的时候就能知道调用函数的全部信息
			   所以又称之为编译时的多态性,虽然效率高,但缺乏灵活
								
	动态多态性:在运行的时候确定操作的对象,称为之运行时的多态性,通过虚函数实现
***********************************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;

class Point
{
public:
	//有默认参数的构造函数
	Point(double x = 0, double y = 0);

	//声明设置坐标值的函数
	void setpoint(double, double);

	//定义获取坐标的函数
	//const 作用是:只永许函数引用类中的数据,不可以修改
	double get_x() const{ return x; }
	double get_y() const{ return y; }

	//友元重载运算符
	friend ostream & operator<<(ostream &, const Point &);

protected:
	double x, y;

};

Point::Point(double a, double b)
{
	x = a;
	y = b;
}

void Point::setpoint(double a, double b)
{
	x = a;
	y = b;
}

//重载运算符"<<" ,使之能输出点的坐标
ostream & operator<<(ostream &output, const Point &p)
{
	output << "[" << p.x << "," << p.y << "]" << endl;
	return output;
}

//Circle 是 Point 的公用派生
class Circle :public Point
{
public:
	Circle(double x = 0, double y = 0, double r = 0);

	void setRadius(double);
	double getRadius()const;
	double area()const;

	//重载运算符"<<"
	friend ostream & operator<<(ostream &, const Circle &);
private:
	double radius;
};

//int main()
//{
//	//定义对象的同时隐士调用构造函数
//	Point p(3.5, 6.4);
//	cout << "x=" << p.get_x() << ",y=" << p.get_y() << endl;
//	
//	p.setpoint(8.5, 6.8);
//	cout << "p(new):" << p << endl;
//
//
//	system("pause")9;
//	return 0;
//}

/************************************************************************
利用虚函数实现动态多态性
	虚函数的作用是:永许在派生类重新定义与基类同名的函数,并且可以通过基类指针
				   或引用来访问基类和派生类的同名函数

	使用方法:在基类中用 virtual 声明成员函数为虚函数,在类外定义的时候不加virtual

	所谓虚函数就是:在基类声明函数是虚拟的,并不是实际存在的,然后在派生类中
				   真正的定义函数,
*************************************************************************/


