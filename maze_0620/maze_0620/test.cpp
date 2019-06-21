//写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。
//输入描述：输入N个字符
//输出描述：输出该字符串反转后的字符串
//例1  输入：abcd 输出：dcba
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

string ReverseString(string& s) {
	size_t start = 0;
	size_t end = s.size() - 1;
	while (start < end) {
		swap(s[start], s[end]);
		++start;
		--end;
	}
	return s;
}

int main()
{
	string str;
	while (getline(cin, str)) {
		cout << ReverseString(str);
	}

	return 0;
	string str;
	string temp;
	while (cin >> str) {
		int i = 0;
		int len = str.size();
		temp.resize(len);
		while (len) {
			temp[i] = str[--len];
			++i;
		}
		cout << temp << endl;
	}


	system("pause");
	return 0;
}