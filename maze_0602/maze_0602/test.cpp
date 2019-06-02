#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int count = 0;
	while (getline(cin, str)) {
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (str[i] == ' ')
			{
				++i;
				if (str[i] == '\"' || str[i] == '\'') {
					str[i] = '\n';
					++count;
					--i;
					while (str[i] != '\"') {
						++i;
					}
					str[i] = '\0';
				}
				else {
					str[--i] = '\n';
					++count;
				}
			}
		}
		cout << count + 1 << endl;
		cout << str;
	}

	return 0;
}

#include <iostream>
#include <stdlib.h>
using namespace std;

int mult(int n)
{
	static int max_ = 0;
	for (int i = 2; i <= n / 2; ++i)
	{
		if (n % i == 0)
		{
			max_ = i;
		}
	}
	return max_;
}

int main()
{
	int N, M;
	while (cin >> N, cin >> M) {

		int max = 0;
		int count = 0;
		while ((N + max) < M)
		{
			N += max;
			max = mult(N);
			++count;
		}

		int temp = M - N;
		if (temp == 0 || N % temp == 0)
		{
			cout << count + 1;
		}
		else {
			cout << -1;
		}
	}
	system("pause");
	return 0;
}