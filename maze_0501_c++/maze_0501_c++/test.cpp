#include <stdlib.h>
#include <iostream>

using namespace std;

//void Swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;	
//}

////声明一个名为Student的结构体类型
//struct Student
//{
//	int num;
//	char name[20];
//	char sex;
//};
//
////定义两个结构体
//Student student1, student2;
////上面是声明一个名为Student 结构体类型并定义了两个结构体变量
//
//class Student//声明一个类，类名为Student
//{
//	int num;
//	char name[20];
//	char sex;
//	void display()//成员函数
//	{
//		cout << "num:" << num << endl;
//		cout << "name:" << name << endl;
//		cout << "sex:" << sex << endl;
//	}
//};
//
//class Time
//{
//public:
//	int hour;
//	int minute;
//	int sec;
//};
//
//int main()
//{
//	Time t1;
//	cin >> t1.hour;
//	cin >> t1.minute;
//	cin >> t1.sec;
//
//	cout << t1.hour <<":"<< t1.minute <<":"<< t1.sec << endl;
//
//	//int a = 5;
//	//int* p = NULL;
//	//int& ra = a;
//	//Swap(ra, *p);
//
//	/*printf("%d", ra);*/
//
//
//	system("pause");
//	return 0;
//}

//class Time
//{
//public:
//	void set_time();
//	void show_time();
//private:
//	int hour;
//	int minute;
//	int sec;
//};
//
//int main()
//{
//
//	Time t1;
//	t1.set_time();
//	t1.show_time();
//
//	Time t2;
//	t2.set_time();
//	t2.show_time();
//
//	system("pause");
//	return 0;
//}
//
//void Time::set_time()
//{
//	cin >> hour;
//	cin >> minute;
//	cin >> sec;
//}
//
//void Time::show_time()
//{
//	cout << hour<<":" << minute << ":" << sec << endl;
//}

class V
{
public:
	void shuru();
	void calculate_v();
	void display_v();
private:
	float length;
	float width;
	float height;
	float v;
};

//int main()
//{
//	V v1;
//	v1.shuru();
//	v1.calculate_v();
//	v1.display_v();
//
//	V v2;
//	v2.shuru();
//	v2.calculate_v();
//	v2.display_v();
//
//	V v3;
//	v3.shuru();
//	v3.calculate_v();
//	v3.display_v();
//
//	system("pause");
//	return 0;
//}

//void V::shuru()
//{
//	cin >> length;
//	cin >> width;
//	cin >> height;
//}
//
//void V::calculate_v()
//{
//	float v = height * width * length;
//}
//
//void V::display_v()
//{
//	cout << height * width * length << endl;
//}
//
//////不能在类声明的时候对数据成员初始化
////class Time
////{
////	hour = 0;
////	minute = 0;
////	sec = 0;
////};
//
//class Time
//{
//public:
//	Time()
//	{
//		hour = 0;
//		minute = 0;
//		sec = 0;
//	}
//	void set_time();
//	void show_time();
//private:
//	int hour;
//	int minute;
//	int sec;
//};
//
//void Time::set_time()
//{
//	cin >> hour;
//	cin >> minute;
//	cin >> sec;
//}
//
//void Time::show_time()
//{
//	cout << hour << ":" << minute << ":" << sec << endl;
//}

//int main()
//{
//	Time t1;
//	t1.set_time();
//	t1.show_time();
//
//	Time t2;
//
//	t2.show_time();
//
//	system("pause");
//	return 0;
//}
//
//class Time
//{
//public:
//	Time();
//	void set_time();
//	void show_time();
//private:
//	int hour;
//	int minute;
//	int sec;
//};
//构造函数没有返回值
//Time::Time()//类外定义构造函数，并且初始化
//{
//	hour = 0;
//	minute = 0;
//	sec = 0;
//}
//
//void Time::set_time()
//{
//	cin >> hour;
//	cin >> minute;
//	cin >> sec;
//}
//
//void Time::show_time()
//{
//	cout << hour << ":" << minute << ":" << sec << endl;
//}
//

//int main()
//{
//	Time t1;
//	t1.set_time();
//	t1.show_time();
//
//	system("pause");
//	return 0;
//}

//class Box
//{
//public:
//	Box(int, int, int);
//	int volume();
//private:
//	int height;
//	int width;
//	int length;
//};
//
//Box::Box(int h,int w,int l)//构造函数的传参
//{
//	height = h;
//	width = w;
//	length = l;
//}
//
//int Box::volume()
//{
//	return (height*width*length);
//}

//int main()
//{
//	Box box1(12, 25, 40);
//	cout << box1.volume() << endl;
//
//	Box box2(15, 30, 50);
//	cout << box2.volume() << endl;
//
//
//	system("pause");
//	return 0;
//}

//class Box
//{
//public://在声明构造函数的时候指定默认值，而不是在定义的时候
//	Box(int h = 10, int w = 10, int len = 10);
//	int volume();
//private:
//	int height;
//	int width;
//	int length;
//};
//
//Box::Box(int h,int w,int len)
//{
//	height = h;
//	width = w;
//	length = len;
//}
//
//int Box::volume()
//{
//	return (height*width*length);
//}

//int main()
//{
//	Box box1;
//	cout << box1.volume() << endl;
//
//	Box box2(5);
//	cout << box2.volume() << endl;
//
//	Box box3(10, 20);
//	cout << box3.volume() << endl;
//
//	system("pause");
//	return 0;
//}

class Time
{
public:
	Time(int, int, int);//声明结构成员函数
	int hour;
	int minute;
	int sec;
	void get_time();//声明公有成员函数
};

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	sec = s;
}

void Time::get_time()
{
	cout << hour << ":" << minute << ":" << sec << endl;
}

int main()
{
	Time t1(10, 12, 30);//定义Time 类对象t1并初始化
	int *p1 = &t1.hour;//定义指向整形数据的指针变量p1,
	cout << *p1 << endl;//输出p1所指的数据成员t1.hour
	t1.get_time();

	
	Time *p2 = &t1;
	p2->get_time();
	
	void(Time::*p3)();
	p3 = &Time::get_time;
	(t1.*p3)();

	system("pause");
	return 0;
}