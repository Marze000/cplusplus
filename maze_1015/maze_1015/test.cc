#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

vector<int>vec;
void Symmetrical(TreeNode* pRoot) {
	if (pRoot->val == '#') {
		return vec.push_back('#');
	}
	Symmetrical(pRoot->left);
	vec.push_back(pRoot->val);
	Symmetrical(pRoot->right);
}

bool isSymmetrical(TreeNode* pRoot) {
	if (pRoot == nullptr) {
		return true;
	}
	Symmetrical(pRoot);
	int start = 0;
	int end = vec.size() - 1;
	while (start < end) {
		if (vec[start] != vec[end]) {
			return false;
		}
		++start;
		--end;
	}
	return true;
}


// 5, 5, 5, 5, #, #, 5, 5, #, 5
int main() {
	TreeNode* p1 = new TreeNode; p1->val = 5;
	TreeNode* p2 = new TreeNode; p2->val = 5;
	TreeNode* p3 = new TreeNode; p3->val = 5;
	TreeNode* p4 = new TreeNode; p4->val = 5;
	TreeNode* p5 = new TreeNode; p5->val = '#';
	TreeNode* p6 = new TreeNode; p6->val = '#';
	TreeNode* p7 = new TreeNode; p7->val = 5;
	TreeNode* p8 = new TreeNode; p8->val = 5;
	TreeNode* p9 = new TreeNode; p9->val = '#';
	TreeNode* p10 = new TreeNode; p10->val = 5;

	TreeNode* p11 = new TreeNode; p11->val = '#';
	TreeNode* p12 = new TreeNode; p12->val = '#';
	TreeNode* p13 = new TreeNode; p13->val = '#';
	TreeNode* p14 = new TreeNode; p14->val = '#';
	TreeNode* p15 = new TreeNode; p15->val = '#';
	p8->left = p11; p8->right = p12;
	p10->left = p13; p10->right = p14;
	p7->right = p15;
	p1->left = p2; p1->right = p3;
	p2->left = p4; p2->right = p5;
	p3->left = p6; p3->right = p7;
	p4->left = p8; p4->right = p9;
	p7->left = p10;

	isSymmetrical(p1);
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	delete p7;
	delete p8;
	delete p9;
	delete p10;
	delete p11;
	delete p12;
	delete p14;
	delete p13;
	delete p15;

	system("pause");
	return 0;
}