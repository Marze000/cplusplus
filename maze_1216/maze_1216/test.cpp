#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
using namespace std;

#if 0
class B {
public:
	B() {
		cout << "调用了构造函数" << endl;
	}
private:
	~B() {
		cout << "调用了析构函数" << endl;
	}
};

class A{
public:
	A() {
		cout << "调用了构造函数" << endl;
	}
	void destory() {
		delete this;
	}
private:
	~A() {
		cout << "调用了析构函数" << endl;
	}
};


class A{
protected:
	A() {
		cout << "调用了构造函数" << endl;
	}
	~A() {
		cout << "调用了析构函数" << endl;
	}
public:
	static A* create(){
		return new A();
	}
	void destory(){
		delete this;
	}
};


int main() {
	multimap<string, string>mp;
	mp["apple"] = "苹果";
	mp["peae"] = "梨";
	mp["apricot"] = "杏";
	mp["grape"] = "葡萄";
	mp["pineapple"] = "菠萝";
	mp["watermelon"] = "西瓜";
	mp["orange"] = "橙子";
	mp["lemon"] = "柠檬";
	mp["mango"] = "芒果";
	printf("%d\n", mp.size());

	for (auto&e : mp) {
		cout << e.first << "--->" << e.second << endl;
	}
	cout << endl;
	mp.erase("pineapple");
	mp["watermelon"] = "西瓜";
	printf("%d\n", mp.size());
	for (auto&e : mp) {
		cout << e.first << "--->" << e.second << endl;
	}
	cout << endl;
	cout << mp.at("apple")<< endl;
	printf("%d\n", mp.size());

	system("pause");
	return 0;
}


void TestSet(){
	// 用数组array中的元素构造set
	int array[] = {1,2,3,2,3,4,5};
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	// 正向打印set中的元素，从打印结果中可以看出：set可去重
	for (auto& e : s) {
		cout << e << " ";
	}
	cout << endl;
	// 直接把 value 插入进去即可
	//s.insert(6);
	//s.insert(7);
	//// 使用迭代器逆向打印set中的元素
	//for (auto it = s.rbegin(); it != s.rend(); ++it) {
	//	cout << *it << " ";
	//}
	cout << endl;
}


int main() {
	//int myints[] = {16,2,77,29 };
	//int n = sizeof(myints) / sizeof(myints[0]);
	//std::vector<int> fifth(myints, myints +n);
	//fifth.push_back(10);
	//fifth.push_back(20);
	//fifth.push_back(30);
	//std::vector<int>::iterator pos = find(fifth.begin(), fifth.end(), 77);
	//std::vector<int>::iterator it = fifth.begin();
	//for (; it != fifth.end(); ++it) {
	//	cout << *it << ' ';
	//}
	//cout << endl;
	//fifth.erase(pos);
	//it = fifth.begin();
	//for (; it != fifth.end(); ++it) {
	//	cout << *it << ' ';
	//}
	//cout << endl;

	int a[] = { 1, 2, 3, 4,5,6,7,8,9 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 实现删除v中的所有偶数
	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效
	// 对失效的迭代器进行++it，会导致程序崩溃
	vector<int>::iterator it = v.begin();
	while (it != v.end()){
		if (*it % 2 == 0) {
			it = v.erase(it);
		}
		++it;
	}
	for (it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	// 以上程序要改成下面这样，erase会返回删除位置的下一个位置
	//vector<int>::iterator it = v.begin();
	//while (it != v.end()){
	//	if (*it % 2 == 0)
	//		it = v.erase(it);
	//	else
	//		++it;
	//}

	system("pause");
	return 0;
}
class Date {
public:
	Date(int year,int month,int days)
		:_year(year)
		,_month(month)
		,_days(days)
	{
		cout <<this<< "调用了构造函数" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_days(d._days)
	{
		cout << this << "调用了拷贝构造函数" << endl;
	}
private:
	int _year;
	int _month;
	int _days;
};
#endif

class Date {
public:
	Date(int year = 2019, int month = 12, int day = 21)
		:_year(year)
		,_month(month)
		,_day(day) {
		
	}
	bool operator <(const Date&d)const {
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator >(const Date&d)const {
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
	// 重载 << 符号
	friend ostream& operator<<(ostream& _cout, const Date&d) {
		_cout << d._year << "-" << d._month << "-" << d._day << endl;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main() {

	priority_queue<Date> q1;
	q1.push(Date(2018, 10, 29));
	q1.push(Date(2018, 10, 28));
	q1.push(Date(2018, 10, 30));
	cout << q1.top() << endl;
	// 如果要创建小堆，需要用户提供>的重载
	priority_queue<Date, vector<Date>, greater<Date>> q2;
	q2.push(Date(2018, 10, 29));
	q2.push(Date(2018, 10, 28));
	q2.push(Date(2018, 10, 30));
	cout << q2.top() << endl;

	//// 默认情况下，创建的是大堆，其底层按照小于号比较
	//vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
	//priority_queue<int> q1(v.begin(),v.end());

	//cout << q1.top() << endl;
	//// 如果要创建小堆，将第三个模板参数换成greater比较方式
	//priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	//cout << q2.top() << endl;

	//deque<int>d1;
	//deque<int>d2(4, 100);
	//deque<int>d3(d2.begin(), d2.end());
	//deque<int>d4(d2);

	//list<Date>l2;
	//Date d(2019, 12, 20);
	//l2.push_back(d);
	//l2.emplace_back(2019,12,21);
	//l2.emplace_front(2019, 12, 22);

	//// 以数组为迭代器区间构造l5
	//int array[] = { 16,2,77,29 };
	//int n = sizeof(array) / sizeof(array[0]);
	//std::list<int> l5(array, array + n);
	//// list<int>::iterator it = l5.begin();
	//auto it = l5.begin();
	//while (it != l5.end()) {
	//	l5.erase(it);
	//	++it;
	//}


	///// 用迭代器方式打印l5中的元素
	//std::list<int>::iterator it = l5.begin();
	//for (; it != l5.end(); it++) {
	//	std::cout << *it << " ";
	//}
	//std::cout << endl;
	//for (auto& e : l5) {
	//	std::cout << e << " ";
	//}
	//std::cout << endl;


	system("pause");
	return 0;
}
