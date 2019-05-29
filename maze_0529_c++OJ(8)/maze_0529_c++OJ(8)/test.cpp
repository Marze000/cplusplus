#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> a;
	a.resize(n);
	for (auto &e : a)
	{
		cin >> e;
	}

	int lexico = 1;
	int lengths = 1;

	for (size_t i = 0; i < a.size() + 1; ++i)
	{
		if (a[i] < a[i + 1])
		{
			lexico = 0;
			break;
		}
	}

	for (size_t i = 0; i < a.size() + 1; ++i)
	{
		if (a[i].size() > a[i + 1].size())
		{
			lengths = 0;
			break;
		}
	}

	if (lexico == 1 && lengths == 1)
	{
		cout << "both";
	}
	else if (lexico == 1 && lengths == 0)
	{
		cout << "lexicographically";
	}
	else if (lexico == 0 && lengths == 1)
	{
		cout << "lengths";
	}
	else {
		cout << "both";
	}

	return 0;
}

#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	int r;
	while (r = a % b) {
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int a, b;
	while (cin >> a >> b) {
		cout << a * b / gcd(a, b) << endl;
	}
	return 0;
}

class Solution {
public:
	class sum
	{
	public:
		sum()
		{
			++_count;
			_sum += _count;
		}
		static int getsum()
		{
			return _sum;
		}
		static void reset()
		{
			_count = 0;
			_sum = 0;
		}
	private:
		static int _count;
		static int _sum;
	};
	int Sum_Solution(int n) {
		sum::reset();
		sum obj[n];

		return sum::getsum();
	}
};

int Solution::sum::_count = 0;
int Solution::sum::_sum = 0;