#include<iostream>
#include<vector>
#include <string>
using namespace std;

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
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
	string a, b;
	while (cin >> a >> b)
		cout << minDistance(a, b) << endl;

	return 0;
}



int GCD(int a, int b){
	int c;
	while (c = a % b){
		a = b;
		b = c;
	}
	return b;
}

int main()
{
	int n, power;
	vector<int> num;
	while (cin >> n >> power){
		num.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		for (int k = 0; k < n; k++){
			if (num[k] < power){
				power += num[k];
			}else{
				power += GCD(power, num[k]);
			}
		}
		cout << power << endl;
	}
	return 0;
}
int main(){
	string s;
	while (cin >> s){
		int hashtable[256] = { 0 };
		for (auto& e : s){
			hashtable[e]++;
		}
		int i;
		for (i = 0; i < s.size(); i++){
			if (hashtable[s[i]] == 1){
				cout << s[i] << endl;
				break;
			}
		}
		if (i >= s.size())
			cout << -1 << endl;
	}
	return 0;
}