#include <iostream>
#include <stdlib.h>
using namespace std;

class string
{
public:
	string(const char* str = "")
		:_pcount(new int[1])
	{
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	string(const string &s)
		:_str(s._str)
		,_pcount(s._pcount)
	{
		++(*_pcount);
	}

	string &operator = (const string& s)
	{
		if (this != &s)
		{
			if (_str && --*_pcount == 0)
			{
				delete[] _str;
				delete[] _pcount;
			}

			_str = s._str;
			_pcount = s._pcount;
			++(*_pcount);
		}
		return *this;
	}

	~string()
	{
		if (_str && 0 == --(*_pcount))
		{
			delete [] _str;
			delete _pcount;
		}
	}

	char& operator[](size_t index)
	{
		查看是否共享资源，以及分离
		if (getref() > 1)
		{
			string strtemp(_str);
			swap(_str, strtemp._str);
			swap(_pcount, strtemp._pcount);
		}
		return _str[index];
	}

	const char& operator[](size_t index)const
	{
		return _str[index];
	}

	int getref()
	{
		return *_pcount;
	}

private:
	char* _str;
	int* _pcount;
};

int main()
{
	string s1("hello");
	string s2(s1);

	string s3("world");
	string s4(s3);

	s3 = s2;
	s4 = s2;

	s1[1] = 'h';
	const string s4("world");
	cout << s4[0];


	system("pause");
	return 0;
}

class string
{
public:
	string(const char* str = "")
	{
		if (str == nullptr) {
			str = "";
		}
		int len = strlen(str);
		_str = new char[len + 1];
		strcpy(_str, str);
		_size = len;
		_capacity = len;
	}

	string(size_t n, char ch)
	{

	}
	string(const string &s)
		:_str(s._str)
		, _pcount(s._pcount)
	{
		++(*_pcount);
	}

	string &operator = (const string& s)
	{
		if (this != &s)
		{
			if (_str && --*_pcount == 0)
			{
				delete[] _str;
				delete[] _pcount;
			}

			_str = s._str;
			_pcount = s._pcount;
			++(*_pcount);
		}
		return *this;
	}

	~string()
	{
		if (_str && 0 == --(*_pcount))
		{
			delete[] _str;
			delete _pcount;
		}
	}

	char& operator[](size_t index)
	{
		查看是否共享资源，以及分离
		if (getref() > 1)
		{
			string strtemp(_str);
			swap(_str, strtemp._str);
			swap(_pcount, strtemp._pcount);
		}
		return _str[index];
	}

	const char& operator[](size_t index)const
	{
		return _str[index];
	}

	int getref()
	{
		return *_pcount;
	}

private:
	/*静态数组：16 */
	char* _str;
	size_t _size;
	size_t _capacity;
};

int main()
{
	string s1("hello");
	string s2(s1);

	string s3("world");
	string s4(s3);

	s3 = s2;
	s4 = s2;

	s1[1] = 'h';
	const string s4("world");
	cout << s4[0];


	system("pause");
	return 0;
}

#include <iostream>
#include<vector>
#include <stdlib.h>
using namespace std;

int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (int i = 0; i < size; ++i) {
		cin >> nums[i];
	}

	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		 1 2 3 -2 3 -6 4 5
		 计算到num[i]的子数组的最大和
		sum2 = (sum1 >= 0 ? sum1 + nums[i] : nums[i]);
		if (sum2 > result) {
			result = sum2;
		}

		if (sum2 < 0) {
			sum2 = 0;
		}
		sum1 = sum2;
	}
	cout << result << endl;
	system("pause");
	return 0;
}


#include <iostream>
int main()
{
	int(*pt)[3];
	int a[2][3] = { {0,1,2},{3,4,5} };
	pt = a;
	std::cout << *(*(pt + 1) + 1);

	return 0;
}

#include <iostream>
using namespace std;
int main(void)
{
	const int a = 10;
	int * p = (int *)(&a);
	*p = 20;
	cout << "a = " << a << ", *p = " << *p << endl;
	return 0;
}

#include <iostream>
using namespace std;

int perfect(int m) {
	int sum = 0;
	for (int i = 1; i < m; ++i) {
		if (m%i == 0) {
			sum += i;
		}
	}
	if (sum == m) {
		return 1;
	}
	else {
		return 0;
	}
}

void count(int n)
{
	int num = 0;
	for (int i = 3; i < n + 1; ++i) {
		if (perfect(i) == 1) {
			++num;
		}
	}
	if (num != 0) {
		cout << num;
	}
	else {
		cout << -1;
	}
}

int main() {
	int N = 0;
	while (cin >> N) {
		count(N);
	}
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
int count(int n)
{
	int cnt = 0;
	if ((n < 0) | (n > 500000))
	{
		return -1;
	}
	else {
		for (int i = 2; i <= n; i++)
		{
			int sum = 0;
			 遍历范围
			int sq = sqrt(i);
			for (int j = 2; j <= sq; j++)
			{
				if (i%j == 0) {
					 如果 j^2 = i ，说明两个约数相同，只加一个
					if (i / j == j)
						sum += j;
					else {
						否则，两个不同的约数都要相加
						sum += j + (i / j);
					}
				}
			}
			if (sum + 1 == i)
				cnt++;
		}
		return cnt;
	}
}
int main() {
	int input;
	while (cin >> input)
		cout << count(input) << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string line;
	while (getline(cin, line)) {
		 王炸最大，直接输出
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else {
			int dash = line.find('-');
			 分开两手牌
			string car1 = line.substr(0, dash);
			string car2 = line.substr(dash + 1);
			 获取空格的次数，牌数为 c + 1
			int c1 = count(car1.begin(), car1.end(), ' ');
			int c2 = count(car2.begin(), car2.end(), ' ');
			 拿到第一张牌
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2) {
				 只要牌数相等，则第一张牌大的即为大
				if (str.find(first1) > str.find(first2))
					cout << car1 << endl;
				else
					cout << car2 << endl;
			}
			else
			{
				 牌数不相同，说明类型不同 , 只有炸弹可以和其它牌比较
				 其它类型都是错误的
				if (c1 == 3)
					cout << car1 << endl;
				else if (c2 == 3)
					cout << car2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;
	string str2;
	while (getline(cin, str1), getline(cin, str2)) {
		for (size_t i = 0; i < str2.size(); ++i) {
			if (str1[i] != str2[i]) {
				if (str1[i] != '*'&& str1[i] != '?')
				{
					cout << "fasle" << endl;
				}

				if(str1[i]=='*')
			}
		}
		cout << "true" << endl;
	}

	system("pause");
	return 0;
}