#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <string>
using namespace std;

#if 0
int findDuplicate(vector<int>& nums) {
	int low = 0;
	int hight = nums.size() - 1;
	while (low < hight) {
		int mid = (low + hight) / 2;
		int count = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] <= mid) {
				count += 1;
			}
		}
		if (count <= mid) {
			low = mid + 1;
		}
		else {
			hight = mid;
		}
	}
	return low;
}

bool isSubsequence(string s, string t) {
	t.insert(t.begin(), ' ');
	int len1 = s.size(), len2 = t.size();
	vector<vector<int> > dp(len2, vector<int>(26, 0));
	for (char c = 'a'; c <= 'z'; c++) {
		int nextPos = -1; //表示接下来再不会出现该字符

		for (int i = len2 - 1; i >= 0; i--) {  //为了获得下一个字符的位置，要从后往前
			dp[i][c - 'a'] = nextPos;
			if (t[i] == c)
				nextPos = i;
		}
	}

	int index = 0;
	for (char c : s) {
		index = dp[index][c - 'a'];
		if (index == -1)
			return false;
	}
	return true;

}
#include <queue>
class TreeNode{
public:
	TreeNode(int data) {
		val = data;
	}
	int val;
	TreeNode* left;
	TreeNode* right;
};

int sumOfLeftLeaves(TreeNode* root) {
	queue<TreeNode*>q;
	if (root == nullptr) {
		return 0;
	}
	q.push(root);
	int ans = 0;
	while (q.empty()) {
		TreeNode* temp = q.front();
		q.pop();
		if (temp->left && temp->left->left == nullptr
			&& temp->left->right == nullptr) {

			ans += temp->left->val;
		}
		if (temp->left) {
			q.push(temp->left);
		}
		if (temp->right) {
			q.push(temp->right);
		}
	}
	return ans;
}
#endif

bool wordPattern(string pattern, string str) {
	stringstream stream(str);
	string word;
	vector<string>words;
	while (stream >> word) {
		words.push_back(word);
	}
	if (word.size() != pattern.size()) {
		return false;
	}
	unordered_map<char, string>um;
	for (int i = 0; i < pattern.size(); ++i) {
		if (um[pattern[i]] == "") {
			um[pattern[i]] = words[i];
		}
		else {
			if (words[i] != um[pattern[i]]) {
				return false;
			}
		}
	}
	return true;
}

#include <stdlib.h>
int main() {
	string pattern = "abba";
	string str = "dog cat cat dog";
	if (wordPattern(pattern, str)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}


#if 0
	TreeNode* n1 = new TreeNode(3);
	TreeNode* n2 = new TreeNode(9);
	TreeNode* n3 = new TreeNode(20);
	TreeNode* n4 = new TreeNode(15);
	TreeNode* n5 = new TreeNode(7);
	n1->left = n2;n1->right = n3;
	n2->left = nullptr;n2->right = nullptr;
	n3->left = n4; n3->right = n5;
	n4->left = nullptr; n4->right = nullptr;
	n5->left = nullptr; n5->right = nullptr;

	int res = sumOfLeftLeaves(n1);
	cout << res << endl;

	delete n1;
	delete n2;
	delete n3;
	delete n4;
	delete n5;

#endif
	system("pause");
	return 0;
}