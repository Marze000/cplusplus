#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int isSuShu(int n){
	for (int i = 2; i < sqrt(n)+1; ++i){
		if (n%i == 0){
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int N = n / 2;
		int small = N;
		int big = N;

		while (big != n) {
			while (isSuShu(big) != 1 && big < n) {
				++big;
			}

			small = N;
			while (small > 1) {
				if ((isSuShu(small) == 1) && small + big == n) {
					break;
				}
				else { --small; }
			}

			if (small + big == n) {
				break;
			}
			else { ++big; }
		}

		cout << small << endl;
		cout << big << endl;
	}
	system("pause");
	return 0;
}

#include <iostream>
#include <stdlib.h>
using namespace std;

class Date
{
public:
	Date(int year)
		:_year(year)
	{}
	//	explicit Date(int year)
	//	:_year(year)
	//{}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2018);

	// 用一个整形变量给日期类型对象赋值
	// 实际编译器背后会用2019构造一个无名对象，最后用无名对象给d1对象进行赋值
	d1 = 2019;
}


int main()
{
	TestDate();

	system("pause");
	return 0;
}

比特科技
上述代码可读性不是很好，用explicit修饰构造函数，
将会禁止单参构造函数的隐式转换。

2. static成员
声明为static的类成员称为类的静态成员，用static修饰的成员变量，称之为静态成员变量；用static修饰的
成员函数，称之为静态成员函数。静态的成员变量一定要在类外进行初始化
面试题：实现一个类，计算中程序中创建出了多少个类对象。

1. 静态成员为所有类对象所共享，不属于某个具体的实例
