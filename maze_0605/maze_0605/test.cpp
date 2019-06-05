#include <iostream>
using namespace std;

int perfect(int m)
{
	int sum = 0;
	for (int i = 1; i < m; ++i) {
		if (m%i == 0) {
			sum += i;
		}
	}
	if (sum == m) {
		return 1;
	}
	else {
		return 0;
	}
}

void count(int n)
{
	int num = 0;
	for (int i = 3; i < n + 1; ++i) {
		if (perfect(i) == 1) {
			++num;
		}
	}
	if (num != 0) {
		cout << num;
	}
	else {
		cout << -1;
	}
}

int main()
{
	int N = 0;
	while (cin >> N) {
		count(N);
	}

	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
判断素数
bool isPrime(int num){
	int tmp = sqrt(num);
	只遍历到开方出，不能被开方左边的数整除，则一定不能被开方右边的数整除
	for (int i = 2; i <= tmp; i++){
		if (num %i == 0)
			return false;
	}
	return true;
}
int main()
{
	int num;
	int half;
	int i;
	while (cin >> num){
		half = num / 2;
		从中间向两边找
		for (i = half; i > 0; i--){
			if (isPrime(i) && isPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}

#include < iostream>
using namespace std;

void func(const int& v1, const int& v2)
{
	cout << "v1地址"<<&v1 << endl;
	cout << "v2地址"<<&v2 << endl;
	std::cout<<"v1 = " << v1 << ' ';
	std::cout << "v2 = "<< v2 << ' ';
}

int main(int argc, char* argv[])
{
	int i = 0;
	func(++i, i++);
	return 0;
}

struct st_task
{
	uint16_t id;
	uint32_t value;
	uint64_t timestamp;
};

void fool()
{
	st_task task = {};
	uint64_t a = 0x00010001;
	memcpy(&task, &a, sizeof(uint64_t));
	printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
}

因为字节对齐的原因，所以id占用4个字节，value和timestamp分别是4个字节、8个字节。
虽然id占用四个字节的地址，但是只有低两位地址的数值有效
（字节对齐的机制，即value存储时的地址对4（自身对齐值）求余应为0）。
所以id为 0001 0001，高四位无效，所以为0001，value与timestamp分别为0.
比如：地址从0x0000开始，id存储地址本来为0x0000 - 0x0001，
但value存储地址要从0x0004开始，因为0x0004 % 4 == 0，
所以id存储地址为0x0000 - 0x0003, value存储地址为0x0004 - 0x0007, 
timestamp存储地址为0x0008 - 0x000F.
所以id == 0x00010001，去掉高4位，id = 0x0001，其余为0.

int main()
{
	fool();

	system("pause");
	return 0;
}

#define SQR(A) A*A

int main() {
	int x = 6, y = 3, z = 2;
	x /= SQR(y + z) / SQR(y + z);
	x = 5 * 5 / 5 * 5;
	cout << x << endl;
	system("pause");
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int c = 0;
void move(char x, int n, char z){
	第n个圆盘从塔座x搬到塔座z
	printf("第%-2d步：将%d号盘从%c移到%c\n", ++c, n, x, z);
}

void hanoi(int n, char x, char y, char z){
	if (n == 1){
		move(x, 1, z);
	}else{
		/*如果n为奇数，则直接把1号盘移到z的位置
		但是如果n为偶数，则先把1号盘移到y的位置
		所以需要交换形参的位置,如果 n 是奇数，
		则正好又交换回去了，相当于没有交换*/
		hanoi(n - 1, x, z, y);
		move(x, n, z);

		/*交换x 和 y 的位置，因为执行到这步之前
		就已经把x位置的盘子全部移到y上了，所以得
		交换一下x y 位置，让y 位置的盘子移到z位置 */
		hanoi(n - 1, y, x, z);
	}
}

int main(){
	int n = 0;
	printf("输入圆盘数：\n");
	scanf("%d", &n);
	hanoi(n, 'a', 'b', 'c');

	system("pause");
	return 0;
}

