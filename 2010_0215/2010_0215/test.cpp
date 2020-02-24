#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int dict[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool ifcount(int i, int j, int k) {
	int num = 0;
	while (i) {
		num += i % 10;
		i /= 10;
	}
	while (j) {
		num += j % 10;
		j /= 10;
	}
	if (num > k) {
		return false;
	}
	return true;
}

void getcount(vector<vector<int>>&v, \
	int i, int j, int m, int n, int k) {
	if (i < 0 || i >= m || j < 0 || j >= n || (v[i][j]==1)) {
		return;
	}
	if (ifcount(i, j, k)) {
		v[i][j] = 1;
	}
	else {
		return;
	}
	for (int t = 0; t < 4; ++t) {
		getcount(v, i + dict[t][0], j + dict[t][1], m, n, k);
	}
}

int movingCount(int m, int n, int k) {
	vector<vector<int>>v(m, vector<int>(n, 0));

	getcount(v, 0, 0, m, n, k);
	int count = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] == 1) {
				++count;
			}
		}
	}
	return count;
}
int main() {
	cout << movingCount(2, 3, 1) << endl;

	system("pause");
	return 0;
}
