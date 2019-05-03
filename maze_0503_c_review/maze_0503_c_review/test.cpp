//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 2*i+1; ++j)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	for (int i = 0; i < 4; ++i)
//	{
//		for (int j = 7; j >  2 * i; --j)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	system("pause");
//	return 0;
//}
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//class Student//声明基类
//{
//public:
//	void get_value()//输入基类成员函数
//	{
//		cin >> num >> name >> sex;
//	}
//
//	//输入基类数据的成员函数
//	void display()
//	{
//		cout << "name:" << num << endl;
//		cout << "name:" << name << endl;
//		cout << "sex:" << sex << endl;
//	}
//private: //基类私有成员
//	int num;
//	string name;
//	char sec;
//};

//
////以 public 方式声明派生类 Student1
//class Student1:public Student
//{
//public:
//	void get_value_1() //输入派生类数据
//	{
//		cin >> age >> addr;
//	}
//	void display_1()
//	{
//		//此处不能引用基类的私有成员
//		//下面是引用派生类的私有成员
//		cout << "age:" << age << endl;
//		cout << "address:" << addr << endl;
//	}
//private:
//	int age;
//	string addr;
//};
//
//int main()
//{
//	//定义派生类Student1 的对象 stud
//	Student1 stud;
//
//	//调用基类的公有成员函数,输入基类中3个数据成员的值
//	stud.get_value();
//
//	//调用派生类的公有成员函数,输入派生类两个数据成员的值
//	stud.get_value_1();
//
//	//调用基类的公有成员函数,输出基类中3个数据成员的值
//	stud.display();
//
//	//调用派生类的公有成员函数,输出派生类中两个数据成员的值
//	stud.display_1();
//
//
//	system("pause");
//	return 0;
//}


//class Student1:private Student
//{
//public:
//	void get_value_1()
//	{
//		//调用基类的公用函数输入基类3个数据
//		get_value();
//		cin >> age >> addr;//输入派生类的两个数据
//	}
//
//	//输出5个数据成员的值
//	void display_1()
//	{
//		display();//调用基公用成员函数,输出3个数据成员的值
//
//		//输出派生类的私有数据成员
//		cout << "age:" << age << endl;
//		cout << "address:" << addr << endl;
//	}
//private:
//	int age;
//	string addr;
//};
//
//int main()
//{
//	//定义一个Student1 类的对象 stud1
//	Student1 stud1;
//
//	//私有基类的公有成员函数在派生类中是私有函数;
//	//stud1.display();
//
//	//display_1函数是Student1 类的公用函数
//	stud1.display_1();
//
//	//外界不能引用派生类的私有成员
//	//stud1.age = 18;
//
//
//	system("pause");
//	return 0;
//}

//
//class Student
//{
//public:
//
//protected:
//	int num;
//	string name;
//	char sec;
//};
//
//class Student1 :protected Student
//{
//public:
//	void get_value1(); //派生类公用成员函数
//	void display1();  //派生类公用成员函数
//private:
//	int age;  //派生类私有数据成员
//	string addr; //派生类私有数据成员
//};
//
////定义派生类公用成员函数
//void Student1::get_value1()
//{
//	cin >> num >> name >> sec;
//	cin >> age >> addr;
//}
//
//void Student1::display1()
//{
//	//引用基类的保护成员
//	cout << "num:" << num << endl;
//	cout << "name:" << name << endl;
//	cout << "sex:" << sec << endl;
//
//	//引用派生类的私有成员
//	cout << "age:" << age << endl;
//	cout << "address:" << addr << endl;
//}
//
//int main()
//{
//	Student1 stud1; //stud1 是派生类 Student1 类的对象
//
//	//派生类的公用成员函数,输入数据
//	stud1.get_value1();
//	stud1.display1();
//
//	//stud1.num = 1100; //这是错误的
//	system("pause");
//	return 0;
//}


