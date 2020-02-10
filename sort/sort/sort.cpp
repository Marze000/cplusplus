#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct player {
	int h;
	int w;
};
bool com_w(player p1, player p2) {
	if (p1.w == p2.w) {
		return p1.h > p2.h;
	}
	else {
		return p1.w < p2.w;
	}
}


vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
	vector<int>ans;
	int order[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//方向数组
	int i = 0, j = -1, start = 0;
	while (true) {
		int a = i + order[start][0];
		int b = j + order[start][1];
		if (!(0 <= a && a < n) ||
			!(0 <= b && b < m) ||
			mat[a][b] == INT_MAX) {
			
			start = (start + 1) % 4;
		}
		i = i + order[start][0];
		j = j + order[start][1];
		ans.push_back(mat[i][j]);
		mat[i][j] = INT_MAX;
		if (ans.size() == n * m) {
			break;
		}
	}
	return ans;
}

int main() {
	int n, h, w, index;
	vector<player>p;
	while (cin >> n) {
		p.clear();
		for (int i = 0; i < n; ++i) {
			player pt;
			cin >> index >> w >> h;
			pt.h = h;
			pt.w = w;
			p.push_back(pt);
		}
		sort(p.begin(), p.end(), com_w);
		vector<int>v(n);
		for (int i = 0; i < n; ++i) {
			v[i] = p[i].h;
		}
		// 对容器进行最长上升子序列的算法
		int cnt, maxnum;
		for (int i = 0; i < n; ++i) {
			cnt = 0;
			for (int j = i + 1; j < n; ++j) {
				if (v[j] >= v[i]) {
					v[i] = v[j];
					++cnt;
				}
			}
			maxnum = max(maxnum, cnt);
		}
		cout << maxnum + 1 << endl;
	}
	return 0;
}

#if 0
#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
using namespace std;

int main() {
	vector<int>v{ 95,100,80,100,70,102 };
	int cnt, maxnum;
	for (int i = 0; i < v.size(); ++i) {
		cnt = 0;
		for (int j = i+1; j <v.size(); j++){
			if (v[j] >= v[i]) {
				v[i] = v[j];
				cnt++;
			}
		}
		maxnum = max(maxnum, cnt);
	}
	cout << maxnum+1 << endl;

	int n, k, d;
	cin >> n;

	vector<int> stud(n);
	for (int i = 0; i < n; i++) {
		cin >> stud[i];
	}
	cin >> k >> d;

	vector<vector<long long>> maxMul(n, vector<long long>(k + 1, 0));
	vector<vector<long long>> minMul(n, vector<long long>(k + 1, 0));

	for (int i = 0; i < n; i++) {
		maxMul[i][1] = stud[i];
		minMul[i][1] = stud[i];
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			for (int m = 1; m <= d && j >= m; m++) {
				maxMul[j][i] = max(maxMul[j][i],\
					max(maxMul[j - m][i - 1] * stud[j],\
						minMul[j - m][i - 1] * stud[j]));

				minMul[j][i] = min(minMul[j][i], \
					min(minMul[j - m][i - 1] * stud[j],\
						maxMul[j - m][i - 1] * stud[j]));
			}
		}
	}

	long long maxMulResult = 1LL << 63;
	for (int i = 0; i < n; i++) {
		maxMulResult = max(maxMulResult, maxMul[i][k]);
	}
	cout << maxMulResult;
	system("pause");
	return 0;
}

// 获取文件名
string getFileName(string path) {
	int pos = path.rfind('\\');
	return path.substr(pos + 1);
}

// 截取文件名后 16 位
string modifyName(string name) {
	if (name.size() > 16) {
		name = name.substr(name.size() - 16);
	}
	return name;
}

struct ErrRecord {
	string file;
	int lineNo;
	int count;
	// 构造函数
	ErrRecord(string file, int lineNo) {
		this->file = file;
		this->lineNo = lineNo;
		count = 1;
	}
	// 文件名相等的规则
	bool operator==(const ErrRecord & a) {
		return (file == a.file) && (lineNo == a.lineNo);
	}
};

int main() {
	string file;
	int lineNo;
	vector<ErrRecord> myvec;
	while (cin >> file >> lineNo) {
		ErrRecord record(getFileName(file), lineNo);
		auto res = find(myvec.begin(), myvec.end(), record);
		// 如果相等代表没有记录
		if (res == myvec.end()) {
			myvec.push_back(record);
		}
		else {
			res->count++;
		}
	}
	int count = 0;
	for (auto item : myvec) {
		if (count + 8 >= myvec.size()) {
			cout << modifyName(item.file)<<" "\
				 << item.lineNo << " "\
				 << item.count << endl;
		}
		count++;
	}
	system("pause");
	return 0;
}
#endif
