#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
给定一个二维数组board，代表当前棋盘
其中元素为 1 的代表是当前玩家的棋子，为 0 表示没有棋子，
为 -1 代表是对方玩家的棋子。
测试样例：

class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		 write code here
		int row = board.size();
		int sum = 0;
		int i = 0;
		int j = 0;
		for (i = 0; i < row; ++i)
		{
			for (j = 0; j < row; ++j)
			{
				sum += board[i][j];
			}
			if (sum == row) {
				return true;
			}
		}

		sum = 0;
		for (i = 0; i < row; ++i)
		{
			for (j = 0; j < row; ++j)
			{
				sum += board[j][i];
			}
			if (sum == board) {
				return true;
			}
		}

		sum = 0;
		for (i = 0; i < row; ++i)
		{
			sum += board[i][i];
		}
		if (sum == row) {
			return true;
		}

		sum = 0;
		for (i = 0; i < row; ++i)
		{
			sum += board[i][row - i - 1];
		}
		if (row == sum)
		{
			return true;
		}
		return false;
	}
};


#include<iostream>
#include<string>
using namespace std;

int numChar(string str, int k)
{
	根据ASCII码判断字母大小写
	int small = 0;
	int big = 0;
	for (int i = 0; i < k; i++){
		if (str[i] >= 65 && str[i] <= 90){
			big++;
		}
		else if (str[i] >= 97 && str[i] <= 122) {
			small++;
		}
	}
	if ((small + big) == 0) {
		return 0;
	}
	else if (small == k || big == k) {
		return 10;
	}
	else if (small > 0 && big > 0) {
		return 20;
	}

	return 0;
}

int numNumber(string str, int k)
{
	根据ASCII码判断数字个数，减去字符‘0’之后在0~9之间的即为数字
	int num = 0;
	for (int i = 0; i < k; i++){
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
			num++;
		}
	}
	if (num == 0){
		return 0;
	}
	else if (num == 1) {
		return 10;
	}
	else {return 20;}
}

int numSymbal(string str, int k)
{
	int num = 0;
	for (int i = 0; i < k; i++){
		除去字母，数字，其它都为符号
		if (!(str[i] >= 65 && str[i] <= 90)
			&& !(str[i] >= 97 && str[i] <= 122)
			&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
			num++;
	}
	if (num == 0) {
		return 0;
	}
	else if (num == 1) {
		return 10;
	}
	else{return 25;}
}
int main()
{
	string str;
	while (cin >> str)
	{
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
		int k = str.size();
		if (k <= 4)
			sum1 = 5;
		else if (k >= 8)
			sum1 = 25;
		else
			sum1 = 10;

		sum2 = numChar(str, k);
		sum3 = numNumber(str, k);
		sum4 = numSymbal(str, k);
		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0))
		{
			if (sum2 == 10)
				sum5 = 3;
			else
				sum5 = 5;
		}
		else if (sum2 > 0 && sum3 > 0 && sum4 == 0)
			sum5 = 2;
		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
			cout << "VERY_SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
			cout << "SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
			cout << "VERY_STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
			cout << "STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
			cout << "AVERAGE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}

#define N 9

int x[N];
int count = 0;

void dump() {
	int i = 0;
	for (i = 0; i < N; i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}
void swap(int a, int b) {
	int t = x[a];
	x[a] = x[b];
	x[b] = t;
}

void run(int n) {
	int i;
	if (N - 1 == n) {
		dump();
		count++;
		return;
	}
	for (i = n; i < N; i++) {
		swap(n, i);
		run(n + 1);
		swap(n, i);
	}
}

int main() {
	int i;
	for (i = 0; i < N; i++) {
		x[i] = i + 1;
	}
	run(0);
	printf("* Total: %d\n", count);

	system("pause");
	return 0;
}

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int func(int x) {
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);//与运算
		0010 0111 0000 1111
		0010 0111 0000 1110
	}
	return count;
}

int main()
{
	int ret = func(999);
	cout << ret << endl;

	system("pause");
	return 0;
}

int main()
{
	int n;
	while (cin >> n){
		int count = 0, maxCount = 0;
		 n右移32次就变为0
		while (n){
			获取当前位的二进制值
			if (n & 1){
				如果1的值连续，计数累加，并且跟新最大计数
				++count;
				maxCount = max(count, maxCount);
			}
			else{
				如果1的值不连续，重新累加
				count = 0;
			}
			右移一次，为获取下一位二进制值做准备
			n = n >> 1;
		}
		cout << maxCount << endl;
	}
	return 0;
}