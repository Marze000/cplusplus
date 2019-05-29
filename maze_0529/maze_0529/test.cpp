/******************
*代码功能：不使用加法以及其他运算符实现相加两个数

*实现方法：位运算
*******************/

#include <iostream>
#include <stdlib.h>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		while (B != 0)
		{
			int temp = A ^ B;
			B = (A & B) << 1;
			A = temp;
		}
		return A;
	}
};

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	
	int s = (n-1) * (m-1) - 1;
	cout << 2 * s << endl;

	system("pause");
	return 0;
}

