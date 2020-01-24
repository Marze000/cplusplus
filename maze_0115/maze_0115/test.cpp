#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class A{
public:
	A() :m_iVal(0) {
		test(); 
	}
	virtual void func() {
		std::cout << m_iVal <<' '; 
	}
	void test() {
		func(); 
	}
public:
	int m_iVal;
};
class B : public A{
public:
	B() {
		test(); 
	}
	virtual void func(){
		++m_iVal;
		std::cout << m_iVal << ' ';
	}
};

int main(){
	A*p = new B;
	p->test();

	system("pause");
	return 0;
}

#if 0
int main(){
	string str1, str2;
	while (cin >> str1 >> str2){
		//以最短的字符串作为s1
		if (str1.size() > str2.size()) {
			swap(str1, str2);
		}
		int len1 = str1.size(), len2 = str2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
			for (j = 1; j <= len2; j++){
				if (str1[i - 1] == str2[j - 1])
					MCS[i][j] = MCS[i - 1][j - 1] + 1;
				//如果有更长的公共子串，更新长度
				if (MCS[i][j] > max){
					max = MCS[i][j];
					//以i结尾的最大长度为max, 则子串的起始位置为i - max
					start = i - max;
				}
			}
		cout << str1.substr(start, max) << endl;
	}

	system("pause");
	return 0;
}

class A{
public:
	void print(){
		cout << "A:print()";
	}
};
class B : private A{
public:
	void print(){
		A::print();
		cout << "B:print()";
	}
};
class C : public B{
public:
	void print(){
		A::print();
	}
};

int main(){
	C b;
	b.print();

	system("pause");
	return 0;
}


int f(int n) {
	static int i = 1;
	if (n >= 5) {
		return n;
	}
	n = n + i;
	i++;
	return f(n);
}

//void increment_ints(int p[], int n){
//	assert(p != NULL);
//	assert(n >= 0); 
//	while (n--){
//		*p++;
//		p++;
//	}
//}

int main() {
	f(1);

	system("pause");
	return 0;
}
#endif
