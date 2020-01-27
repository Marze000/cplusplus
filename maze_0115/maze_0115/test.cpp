#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

class A{
public:
	A(){
		printf("A ");
	}
	~A(){
		printf("deA ");
	}
};
class B{
public:
	B(){
		printf("B ");
	}
	~B(){
		printf("deB ");
	}
};
class C : public A, public B{
public:
	C(){
		printf("C ");
	}
	~C(){
		printf("deC ");
	}
};
int main(){
	A *a = new C();
	delete a;
	return 0;
}

#if 0
class A{
public:
	void f(){
		printf("A\n");
	}
};
class B : public A{
public:
	virtual void f(){
		printf("B\n");
	}
};

int main(){
	A *a = new B;
	a->f();
	delete a;
	return 0;
}

void fun3(void) { 
	static int a = 4; 
}
int main(int argc, char** args) {
	printf("%d",a);
	fun3();
	printf("%d", a);

	return 0;
}
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
/*
getLuckyPacket:从当前位置开始搜索符合要求的组合，一直搜索到最后一个位置结束
x: 袋子中的所有球
n: 球的总数
pos: 当前搜索的位置
sum: 到目前位置的累加和
multi: 到目前位置的累积值
*/
int getLuckyPacket(vector<int>&x, int n, int pos, int sum, int multi){
	int count = 0;
	//循环，搜索以位置i开始所有可能的组合
	for (int i = pos; i < n; i++){
		sum += x[i];
		multi *= x[i];
		if (sum > multi){
			// 找到符合要求的组合，加 1 ，继续累加后续的值，看是否有符合要求的集合
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1){
			// 如何不符合要求，且当前元素值为 1 ，则继续向后搜索
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else{
			// 如何 sum 大于 multi, 则后面就没有符合要求的组合了
			break;
		}
		// 要搜索下一个位置之前，首先恢复 sum 和 multi
		sum -= x[i];
		multi /= x[i];
		// 数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过
		while (i < n - 1 && x[i] == x[i + 1]){
			i++;
		}
	}
	return count;
}
int main(){
	char a[] = "ABCDEF"; 
	char b[] = { 'A','B','C','D','E','F','0' }; 
	cout << sizeof(a) << endl;
	cout<<sizeof(b) << endl;
	//cout << "A:" << sizeof(a) / sizeof(a[0]) << endl;
	//cout << "B:" << sizeof(b) / sizeof(b[0]) << endl;

	//int n;
	//while (cin >> n){
	//	vector<int>x(n);
	//	for (int i = 0; i < n; i++){
	//		cin >> x[i];
	//	}
	//	sort(x.begin(), x.end());
	//	// 从第一个位置开始搜索
	//	cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	//}

	return 0;
}

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int y, m, d;
	while (cin >> y >> m >> d) {
		int arr[] = { 0,31,59,90,120,151,181,212,243,273,304,334,335 };
		int days = arr[m - 1];
		days += d;
		if (m > 2) {
			if (y % 400 == 0 || (y % 4 == 0 && y & 100 != 0)) {
				days += 1;
			}
		}
		cout << days << endl;
	}

	system("pause");
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

int minDistance(string word1, string word2) {
	// word与空串之间的编辑距离为word的长度
	if (word1.empty() || word2.empty()) {
		return max(word1.size(), word2.size());
	}
	int len1 = word1.size();
	int len2 = word2.size();
	// F(i,j)初始化
	vector<vector<int> > f(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; ++i) {
		f[i][0] = i;
	}
	for (int i = 0; i <= len2; ++i) {
		f[0][i] = i;
	}
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
			// F(i,j) = min { F(i-1,j）+1, F(i,j-1) +1, F(i-1,j-1) +
			//(w1[i]==w2[j]?0:1) }
			// 判断word1的第i个字符是否与word2的第j个字符相等
			if (word1[i - 1] == word2[j - 1]) {
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// 字符相等，F(i-1,j-1)编辑距离不变
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
			else {
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// 字符不相等，F(i-1,j-1)编辑距离 + 1
				f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);
			}
		}
	}
	return f[len1][len2];
}

int main() {
	int a = 2180;
	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {
		cout << "是闰年" << endl;
	}

	system("pasue");
	return 0;
}

int DFS(int x, int y, vector<vector<int>>& matrix,\
		vector<vector<int>>& dp){
	if (dp[x][y] != 0) {
		return dp[x][y];
	}

	int maxNum = 1;
	for (int i = -1; i <= 1; ++i){
		for (int j = -1; j <= 1; ++j){
			if ((i + j == -1 || i + j == 1) 
				&& x + i < matrix.size() 
				&& x + i >= 0 
				&& y + j < matrix[0].size() 
				&& y + j >= 0){
				if (matrix[x][y] < matrix[x + i][y + j]){
					int k = DFS(x + i, y + j, matrix, dp) + 1;
					maxNum = max(maxNum, k);
				}
			}
		}
	}
	dp[x][y] = maxNum;
	return maxNum;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
	int Max = 0;
	if (matrix.empty())
		return 0;
	vector<vector<int>> dp(matrix.size(), \
		vector<int>(matrix[0].size()));

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			Max = max(DFS(i, j, matrix, dp), Max);
		}
	}
	return Max;
}


int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
	if (S == T) {
		return 0;
	}
	//广度优先搜索辅助队列
	queue<int> myQue;
	myQue.push(S);
	//hashMap[station]记录所有线路中存在station这个站点的线路下标
	unordered_map<int, vector<int>> hashMap;
	//minSteps为最少需要乘坐的公交车数量
	int minSteps = 1;
	int routesSize = (int)routes.size();
	//标记已经访问过的线路
	vector<bool> visitedRoute(routesSize, false);
	//构建hashMap信息，统计每个站点出现的线路
	for (int i = 0; i < routesSize; ++i) {
		for (const auto &station : routes[i]) {
			hashMap[station].push_back(i);
		}
	}
	while (!myQue.empty()) {
		//将当前队列中所有的站点都向下寻找一条线路
		for (int i = (int)myQue.size(); i > 0; --i) {
			int frontStation = myQue.front();
			myQue.pop();
			//遍历frontStation这个站点能够到达的所有线路
			for (const auto &routeIndex : hashMap[frontStation]) {
				//这条线路必须是未访问过的
				if (!visitedRoute[routeIndex]) {
					visitedRoute[routeIndex] = true;
					//遍历routeIndex这条线路中的所有站点
					for (const auto &station : routes[routeIndex]) {
						//到达了目的地
						if (station == T) {
							return minSteps;
						}
						myQue.push(station);
					}
				}
			}
		}
		//实际上size就是这一层的多少
		minSteps++;
	}
	return -1;//无法到达
}

#endif

#if 0
class Base {
public:
	Base(int j) : i(j) 
	{}

	virtual~Base() 
	{}
	void func1() {
		i *= 10;
		func2();
	}
	int getValue() {
		return i;
	}
protected:
	virtual void func2() {
		i++;
	}
protected:
	int i;
};
class Child : public Base {
public:
	Child(int j) : Base(j) {}
	void func1() {
		i *= 100;
		func2();
	}
protected:
	void func2() {
		i += 2;
	}
};
int main() {
	Base * pb = new Child(1);
	pb->func1();
	cout << pb->getValue() << endl; 
	delete pb;

	system("pause");
	return 0;
}

int main() {
	char ccString1[] = "Is Page Fault??";
	char ccString2[] = "No Page Fault??";
	strcpy(ccString1, "No");
	if (strcmp(ccString1, ccString2) == 0) {
		cout << ccString2;
	}
	else {
		cout << ccString1;
	}

	//int a[] = { 2, 4, 6, 8, 10 }, *p, **k;
	//p = a;
	//k = &p;
	//printf(" % d", *(p++));
	//printf(" % d\n", **k);

	//int a = 10;

	//int b = 20;
	//int c = max(a, b);
	//cout << c << endl;
	//
	system("pause");
	return 0;
}
#endif


