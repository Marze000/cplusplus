#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
#endif

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int>v(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		int count = 0;
		for (int i = 1; i < n; ++i) {
			if (v[i - 1] < v[i]) {
				while (i < n && v[i - 1] <= v[i]) {
					++i;
				}
				++count;
			}
			else if (v[i - 1] > v[i]) {
				while (i < n && v[i] < v[i - 1]) {
					++i;
				}
				++count;
			}
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}
