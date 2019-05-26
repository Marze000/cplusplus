#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int w, h, res = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	//设置容量
	a.resize(w);

	//初始化
	for (auto& e : a)
		e.resize(h, 1);

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (a[i][j] == 1)
			{
				res++;
				// 标记不能放蛋糕的位置
				if ((i + 2) < w)
					a[i + 2][j] = 0;
				if ((j + 2) < h)
					a[i][j + 2] = 0;
			}
		}
	}
	cout << res;
	return 0;
}



#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int begin = 0;
	int last = 1;
	int sum = 0;
	int left = 0;
	int right = 0;
	while (1)
	{
		sum = begin + last;
		begin = last;
		last = sum;

		if (N < sum)
		{
			left = sum - N;
			break;
		}
		else {
			right = N - sum;
		}
	}

	if (left < right)
	{
		cout << left;
	}
	else
	{
		cout << right;
	}
	
	return 0;
}

#include<iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
	bool isValid(string A,int n)
	{
		stack<char> stack_ch;
		for (int i = 0; i < n; ++i)
		{
			char ch = A[i];
			if (ch == '(')
			{
				stack_ch.push(ch);
			}
			else
			{
				if (stack_ch.empty())
				{
					return false;
				}//()(())
				stack_ch.pop();
			}
		}
		if (!stack_ch.empty())
		{
			return false;
		}
		else { return true; }
	}
};


int main()
{
	stack<char> stack_ch;


	system("pause");
	return 0;
}