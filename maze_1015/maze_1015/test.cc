#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <string>
#include <regex>
#include <assert.h>
using namespace std;


int main() {
	string str = "i am a student!";
	string s = str;
	reverse(s.begin(), s.end());
	cout << s << endl;

	system("pause");
	return 0;
}

#if 0
class TreeNode {
public:
	TreeNode* left;
	TreeNode* right;
};

bool isBalanced = true;
bool IsBalanced_Solution(TreeNode* pRoot) {
	getDepth(pRoot);
	return isBalanced;
}

int getDepth(TreeNode *root) {
	if (root == nullptr) {
		return 0;
	}
	int left = getDepth(root->left);
	int right = getDepth(root->right);
	if (abs(left - right) > 1) {
		isBalanced = false;
	}
	return right > left ? right + 1 : left + 1;
}
#endif

//#if 0
//void test1() {
//	std::string tmp, html;
//	while (getline(std::cin, tmp)) {
//		tmp += '\n';
//		html += tmp;
//	}
//	std::string pattern("http(s)?://([\\w-]+\\.)+[\\w-]+(/[\\w- ./?%&=]*)?");
//	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
//	std::regex r(pattern);
//	for (std::sregex_iterator it(html.begin(), html.end(), r), end;     //end是尾后迭代器，regex_iterator是regex_iterator的string类型的版本
//		it != end; ++it)
//	{
//		std::cout << it->str() << std::endl;
//	}
//}
//
//void test2() {
//	string regex_str("^(\\d{6})((1|2)\\d{3})((0|1)\\d)([0-3]\\d)(\\d{3}(X|\\d))$");
//
//	std::regex pattern(regex_str, std::regex::icase);
//	//忽略字母大小写
//
//	string id("61251719901212444X");
//	if (std::regex_match(id, pattern) == true) {
//		cout << "匹配成功" << endl;
//	}
//
//	// [a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+  邮箱简单正则
//	string mail_reg_str("^[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\\.[a-zA-Z0-9]+$");
//	std::regex mail_reg(mail_reg_str, std::regex::icase);
//
//	assert(std::regex_match("chm--1989@163.com", mail_reg) == true);
//}
//
//void IPTest(){
//	//识别一个IP地址，并打印各个部分
//	//输入exit退出程序
//	bool isInputEnd = false;
//	//(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})
//	//有四个子表达式，括号中的内容为一个子表达式
//	std::regex ip_reg("(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})");
//	std::smatch matchResult;
//	const string exitStr("EXIT");
//	while (!isInputEnd){
//		cout << "\nInput a IP address:";
//		string inputStr;
//		std::getline(std::cin, inputStr);
//		if (inputStr.empty()){
//			continue;
//		}
//
//		string tmpStr(inputStr);
//		std::transform(tmpStr.begin(), tmpStr.end(), tmpStr.begin(), toupper);
//		if (tmpStr == exitStr){
//			cout << "\nSYSTEM EXIT!";
//			isInputEnd = true;
//			continue;
//		}
//		//正则匹配
//		if (std::regex_match(inputStr, matchResult, ip_reg)){
//			cout << "Match: ";
//			//打印子表达式结果
//			for (size_t i = 1; i < matchResult.size(); ++i){
//				cout << matchResult[i] << " ";
//			}
//		}
//		else{
//			cout << "Not Match!";
//		}
//	}
//}
//
//
//int main() {
//	string str = "123143";
//	string regex = "^[0-9]*&";
//	regex_match(str,)
//	//string regex_str = "runoo+b";
//	//std::regex pattern(regex_str, std::regex::icase);
//	//string id = "runoooob";
//	//smatch res;
//	//if (std::regex_match(id,res, pattern)) {
//	//	cout << "匹配成功" << endl;
//	//	for (size_t i = 0; i < res.size(); ++i) {
//	//		cout << res[i] << ' ';
//	//	}
//	//	cout << endl;
//	//}
//	//else {
//	//	cout << "没有匹配结果" << endl;
//	//}
//
//	system("pause");
//	return 0;
//}
//
//#endif
