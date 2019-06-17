#include <iostream>
#include <string>
using namespace std;

class Solution {
	public String addStrings(String num1, String num2) {
		StringBuilder sb = new StringBuilder();
		int carry = 0, i = num1.length() - 1, j = num2.length() - 1;
		while (i >= 0 || j >= 0 || carry != 0) {
			if (i >= 0) carry += num1.charAt(i--) - '0';
			if (j >= 0) carry += num2.charAt(j--) - '0';
			sb.append(carry % 10);
			carry /= 10;
		}
		return sb.reverse().toString();
	}
}

int main()
{
	string num1, num2;
	cin >> num1;
	cin >> num2;

	int LSize = num1.size();
	int RSize = num2.size();
	 以长字符串作为外部循环
	if (LSize < RSize){
		num1.swap(num2);
		swap(LSize, RSize);
	}

	string strRet;
	strRet.reserve(LSize + 1);
	char cRet = 0;
	char cstep = 0;
	for (size_t i = 0; i < LSize; ++i)
	{
		cRet = num1[LSize - i - 1] - '0' + cstep;
		cstep = 0;
		if (i < RSize)
		{
			cRet += num2[RSize - i - 1] - '0';
		}
		if (cRet >= 10)
		{
			cRet -= 10;
			cstep = 1;
		}
		strRet += cRet + '0';
	}
	if (cstep)
	{
		strRet += '1';
	}

	reverse(strRet.begin(), strRet.end());





	string s = "jajkhgkaj";
	int arr[] = { 0 };
	size_t i = 0;
	for (; i < s.size(); ++i) {
		arr[s[i]]++;
	}
	i = 0;
	for (; i < s.size(); ++i) {
		if (arr[s[i]] == 1) {
			printf("%d\n", i);
			break;
		}
	}

	system("pause");
	return -1;




	string s;
	size_t cap = s.capacity();
	for (size_t i = 0; i < 100; ++i) {
		s.push_back('a');
		if (s.size() == s.capacity()) {
			cout << "make change" << s.capacity() << endl;
		}
	}


	string url("http://www.cplusplus.com/reference/string/string/find/");
	 删除url的协议前缀
	size_t pos = url.find("://");
	erase 第一个参数是从哪个位置开始抹除
	第二个参数是抹除的结束位置，不包括最后指向的那个位置
	url.erase(0, pos + 3);
	cout << url << endl;



	size_t start = url.find("://", 0);
	if (start == string::npos) {
		字符串中没有 “://” 这个字符串
		 npos 相当于 -1 如果找不到就返回-1
		cout << "解析失败" << endl;
		return 0;
	}
	start += 3;//跳过 "://" 让start 指到 w 的位置
	size_t end = url.find('/', start);
	end -= start;

	string str = url.substr(start, end);
	cout << str << endl;

	


	string file("string.cpp");
	size_t pos = file.rfind('.');

	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;



	string str1 = "http://www.baidu.com";
	substr第一个参数是从指定位置开始截取，包括指定位置的字符
	位置是从0开始的
	第二个参数是一共截取多少个字符；
	string s1 = str1.substr(7, 9);
	cout << s1 << endl;


	find 和 rfind 如果找不到自动返回-1；
	找到了返回所在字符的下标
	注意：找的只是最靠近第二个参数的位置
	string s1 = "abcdefghgijklmn";
	size_t n = s1.rfind('g',10);
	size_t n1 = s1.find('g', 1);
	printf("%d\n%d\n", n,n1);
	printf("%c\n", s1[6]);

	string s;
	s.push_back('a');
	s.append("sss");
	s += "bbb";

	返回字符 s 在字符串第一个的位置
	只要遇到s 就会直接返回，不管后面是否还有s
	size_t n = s.find('s', 0);

	printf("%d\n", n);

	s.reserve(100);
	

	string s1 = "hehehe";
	size_t len = s1.length();
	size_t cap = s1.capacity();
	printf("%d:%d", len, cap);

	size_t n = s1.size();
	printf("%d\n", n);

	string s1;
	string s2("hehe");
	string s3(s2);
	string s4(10, 'a');
	string s5(s2, 3);

	system("pause");
	return 0;
}