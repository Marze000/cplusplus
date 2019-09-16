#include <iostream>
#include <stdlib.h>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		if (grid.empty()) {
			return 0;
		}
		int rsp = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == 1) {
					rsp += 4;
					if (i > 0 && grid[i - 1][j] == 1) {
						rsp -= 2;
					}
					if (j > 0 && grid[i][j - 1] == 1) {
						rsp -= 2;
					}
				}
			}
		}
		return rsp;
	}
};

#if 0
int post[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };
class Solution {
public:
	int Csum = 4;
	int dfs(vector<vector<int>>& grid, int row, int col,
		vector<vector<int>>& map, int i, int j) {
		map[i][j] = 1;
		for (int k = 0; k < 4; ++k) {
			int newi = i + post[k][0];
			int newj = j + post[k][1];
			if (newi >= row || newi < 0 ||
				newj >= col || newj < 0) {
				continue;
			}
			if (grid[newi][newj] == 1 &&
				map[newi][newj] == 0) {
				Csum += 2;
			}
		}
		return Csum;
	}
	int islandPerimeter(vector<vector<int>>& grid) {
		if (grid.empty()) {
			return 0;
		}
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>>map(row, vector<int>(col, 0));
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (grid[i][j] == 1) {
					return dfs(grid, row, col, map, i, j);
				}
			}
		}
	}
};
//你现在在(0, 0)，需要到(x, y)去，路上有n个障碍物。
//给出每个障碍物的坐标，你只能平行于坐标轴走整数步，
//问你最少需要多少步才能走到目的地。
//第一行三个数x, y, n
// 接下来n行，每行描述一个障碍物的坐标x_i, y_i  - 500≤x, y, x_i, y_i≤500
//n≤10000 保证有解
int main() {
	int x, y, n;
	int x1, y1;
	vector<vector<int>>map(500, vector<int>(500, 0));
	while (cin >> x >> y >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> x1 >> y1;
			map[x1][y1] = 1;
		}
		
	}

	system("pause");
	return 0;
}
int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	for (auto o : a) {
		cout << o << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}

void Dfs(int index, int n, vector<int>& boxs, vector<int>& book){
	if (index == n + 1){
		for (int i = 1; i <= n; i++)
			cout << boxs[i] << " ";

		cout << endl;
		return; //向上回退
	}
	for (int i = 1; i <= n; i++){
		//第i号牌仍在手上
		if (book[i] == 0){
			boxs[index] = i;
			//现在第i号牌已经被用了
			book[i] = 1;
			//处理下一个盒子
			Dfs(index + 1, n, boxs, book);
			//从下一个盒子回退到当前盒子，取出当前盒子的牌，
			//尝试放入其它牌。
			book[i] = 0;
		}
	}
}

int main(){
	int n;
	vector<int> boxs;
	vector<int> books;
	cin >> n;
	boxs.resize(n + 1, 0);
	books.resize(n + 1, 0);
	Dfs(1, n, boxs, books);
	return 0;
}

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