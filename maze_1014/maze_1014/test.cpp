#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <string>
#include <regex>
#include <assert.h>
using namespace std;

#if 0
void test1() {
	std::string tmp, html;
	while (getline(std::cin, tmp)) {
		tmp += '\n';
		html += tmp;
	}
	std::string pattern("http(s)?://([\\w-]+\\.)+[\\w-]+(/[\\w- ./?%&=]*)?");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern);
	for (std::sregex_iterator it(html.begin(), html.end(), r), end;     //end是尾后迭代器，regex_iterator是regex_iterator的string类型的版本
		it != end; ++it)
	{
		std::cout << it->str() << std::endl;
	}
}

void test2() {
	string regex_str("^(\\d{6})((1|2)\\d{3})((0|1)\\d)([0-3]\\d)(\\d{3}(X|\\d))$");

	std::regex pattern(regex_str, std::regex::icase);
	//忽略字母大小写

	string id("61251719901212444X");
	if (std::regex_match(id, pattern) == true) {
		cout << "匹配成功" << endl;
	}

	// [a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+  邮箱简单正则
	string mail_reg_str("^[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\\.[a-zA-Z0-9]+$");
	std::regex mail_reg(mail_reg_str, std::regex::icase);

	assert(std::regex_match("chm--1989@163.com", mail_reg) == true);
}

#endif
void IPTest(){
	//识别一个IP地址，并打印各个部分
	//输入exit退出程序
	bool isInputEnd = false;
	//(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})
	//有四个子表达式，括号中的内容为一个子表达式
	std::regex ip_reg("(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})");
	std::smatch matchResult;
	const string exitStr("EXIT");
	while (!isInputEnd){
		cout << "\nInput a IP address:";
		string inputStr;
		std::getline(std::cin, inputStr);
		if (inputStr.empty()){
			continue;
		}

		string tmpStr(inputStr);
		std::transform(tmpStr.begin(), tmpStr.end(), tmpStr.begin(), toupper);
		if (tmpStr == exitStr){
			cout << "\nSYSTEM EXIT!";
			isInputEnd = true;
			continue;
		}
		//正则匹配
		if (std::regex_match(inputStr, matchResult, ip_reg)){
			cout << "Match: ";
			//打印子表达式结果
			for (size_t i = 1; i < matchResult.size(); ++i){
				cout << matchResult[i] << " ";
			}
		}
		else{
			cout << "Not Match!";
		}
	}
}


int main() {
	IPTest();
	string regex_str = "^[0 - 9] + abc$";
	std::regex pattern(regex_str, std::regex::icase);
	string id = "123abc";
	string res;
	if (std::regex_match(id,res, pattern)) {
		cout << "匹配成功" << endl;
		for (int i = 0; i < res.size(); ++i) {
			cout << res[i] << ' ';
		}
		cout << endl;
	}
	else {
		cout << "没有匹配结果" << endl;
	}

	system("pause");
	return 0;
}

















































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

//int GetNumberOfK(vector<int> data, int k) {
//	if (data.empty()) {
//		return 0;
//	}
//	int s = 0;
//	int e = data.size() - 1;
//	int mid = 0;
//	while (data[mid] != k) {
//		mid = (e - s) / 2 + s;
//		if (data[mid] < k) {
//			s = mid + 1;
//		}
//		else if (data[mid] > k) {
//			e = mid - 1;
//		}
//	}
//	int count = 1;
//	int left = mid - 1;
//	int right = mid + 1;
//	while (left >= s && data[left] == k ) {
//		if (left >= s && data[left--] == k ) {
//			++count;
//		}
//	}
//	while(right <= e && data [right] ==k){
//		if (right <= e && data[right++] == k ) {
//			++count;
//		}
//	}
//	return count;
//}
//
//int main() {
//	vector<int>data{ 1,1,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3};
//	auto resultPair = equal_range(data.begin(), data.end(), 3);
//	cout << resultPair.second - resultPair.first << endl;
//	//ListNode* a1 = new ListNode; a1->val = 1;
//	//ListNode* a2 = new ListNode; a2->val = 2;
//	//ListNode* a3 = new ListNode; a3->val = 3;
//	//ListNode* p4 = new ListNode; p4->val = 4;
//	//ListNode* p5 = new ListNode; p5->val = 5;
//	//ListNode* m6 = new ListNode; m6->val = 6;
//	//ListNode* m7 = new ListNode; m7->val = 7;
//	//a1->next = a2; a2->next = a3;
//	//a3->next = m6; m6->next = m7;
//	//p4->next = p5; p5->next = m6;
//	//m7->next = nullptr;
//	//cout << FindFirstCommonNode(a1, p4)->val << endl;
//	//delete a1;
//	//delete a2;
//	//delete a3;
//	//delete p4;
//	//delete p5;
//	//delete m6;
//	//delete m7;
//
//	//stack<int>s;
//	//s.push(1);
//	//s.push(1);
//	//s.pop();
//	//s.pop();
//	//if (s.size() == 0) {
//	//	cout << "ok" << endl;
//	//}
//
//	system("pause");
//	return 0;
//}