#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
	int arr[2][4] = { 6,-3,-2,7,-15,1,2,2 };
	vector<vector<int>>vec(arr,arr+8);
	int row = vec.size();
	int lin = vec[0].size();
	cout << row << " " << lin << endl;

	return 0;
}

#if 1
int main() {
	int arr[8] = { 6,-3,-2,7,-15,1,2,2 };
	vector<int>vec(arr, arr + 8);
	int sum = vec[0];//前i个元素为止的和
	int maxsum = vec[0];
	for (int i = 1; i < vec.size(); ++i) {
		if (sum < 0) {
			sum = vec[i];
		}
		else {
			sum += vec[i];
		}
		if (sum > maxsum) {
			maxsum = sum;
		}
	}
	cout << maxsum << endl;

	system("pause");
	return 0;
}

// 6, -3, -2, 7, -15, 1, 2, 2

int main() {
	int arr[8] = { 6,-3,-2,7,-15,1,2,2 };
	vector<int>vec(arr, arr + 8);
	int sum = vec[0];
	// maxsum初始化
	int maxsum = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		// F(i) = max(F(i-1) + vec[i]，vec[i])
		sum = (sum > 0) ? sum + vec[i] : vec[i];
		// maxsum = max( maxsum，F(i))
		maxsum = (sum < maxsum) ? maxsum : sum;
	}
	cout << maxsum << endl;

	system("pause");
	return 0;
}

int main() {
	int n = 0;
	string str1;
	while (cin >> n) {
		cin >> str1;
		string str2(2,0);
		if (n == 1) {
			str2[0] = str1[1];
			str2[1] = str1[0];
			cout << str2 << endl;
			return 0;
		}
		for (int i = 0; i < n - 1; ++i) {
			cin >> str2;
			for (int j = 0; j < str1.size(); ++j) {
				str1[j] = str1[j] ^ str2[j];
			}
		}
		cout << str1 << endl;
	}
	return 0;
}

int main() {
	string str1;
	string str2;
	cin >> str2;
	while (cin>>str1) {
		str2 = str1 + " " + str2;
	}
	cout << str2 << endl;

	system("pause");
	return 0;
}

//快速排序
int partion(int* vec,int left,int right) {
	int cur = left;
	int pre = cur - 1;
	int key = vec[right - 1];
	while (cur < right) {
		if (vec[cur] < key && ++pre != cur) {
			swap(vec[cur], vec[pre]);
		}
		++cur;
	}
	if (++pre != right-1) {
		swap(vec[pre], vec[right-1]);
	}
	return pre;
}

void QucikSort(int* vec, int start, int end) {
	if (end - start > 1) {
		int div = partion(vec, start, end);
		QucikSort(vec, start, div);
		QucikSort(vec, div+1, end);
	}
}

void QucikSortNor(int* vec, int size) {
	stack<int>sta;
	int left = 0;
	int right = size ;
	sta.push(right);
	sta.push(left);
	while (!sta.empty()) {
		left = sta.top();
		sta.pop();
		right = sta.top();
		sta.pop();
		if (left < right) {
			int div = partion(vec, left, right);
			sta.push(right);
			sta.push(div + 1);
			sta.push(div);
			sta.push(left);
		}
	}
}

int main() {
	int arr[10] = { 4,1,6,3,7,5,2,9,8,0 };
	QucikSort(arr, 0, 10);
	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
#endif
