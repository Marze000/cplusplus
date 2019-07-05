#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int>v;
	int n;
	while (cin >> n) {
		int count = 0;
		v.clear();
		v.resize(n);
		int j = 0;
		for (int i = n / 2; i > 0; --i) {
			if (n % i == 0) {
				n = n / i;
				v[j++] = n;
				n = i;
			}
		}
		for (int i = 0; i < v.size(); ++i) {
			if (v[i] == 0) {
				break;
			}
			if (v[0] != v[i]) {
				++count;
			}
		}
		cout << count+1 << endl;
	}
	return 0;
}

int main() {
	string str;
	while (getline(cin, str)) {
		for (size_t i = 0; i < str.size(); ++i) {
			if (str[i] > 'E' && str[i] < 'Z') {
				str[i] = str[i] - 5;
			}
			else if (str[i] == 'E') {
				str[i] = 'Z';
			}
			else if (str[i] == 'D') {
				str[i] = 'Y';
			}
			else if (str[i] == 'C') {
				str[i] = 'X';
			}
			else if (str[i] == 'B') {
				str[i] = 'W';
			}
			else if (str[i] == 'A') {
				str[i] = 'V';
			}
			else {

			}
		}
		for (size_t i = 0; i < str.size(); ++i) {
			cout << str[i];
		}
	}
	return 0;
}
