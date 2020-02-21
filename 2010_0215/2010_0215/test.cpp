#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Cmp {
	bool operator()(const int a, const int b) {
		return a > b;
	}
}cmp;

int main() {
	vector<int>v{ 1,3,4,5,2,6 };
	replace(v.begin(), v.end(), 6, 600);
	for (auto&e : v) {
		cout << e << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}

