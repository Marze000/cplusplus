/*输入有多组数据，每组数据有两行。
第一行抄送列表，姓名之间用一个逗号隔开。
如果姓名中包含空格或逗号，则姓名包含在双引号里。总长度不超过512个字符。
第二行只包含一个姓名，是待查找的用户的名字（姓名要完全匹配）。
长度不超过16个字符。
输出描述：如果第二行的名字出现在收件人列表中，则输出“Ignore”，
表示这封邮件不重要；否则，输出“Important!”，
表示这封邮件需要被优先处理。
示例1 :输入
Joe, Kewell, Leon
Joe
"Letendre, Bruce", Joe, "Quan, William"
William
输出
Ignore
Important!*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	std::string line;
	// 第一次的输入抓到 line 里
	while (getline(cin, line)) {
		//names 里存放所有的数据
		vector<string> names; 
		size_t pos = 0;
		// 位置如果大于等于了长度，那么证明找完了，双引号的情况从这里跳出
		while (pos < line.length()) {
			// 找到双引号要处理双引号内部
			if (line[pos] == '\"') {
				size_t end = line.find("\"", pos + 1);
				names.push_back(line.substr(pos + 1, end - pos - 1));
				// 截取出来放到 names 里
				pos = end + 2;
				// 跳掉后面的双引号和逗号
			}else{
				size_t end = line.find(",", pos + 1);
				// 找不到逗号证明这是最后一个字符串了，
				//直接存了这个字符串后跳出
				if (end == -1) {
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				}
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1; // 跳掉后面的逗号
			}
		}

		std::getline(cin, line);
		if (names.end() == find(names.begin(), names.end(), line))
			//std::find 函数是在两个迭代器中间查找，最后一个参数是要找的值。
			// 找到了返回对应迭代器，找不到就返回区间末尾的位置。
			//本例中是 end() 。
		{
			printf("Important!\n"); // 没找到
		}else{
			printf("Ignore\n"); // 找到了
		}
	}
	return 0;
}

//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
//int main() {
//	int n;
//	//获得无人中奖的概率是 1- 所有人都中奖的概率
//	while (cin >> n) {
//		int sum = 1;
//		for (int i = 0; i < n; ++i) {
//			sum = sum * 1 / n;
//		}
//		int p = 1 - sum;
//		printf("%.2f%%\n", p);
//	}
//
//	system("pause");
//	return 0;
//}
//
//1. 首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
//2. 待所有字条加入完毕，每人从箱中取一个字条；
//3. 如果抽到的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
//现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？
//输入描述：输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。
//输出描述：对应每一组数据，以“xx.xx%”的格式输出发生无人获奖的概率。
	//输入:2
	//输出:50.00%