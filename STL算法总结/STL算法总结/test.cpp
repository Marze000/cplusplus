#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;


#if 1
bool myfunction(int i, int j) {
	return (i == j);
}

int main() {
	int myints[] = { 5,20,5,30,30,20,10,10,20 };
	std::vector<int> myvector(myints, myints + 8);
	std::vector<int>::iterator it;

	// using default comparison:
	it = std::adjacent_find(myvector.begin(), myvector.end());
	if (it != myvector.end()) {
		cout << *it << endl;
	}
	//using predicate comparison:
	it = std::adjacent_find(++it, myvector.end(), myfunction);
	if (it != myvector.end()) {
		std::cout << *it << '\n';
	}

	system("pause");
	return 0;
}


bool myfunction(int i, int j) {
	return (i > j);
}

int main() {
	int myints[] = { 1,2,3,4,5,4,3,2,1 };
	std::vector<int> v(myints, myints + 9);

	// using default comparison:
	std::sort(v.begin(), v.end());

	std::cout << "looking for a 3... ";
	if (std::binary_search(v.begin(), v.end(), 3)) {
		std::cout << "found!\n";
	}
	else {
		std::cout << "not found.\n";
	}
	for (auto&e : v) {
		cout << e << " ";
	}
	cout << endl;

	// using myfunction as comp:
	std::sort(v.begin(), v.end(), myfunction);

	std::cout << "looking for a 6... ";
	if (std::binary_search(v.begin(), v.end(), 6, myfunction)) {
		std::cout << "found!\n";
	}
	else {
		std::cout << "not found.\n";
	}
	for (auto&e : v) {
		cout << e << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
bool IsOdd(int i) { return ((i % 2) == 0); }

int main() {
	std::vector<int> myvector;
	// myvector: 1 2 3 4 5 6 7 8 9
	for (int i = 1; i < 10; i++) {
		myvector.push_back(i);
	}

	//返回满足条件的个数
	int mycount = count_if(myvector.begin(), myvector.end(), IsOdd);
	std::cout << "myvector contains " << mycount << " odd values.\n";

	system("pause");
	return 0;
}
bool mygreater(int i, int j) { return (i > j); }

int main() {
	int myints[] = { 10,20,30,30,20,10,10,20 };
	vector<int> v(myints, myints + 8);  
	pair<vector<int>::iterator, vector<int>::iterator> bounds;

	// using default comparison:
	sort(v.begin(), v.end()); // 10 10 10 20 20 20 30 30
	bounds = std::equal_range(v.begin(), v.end(), 20);
	cout << bounds.first-v.begin() << endl;
	cout << bounds.second-v.begin() << endl;

	// using "mygreater" as comp:
	sort(v.begin(), v.end(), mygreater);  // 30 30 20 20 20 10 10 10
	bounds = std::equal_range(v.begin(), v.end(), 20, mygreater); // ^   ^
	cout << bounds.first-v.begin() << endl;
	cout << bounds.second-v.begin() << endl;

#if 1
	cout << "bounds at positions " << (bounds.first - v.begin());
	cout << " and " << (bounds.second - v.begin()) << '\n';

#endif
	system("pause");
	return 0;
}
int main() {
	// using std::find with array and pointer:
	int myints[] = { 10, 20, 30, 40 };
	int* p = nullptr;

	// 如果找到 30 就直接返回
	p = std::find(myints, myints + 4, 30);
	//如果指针走到了 40 的后面就说一定没有找到
	if (p != myints + 4)
		std::cout << "Element found in myints: " << *p << '\n';
	else
		std::cout << "Element not found in myints\n";

	// using std::find with vector and iterator:
	std::vector<int> myvector(myints, myints + 4);
	std::vector<int>::iterator it;

	it = find(myvector.begin(), myvector.end(), 30);
	if (it != myvector.end())
		std::cout << "Element found in myvector: " << *it << '\n';
	else
		std::cout << "Element not found in myvector\n";

	system("pause");
	return 0;
}
bool comp_case_insensitive(char c1, char c2) {
	return (tolower(c1) == tolower(c2));
}

int main() {
	int mychars[] = { 'a','b','c','A','B','C' };
	std::vector<char> v(mychars, mychars + 6);
	std::vector<char>::iterator it;

	int needle[] = { 'A','B','C' };

	// using default comparison:
	it = find_first_of(v.begin(), v.end(), needle, needle + 3);

	if (it != v.end())
		std::cout << "The first match is: " << *it << '\n';

	// using predicate comparison:
	it = find_first_of(v.begin(), v.end(),
		needle, needle + 3, comp_case_insensitive);

	if (it != v.end())
		std::cout << "The first match is: " << *it << '\n';

	system("pause");
	return 0;
}

int main() {
	int first[] = { 5,10,15,20,25 };
	int second[] = { 50,40,30,20,10 };
	std::vector<int> v(10);
	std::vector<int>::iterator it;

	std::sort(first, first + 5);
	std::sort(second, second + 5);

	it = std::copy(first, first + 5, v.begin());
	std::copy(second, second + 5, it);

	//排序
	std::inplace_merge(v.begin(), v.begin() + 5, v.end());

	std::cout << "The resulting vector contains:";
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	system("pause");
	return 0;
}

int main() {
	int first[] = { 5,10,15,20,25 };
	int second[] = { 50,40,30,20,10 };
	std::vector<int> v(10);

	std::sort(first, first + 5);
	std::sort(second, second + 5);
	std::merge(first, first + 5, second, second + 5, v.begin());

	std::cout << "The resulting vector contains:";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
int main() {
	int a[] = { 1,3,5,7,9 };
	int b[] = { 2,4,6,8 ,10};
	int v[10] = { 0 };
	//很重要的排序算法 但是有个前提就是 它要重新在另个数组中合并
	// 合并两个有序的数组
	for (auto&e : v) {
		cout << ' ' << e;
	}
	cout << endl;
	system("pause");
	return 0;
}
bool myfunction(int i, int j) { return (i < j); }

int main() {
	std::vector<int> myvector;
	std::vector<int>::iterator it ;

	// set some values:
	for (int i = 1; i < 10; i++) {
		myvector.push_back(i);
	}
	// 1 2 3 4 5 6 7 8 9

	//打乱排序
	std::random_shuffle(myvector.begin(), myvector.end());

	// using default comparison (operator <):
	std::nth_element(myvector.begin(), myvector.begin() + 3, myvector.begin()+5);

	// using function as comp
	std::nth_element(myvector.begin(), myvector.begin() + 5, myvector.end(), myfunction);

	// print out content:
	std::cout << "myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
int main() {
	int a[] = { 1,4,6,34,12,65,56,23,76,98,34,76,34 ,23,24};
	//在 a -- a+13 的范围内，把小于a+5 的数放在前面，大于a+5的数放在后面
	nth_element(a, a + 5, a + 13);
	for (auto&e : a) {
		cout << ' ' << e;
	}
	cout << endl;

	system("pause");
	return 0;
}
int main() {
	// using std::find with array and pointer:
	int myints[] = { 10, 20, 30, 40 };
	int * p = find(myints, myints + 4, 30);

	if (p != myints + 4) {
		std::cout << "Element found in myints: " << *p << '\n';
	}
	else {
		std::cout << "Element not found in myints\n";
	}

	// using std::find with vector and iterator:
	std::vector<int> myvector(myints, myints + 4);
	std::vector<int>::iterator it;

	it = find(myvector.begin(), myvector.end(), 30);
	if (it != myvector.end()) {
		std::cout << "Element found in myvector: " << *it << '\n';
	}
	else {
		std::cout << "Element not found in myvector\n";
	}

	return 0;
}

bool mypredicate(int i, int j) {
	return (i == j);
}

int main() {
	std::vector<int> v;

	// v: 10 20 30 40 50 60 70 80 90
	for (int i = 1; i < 10; i++)
		v.push_back(i * 10);

	// using default comparison:
	int needle1[] = { 40,50,60,70 };
	std::vector<int>::iterator it;
	it = search(v.begin(), v.end(), needle1, needle1 + 4);

	if (it != v.end()) {
		cout << (it - v.begin()) << '\n';
	}
	else {
		cout << "needle1 not found\n";
	}

	// using predicate comparison:
	int n[] = { 20,30,50 };
	it =search(v.begin(), v.end(), n, n + 3, mypredicate);

	if (it != v.end()) {
		cout << (it - v.begin()) << '\n';
	}
	else {
		cout << " not found\n";
	}

	system("pause");
	return 0;
}

int main() {
	std::vector<int> myvector;

	// set some values:
	for (int i = 1; i < 10; ++i) 
		myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9

	std::reverse(myvector.begin(), myvector.end());    // 9 8 7 6 5 4 3 2 1

	// print out content:
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
int main() {
	vector<int>v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < 10; ++i) {
		printf("%d ", v[i]);
	}
	cout << endl;

	system("pause");
	return 0;
}


bool mcp(int x,int y) {
	return x > y;
}

int main() {
	int a[10] = { 1,4,6,3,2,8,5,9,0 ,7};
	vector<int>v(a,a+10);
	sort(v.begin(), v.end(),mcp);
	for (auto&e : v) {
		cout << ' ' << e;
	}
	cout << endl;

	system("pause");
	return 0;
}
int main() {
	int myints[] = { 10,20,30,40,50,60,70 };
	std::vector<int> myvector(7);
	std::vector<int>::iterator it;

	std::copy(myints, myints + 7, myvector.begin());

	std::cout << "myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';

	return 0;
}




int main() {
	int myints[] = { 10,20,30,30,20,10,10,20 };      // 10 20 30 30 20 10 10 20

	// bounds of range:
	int* pbegin = myints;                          // ^
	int* pend = myints + sizeof(myints) / sizeof(int); // ^                       ^

	pend = std::remove(pbegin, pend, 20);         // 10 30 30 10 10 ?  ?  ?
												   // ^              ^
	std::cout << "range contains:";
	for (int* p = pbegin; p != pend; ++p)
		std::cout << ' ' << *p;
	std::cout << '\n';

	system("pause");
	return 0;
}

int main() {
	int myints[] = { 10,20,30,40,50,60,70,20,20 ,30};
	int* end = myints + sizeof(myints) / sizeof(int);
	end = remove(myints, end, 20);
	
	std::cout << "myvector contains:";
	for (int* i = myints; i < end; ++i) {
		cout << ' ' << *i;
	}
	std::cout << '\n';

	system("pause");
	return 0;
}
#endif
int main() {
	int myints[] = { 10,20,30,40,50,60,70,20,20 ,30};
	vector<int>v(myints,myints+10);
	replace(v.begin(), v.end(),20,200);
	
	std::cout << "myvector contains:";
	for (auto&e : v) {
		cout << ' ' << e;
	}
	std::cout << '\n';

	system("pause");
	return 0;
}
