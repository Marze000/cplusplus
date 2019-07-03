#include <iostream>
#include<stdlib.h>
#include <vector>
using namespace std;

int FeiBoNa(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	return FeiBoNa(n - 1) + FeiBoNa(n - 2);
}

int main() {
	int n;
	vector<int>a;
	while (cin >> n) {
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			printf("%04d", FeiBoNa(a[i])%10000);
		}
	}
	return 0;
}

#include <iostream>
#include <vector>
std::vector<int> a = { 1,1 };
void data_init()
{
	int i;
	for (i = 2; i < 10005; i++) {
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
	}
}
int main()
{
	int n, t;
	data_init();
	while (std::cin >> n) {
		while (n--) {
			std::cin >> t;
			printf("%04d", a[t]);
		}
		printf("\n");
	}
	return 0;
//}
#include <iostream>
using namespace std;

int datacal(int num) {
	int first = 1;
	int second = 2;
	int third = 0;
	while (--num) {
		third = first + second;
		first = second;
		second = third;
	}
	return first;
}

int main(){
	int n, t;
	while (std::cin >> n) {
		while (n--) {
			std::cin >> t;
			printf("%04d", datacal(t)%10000);
		}
		printf("\n");
	}
	return 0;
} 

#include <string>
int numRoot(int num) {
	int nroot = 0;
	while (num > 0) {
		nroot += num % 10;
		num /= 10;
	}
	while (nroot > 9) {
		nroot = numRoot(nroot);
	}
	return nroot;
}

int main(){
	std::string origin;
	while (std::cin >> origin) {
		int sum = 0;
		//先将每一位进行相加得到总和，防止数字过大
		for (int i = 0; i < origin.length(); i++) {
			sum += origin[i] - '0';
		}
		//对总和求树根
		std::cout << numRoot(sum) << std::endl;
	}
	return 0;
}
#include<iostream>
#include<vector>
#include <string>
using namespace std;

int main(){
	int max = 0; //max初值.
	string str1, str2;
	while (cin >> str1 >> str2){
		int len1 = str1.size();
		int len2 = str2.size();
		int max = 0;
		//所有值初始化为0
		vector<vector<int>> dp(len1, vector<int>(len2, 0));
		//计算dp
		for (int i = 0; i < len1; i++){
			for (int j = 0; j < len2; j++){
				//如果当前结尾的字符相等，则在dp[i-1][j-1]的基础上加1
				if (str1[i] == str2[j]){
					if (i >= 1 && j >= 1)
						dp[i][j] = dp[i - 1][j - 1] + 1;

					else
						//dp[i][0] or dp[0][j]
						dp[i][j] = 1;
				}
				//更新最大值
				if (dp[i][j] > max)
					max = dp[i][j];
			}
		}
		cout << max << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;

void oddInOddEvenInEven(int arr[], int len) {
	int begin = 0;
	int end = len - 1;
	if (len % 2 == 0) {
		while (begin <= end) {
			while (arr[begin] % 2 == 0 && begin <= end) {
				begin += 2;
			}

			while (arr[end] % 2 != 0 && begin <= end) {
				end-=2;
			}
			swap(arr[end], arr[begin]);
		}
	}
	else {
		while (begin < end) {
			while (arr[begin] % 2 == 0 && begin <= end) {
				begin += 2;
			}

			while (arr[end] % 2 == 0 && begin <= end) {
				end-=2;
			}
			swap(arr[end], arr[begin]);
		}
	}
}

int main() {
	int array[4] = { 1,2,3,4 };
	oddInOddEvenInEven(array, 4);
	for (int i = 0; i < 4; i++) {
		cout << array[i] << " " ;
	}

	system("pause");
	return 0;
}
