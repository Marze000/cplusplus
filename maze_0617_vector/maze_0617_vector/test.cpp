#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	
	
	
	int a[] = { 10,20,30,40,50 };
	vector<int> array(a, a + sizeof(a) / sizeof(int));

	迭代器失效的场景
	auto it = array.begin();
	while (it != array.end()){
		if (*it % 2 == 0) {
			array.erase(it);
		}else {
			++it;
		}
	}

	for (size_t i = 0; i < array.size(); ++i) {
		cout << a[i] << " ";
	}



	vector<int>::iterator it = array.begin();
	while (it != array.end())
	{
		if (*it % 2 == 0)
			it = array.erase(it);
		else
			++it;
	}

	size_t len = array.size();
	for (auto e : len) {
		cout << e << " ";
	}

	for (auto x : array) {
		cout << x << " ";
	}
	cout << endl;

	auto pos = find(array.begin(), array.end(), 30);

	删除元素导致迭代器失效
	array.erase(pos);
	此处无法解引用
	cout << *pos<< endl;

	array.insert(pos, 50);




	int a[] = { 1,2,3,4 };
	vector<int>arr(a, a + sizeof(a) / sizeof(int));

	for (auto x : arr) {
		cout << x << " ";
	}

	vector<int>ayy;

	
	for (size_t i = 0; i < arr.size(); ++i) {
		cout << " " << arr[i];
		 1 2 3 4
	}
	arr.swap(ayy);
	cout << endl;
	for (size_t i = 0; i < arr.size(); ++i) {
		cout << " " << arr[i];
	}
	cout << endl;
	for (size_t i = 0; i < ayy.size(); ++i) {
		cout << " " << ayy[i];
		 1 2 3 4
	}
	cout << endl;



	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	 使用find查找3所在位置的iterator
	auto pos = find(v.begin(), v.end(), 3);
	 在pos位置之前插入30
	v.insert(pos, 30);
	auto it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	第三个参数不是下标索引 ，而是值

	使用find 如果找不到代码就会崩溃
	pos = find(v.begin(), v.end(), 5);

	 删除pos位置的数据
	v.erase(pos);
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}

	vector<int>v;
	v.push_back('a');
	v.push_back('b');
	v.push_back('c');
	v.push_back('d');
	v.push_back('e');
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i]<< " ";
	}
	cout << endl;

	v.pop_back();
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v.begin(), v.end(), 'c');
	v.insert(pos ,'o');
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

	vector <int>::iterator pot = find(v.begin(), v.end(), 'd');
	v.erase(pot);
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;




	void push_back(const value_type& val); 尾插
	void pop_back(); 尾删
	InputIterator find(InputIterator first,
		InputIteratorlast, const T& val);

	iterator insert(iterator position, 
		constvalue_type& val);//在position之前插入val
	
	iterator erase(iterator position);// 删除position位置的数据
	void swap(vector& x); //交换两个vector的数据空间
	reference operator[] (size_type n);// 像数组一样访问


	std::vector<int> myvector;
	for (int i = 1; i < 10; i++) {
		myvector.push_back(i);
	}

	有效元素减小为5，5后面的元素全部丢去
	myvector.resize(5);
	5后面的元素3个元素初始化为100
	myvector.resize(8, 100);
	将有效元素设置为12；程序员没有自动设置的元素为0
	myvector.resize(12);

	for (int i = 0; i < myvector.size(); i++) {
		std::cout << myvector[i] << ' ';
	}
	std::cout << '\n';



	vector<int>v;
	int n = v.capacity();
	v.reserve(100);
	for (int i = 0; i < 100; ++i) {
		v.push_back('a');
		if (n != v.capacity()) {
			n = v.capacity();
			cout << n << endl;
		}
	}

	vector<int> arr;
	size_t n = arr.capacity();
	for (int i = 0; i < 100; ++i) {
		arr.push_back('a');
		当容器容量不足时编译器自动扩容
		if (n != arr.capacity()) {
			n = arr.capacity();
			cout << n << endl;
		}
	}

	std::vector<int>arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	vector<int>::iterator it = arr.begin();
	while (it!=arr.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = arr.begin();
	while (it != arr.end()) {
		*it = *it * 2;
		++it;
	}

	vector<int>::reverse_iterator rit = arr.rbegin();
	while (rit != arr.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;



	int myints[] = { 16,2,77,29 };
	int len = sizeof(myints) / sizeof(int);
	vector<int> fifth(myints, myints + len);

	vector<int>::iterator it = fifth.begin();
	for(;it != fifth.end(); ++it){
		std::cout << ' ' << *it;
	}
	cout << endl;

	std::vector<int> first; // empty vector of ints
	std::vector<int> second(4, 100); // four ints with value 100
	
	iteratingthrough second
	std::vector<int> third(second.begin(), second.end()); 
	std::vector<int> fourth(third); // a copy of third


	system("pause");
	return 0;
}