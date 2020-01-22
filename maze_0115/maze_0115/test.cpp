#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#if 0
class A {
public:
	A(const char *s){
		cout << s << endl;
	}
	~A() {}
};

class B :virtual public A{
public:
	B(const char *s1,const char*s2)
		:A(s1) {

		cout << s2 << endl;
	}
};

class C :virtual public A{
public:
	C(const char *s1, const char*s2) 
		:A(s1) {

		cout << s2 << endl;
	}
};

class D :public B, public C{
public:
	D(const char *s1,const char *s2,const char *s3,const char *s4) 
		:A(s1)
		,B(s1, s2)
		,C(s1, s3)
	{
		cout << s4 << endl;
	}
};
#endif

class A {
public:
	void test(float a) {
		cout << "1"; 
	}
};
class B :public A {
public:
	void test(int b) {
		cout << "2"; 
	}
};

int main() {
	A *a = new A;
	B *b = new B;
	a = b;
	(*a).test(1.1);
	//D *p = new D("class A", "class B", "class C", "class D");
	// delete p;

	system("pause");
	return 0;
}

#if 0
class A {
public:
	A() {
		cout << "A构造函数" << endl;
	}
	~A() {
		cout << "A析构函数" << endl;
	}
};
class B {
public:
	B(int b) {
		cout << "B构造函数" << endl;
	}
	~B() {
		cout << "B析构函数" << endl;
	}
private:
	int b;
};
B fun(B b) {
	return b;
}

int main() {
	B b1(3);
	B b2 = fun(b1);

	system("pause");
	return 0;
}
#endif

#if 0
void fun(int& n) {
	n += 1;
}
int main() {
	int a = 1;
	fun(a);


	system("pause");
	return 0;
}
int main() {
	int n;
	vector<int>vec;
	while (cin >> n) {
		vec.push_back(n);
	}
	int array[256] = { 0 };
	for (int i = 0; i < vec.size(); ++i) {
		array[vec[i]]++;
		if (array[vec[i]] > (vec.size() / 2)) {
			cout << vec[i] << endl;
			break;
		}
	}

	system("pause");
	return 0;
}
int main() {
	string str, temp, res;
	while (getline(cin, str)) {
		for (int i = 0; i <= str.size(); ++i) {
			if (str[i] >= '0' && str[i] <= '9') {
				temp += str[i];
			}
			else {
				if (temp.size() > res.size()) {
					res = temp;
				}
				else {
					temp.clear();
				}
			}
		}
		cout << res;
	}

	system("pause");
	return 0;
}

// 该类的静态方法只能访问该类的静态成员函数

class A{
public:
	static void a_print(){
		a = 2;
		cout <<"a_print调用"<<a<< endl;
	}
private:
	static int a;
};
int A::a = 1;

class B :public A{
public:
	void b_print(){
		cout <<"B::print()"<< endl;
	}
private:
	int b;
};
class C :public B{
public:
	void c_print(){
		cout <<"C::print()"<< endl;
	}
private:
	int c;
};
int main(){
	A a;
	a.a_print();

	system("pause");
	return 0;
}


int main() {
	vector<int>array;
	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	vector<int>::iterator itor;
	for (itor = array.begin(); itor != array.end(); itor++){
		if (*itor == 300) {
			itor = array.erase(itor);
		}
	}
	for (itor = array.begin(); itor != array.end(); itor++){
		cout << *itor << " ";
	}

	system("pause");
	return 0;
}

void divnum_cout(int n, vector<int>& divnum) {
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n%i == 0) {
			divnum.push_back(i);
			if (n / i != i) {
				divnum.push_back(n / i);
			}
		}
	}
}
int Jump(int n, int m) {
	vector<int>step(m + 1, 0);
	step[n] = 1;
	for (int i = n; i < m; ++i) {
		if (step[i] == 0) {
			continue;
		}
		vector<int>divnum;
		divnum_cout(i, divnum);
		// 上面都是准备步骤
		// 下面才是转义方程的动态规划
		for (int j = 0; j < divnum.size(); ++j) {
			if ((divnum[j] + i )<= m && (step[divnum[j] + i] != 0)) {
				step[divnum[j] + i] = min(step[divnum[j] + i], step[i] + 1);
			}
			else if ((step[j] + i) <= m) {
				step[divnum[j] + i] = step[i] + 1;
			}
		}
	}

	if (step[m] == 0) {
		return -1;
	}
	else {
		//初始化时多给了一步，故需要减 1
		return step[m] - 1;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	cout << Jump(n, m) << endl;
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sample {
public:
	Sample(int x) {
		*p = x;
	}
	~Sample() {
		if (p) delete p;
	}
	int show() {
		return *p;
	}
private:
	int*p;
};
int main() {
	Sample S(5);
	cout << S.show() << endl;

	system("pause");
	return 0;
}

int main() {
	struct A {
		unsigned a:19;
		unsigned b:11;
		unsigned c:4;
		unsigned d:29;
		char index;
	};
	cout << sizeof(struct A) << endl;

	int a[] = { 1,2,3,4 };
	int *b = a;
	*b += 2;
	*(b + 2) = 2;
	b++;
	printf("%d, %d\n", *b, *(b + 2));

	char acX[] = "abc";
	char acY[] = {'a','b','c'};
	const char *szX = "abc";
	const char *szY = "abc";
	cout << &szX << ':' << &szY << endl;
	cout << szX << ':' << szY << endl;
	

	int n;
	while (cin >> n) {
		vector<int>a_i(3 * n, 0);
		for (int i = 0; i < 3 * n; ++i) {
			cin >> a_i[i];
		}
		sort(a_i.begin(), a_i.end());
		long long res = 0;
		int index = 3 * n - 2;
		while (n--) {
			res += a_i[index];
			index -= 2;
		}
		cout << res << endl;
	}
	system("pause");
	return 0;
}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool fun(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return false;
	}
	return true;
}
int evalRPN(vector<string>& tokens) {
	stack<int>s;
	for (int i = 0; i < tokens.size(); ++i) {
		if (fun(tokens[i])) {
			s.push(tokens[i]);
		}
		else {
			int a = top();
			s.pop();
			int b = top();
			s.pop();
			if (tokens[i] == '+') {
				s.push(a + b);
			}
			else if (tokens[i] == '-') {
				s.push(a - b);
			}
			else if (tokens[i] == '*') {
				s.push(a*b);
			}
			else if (tokens[i] == '/') {
				s.push(a / b);
			}
		}
	}
	return s.top();
}
#endif


#if 0
vector<vector<int>> subsets(vector<int>& nums) {
	int S = nums.size();
	int N = 1 << S;
	vector<vector<int>>res;
	for (size_t i = 0; i < N; ++i){
		vector<int> v;
		for (size_t j = 0; j < S; ++j) {
			if (i & (1 << j)) {
				v.push_back(nums[j]);
			}
		}
		res.push_back(v);
	}
	return res;
}

void subsetss(int numssize, int i,vector<int>&nums,
	vector<vector<int>>& output,vector<int>& newtemp){

    //递归出口，当下标大达到最大时不进行递归。
	if (i >= numssize) {
		output.push_back(newtemp);//记录集合
		return;
	}
    //选择加入下标为i的元素。        
	newtemp.push_back(nums[i]);

	//递归进行后续元素
	subsetss(numssize, i + 1, nums, output, newtemp);

	//选择不加入下标为i的元素。
	newtemp.pop_back();            

	//递归进行后续元素的操作
	subsetss(numssize, i + 1, nums, output, newtemp);
}
vector<vector<int>> subsets(vector<int>& nums) {
	int numssize = nums.size();  //记录数组的元素个数
	int i = 0;
	vector<vector<int>>output;
	vector<int>newtemp;
	subsetss(numssize, i, nums, output, newtemp);
	return output;
}

int main() {
	char a[10] = { '1','2','3','4','5',\
		'6','7','8','9','\0',};
	int i = 8;
	char* p = a + i;
	printf("%s\n", p - 3);

	system("pause");
	return 0;
}

int main() {

	vector<int> nums{1,2,3};
	vector<vector<int>>ret = subsets(nums);

	for (size_t i = 0; i < ret.size(); ++i) {
		for (size_t j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j]<<' ';
		}
		cout << endl;
	}
	cout << endl;

	//string str = "12";
	//int a = stoi(str);

	//cout << str << endl;
	//cout << a << endl;

	system("pause");
	return 0;
}
#endif
