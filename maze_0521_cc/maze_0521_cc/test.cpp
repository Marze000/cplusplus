#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;//hellmdo worldte 
	string str2;// lor
	getline(cin, str1);
	getline(cin, str2);

	 使用哈希映射思想先str2统计字符出现的次数
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}
	 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在
	 str2中没有出现过，则将他+=到ret。注意这里最好不要str1.erases(i)
	 因为边遍历，边erase，容易出错。
	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}
	cout << ret << endl;

	system("pause");
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void reverse(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		--end;
		++start;
	}
}

void str_reverse(char* str1)
{
	int len = strlen(str1);
	reverse(str1, str1 + len - 1);
	while (*str1 != '\0')
	{
		char* pos = str1;
		while ((*str1 != ' ') && (*str1 != '\0'))
		{
			str1++;
		}
		reverse(pos, str1 - 1);
		if (*str1 != '\0')
		{
			str1++;
		}
	}
}

int main()
{
	char str[100] = "hellp ";// hello wrold! maze 

	while (1) {
		scanf("%[^\n]", &str);
		str_reverse(str);
	}

	printf("%s\n", str);
	system("pause");
	return 0;
}














int main()
{
	int n;
	while(1){	//输入数列个数
		cin >> n;

		vector<int> a;
		a.resize(n+1);
		a[n] = 0;

		输入数据
		int i;
		for (i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		i = 0;
		int count = 0;
		while (i < n){
			如果第一个数字大于第二个数字，非递增
			if (a[i] > a[i + 1])
			{
				while (i < n&&a[i] >= a[i + 1])
				{//则一直往后走，直到前一个数字小与后一个数字
					i++;
				}
				count++;
				i++;
			}

			else if (a[i] < a[i + 1])
			{
				while (a[i] <= a[i + 1])
				{
					i++;
				}
				count++;
				i++;
			}

			else
			{
				i++;
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}
int main()
{
	 IO型OJ可能会有多组测试用例，所以这里要持续接收输入多组测试用例。
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> a;
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		/*排序，然后取下标为3n - 2，3n - 4 ，3n - 4... n+2，n位置的元素累加即可，
		相当下标为[0,n-1]的n个数做每组的最左边的数，剩下的2个数据两个为一组，
		大的值做最右边的数，次大的做中间值，这里就是把这个次大的值加起来*/
		std::sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		for (int i = 1; i <= 3 * n-2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* start, char* end)
{
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

void str_reverse(char* str)
{
	int len = strlen(str);
	reverse(str, str + len - 1);  //全部逆置
	while (*str != '\0')
	{
		char* pos = str;
		while ((*str != ' ') && (*str != '\0'))
		{
			str++;
		}
		reverse(pos, str - 1);    //每个单词的逆置
		if (*str != '\0')
		{
			str++;
		}
	}
}

int main()
{
	char str[1024];
	printf("原字符串:");
	scanf("%[^\n]", &str)

	str_reverse(str);
	printf("翻转后的字符串为：%s\n", str);

	system("pause");
	return 0;
}

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	string str1,str2;
	cin>>str2;

	while (cin>> str1)
	{
		str2 = str1 + " " + str2;
	}

	cout << str2 << endl;

	system("pause");
	return 0;
}
#include<iostream>
#include<string>
#include <stdlib.h>
using namespace std;
cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
int main()
{
	string s1, s2;
	cin >> s2;

	while (cin >> s1)
		s2 = s1 + " " + s2;

	cout << s2 << endl;
	system("pause");
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	 注意这里要使用getline，cin>>s遇到空格就接收结束了
	getline(cin, s);
	 翻转整个句子
	reverse(s.begin(), s.end());
	 翻转单词
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);
			if (end != s.end())
				start = end + 1;
			else
				start = end;
	}
	cout << s << endl;
	return 0;
}