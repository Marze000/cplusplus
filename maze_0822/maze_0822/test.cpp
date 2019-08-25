#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <functional> // greater算法的头文件
#include <list>
using namespace std;

#if 1
// insert/erase导致的迭代器失效
int main(){
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 使用find查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	// 删除pos位置的数据，导致pos迭代器失效。
	v.erase(pos);
	cout << *pos << endl; // 此处会导致非法访问
	// 在pos位置插入数据，导致pos迭代器失效。
	// insert会导致迭代器失效，是因为insert可
	// 能会导致增容，增容后pos还指向原来的空间，而原来的空间已经释放了。
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl; // 此处会导致非法访问

	system("pause");
	return 0;
}

int main(){
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 实现删除v中的所有偶数
	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效
	// 对失效的迭代器进行++it，会导致程序崩溃
	vector<int>::iterator it = v.begin();
	while (it != v.end()){
		if (*it % 2 == 0) {
			v.erase(it);
		}
		++it;
	}
	//修改程序 为下面：
	//erase会返回删除位置的下一个位置
	vector<int>::iterator it = v.begin();
	while (it != v.end()){
		if (*it % 2 == 0) {
			it = v.erase(it);
		}
		else {
			++it;
		}
	}
	return 0;
}

int main() {
	cout << "hello";
	return 0;
}

int main() {
	string str1 = "hello maze";
	string str2 = str1;
	printf("%p\n", str1.c_str());
	printf("%p\n", str2.c_str());
	str1[0] = 'W';
	str2[0] = 'W';
	printf("%p\n", str1.c_str());
	printf("%p\n", str2.c_str());

	system("pause");
	return 0;
}

char *mystrcpy(char *str, const char *ptr){
	char *temp = str;
	while ((*str++ = *ptr++) != '\0');
	return temp;
}



char* mystrcpy(char* s1, const char *s2) {
	int len = strlen(s2);
	char* tmp = s1;
	while (len--) {
		*s1++ = *s2++;
	}
	*s1 = '\0';
	return tmp;
}

void test() {
	char str1[] = "heheheheh";
	char str2[] = "maze";
	printf("%s\n",mystrcpy(str1, str2));
}

int mystrlen(char* s) {
	int count = 0;
	while (*(s++) != '\0') {
		++count;
	}
	return count;
}

int mystrlen_nor(char* s) {
	if (*s == '\0') {
		return 0;
	}
	return 1 + mystrlen(s + 1);
}
void test() {
	char str1[] = "heheh";
	int len = mystrlen(str1);
	printf("%d\n", len);
	printf("%d\n", mystrlen_nor(str1));
}

void test() {
	
}

int main() {
	test();
	system("pause");
	return 0;
}

int main(){
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	// 使用正向迭代器正向list中的元素
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;
	// 使用反向迭代器逆向打印list中的元素
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	// cosnt的正向迭代器
	auto cit = l.cbegin();
	cout << typeid(cit).name() << endl;
	//*cit = 10; 此行代码编译失败，因为cit为const_iterator类型的迭代器

	system("pause");
	return 0;
}
void PrintDeque(const std::deque<int>& d){
	for (const auto& e : d) {
		cout << e << " ";
	}
	cout << endl;
}

void TestDeque2(){
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
	// 利用正向迭代器打印deque中的元素
	for (auto it = d.cbegin(); it != d.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	auto cit = d.cbegin();
	//*it = 100; 该条语句编译失败，it为const迭代器，
	// 其指向空间元素值不能修改
	// 利用反向迭代器逆向打印deque中的元素
	for (auto it = d.crbegin(); it != d.crend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void TestDeque3(){
	// 列表方式初始化，C++11语法
	deque<int> d1{ 3,4,5 };
	// 在deque的尾部插入5，头部插入1，并打印
	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1);
	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;
	// 在deque的尾部构造6，头部构造0
	// 注意：如果是内置类型元素，
	// emplace_back与push_back emplace_front与push_front的效率形同
	// 如果是自定义类型元素
	// emplace_back/emplace_front的效率更高，
	// 这两个操作直接在尾部或者头部构造元素
	// push_back/push_front的效率低，该操作时先将元素构造好，
	// 然后拷贝到尾部或头部
	d1.emplace_back(7);
	d1.emplace_front(1);
	PrintDeque(d1);
	// 在deque的begin位置插入元素0
	d1.insert(d1.begin(), 0);
	PrintDeque(d1);
	// 删除deque首部与尾部元素
	d1.pop_front();
	d1.pop_back();
	d1.erase(d1.begin());
	PrintDeque(d1);
	// 将deque中的元素清空
	d1.clear();
	cout << d1.size() << endl;
}
// 问题：如果要对deque中的元素进行排序，以下的效率高吗？
void TestDequeSort(){
	int array[] = { 5, 2, 1, 9, 6, 3, 8, 7, 4, 0 };
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d);
	// 利用标准库中的算法对deque中的元素进行升序排序
	sort(d.begin(), d.end());
	PrintDeque(d);
}
/*
上述对deque中排序操作的效率是非常低的，
当对deque排序时，需要多次对deque中的元素进行整体遍历，
而deque中的元素整体遍历时效率比较低，
这是因为deque底层的空间不连续，
如果要进行整体遍历，在某段空间的默认或首部时，
必须要计算下一段或者前一段空间的位置，导致deque的效率比较底下。
*/
int main() {
	TestDeque2();

	system("pause");
	return 0;
}
void TestPriorityQueue(){
	// 默认情况下，创建的是大堆，其底层按照小于号比较
	vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
	priority_queue<int> q1;
	for (auto& e : v) {
		q1.push(e);
	}
	cout << q1.top() << endl;
	// 如果要创建小堆，将第三个模板参数换成greater比较方式
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	cout << q2.top() << endl;
}

int main() {
	TestPriorityQueue();

	system("pause");
	return 0;
}
#endif
template<class T, class Con = deque<T>>
class Stack
{
public:
	Stack() {}
	void Push(const T& x) { _c.push_back(x); }
	void Pop() { _c.pop_back(); }
	T& Top() { return _c.back(); }
	const T& Top()const { return _c.back(); }
	size_t Size()const { return _c.size(); }
	bool Empty()const { return _c.empty(); }
private:
	Con _c;
};
template<class T, class Con = deque<T>>
class Queue
{
public:
	Queue() {}
	void Push(const T& x) { _c.push_back(x); }
	void Pop() { _c.pop_front(); }
	T& Back() { return _c.back(); }
	const T& Back()const { return _c.back(); }
	T& Front() { return _c.front(); }
	const T& Front()const { return _c.front(); }
	size_t Size()const { return _c.size(); }
	bool Empty()const { return _c.empty(); }
private:
	Con _c;
};
