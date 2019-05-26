#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{	

	string line;
	 不要使用cin>>line,因为会它遇到空格就结束了
	 while(cin>>line)
	while (getline(cin, line))
	{
		size_t pos = line.rfind(' ');
		cout << line.size() - pos - 1 << endl;
	}


	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	strst是冒号的位置
	size_t start = url.find("://"); 

	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return 0;
	}
	//第一个 w 的位置
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;

	size_t pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;

	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;


	string str = "hello maze";
	s.push_back('a');
	s.append("bbb");
	cout << str << endl;
	cout << str.c_str() << endl;

	string s = "hello maze";
	const string s1 = "hehe";
	cout << s << " " << s1 << endl;
	cout << s[0] << " " << s1[0] << endl;

	s[0] = 'H';
	cout << s[0] << endl;
	s1[0] = 'H';
	string s;
	// 测试reserve是否会改变string中有效元素个数
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	// 测试reserve参数小于string的底层空间大小时，会将空间缩小
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;


	
	s.resize(25);
	cout << s.capacity() << endl;


	string s;

	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
	// "aaaaaaaaaa\0\0\0\0\0"
	// 注意此时s中有效字符个数已经增加到15个
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	// 将s中有效字符个数缩小到5个
	//有效字符串会缩小，但是容量不会缩小
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	string s("hello, bit!!!");
	//字符串的长度
	cout << s.length();
	//字符串的有效字符个数
	cout << s.size() << endl;
	//字符串的容量，空间总大小
	cout << s.capacity() << endl;
	cout << s << endl;

	s.resize(20, 'a');
	
	//s.clear();
	cout << s.length();
	//字符串的有效字符个数
	cout << s.size() << endl;
	//字符串的容量，空间总大小
	cout << s.capacity() << endl;
	cout << s << endl;

	s.resize(5, 'a');
	cout << s.length() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//用C格式字符串构造对象str1
	string str1 = "haha";
	//拷贝构造str2
	string str2(str1);
	//用10个字符q 构造str3
	string str3(10, 'q');
	//用str1中的前2个字符构造str4
	string str4(str1, 2);


	system("pause");
	return 0;
}3