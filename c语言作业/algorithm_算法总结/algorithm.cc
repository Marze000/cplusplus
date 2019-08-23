#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

#if 1
//打印100 -200 之间的素数
void print() {
	for (int i = 100; i <= 200; ++i) {
		bool flag = true;
		for (int j = 2; j < i / 2; ++j) {
			if (i % j == 0) {
				flag = false;
			}
		}
		if (flag) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

//输出乘法口诀表
void mult_pintf() {
	printf("请输入乘法口诀表的行数\n");
	int num = 0;
	cin >> num;
	for (int i = 1; i <= num; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%d*%d==%2d ", j, i, i*j);
		}
		printf("\n");
	}
}

//判断1000年---2000年之间的闰年
void print_year() {
	int year = 1000;
	printf("请输入你想测试的年份\n");
	while (cin >> year) {
		if (year % 400 == 0 || ((year % 4 == 0) && year % 100 !=0)){
			printf("%d 是闰年", year);
		}
		else {
			printf("%d 不是闰年", year);
		}
		printf("\n");
	}
	printf("\n");
}

//交换两个整形变量的值
void swap_temp(int* a1,int* a2) {
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}

void swap(int* a1,int* a2) {
	*a1 = *a1 + *a2;
	*a2 = *a1 - *a2;
	*a1 = *a1 - *a2;
}

void test() {
	int a = 10;
	int b = 20;
	printf("a=%d  ",a);
	printf("b=%d\n",b);
	swap(&a,&b);
	printf("a=%d  ",a);
	printf("b=%d\n",b);
}

//3.求10 个整数中最大值。 
#include <vector>
void int_max() {
	vector<int>vec(10);
	for (int i = 0; i < 10; ++i) {
		cin >> vec[i];
	}
	int max = 0;
	for (int i = 0; i < 10; ++i) {
		if (max < vec[i]) {
			max = vec[i];
		}
	}
	printf("最大的数是 %d\n", max);
}
//4.将三个数按从大到小输出。
bool cmp(int a, int b) {
	return a > b;
}

bool cmp_dec(int a, int b) {
	return a < b;
}

void Greet_num() {
	vector<int>vec(10);
	for (int i = 0; i < 10; ++i) {
		vec[i] = i;
	}

	sort(vec.begin(),vec.end(),cmp_dec);
	for (int i = 0; i < 10; ++i) {
		cout << vec[i]<<" ";
	}
	cout << endl;
	sort(vec.begin(),vec.end(),cmp);
	for (int i = 0; i < 10; ++i) {
		cout << vec[i]<<" ";
	}
	cout << endl;

}

//5.求两个数的最大公约数。
void max_yueshu() {
	int a = 1;
	int b = 1;
	printf("请输入两个数\n");
	while (cin >> a >> b) {
		int Max = max(a, b);
		int Min = min(a, b);
		for (int i = Min; i > 1; --i) {
			if (Max % i == 0 && Min % i == 0) {
				printf("最大公约数是 %d\n", i);
				break;
			}
		}
	}
}

//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
void array_swap() {
	vector<int>a(11);
	vector<int>b(11);
	for (int i = 0; i < 10; ++i) {
		a[i] = i;
	}
	for (int i = 10; i > 0; --i) {
		b[i] = i;
	}

	cout << "a数组中的元素" << endl;
	for (int i = 0; i < 10; ++i) {
		cout << a[i]<<" ";
	}
	cout << "b数组中的元素" << endl;
	for (int i = 10; i > 0; --i) {
		cout << b[i]<<" ";
	}
	for (int i = 0; i < 10; ++i) {
		int temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	cout << "a数组中的元素" << endl;
	for (int i = 0; i < 10; ++i) {
		cout << a[i]<<" ";
	}
	cout << "b数组中的元素" << endl;
	for (int i = 0; i < 0; ++i) {
		cout << b[i]<<" ";
	}
	cout << endl;
}
//2. 计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
void calc() {
	int j = 1;
	int result = 0;
	for (int i = 1; i < 100; ++i) {
		if (i % 2 == 0) {
			result -= j / i;
		}
		else {
			result += j / i;
		}
	}
	cout << result << endl;
}

//3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。
void calc_count() {
	int count = 0;
	for (int i = 0; i < 100; ++i) {
		if (i % 9 == 0 || i / 9 == 0) {
			++count;
		}
	}
	cout << count << endl;
}

// 打印一个* 号的图样
void print_xin() {
	for (int i = 1; i <= 11; i+=2){
		for (int j = 0; j < i; ++j) {
			printf("*");
		}
		cout << endl;
	}
	for (int i = 9; i >= 1; i-=2){
		for (int j = 0; j < i; ++j) {
			printf("*");
		}
		cout << endl;
	}
}

//2.求出0～999之间的所有“水仙花数”并输出。
//“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，
//	如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。

/*
在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），是指一N位数，其各个数之N次方和等于该数。
例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
153 = 1^3 + 5^3 + 3^3。
370 = 3^3 + 7^3 + 0^3。
371 = 3^3 + 7^3 + 1^3。
407 = 4^3 + 0^3 + 7^3。
*/
void printWater() {
	for (int i = 0; i <= 999; ++i) {
		int a1 = i % 10;
		int a2 = i / 10 % 10;
		int a3 = i / 10 / 10 % 10;
		if (a1*a1*a1 + a2 * a2*a2 + a3 * a3*a3 == i) {
			printf("%d 是一个水仙花数\n",i);
			printf("%d = %d^3 + %d^3 + %d^3\n", i, a3, a2, a1);
		}
	}
}

//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222

//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。

void init(int* arr) {
	for(int i = 0;i < 10;++i)
		arr[i] = 0;
}
void reverse(int* arr) {
	for (int i = 9; i > 0; --i)
		arr[i] = 0;
}
void create() {
	int result = 0;
	int a = 0;
	cout << "请输入 a 数字的值" << endl;
	cin >> a;
	int an = 0;
	for (int i = 1; i <= 5; ++i) {
		an = an * 10 + a;
		result += an;
	}
	cout << result << endl;


	int array[10];
	init(array);
	reverse(array);
}


//1.递归和非递归分别实现求第n个斐波那契数。
int FeiBo(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1;
	}
	return FeiBo(n - 1) + FeiBo(n - 2);
}

int FeiBoNor(int n) {
	int first = 1;
	int second = 1;
	int last = 2;
	for (int i = 3; i < n; ++i) {
		first = second;
		second = last;
		last = first + second;
	}
	return last;
}
void test() {
	cout << FeiBo(12) << endl;
	cout << FeiBoNor(12) << endl;
}
//2.编写一个函数实现n^k，使用递归实现
int zhishu(int n,int k) {
	if (k == 1) {
		return n;
	}
	else {
		return n * zhishu(n, k - 1);
	}
}

int zhishuNor(int n, int k) {
	int result = 1;
	for (int i = 0; i < k; ++i) {
		result = result * n;
	}
	return result;
}
void test() {
	int n = 2;
	int k = 10;
	cout << zhishu(n, k) << endl;
	cout << zhishuNor(n, k) << endl;
}

//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
int DigitSum(int n) {
	if (n < 10) {
		return n;
	}
	return DigitSum(n / 10) + (n%10);
}

int DigitSumNor(int n) {
	int res = n % 10;
	while (n) {
		n = n / 10;
		res += n % 10;
	}
	return res;
}

void test() {
	int a = 1729;
	cout << DigitSum(a) << endl;
	cout << DigitSumNor(a) << endl;
}
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
char* reverse_string(char*string) {
	char* q = string;
	int n = strlen(string);
	if (n > 1) {
		char tmp = q[0];
		q[0] = q[n - 1];
		q[n - 1] = '\0';
		reverse_string(string + 1);
		q[n - 1] = tmp;
	}
	return q;
}
void test() {
	char str[] = "hehemaze";
	printf("%s\n", str);
	char* ret = reverse_string(str);
	printf("%s\n", ret);
}
//5.递归和非递归分别实现strlen
int Strlen(char* string ) {
	int count = 0;
	while (*string != '\0') {
		string++;
		count++;
	}
	return count;
}
int strlenNor(char* str) {
	if (*str == '\0') {
		return 0;
	}
	return 1 + strlenNor(str + 1);
}
void test() {
	char str[] = "hehehe";
	cout << Strlen(str) << endl;
	cout << strlenNor(str) << endl;
}
//6.递归和非递归分别实现求n的阶乘
int jiechen(int n) {
	if (n == 1) {
		return 1;
	}
	return n * jiechen(n - 1);
}
int jiechengxunhuan(int n) {
	int result = 1;
	for (int i = 1; i <= n; ++i) {
		result *= i;
	}
	return result;
}
void test() {
	cout<<jiechen(5);
	cout << endl;
	cout << jiechengxunhuan(5) << endl;
}
//7.递归方式实现打印一个整数的每一位
void print(int n) {
	if (n > 9) {
		print(n / 10);
	}
	printf("%d ", n % 10);
}
void Print(int n) {
	if (n < 10) {
		printf("%d ", n);
	}
	else {
		Print(n / 10);
		printf("%d ", n % 10);
	}
}

void test() {
	print(1729);
	printf("\n");
	Print(1729);
	printf("\n");
}

#endif
/*
1.
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
*/
int partion() {
	for (int);
}
/*
2.
日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
嫌疑犯的一个。以下为4个嫌疑犯的供词。
A说：不是我。
B说：是C。
C说：是D。
D说：C在胡说
已知3个人说了真话，1个人说的是假话。
现在请根据这些信息，写一个程序来确定到底谁是凶手。
*/
void mudder() {
	char muder = 'A';
	for (muder = 'A'; muder < 'D'; ++muder) {
		if ((muder != 'A') + (muder == 'C') + (muder == 'D') + (muder != 'D') == 3) {
			printf("熊搜是 %c\n", muder);
		}
	}
}
void test() {
	mudder();
}
/*
3.在屏幕上打印杨辉三角。
1
1 1
1 2 1
1 3 3 1

*/
int main() {
	test();
	system("pause");
	return 0;
}