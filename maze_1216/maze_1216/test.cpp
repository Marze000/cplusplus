#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <set>
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

#endif

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
	TestSet();
	system("pause");
	return 0;
}
