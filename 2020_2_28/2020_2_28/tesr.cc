#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool ispalindrome(string s, int i, int j) {
	while (i < j) {
		if (s[i] != s[j]) {
			return false;
		}
		++i; --j;
	}
	return true;
}
int minCut(string s) {
	if (s.empty()) return 0;
	int n = s.size();
	vector<int>dp(n + 1, 0);
	dp[0] = -1;// 如果没有这一项，aaaaaaa会产生错误
	// dp[i] 表示到第 i 个字符需要的最小分割次数
	for (int i = 1; i <= n; ++i) {
		dp[i] = i - 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			// dp(i) = min(dp(i),1+dp(j)) 
			if (ispalindrome(s, j, i - 1)) {
				dp[i] = min(dp[i], 1 + dp[j]);
			}
		}
	}
	return dp[n];
}


int main() {
	string s = "aaaaaa";

	cout << minCut(s) << endl;

	system("pause");
	return 0;
}

