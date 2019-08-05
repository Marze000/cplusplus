#include <iostream>
#include <vector>
#include <stdlib.h>
#include <map>
#include <string>
#include <set>
using namespace std;

#if 1
class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		vector<int> ret;
		int x1 = 0, y1 = 0; //左上角坐标
		int x2 = n - 1, y2 = m - 1; //右下角坐标
		// 这两个坐标表示了一个矩形(最开始的矩阵)
		// 然后按照要求打印最外圈的数据.
		// 打印完毕之后, 缩小矩形的大小.
		while (x1 <= x2 && y1 <= y2) {
			for (int j = y1; j <= y2; ++j) {
				ret.push_back(mat[x1][j]);
			}
			for (int i = x1 + 1; i < x2; ++i) {
				ret.push_back(mat[i][y2]);
			}
			for (int j = y2; x1 < x2 && j >= y1; --j) {
				//x1 < x2：只有在不是单一的横行时才执行这个循
				ret.push_back(mat[x2][j]);
			}
			for (int i = x2 - 1; y1 < y2 && i > x1; --i) {
				//y1 < y2：只有在不是单一的竖列时才执行这个循
				ret.push_back(mat[i][y1]);
			}
			x1++; y1++;
			x2--; y2--;
		}
		return ret;
	}
};

void TestMap() {
	map<string, string> m;
	m.insert(pair<string, string>("pear", "桃子"));
	m.insert(make_pair("banan", "香蕉"));
	m["apple"] = "苹果";
	cout << m.size() << endl;

	//默认按照字典序的方式进行排序
	for (auto& e : m) {
		cout << e.first << "---->" << e.second << endl;
	}
}
void TestMultiMap() {
	multimap<string, string>mu;
	mu.insert(pair<string, string>("maze", "马泽"));
	mu.insert(make_pair("xiao maze", "小马泽"));
	mu.insert(pair<string, string>("maze", "大马泽"));
	for (auto& e : mu) {
		cout << e.first << "-->" << e.second << endl;
	}
}

void Testset(){
	// 用数组array中的元素构造set
	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3,
		5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
	cout << s.size() << endl;
	// 正向打印set中的元素，从打印结果中可以看出：set可去重
	for (auto& e : s) {
		cout << e << " ";
	}
	cout << endl;
	for (auto it = s.rbegin(); it != s.rend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	cout << s.count(3) << endl;
}

void TestMultiset() {
	int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7 };
	// 注意：multiset在底层实际存储的是<int, int>的键值对
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : s)
		cout << e << " ";

	cout << endl;
}

int main() {
	//TestMap();
	//TestMultiMap();
	//Testset();
	TestMultiset();

	system("pause");
	return 0;
}
#endif


