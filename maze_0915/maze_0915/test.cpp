#include <iostream>
#include <stdlib.h>
#include <set>
#include <vector>
using namespace std;

int Partion(int* input, int n ,int start, int end) {
	if (input == nullptr || n <= 0 || start < 0 || end >= n) {
		throw new std::exception("cuowu");
	}
	int pre = start - 1;
	int key = input[end - 1];
	while (start < end) {
		if (input[start] < key && ++pre != start) {
			swap(input[pre], input[start]);
		}
		++start;
	}
	if (++pre != end-1) {
		swap(input[pre], input[end]);
	}
	return pre;
}

void GetLeastNumber(int input[],int n, int* output, int k) {
	if (input == nullptr || output == nullptr || n <= 0 || k <= 0 || k > n) {
		return;
	}
	int start = 0;
	int end = n-1;
	int index = Partion(input,n,start,end);
	while (index != k - 1) {
		if (index > k - 1) {
			end = k - 1;
			index = Partion(input,n,start,end);
		}
		else {
			start = k-1;
			index = Partion(input,n,start,end);
		}
	}
	for (int i = 0; i < k; ++i) {
		output[i] = input[i];
	}
}

int main() {
	int input[10] = { 6,4,7,1,2,8,9,0,5 ,3};
	int output[3] = { 0 };
	GetLeastNumber(input,10, output, 3);
	for (auto e : output) {
		cout << e << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}

#if 1
typedef multiset<int, greater<int>> inSet;
typedef multiset<int,greater<int>>::iterator setIterator;
//typedef multiset<int> inSet;
//typedef multiset<int>::iterator setIterator;

void GetLeastNumbers(const vector<int>&data, inSet& leastNumber, int k) {
	leastNumber.clear();
	if (k < 1 || data.size() < k) {
		return;
	}
	vector<int>::const_iterator iter = data.begin();
	for (; iter != data.end(); ++iter) {
		if (leastNumber.size() < k) {
			leastNumber.insert(*iter);
		}
		else {
			setIterator iterGreatest = leastNumber.begin();
			if (*iter < *(leastNumber.begin())) {
				leastNumber.erase(iterGreatest);
				leastNumber.insert(*iter);
			}
		}
	}
}

int main() {
	int arr[10] = { 4,5,1,3,9,2,0,6,8,7 };
	const vector<int>data(arr, arr + 10);
	//multiset<int,greater<int>>mult(arr, arr + 10);
	//for (auto e : mult) {
	//	cout << e << ' ';
	//}
	//cout << endl;
	multiset<int,greater<int>> inSet;
	GetLeastNumbers(data,inSet ,5);
	for (auto e : inSet) {
		cout << e << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
#endif