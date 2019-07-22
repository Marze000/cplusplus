#if 1
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	long long CD[3] = {0, 0,1 };
	long long JC[3] = {0, 1,2 };
	for (int i = 3; i < 22; ++i) {
		CD[i] = (i - 1)*(CD[i - 1] + CD[i - 2]);
		JC[i] = JC[i - 1] * JC[i - 2];
	}

	cout << JC[4] << endl;

	system("pause");
	return 0;
}
#endif

#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	long long d[22] = { 0, 0, 1 };
	// 错排数量，预留第一项为 0 ，配合下文中输入的 n
	long long f[22] = { 0, 1, 2 }; 
	// 阶 乘
	for (int i = 3; i < 22; i++){
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]); // 错排的递推公式
		f[i] = i * f[i - 1]; // 阶乘的递推公式
	}

	int n;
	while (std::cin >> n){
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
		// 用 100.0 来把结果处理成 double ，保留两位小数
	}

	system("pause");
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	long long d[22] = { 0, 0, 1 };
	// 错排数量，预留第一项为 0 ，配合下文中输入的 n
	long long f[22] = { 0, 1, 2 };
	// 阶 乘
	for (int i = 3; i < 22; i++) {
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]); // 错排的递推公式
		f[i] = i * f[i - 1]; // 阶乘的递推公式
	}

	int n;
	while (std::cin >> n) {
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
		// 用 100.0 来把结果处理成 double ，保留两位小数
	}

	system("pause");
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
int main(){
	std::string line;
	// 第一次的输入抓到 line 里
	while (std::getline(std::cin, line)) {
		std::vector<std::string> names; 
		//names 里存放所有的数据
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
				size_t end = line.find(",",pos+1);
				// 找不到逗号证明这是最后一个字符串了，直接存了这个字符串后跳出ne.find(",", pos + 1);
				if (end == -1) {
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				}
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1; // 跳掉后面的逗号
			}
		}

		std::getline(std::cin, line);
		if (names.end() == std::find(names.begin(), names.end(), line))
			//std::find 函数是在两个迭代器中间查找，最后一个参数是要找的值。
			// 找到了返回对应迭代器，找不到就返回区间末尾的位置。本例中是 end() 。
		{
			printf("Important!\n"); // 没找到
		}else{
			printf("Ignore\n"); // 找到了
		}
	}
	return 0;
}