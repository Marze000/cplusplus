#if 1
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

void Dfs(int index, int n, vector<int>& boxs, vector<int>& book){
	if (index == n + 1){
		for (int i = 1; i <= n; i++) {
			cout << boxs[i] << " ";
		}
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

	system("pause");
	return 0;
}
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int DFS(unordered_map<int, Employee*>& info, int id){
		int curImpo = info[id]->importance;
		for (const auto& sid : info[id]->subordinates){
			curImpo += DFS(info, sid);
		}
		return curImpo;
	}
	int getImportance(vector<Employee*> employees, int id) {
		if (employees.empty()) {
			return 0;
		}
		unordered_map<int, Employee*> info;
		for (const auto& e : employees){
			info[e->id] = e;
		}
		return DFS(info, id);
	}
};
#endif
