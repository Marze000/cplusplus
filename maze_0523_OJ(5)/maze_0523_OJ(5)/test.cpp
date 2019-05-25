#include <iostream>
#include <string>
#include <vector>
using namespace std;

int backword(string str1)
{
	size_t len = str1.size() - 1;
	for (size_t i = 0; i < len; ++i, --len)
	{
		if (str1[i] != str1[len])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	string A, B;
	cin >> A;
	cin >> B;
	int num = 0;
	string temp = A;
	for (size_t i = 0; i < A.size() - 1; ++i)
	{
		A = temp;
		A.insert(i, B);
		if (backword(A))
		{
			++num;
		}
	}

	cout << num;

	system("pause");
	return 0;
}

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n);
	int i = 0;
	for (; i < n; ++i)
	{
		cin >> a[i];
	}

	int num = 0;
	for (int i = 0; a[i] <= 0; ++i) {}



	system("pause");
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int backword(string str1)
{
	size_t end = str1.size() - 1;
	size_t begin = 0;
	while (begin < end) {
		if (str1[begin] != str1[end])
		{
			return 0;
		}
		++begin;
		--end;
	}
	return 1;
}

int main()
{
	string A, B;
	getline(cin, A);
	getline(cin, B);
	size_t num = 0;
	for (size_t i = 0; i < A.size() + 1; ++i)
	{
		string temp = A;
		temp.insert(i, B);
		if (backword(temp))
		{
			++num;
		}
	}

	cout << num << endl;

	system("pause");
	return 0;
}
