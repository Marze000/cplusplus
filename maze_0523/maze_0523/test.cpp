#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int n;
	vector <int> vec;
	while (cin >> n)
		vec.push_back(n);
	
	int count = 1;
	int temp = vec[0];
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i] == temp)
			count++;

		else
			count--;

		if (count == 0)
		{
			temp = vec[i];
			count++;
		}
	}
	cout << temp << endl;
	return 0;
}

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	vector <int> vec;
	while (cin >> n)
	{
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	1 2 3 3 3 4 4 3 3 3
	cout << vec[vec.size() / 2 - 1] << endl;
	
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	unsigned int n = 0;
	unsigned int i = 0;
	vector<int> a;
	while (cin >> n)
	{
		a.push_back(n);
	}

	unsigned int array[50] = { 0 };
	for (; i < a.size(); ++i)
	{
		array[a[i]]++;
		if (array[a[i]] >= (a.size()/2))
		{
			cout << a[i] << endl;
			break;
		}
	}

	system("pause");
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned int i = 0;
	int max = 0;//记录最长的数字串长度
	string ret;//记录最长的数字串
	string str;
	string s;
	int len = 0;
	while (cin >> str)
	{
		while (i < str.size())
		{
			每一个都要赋值为0，这样才可以比较出来数字的长度
			len = 0;
			while (isdigit(str[i]))
			{
				s += str[i++];
				++len;
			}

			if (len > max)
			{
				max = len;
				ret = s;
			}
			s.clear();
			++i;
		}
		cout << ret ;
		ret.clear();//记录最长的数字串
		str.clear();
		len = 0;
		max = 0;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main()
{
	vector<int>array;
	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	vector<int>::iterator itor;
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		if (*itor == 300)
		{
			itor = array.erase(itor);
		}
	}
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		cout << *itor << "";
	}

	char a[10] = { '1','2','3','4','5','6','7','8','9',0 }, *p; int i;
	i = 8;
	p = a + i;
	printf("%d\n", p - 3);

	system("pause");
	return 0;
}