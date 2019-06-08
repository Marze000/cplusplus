#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//using namespace std;
//
//int main()
//{
	
	
	//int a = 1;
	//if (*(char*)&a == 1)
	//{
	//	std::cout << "big" << endl;
	//}
	//else {
	//	std::cout << "small" << endl;
	//}


	//long a = 0;
	//long long b = 0;
	//printf("long字节数： %d\n", sizeof(a));
	//printf("long long 字节数： %d\n", sizeof(b));
	//long long a = 1, b = 2, c = 3;
	//printf("%lld %lld %lld\n", a, b, c);
	//printf("%lld ", a);
	//printf("%lld ", b);
	//printf("%lld\n", c);
	//char p[] = "abc";
	//char q[] = "abc123";
	//char *p1 = p;
	//char *q2 = q;
	//while (*p1 == *q2) {
	//	printf("%c %c", *p1, *q2);
	//	++q2, ++p1;
	//}

	//int a[] = { 1,2,3,4,5 };
	//int*p[] = { a,a + 1,a + 2,a + 3 };
	//int **q = p;

	//printf("%n\n", *(p[0] + 1) + **(q + 2));

//	system("pause");
//	return 0;
//}


//函数fun的功能是:求ss所指字符串数组中长度最短的字符串所在的
//行下标作为函数值返回,并把其串长放在形参n所指的变量中。
////ss所指字符串数数组中共有M个字符串，且串长小于N。
//#include <iostream>
//#include <string>
//using namespace std;
//#define M 5
//#define N 20
//int fun(char(*ss)[N], int *n){
//	int i, k = 0, len = N;
//	for (i = 0; i < M; i++){
//		len = strlen(ss[i]);
//		if (i == 0)
//			*n = len;
//		if (len < * n){
//			*n = len;
//			k = i;
//		}
//	}
//	return k;
//}
//
//int main()
//{
//	char ss[M][N] = { "shanghai", "guangzhou", "beijing",
//		"tianjing", "chongqing" };
//	int n, k, i;
//	printf("\nThe originalb stringsare:\n");
//	for (i = 0; i < M; i++){
//		puts(ss[i]);
//	}
//	k = fun(ss, &n);
//	printf("\nThe length of shortest string is: % d\n", n);
//	printf("\nThe shortest string is: % s\n", ss[k]);
//
//	return 0;
//}

//				1
//			1	1	1
//		1	2	3	2	1	
//	1	3	6	7	6	3	1
//1	4	10  16  19  16  10  4   1

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n, m;
//	while (cin >> n){
//		m = 2 * n - 1;
//		vector<vector<int>> dp(n, vector<int>(m, 0));
//		dp[0][0] = 1;
//		for (int i = 1; i < n; i++){
//			// 第一列和最后一列都为 1
//			dp[i][0] = dp[i][2 * i] = 1;
//			for (int j = 1; j < 2 * i; ++j){
//				if (j == 1) {
//					// 如果是第二列，则只是两个元素之和
//					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//				}
//				else {
//					// 第 i,j 元素等于上一行第 j - 2,j - 1,j 三列元素之和
//					dp[i][j] = dp[i - 1][j - 2] + dp[i - 1][j - 1] + dp[i - 1][j];
//				}
//			}
//		}
//		int k;
//		for (k = 0; k < m; k++){
//			if (dp[n - 1][k] % 2 == 0 && dp[n - 1][k] != 0){
//				cout << k + 1 << endl;
//				break;
//			}
//		}
//
//		if (k == m)
//			cout << -1 << endl;
//	}
//	return 0;
//}

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string addStrings(string num1, string num2) {
	由低位向高位相加
		int i = num1.size() - 1;
	int j = num2.size() - 1;
	string result = "";
	当前位的相加结果
		int carry = 0;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0) {
			carry += num1[i] - '0';
		}
		if (j >= 0) {
			carry += num2[j] - '0';
		}
		当前为的最大值不大于 10
			result += (char)(carry % 10 + '0');
		如果大于10, 向上进一位
			carry /= 10;
		i--;
		j--;
	}
	相加完之后，如果还有进位，则再加 1
		if (carry == 1)
		{
			result += '1';
		}
	整体逆置
		reverse(result.begin(), result.end());
	return result;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << addStrings(s1, s2) << endl;
	}
	return 0;
}