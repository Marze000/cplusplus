#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
	int a[8] = { 1,2,4,5,6,2,3,4 };
	vector<int> numbers(a, a + 8);

	int arr[256] = { 0 };
	int len = numbers.size() / 2;
	int flag = 0;
	for (size_t i = 0; i < numbers.size(); ++i) {
		arr[numbers[i]]++;
		if (arr[numbers[i]] > len) {
			cout << numbers[i] << endl;
			flag = 1;
		}
	}

	if (flag == 0) {
		cout << 0 << endl;
	}

	return 0;
}
