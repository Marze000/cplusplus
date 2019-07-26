#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = 20;
	int m = 20;
	vector<vector<char>>v(m, vector<char>(n, '.'));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
		}
		cout << endl;
	}

	int flag = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] == '*' && v[i][j + 1] == '*' && v[i][j + 2] == '*'
				&& v[i][j + 3] == '*'&& v[i][j + 4] == '*' && (j + 4) < n) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}

			if (v[i][j] == '+' && v[i][j + 1] == '+' && v[i][j + 2] == '+'
				&& v[i][j + 3] == '+'&& v[i][j + 4] == '+' && (j + 4) < n) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}
			if (v[i][j] == '+' && v[i + 1][j] == '+' && v[i + 2][j] == '+'
				&& v[i + 3][j] == '+'&& v[i + 4][j] == '+' && (i + 4) < m) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}
			if (v[i][j] == '*' && v[i + 1][j] == '*' && v[i + 2][j] == '*'
				&& v[i + 3][j] == '*'&& v[i + 4][j] == '*' && (i + 4) < m) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}

			if (v[i][j] == '*' && v[i + 1][j + 1] == '*'  && v[i + 2][j + 2] == '*'
				&& v[i + 3][j + 3] == '*' && v[i + 4][j + 4] == '*' && (i + 4) < m && (j + 4) < n) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}
			if (v[i][j] == '+' && v[i + 1][j + 1] == '+'  && v[i + 2][j + 2] == '+'
				&& v[i + 3][j + 3] == '+' && v[i + 4][j + 4] == '+' && (i + 4) < m && (j + 4) < n) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}
			if (v[i][j] == '+' && v[i - 1][j - 1] == '+'  && v[i - 2][j - 2] == '+'
				&& v[i - 3][j - 3] == '+' && v[i - 4][j - 4] == '+' && (i - 4) > 0 && (j - 4) > 0){
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}

			if (v[i][j] == '*' && v[i - 1][j - 1] == '*'  && v[i - 2][j - 2] == '*'
				&& v[i - 3][j - 3] == '*' && v[i - 4][j - 4] == '*' && (i - 4) > 0 && (j - 4) > 0) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}
		}
	}
	if (flag == 0) {
		cout << "No" << endl;
	}
	return 0;
}
int main() {

	int a[5] = { 1,2,3,20,3 };
	int v[5] = { 24,1,1000,100,500 };
	int m = 8;
	vector<int>A(a, a + 5);
	vector<int>V(v, v + 5);
	if (A.empty() || V.empty() || m < 1) {
		return 0;
	}

	const int N = A.size();
	//多加一列，用于设置初始条件，因为第一件商品要用到前面的初始值
	const int M = m + 1;
	vector<int> result;
	//初始化所有位置为0，第一行都为0，初始条件
	result.resize(M, 0);
	//这里商品的索引位置不需要偏移，要和未优化的方法区分开
	//这里的i-1理解为上一行，或者未更新的一维数组值
	for (int i = 0; i != N; ++i) {
		for (int j = M - 1; j > 0; --j) {
			//如果第i个商品大于j,说明放不下， 
			//所以(i,j)的最大价值和(i-1,j)相同
			if (A[i] > j) {
				result[j] = result[j];
			}
			//如果可以装下，分两种情况，装或者不装
			//如果不装，则即为(i-1, j)
			//如果装，需要腾出放第i个物品大小的空间：j - A[i],
			//装入之后的最大价值(i - 1, j-A[i - 1])+ 第i个商品的价值V[i]
			//最后在装与不装中选出最大的价值
			else {
				int newValue = result[j - A[i]] + V[i];
				result[j] = max(newValue, result[j]);
			}
		}
	}
	//返回装入前N个商品，物品大小为m的最大价值
	cout << result[m] << endl;
	return 0;
}

int main() {
	long long d[20] = { 0,0,1 };
	for (int i = 3; i < 20; ++i) {
		d[i] = (i - 1)*(d[i - 1] + d[i - 2]);
	}

	int n = 0;
	while (cin >> n) {
		cout << d[n] << endl;
	}

	system("pause");
	return 0;
}

#include<stdio.h>

int main(void){
	long long der[21] = { 0, 0, 1 };
	int i;
	for (i = 3; i < 21; i++) {
		der[i] = (i - 1) * (der[i - 2] + der[i - 1]);
	}

	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", der[n]);
	}
	return 0;
}

int main() {
	int n;
	while (cin >> n) {
		//数组的初始化与定义
		vector<int> height(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> height[i];
		}

		vector<int> f(n, 1);
		int result = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (height[i] > height[j]) {
					f[i] = max(f[i], f[j] + 1);
				}
			}
			result = max(result, f[i]);
		}
		cout << result << endl;
	}
}

#endif

#include <iostream>
#include <stack>
#include <stdlib.h>
#include <vector>
using namespace std;

#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
	int n;
	int m;
	stack<char>s;
	while (cin >> n) {
		string a;
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		for (int i = 0; i < n; ++i) {
			if (a[i] == '+') {
				char a1 = s.top();
				s.pop();
				char a2 = s.top();
				s.pop();
				m = a1 + a2;
				s.push(m);
			}
			if (a[i] == '-') {
				int a1 = s.top();
				s.pop();
				int a2 = s.top();
				s.pop();
				m = a1 - a2;
				s.push(m);
			}
			if (a[i] == '/') {
				int a1 = s.top();
				s.pop();
				int a2 = s.top();
				s.pop();
				m = a1 / a2;
				s.push(m);
			}
			if (a[i] == '*') {
				int a1 = s.top();
				s.pop();
				int a2 = s.top();
				s.pop();
				m = a1 * a2;
				s.push(m);
			}
			else {
				s.push(a[i]);
			}
		}

		cout << s.top()<< endl;
		s.empty();
	}

	system("pause");
	return 0;
}
