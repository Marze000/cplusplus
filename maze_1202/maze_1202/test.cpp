#include <iostream>
#include <string>
using namespace std;

int ishuiwen(string str) {
	int left = 0;
	int right = str.size() - 1;
	while (left < right) {
		if (str[left] == str[right]) {
			++left;
			--right;
		}
		else if (str[left + 1] == str[right]) {
			return left;
		}
		else {
			return right;
		}
	}
	return -1;
}
int main() {
	int t;
	string str;
	while (cin >> t) {
		cin>>str;
		printf("%d\n", ishuiwen(str));
	}
	return 0;
}