#if 1
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;


int main() {
	int n;
	char id;
	string str;
	while (cin >> n) {
		int sum = 0;
		int max = 0;
		for (int i = 0; i < n; ++i) {
			cin >> id >> str;
			if (str == "connect") {
				sum++;
				if (sum > max) {
					max = sum;
				}
			}
			else if (str == "disconnect") {
				--sum;
			}
		}
		cout << max << endl;
	}

	system("pause");
	return 0;
}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int main(){
	int n;
	while (cin >> n){
		set<string> pool;
		string id, con;
		int maxSize = 0;
		for (int i = 0; i < n; ++i){
			cin >> id >> con;
			if (con == "connect") {
				pool.insert(id);
			}else if (con == "disconnect"){
				pool.erase(id);
			}

			int size = pool.size();
			maxSize = max(maxSize, size);
		}
		cout << maxSize << endl;
	}
	return 0;
}
#endif
#if 1
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
	int n;
	while (cin >> n){
		vector<string> list(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; ++i) {
			cin >> list[i];
		}
		sort(list.begin(), list.end());
		//将类似字符串经过排序，放在一起

		for (int i = 0; i < list.size() - 1; ++i){
			// 1、两串相同
			// 2、前串是后串的子串，而且后串后一位是 '/'
			if (list[i] == list[i + 1]) {
				flag[i] = false;
			}
			else if (list[i].size() < list[i + 1].size()
				&& list[i] == list[i + 1].substr(0, list[i].size())
				&& list[i + 1][list[i].size()] == '/')
			{
				flag[i] = false;
			}
		}

		for (int i = 0; i < list.size(); ++i) {
			if (flag[i]) {
				cout << "mkdir -p " << list[i] << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
#endif

#if 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct pos { 
	int x;
	int y;
	int level;
};

int bfs(vector<vector<char> > & map){
	const int dir[4][2] = { 
		{ -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 }
	};

	queue<pos> que;
	int m = map.size();
	int n = map[0].size();
	vector<vector<bool> > visit(m, vector<bool>(n, false));

	pos start{ 0,1,0 }, end{ 9,8,0 };
	que.push(start);
	visit[start.x][start.y] = true;
	while (!que.empty()){
		pos cur = que.front(), next;
		que.pop();
		for (int i = 0; i < 4; ++i){
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.level = cur.level + 1;
			if (next.x == end.x && next.y == end.y) {
				return next.level;
			}

			if (next.x >= 0 && next.x < m && next.y >= 0 
				&& next.y < n && !visit[next.x][next.y]
				&& map[next.x][next.y] == '.')
			{
				que.push(next);
				visit[next.x][next.y] = true;
			}
		}
	}
	return 0;
}

int main(){
	vector<vector<char> > map(10, vector<char>(10));
	while (cin >> map[0][0]){
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (i == 0 && j == 0) {
					continue;
				}
				cin >> map[i][j];
			}
		}
		cout << bfs(map) << endl;
	}

	return 0;
}

#endif
