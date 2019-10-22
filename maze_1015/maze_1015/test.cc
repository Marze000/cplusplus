#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <string>
#include <regex>
#include <assert.h>
#include <string>
using namespace std;
//
//int StrToInt(string str) {
//	if (str.empty()) {
//		return 0;
//	}
//	int symbol = 1;
//	//处理负号
//	if (str[0] == '-') {
//		symbol = -1;
//		str[0] = '0';
//		//这里是‘0’ 不是0
//	}
//	//处理正号
//	else if (str[0] == '+') {
//		symbol = 1;
//		str[0] = '0';
//	}
//	long long  sum = 0;
//	for (int i = 0; i < str.size(); ++i) {
//		if (str[i] < '0' || str[i] > '9') {
//			sum = 0;
//			break;
//		}
//		sum = sum * 10 + str[i] - '0';
//		if (sum > 2147483647) {
//			return 0;
//		}
//	}
//	return symbol * sum;
//}
//
//int StrToInt(string str) {
//	if (str.empty()) {
//		return 0;
//	}
//	int symbol = 1;
//	//处理负号
//	if (str[0] == '-') {
//		symbol = -1;
//		str[0] = '0'; 
//		//这里是‘0’ 不是0
//	}
//	//处理正号
//	else if (str[0] == '+') {
//		symbol = 1;
//		str[0] = '0';
//	}
//	int sum = 0;
//	for (int i = 0; i < str.size(); ++i) {
//		if (str[i] < '0' || str[i] > '9') {
//			sum = 0;
//			break;
//		}
//		sum = sum * 10 + str[i] - '0';
//	}
//	if (sum < INT_MIN || sum > INT_MAX) {
//		return 0;
//	}
//	return symbol * sum;
//}
//
//
//int StrToInt(string str) {
//	if (str.empty()) {
//		return 0;
//	}
//
//	// 如果字符串正有正负号则zhengfu为 true;
//	// 如果是 '+' 则zhe为true
//	// 如果是 '-' 则zhe为false
//	bool zhengfu = false;
//	bool zhe = true;
//	if (str[0] == '-' ||str[0] =='+') {
//		zhengfu = true;
//		if(str[0] == '-'){
//			zhe = false;
//		}
//	}
//
//	//字符转十进制的数
//	bool nul = true;
//	// nul 表示字符串是否有效，默认为有效
//	int size = str.size();
//	int n = size;
//	long long num = 0;
//
//	//为了跳过第一个字符
//	int j = 0;
//	if (zhengfu) {
//		j = 1;
//	}
//	for (int i = j; i < str.size(); ++i) {
//		if (str[i] >= '0' && str[i] <= '9') {
//			long long a = pow(10, size - 1);
//			num += (str[i] - '0')*a;
//			--size;
//		}
//		else {
//			nul = false;
//			break;
//		}
//	}
//	// 字符串无效直接返回0 
//	if (!nul) {
//		return 0;
//	}
//	if (num / 10 == 2147483648) {
//		return 0;
//	}
//	//如果有正号 则返回的值/10
//	if (zhengfu && zhe) {
//		return num/10;
//	}
//	if (!zhengfu && zhe) {
//		return num;
//	}
//	if (zhengfu && !zhe) {
//		return -(num / 10);
//	}
//	if (!zhengfu && zhe) {
//		-num;
//	}
//}
//

//int StrToInt(string str) {
//	if (str.empty()) {
//		return 0;
//	}
//	int symbol = 1;
//	//处理负号
//	if (str[0] == '-') {
//		symbol = -1;
//		str[0] = '0';
//		//这里是‘0’ 不是0
//	}
//	//处理正号
//	else if (str[0] == '+') {
//		symbol = 1;
//		str[0] = '0';
//	}
//	long long sum = 0;
//	for (int i = 0; i < str.size(); ++i) {
//		if (str[i] < '0' || str[i] > '9') {
//			sum = 0;
//			break;
//		}
//		sum = sum * 10 + str[i] - '0';
//		if (symbol && sum > 2147483647) {
//			return 0;
//		}
//		if (!symbol && sum > 2147483649) {
//			return 0;
//		}
//	}
//	return symbol * sum;
//}
//
int StrToInt(string str) {
	if (str.empty()) {
		return 0;
	}
	int symbol = 1;
	//处理负号
	if (str[0] == '-') {
		symbol = -1;
		str[0] = '0';
		//这里是‘0’ 不是0
	}
	//处理正号
	else if (str[0] == '+') {
		symbol = 1;
		str[0] = '0';
	}
	long long sum = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] < '0' || str[i] > '9') {
			sum = 0;
			break;
		}
		sum = sum * 10 + str[i] - '0';
	}
	if ((symbol == 1) && sum > 2147483647) {
		return 0;
	}
	if ((symbol ==-1) && sum >= 2147483649) {
		return 0;
	}

	return symbol * sum;
}
int main() {
	string str = "-2147483649";
	//for (int i = 0; i < str.size(); ++i) {
	//	str[i] = str[i] - 0;
	//}
	//cout << str << endl;

	cout << StrToInt(str);

	system("pause");
	return 0;
}

#if 0
class Solution {
public:
	Solution() {
		++n;
		sum += n;
	}
	void request() {
		n = 0;
		sum = 0;
	}
	int Sum_Solution(int n) {
		request();
		Solution a = new Solution[n];
		delete[] a;
		a = nullptr;
		return sum;
	}
private:
	int sum;
	int n;
};
#endif

// n = 5
int Sum_Solution(int n) {
	int ans = n;
	ans && (ans+=Sum_Solution(n - 1));

	return ans;
}

//int main() {
//	cout << Sum_Solution(5) << endl;
//
//	system("pause");
//	return 0;
//}
//
//int LastRemaining_Solution(int n, int m) {
//	if (n == 0 || m == 0) {
//		return -1;
//	}
//	vector<int>vec;
//	for (int i = 0; i < n; ++i) {
//		vec.push_back(i);
//	}
//	int index = -1;
//	auto iter = vec.begin();
//	while (vec.size() > 1) {
//		iter = vec.begin();
//		index = (index + m) % vec.size();
//		vec.erase(iter + index);
//		--index;
//	}
//	return vec[0];
//}
//
//
//int main() {
//	int n = 10;
//	int m = 5;
//	LastRemaining_Solution(n, m);
//
//	system("pause");
//	return 0;
//}
//
//bool IsContinuous(vector<int> numbers) {
//	int size = numbers.size();
//	sort(numbers.begin(), numbers.end());
//	int zero_count = 0;
//	for (int i = 0; i < size; ++i) {
//		if (numbers[i] == 0) {
//			++zero_count;
//		}
//	}
//	int j = 0;
//	for (int i = 0; i < size; ++i) {
//		if (numbers[i] != 0) {
//			j = i;
//			break;
//		}
//	}
//	int start = numbers[j];
//	int end = numbers[size - 1];
//	int nozero_num = end - start + 1;
//	int shi_num = size - zero_count;
//	if ((nozero_num - shi_num) <= zero_count) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
////  0 0  5 6 8 10 11
//int main() {
//	vector<int>vec{0,0,0,1,1};
//	if (IsContinuous(vec)) {
//		cout << "有顺子" << endl;
//	}
//	else {
//		cout << "没有顺子" << endl;
//	}
//	system("pause");
//	return 0;
//}
//
#if 0
int main() {
	string str = "i am a student!";
	string s = str;
	reverse(s.begin(), s.end());
	cout << s << endl;

	system("pause");
	return 0;
}

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
