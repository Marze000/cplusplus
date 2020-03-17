#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool fushu = false;
string reverse(string res) {
	int size = res.size();
	int left = 0, right = size - 1;
	if (res[0] == '-') {
		fushu = true;
		left = 1;
	}
	while (left < right) {
		swap(res[left++], res[right--]);
	}
	return res;
}
int main() {
	int n;
	while (cin >> n) {
		string str = reverse(to_string(n));
		bool flag = false;
		string res;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] != '0' && str[i] != '-') {
				flag = true;
			}
			if (flag) {
				res += str[i];
			}
		}
		if (!fushu) {
			cout << res << endl;
		}
		else {
			cout << "-" << res << endl;
		}
	}
	system("pause");
	return 0;
}