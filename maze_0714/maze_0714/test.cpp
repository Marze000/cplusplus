#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){

	long long n[91] = { 1, 2 };
	for (int i = 2; i <= 90; i++){
		n[i] = n[i - 1] + n[i - 2];
	}

	int d;
	while (std::cin >> d){
		printf("%lld\n", n[d - 1]);
	}

	int n;
	//接收数字
	while (std::cin >> n){ 
		 //处理回车
		std::cin.get();
		std::string name;
		 //名字分别处理
		for (int i = 0; i < n; i++){
			bool quote = false;
			std::getline(std::cin, name);
			if (name.find(',') != std::string::npos ||
				name.find(' ') != std::string::npos) 
				//找到逗号或者空格，就要加双引号
			{
				quote = true;
			}

			if (quote){
				putchar('\"'); //putchar效率更高
			}
			std::cout << name;
			if (quote){
				putchar('\"');
			}

			//如果已经是最后一个字符串，那就补回车，否则加逗号和空格
			if (i == n - 1) {
				putchar('\n');
			}else{
				putchar(',');
				putchar(' ');
			}
		}
	}
	system("pause");
	return 0;
}