#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#if 1

vector<int> printMatrix(vector<vector<int> > matrix) {
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int>temp;
	if (row == 0 || col == 0) {
		return temp;
	}
	int left = 0;
	int right = col;
	int up = 0;
	int down = row;
	while (left < right && up < down) {
		//打印从左到右的
		for (int i = left; i < right; ++i) {
			temp.push_back(matrix[up][i]);
		}
		up++;
		// 从上到下的
		for (int i = up; i < down; ++i) {
			temp.push_back(matrix[i][right - 1]);
		}
		--right;
		//从右到左
		for (int i = right - 1; i >= left && up != down; --i) {
			temp.push_back(matrix[down - 1][i]);
		}
		--down;
		for (int i = down - 1; i >= up && left != right; --i) {
			temp.push_back(matrix[i][left]);
		}
		++left;
	}
	return temp;
}

int main() {
	vector<vector<int>>vec(4,vector<int>(4,0));
	int n = 1;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			vec[i][j] = n;
			++n;
		}
	}
	printMatrix(vec);
	system("pause");
	return 0;
}
vector<int> printMatrix(vector<vector<int> > matrix) {
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> res;

	// 输入的二维数组非法，返回空的数组
	if (row == 0 || col == 0)  return res;

	// 定义四个关键变量，表示左上和右下的打印范围
	int left = 0, top = 0, right = col - 1, bottom = row - 1;
	while (left <= right && top <= bottom){
		// left to right
		for (int i = left; i <= right; ++i)
			res.push_back(matrix[top][i]);
		// top to bottom
		for (int i = top + 1; i <= bottom; ++i)
			res.push_back(matrix[i][right]);
		// right to left
		if (top != bottom)
			for (int i = right - 1; i >= left; --i)
				res.push_back(matrix[bottom][i]);
		// bottom to top
		if (left != right)
			for (int i = bottom - 1; i > top; --i)  
				res.push_back(matrix[i][left]);

		left++, top++, right--, bottom--;
	}
	return res;
}
vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int>res;
	res.clear();
	int row = matrix.size();//行数
	int collor = matrix[0].size();//列数
	//计算打印的圈数
	int circle = ((row < collor ? row : collor) - 1) / 2 + 1;//圈数

	for (int i = 0; i < circle; i++) {
		//从左向右打印
		for (int j = i; j < collor - i; j++)
			res.push_back(matrix[i][j]);
		//从上往下的每一列数据
		for (int k = i + 1; k < row - i; k++)
			res.push_back(matrix[k][collor - 1 - i]);
		//判断是否会重复打印(从右向左的每行数据)
		for (int m = collor - i - 2; (m >= i) && (row - i - 1 != i); m--)
			res.push_back(matrix[row - i - 1][m]);
		//判断是否会重复打印(从下往上的每一列数据)
		for (int n = row - i - 2; (n > i) && (collor - i - 1 != i); n--)
			res.push_back(matrix[n][i]);
	}
	return res;
}
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		if (pRoot2 == NULL || pRoot1 == NULL)
			return false;

		return dfs(pRoot1, pRoot2) 
			|| HasSubtree(pRoot1->left, pRoot2)
			|| HasSubtree(pRoot1->right, pRoot2);
	}
	bool dfs(TreeNode* node, TreeNode* pRoot2) {
		if (pRoot2 == NULL)
			return true;

		else if (node != NULL) {
			return (node->val == pRoot2->val) 
				&& dfs(node->left, pRoot2->left)
				&& dfs(node->right, pRoot2->right);
		}
		else 
			return false;
	}
};
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}; 

class Solution {
public:
	bool isSubtree(TreeNode *t1, TreeNode *t2) {
		// 意味着 t2 已近遍历完了
		if (t2 == NULL) {
			return true;
		}
		// 意味着 t1遍历完，但是t2还没有，所以返回false
		if (t1 == NULL && t2 != NULL) {
			return false;
		}
		if (t1->val == t2->val) {
			bool lTree = isSubtree(t1->left, t2->left);
			bool rTree = isSubtree(t1->right, t2->right);
			return lTree && rTree;
		}else {
			return false;
		}
	}

	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		//如果节点为空则返回nullptr
		if (pRoot1 == NULL || pRoot2 == NULL) 
			return false;

		// 这个是由一定的顺序的，主要是找到值一样的节点
		return isSubtree(pRoot1, pRoot2) 
			|| HasSubtree(pRoot1->left, pRoot2)
			|| HasSubtree(pRoot1->right, pRoot2);
		// 直到找到两棵树值相等的两个节点
	}
};
#endif

#if 0
struct ListNode {
	int val;
	ListNode *next;
};

int main() {
	ListNode* p1 = new ListNode;
	ListNode* p2 = new ListNode;
	ListNode* p3 = new ListNode;
	ListNode* p4 = new ListNode;
	ListNode* p5 = nullptr;
	p1->next = p2; p2->next = p3;
	p3->next = p4; p4->next = p5;
	p1->val = 1; p2->val = 2;
	p3->val = 3; p4->val = 4;
	ListNode* Node = p1;
	while (Node != nullptr) {
		cout << Node->val << ' ';
		Node = Node->next;
	}
	cout << endl;
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	system("pause");
	return 0;
}


void reOrderArray(vector<int> &array) {
	vector<int>::iterator even = array.begin();
	int size = array.size();
	while (size){
		if (*even % 2 == 0){
			int tmp = *even;
			even = array.erase(even);
			array.push_back(tmp);
		}
		else {
			even++;
		}
		size--;
	}
}

void reOrderArray(vector<int> &array) {
	int size = array.size();
	vector<int>::iterator it = array.begin();
	for (int i = 0; i < size; ++i) {
		if ((*it & 1) == 0) {
			int temp = *it;
			it = array.erase(it);
			array.push_back(temp);
		}
		else {
			++it;
		}
	}
}
#endif

#if 0
void reOrderArray(vector<int>& array) {
	//相对位置不变，稳定性
	//插入排序的思想
	int m = array.size();

	//记录已经摆好位置的奇数的个数
	int k = 0;
	// 在 k 之前的数据都已经调整好了

	for (int i = 0; i < m; i++) {
		if (array[i] % 2 == 1) {
			int j = i;
			// 找到奇数后把奇数放到偶数的前面
			while (j > k) {
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				j--;
			}
			k++;
		}
	}
}

int main() {
	vector<int>array{ 1,4,5,6,2,3,8,9,4 };
	for (auto& e : array) {
		cout << e << ' ';
	}
	cout << endl;
	reOrderArray(array);
	for (auto& e : array) {
		cout << e << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
class A {
	A() {
		printf("A()\n");
	}
public:
	static A& get() {
		static A a;
		return a;
	}
};

// 696609771
int main() {
	A::get();
	// 要求1：声明一个指向含有10个元素的数组指针
	// 要球2：其中每一个元素是一个函数指针
	// 要求3：该函数的返回值是 int 
	// 要求4：参数类型是 int*
	// int (*(*p)[10])(int*);

	char s[] = "\\123456\123456\t";
	printf("%d\n", strlen(s));

	int c[4][5] = {
		{0, 1, 2, 3, 8 },
		{4, 7, 6, 7, 9 },
		{10,11,12,13,14},
		{15,16,17,18,19}
	};
	cout << (*c)[1] + 1 << endl;

	int(*pc)[5] = c;
	cout << (*pc[1]+2) << endl;
	cout << *(*(pc+1) + 2) << endl;

	 char str[20];
	str = gets();
	 可以一次性读取输出流的字符，直到遇到回车才结束
	 gets(str);
	 语法错误
	str[] = getch();
	 不接受空格，空格会被放到缓冲区等待下一次被取出
	scanf("%s", str);
	 cout << str << endl;
	char a[80] = "0123\1399";
	cout << sizeof(a) << endl;
	// 看看\后面的数字能否被转移，如果不能被转移则就已经是末尾了
	cout << strlen(a) << endl;

	在 C语言是可以通过编译的，但是C++中不可以，
	 因为sp的类型是char* 但是hello的类型是 const char*
	char* sp;
	char s[10];
	sp = "hello";

	 因为数组名知识数组的首地址，无法作为指针去指向hello
	char* sp, s[10];
	s = "hello";

	char str1[10] = "computer";
	char str2[10];//没有被初始化 “烫烫烫”
	// 由于str1是首地址，内存中的值是computer
	// 所以得需要要一个指针去指向，而str2也是一个数组名，不是指针
	str2 = str1;

	/* 数组初始化错误
	char mark[];
	mark = "program";
	*/

	system("pause");
	return 0;
}

struct Goods{
	string _name;
	double _price;
};

struct Compare{
	bool operator()(const Goods& gl, const Goods& gr){
		return gl._price <= gr._price;
	}
};

int main() {
	Goods gds[] = 
	{ 
		{ "苹果", 2.1 }, { "相交", 3 }, 
		{ "橙子", 2.2 }, {"菠萝", 1.5}
	};
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), 
		[](const Goods& l, const Goods& r){
		return l._price <= r._price;
	});
	for (int i = 0; i < sizeof(gds) / sizeof(gds[0]);++i) {
		cout << gds[i]._name <<" "<< gds[i]._price << endl;
	}
	cout << endl;

	Goods gds[] = 
	{ 
		{ "苹果", 2.1 }, { "香蕉", 3 },
		{ "橙子", 2.2 }, {"菠萝", 1.5} 
	};
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());

	for (auto&e : gds) {
		cout << e._price<<' ';
		cout << e._name << endl;
	}
	cout << endl;

	int a[10] = { 1,4,5,2,7,8,0,6,3,9 };
	std::sort(a, a+sizeof(a) / sizeof(a[0]),less<int>());
	for (auto& e : a) {
		cout << e << ' ';
	}
	cout << endl;


	system("pause");
	return 0;
}
int main() {
	int a = 10;
	int &b = a;

	int a = 10;
	int &&b = a + 1;
	cout << b << endl;

	system("pause");
	return 0;
}

int main(){
	cout << "-------下面是引用左值--------" << endl;
	int a = 5;
	int &add_a = a;

	cout << "   a  =" << a << "    " << "    &a = " << &a << endl;
	cout << "add_a =" << add_a << "    " << "&add_a = " << &add_a << endl;

	cout << "-------下面是引用右值--------" << endl;
	int b = 10;
	int &&add_b = b + 1;
	cout << "   b  =" << b << "    " << "    &b = " << &b << endl;
	cout << "add_b =" << add_b << "    " << "&add_b = " << &add_b << endl;
	add_b++;
	cout << "add_b++ =" << add_b << "    " << "&add_b++ = " << &add_b << endl;
	cout << "-----------------------" << endl;

	system("pause");
	return 0;
}

class Person{
public:
	Person(string name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(const Person& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#if 0
	Person(Person&& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#else
	Person(Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}
#endif
private:
	string _name;
	string _sex;
	int _age;
};

Person GetTempPerson(){
	Person p("prety", "male", 18);
	return p;
}

int main() {
	Person p(GetTempPerson());

	system("pause");
	return 0;
}
class String{
public:
	// 构造函数
	String(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& str) {
		_str = new char[strlen(str._str) + 1];
		strcpy(_str, str._str);
	}

	// 赋值运算符重载
	String& operator=(const String& str) {
		if (this != &str) {
			char* temp = new char[strlen(str._str) + 1];
			strcpy(temp, str._str);
			delete[]_str;
			_str = temp;
		}
		return *this;
	}

	//移动构造函数
	String(String&& s) : _str(s._str){
		s._str = nullptr;
	}

	// 析构函数
	~String() {
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}

private:
	char* _str;

};

int main(){
	String s1("hello world");
	/*C++11中，std::move()函数位于 头文件中，这个函数名字具有迷惑性，
		它并不搬移任何东西，唯一的功能就是：将一个左值强制转化为右值引用，
		通过右值引用使用该值，实现移动语义。
		注意：被转化的左值，其声明周期并没有随着左右值的转化而改变，
		即std::move转化的左值变量lvalue不会被销毁。*/
	String s2(move(s1));

	String s3(s2);

	system("pause");
	return 0;
}

int main() {
	int a = 10;
	// int&& ra; // 编译失败，没有进行初始化
	int&& ra = a; // 编译失败，a是一个左值
	// ra是匿名常量10的别名
	//const int&& ra = 10;
	cout << ra << endl;

	system("pause");
	return 0;
}

class String {
public:
	// 构造函数
	String(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& str) {
		_str = new char[strlen(str._str) + 1];
		strcpy(_str, str._str);
	}

	// 赋值运算符重载
	String& operator=(const String& str) {
		if (this != &str) {
			char* temp = new char[strlen(str._str) + 1];
			strcpy(temp, str._str);
			delete[]_str;
			_str = temp;
		}
		return *this;
	}
	// 析构函数
	~String() {
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

String GetString(const char* pStr) {
	return String(pStr);
}

int main() {
	// 给一个匿名对象取别名
	// 延长匿名对象的生命周期
	String&& s = GetString("hello");
	
	system("pause");
	return 0;
}
#endif