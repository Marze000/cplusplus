#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <stdlib.h>
using namespace std;

int IsNumberRoot(int N) {
	int sum = 0;
	while (N > 0) {
		sum = sum + N % 10;
		N = N / 10;
	}
	if (sum > 9) {
		IsNumberRoot(sum);
	}
	else {
		cout << sum << endl;
	}
	return 0;
}

int main() {
	int n;
	while (cin >> n) {
		IsNumberRoot(n);
	}
	return 0;
}
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {

		int array[256] = { 0 };
		for (size_t i = 0; i < words.size(); ++i) {
			array[words[i]]++;
		}

		priority_queue<int>q(array.begin(), array.end);

		for (int i = 0; i < k; ++i) {
			cout << words[i] << " ";
		}
	}
};


int main() {

	int k = 4;
	vector<string>words;
	string array[256] = { 0 };
	for (size_t i = 0; i < words.size(); ++i) {
		array[words[i]]++;
	}

	priority_queue<int>q(array.begin(), array.end());

	for (int i = 0; i < k; ++i) {
		cout << words[i] << " ";
	}

	vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };

	priority_queue<int> q1;
	for (auto& e : v) {
		q1.push(e);
	}

	priority_queue默认是大堆的方式，大堆对应的是降序排列
	for (auto &e : v) {
		cout << q1.top() << " " ;
		q1.pop();
	}

	cout << endl;
	 如果要创建小堆，将第三个模板参数换成greater比较方式
	小堆对应的是升序排列
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	for (auto &e : v) {
		cout << q2.top() << " " ;
		q2.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}