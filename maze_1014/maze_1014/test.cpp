#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <string>
using namespace std;

//struct ListNode {
//	int val;
//	struct ListNode *next;
//};
//
//stack<ListNode*>s1;
//stack<ListNode*>s2;
//ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//	ListNode *p1 = pHead1;
//	ListNode *p2 = pHead2;
//	while (p1 != nullptr) {
//		s1.push(p1);
//		p1 = p1->next;
//	}
//	while (p2 != nullptr) {
//		s2.push(p2);
//		p2 = p2->next;
//	}
//	ListNode *ret = s1.top();
//	while (s1.top() == s2.top()) {
//		ret = s1.top();
//		s1.pop();
//		s2.pop();
//	}
//	return ret;
//}
//
//
//int GetNumberOfK(vector<int> data, int k) {
//	int GetNumberOfK(vector<int> data, int k) {
//		if (data.empty()) {
//			return 0;
//		}
//		int start = 0;
//		int end = data.size();
//		int mid = data.size() / 2;
//		while (data[mid] != k) {
//			if (data[mid] > k) {
//				mid = (start + mid) / 2;
//			}
//			else {
//				mid = (end + mid) / 2;
//			}
//		}
//		int count = 1;
//		int left = mid - 1;
//		int right = mid + 1;
//		while (data[left] != k || data[right] != k) {
//			if (data[left--] == k) {
//				++count;
//			}
//			if (data[right++] == k) {
//				++count;
//			}
//		}
//		return count;
//	}
//}
//

int GetNumberOfK(vector<int> data, int k) {
	if (data.empty()) {
		return 0;
	}
	int s = 0;
	int e = data.size() - 1;
	int mid = 0;
	while (data[mid] != k) {
		mid = (e - s) / 2 + s;
		if (data[mid] < k) {
			s = mid + 1;
		}
		else if (data[mid] > k) {
			e = mid - 1;
		}
	}
	int count = 1;
	int left = mid - 1;
	int right = mid + 1;
	while (left >= s && data[left] == k ) {
		if (left >= s && data[left--] == k ) {
			++count;
		}
	}
	while(right <= e && data [right] ==k){
		if (right <= e && data[right++] == k ) {
			++count;
		}
	}
	return count;
}

int main() {
	vector<int>data{ 1,1,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3};
	auto resultPair = equal_range(data.begin(), data.end(), 3);
	cout << resultPair.second - resultPair.first << endl;
	//ListNode* a1 = new ListNode; a1->val = 1;
	//ListNode* a2 = new ListNode; a2->val = 2;
	//ListNode* a3 = new ListNode; a3->val = 3;
	//ListNode* p4 = new ListNode; p4->val = 4;
	//ListNode* p5 = new ListNode; p5->val = 5;
	//ListNode* m6 = new ListNode; m6->val = 6;
	//ListNode* m7 = new ListNode; m7->val = 7;
	//a1->next = a2; a2->next = a3;
	//a3->next = m6; m6->next = m7;
	//p4->next = p5; p5->next = m6;
	//m7->next = nullptr;
	//cout << FindFirstCommonNode(a1, p4)->val << endl;
	//delete a1;
	//delete a2;
	//delete a3;
	//delete p4;
	//delete p5;
	//delete m6;
	//delete m7;

	//stack<int>s;
	//s.push(1);
	//s.push(1);
	//s.pop();
	//s.pop();
	//if (s.size() == 0) {
	//	cout << "ok" << endl;
	//}

	system("pause");
	return 0;
}