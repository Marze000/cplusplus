#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class TreeNode {
public:
	TreeNode(int data) {
		val = data;
	}
	TreeNode* left;
	TreeNode* right;
	int val;
};

vector<string> binaryTreePaths(TreeNode* root) {
	queue<pair<TreeNode*, string>>q;
	q.push(pair<TreeNode*, string>\
		(root, to_string(root->val)));
	vector<string>res;
	while (!q.empty()) {
		TreeNode* node = q.front().first;
		string path = q.front().second;
		q.pop();
		if (node->left == nullptr &&
			node->right == nullptr) {
			res.push_back(path);
		}
		if (node->left) {
			q.push(pair<TreeNode*, string>\
				(node->left, path + "->" + to_string\
				(node->left->val)));
		}
		if (node->right) {
			q.push(pair<TreeNode*, string>\
				(node->right, path + "->" + to_string\
				(node->right->val)));
		}
	}
	return res;
}

int main() {
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n5 = new TreeNode(5);
	n1->left = n2; n1->right = n3;
	n2->left = nullptr; n2->right = n5;
	n3->left = nullptr; n3->right = nullptr;
	n5->left = nullptr; n5->right = nullptr;
	for (auto&e : binaryTreePaths(n1)) {
		cout << e << endl;
	}
	cout << endl;

	delete n1;
	delete n2;
	delete n3;
	delete n5;

	system("pause");
	return 0;
}