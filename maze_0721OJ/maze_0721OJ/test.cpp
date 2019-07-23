

#include <iostream>
#include <stdlib.h>
using namespace std;
#if 1
int main() {
	long long CD[3] = {0, 0,1 };
	long long JC[3] = {0, 1,2 };
	for (int i = 3; i < 22; ++i) {
		CD[i] = (i - 1)*(CD[i - 1] + CD[i - 2]);
		JC[i] = JC[i - 1] * JC[i - 2];
	}

	cout << JC[4] << endl;

	system("pause");
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	long long d[22] = { 0, 0, 1 };
	// 错排数量，预留第一项为 0 ，配合下文中输入的 n
	long long f[22] = { 0, 1, 2 }; 
	// 阶 乘
	for (int i = 3; i < 22; i++){
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]); // 错排的递推公式
		f[i] = i * f[i - 1]; // 阶乘的递推公式
	}

	int n;
	while (std::cin >> n){
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
		// 用 100.0 来把结果处理成 double ，保留两位小数
	}

	system("pause");
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	long long d[22] = { 0, 0, 1 };
	// 错排数量，预留第一项为 0 ，配合下文中输入的 n
	long long f[22] = { 0, 1, 2 };
	// 阶 乘
	for (int i = 3; i < 22; i++) {
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]); // 错排的递推公式
		f[i] = i * f[i - 1]; // 阶乘的递推公式
	}

	int n;
	while (std::cin >> n) {
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
		// 用 100.0 来把结果处理成 double ，保留两位小数
	}

	system("pause");
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
int main(){
	std::string line;
	// 第一次的输入抓到 line 里
	while (std::getline(std::cin, line)) {
		std::vector<std::string> names; 
		//names 里存放所有的数据
		size_t pos = 0;
		// 位置如果大于等于了长度，那么证明找完了，双引号的情况从这里跳出
		while (pos < line.length()) {
			// 找到双引号要处理双引号内部
			if (line[pos] == '\"') {
				size_t end = line.find("\"", pos + 1);
				names.push_back(line.substr(pos + 1, end - pos - 1)); 
				// 截取出来放到 names 里
				pos = end + 2;
				// 跳掉后面的双引号和逗号
			}else{
				size_t end = line.find(",",pos+1);
				// 找不到逗号证明这是最后一个字符串了，直接存了这个字符串后跳出ne.find(",", pos + 1);
				if (end == -1) {
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				}
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1; // 跳掉后面的逗号
			}
		}

		std::getline(std::cin, line);
		if (names.end() == std::find(names.begin(), names.end(), line))
			//std::find 函数是在两个迭代器中间查找，最后一个参数是要找的值。
			// 找到了返回对应迭代器，找不到就返回区间末尾的位置。本例中是 end() 。
		{
			printf("Important!\n"); // 没找到
		}else{
			printf("Ignore\n"); // 找到了
		}
	}
	return 0;
}
#endif

#include <iostream>
#include <stdlib.h>
using namespace std;

//通过一套快速排序将数列分为两部分
#if 1
int Partion1(int* arr, int left, int right) {
	int key = arr[right - 1];
	int begin = left;
	int end = right - 1;
	//设置两个下标 begin 指向首元素，end 指向尾元素
	// 把最后一个元素保存在一个变量中，如果第一个首下标小与key就一直往前走
	while (begin < end) {
		while (begin < end && arr[begin] <= key) {
			++begin;
		}
		while (begin < end && arr[end] >= key) {
			--end;
		}
		//如果两个下标对应的是同一个值也就不需要交换了
		if (begin < end) {
			swap(arr[end], arr[begin]);
		}
	}
	//如果begin 在最后一个位置的话说明前面的值都比key小
	// 也就不需要交换了
	if (begin != right - 1) {
		swap(arr[begin], arr[right -1]);
	}
	return begin;
}

void QuickSort(int* array, int left, int right) {
	if (right - left > 1) {
		//划分基准值
		int div = Partion1(array, left, right);

		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

int Partion1(int* array, int left, int right) {
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];

	while (begin < end) {
		while (begin < end && array[begin] <= key){
			++begin;
		}
		while (begin < end && array[end] >= key) {
			--end;
		}

		if (begin < end) {
			swap(array[begin], array[end]);
		}
	}
	if (begin != right - 1) {
		swap(array[begin], array[right - 1]);
	}
	return begin;
}

int Partion2(int* array, int left, int right) {
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];

	while (begin < end) {
		while (begin < end && array[begin] <= key) {
			++begin;
		}
		if (begin < end) {
			array[end] = array[begin];
			--end;
		}

		while (begin < end && array[end] >= key) {
			--end;
		}
		if (begin < end) {
			array[begin] = array[end];
			++begin;
		}
	}
	array[begin] = key;
	return begin;
}

int Partion3(int* array, int left, int right) {
	int key = array[right - 1];
	int cur = left;
	int pre = cur - 1;

	while (cur < right) {
		if (array[cur] < key && ++pre != cur) {
			swap(array[cur], array[pre]);
		}
		++cur;
	}
	if (++pre != right - 1) {
		swap(array[pre], array[right - 1]);
	}
	return pre;
}


void QuickSort(int* array, int left, int right) {
	if (right - left  > 1) {
		//int div = Partion1(array, left, right);
		//int div = Partion2(array, left, right);
		int div = Partion3(array, left, right);

		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

#include <stack>
void QuickSortNor(int* array, int size) {
	int left = 0;
	int right = size;

	stack<int>st;
	st.push(right);
	st.push(left);
	while (!st.empty()) {
		left = st.top();
		st.pop();
		right = st.top();
		st.pop();
		if (left < right) {
			int div = Partion2(array, left, right);
			st.push(right);
			st.push(div + 1);
			st.push(div);
			st.push(left);
		}
	}
}

int main() {
	int a[10] = { 3,5,1,6,9,0,7,2,8,4 };
	QuickSort(a, 0, 10);
	for (int i = 0; i < 10; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;

	int b[10] = { 3,5,1,6,9,0,7,2,8,4 };
	QuickSortNor(b, 10);
	for (int i = 0; i < 10; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
#endif

#if 1
void BubbleSort(int* array, int size) {
	for (int i = 0; i < size - 1; ++i) {
		int flag = 0;
		for (int j = 1; j < size - i; ++j) {
			if (array[j-1] > array[j]) {
				swap(array[j], array[j - 1]);
				flag = 1;
			}
		}
		if (flag == 0) {
			return;
		}
	}
}

void BubbleSort(int* array, int size) {
	for (int i = 0; i < size - 1; ++i) {
		int flag = 1;
		for (int j = size-1; j > 0; --j) {
			if (array[j] < array[j - 1]) {
				swap(array[j], array[j - 1]);
				flag = 0;
			}
		}
		if (flag == 1) {
			return;
		}
	}
}
#endif

//选择排序法 大致思路：
//如果是升序的话 先整体遍历找到最大的元素，让它和最后一个元素交换
// 每交换一次，遍历的范围就缩小一次，直到将整个序列排好
#if 1
void SelectSortLess(int* array, int size) {
	for (int i = 0; i < size - 1; ++i) {
		int maxpos = 0;
		//找到最大元素的下标
		for (int j = 1; j < size - i; ++j) {
			if (array[maxpos] < array[j]) {
				maxpos = j;
			}
		}
		if (maxpos != size - i - 1) {
			swap(array[maxpos], array[size - i - 1]);
		}
	}
}

void SelectSortGreat(int* array, int size) {
	for (int i = 0; i < size - 1; ++i) {
		int minpos = 0;
		for (int j = 0; j < size - i; ++j) {
			if (array[minpos] > array[j]) {
				minpos = j;
			}
		}
		if (minpos != size - i - 1) {
			swap(array[minpos], array[size - i - 1]);
		}
	}
}
#endif

void AdjustDown(int* array, int size, int last) {
	int child = last * 2 + 1;
	while (child < size) {
		if (child + 1 < size && array[child] < array[child + 1]) {
			++child;
		}
		if (array[child] > array[last]) {
			swap(array[child], array[last]);
			last = child;
			child = 2 * last + 1;
		}
		else {
			return;
		}
	}
}

void HeapSort(int* array, int size) {
	int last = (size - 2) / 2;
	//建堆
	for (; last >= 0; --last) {
		AdjustDown(array, size,last);
	}

	//删除堆顶元素
	int end = size - 1;
	while (end) {
		swap(array[end], array[0]);
		AdjustDown(array, end,0);
		end--;
	}
}

int main() {

	int b[10] = { 3,5,1,6,9,0,7,2,8,4 };
	HeapSort(b, 10);
	for (int i = 0; i < 10; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;
	
	int b[10] = { 3,5,1,6,9,0,7,2,8,4 };
	SelectSortLess(b, 10);
	for (int i = 0; i < 10; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;

	SelectSortGreat(b, 10);
	for (int i = 0; i < 10; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}