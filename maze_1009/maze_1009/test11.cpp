#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	vector<int>vec{ 1,2,3,4,5,6,7,8, };
	sort(vec.begin(), vec.end(), cmp);
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}

#if 1
static bool cmp(int a, int b) {
	string A = "";
	string B = "";
	A += to_string(a);
	A += to_string(b);
	B += to_string(b);
	B += to_string(a);

	return A < B;
}

string PrintMinNumber(vector<int> numbers) {
	string  answer = "";
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i < numbers.size(); i++) {
		answer += to_string(numbers[i]);
	}
	return answer;
}


//static bool cmp(int a, int b) {
//	string A = "";
//	string B = "";
//	A += to_string(a);
//	A += to_string(b);
//	B += to_string(b);
//	B += to_string(a);
//
//	return A < B;
//}

string PrintMinNumber(vector<int> numbers) {
	string  answer = "";
	sort(numbers.begin(), numbers.end(), [](int a,int b) {
		string A = to_string(a);
		string B = to_string(a);
		return A + B < B + A;
	});
	for (int i = 0; i < numbers.size(); i++) {
		answer += to_string(numbers[i]);
	}
	return answer;
}
bool cmp(int a, int b) {
	string A = to_string(a);
	string B = to_string(b);
	return A > B;
}
string PrintMinNumber(vector<int> numbers) {
	string result = "";
	sort(numbers.begin(), numbers.end(), cmp);

	for (size_t i = 0; i < numbers.size(); i++) {
		result += to_string(numbers[i]);
	}
	return result;
}

int main() {
	vector<int> numbers{ 1,23,34,234 };
	//34234231
	// sort(numbers.begin(), numbers.end());
	//int a[10] = { 1,4,6,3,2,8,5,9,0 ,7 };
	//vector<int>v(a, a + 10);
	//sort(v.begin(), v.end());
	//for (auto&e : v) {
	//	cout << ' ' << endl;
	//}
	//cout << endl;
	cout << PrintMinNumber(numbers) << endl;
	//332321
	system("pause");
	return 0;
}
int main() {
	int n = 100;
	string str = to_string(n);
	cout << str << endl;

	system("pause");
	return 0;
}
//按字典序从小到大排列 
bool cmp(string a, string b) {
	return a + b < b + a; 
}

int main() {
	string numbers[3];
	numbers[0] = "3";
	numbers[1] = "32";
	numbers[2] = "321";
	sort(numbers, numbers + 3,cmp);
	string s = "";
	for (int i = 0; i < 3; ++i) {
		s += numbers[i];
	}
	cout << s << endl;
	//PrintMinNumber(numbers);
	system("pause");
	return 0;
}
bool cmp(string a, string b) {
	return a + b < b + a; 
}
string PrintMinNumber(vector<int> numbers) {
	string answer;

	int size = numbers.size();
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i < numbers.size(); i++) {
		answer += numbers[i];
	}
	return answer;
}


int main() {
	string s[3];
	s[0] = "b"; s[1] = "ba"; s[2] = "ab";
	sort(s, s + 3, cmp);

	string res = "";
	for (int i = 0; i < 3; i++){
		res += s[i];
	}
	cout << res << endl;;

	system("pause");
	return 0;
}

//按字典序从小到大排列 
bool cmp(string a, string b) {
	return a < b; 
}

string PrintMinNumber(vector<int> numbers) {
	string answer;

	int size = numbers.size();
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i < numbers.size(); i++) {
		answer += numbers[i];
	}
	return answer;
}

int main() {
	vector<int>numbers{ '3','32','321' };
	PrintMinNumber(numbers);

	system("pause");
	return 0;
}

int NumberOf1Between1AndN_Solution(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 2;
	}
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		int j = i;
		while (j) {
			if (j % 10 == 1) {
				count += 1;
			}
			j = j / 10;
		}
	}
	return count;
}

int main() {
	cout << NumberOf1Between1AndN_Solution(10000)-1<< endl;

	system("pause");
	return 0;
}

int NumberOf1Between1AndN_Solution(int n){
	/* 主要思路：设定整数点（如1、10、100等等）
	作为位置点i（对应n的各位、十位、百位等等）
	分别对每个数位上有多少包含1的点进行分析
	根据设定的整数位置，对n进行分割，分为两部分，高位n/i，低位n%i
	当i表示百位，且百位对应的数>=2,如n=31456,i=100，
		则a=314,b=56，此时百位为1的次数有a/10+1=32（最高两位0~31），
		每一次都包含100个连续的点，即共有(a%10+1)*100个点的百位为1
	当i表示百位，且百位对应的数为1，如n=31156,i=100，
		则a=311,b=56，此时百位对应的就是1，
		则共有a%10(最高两位0-30)次是包含100个连续点，
		当最高两位为31（即a=311），本次只对应局部点00~56，共b+1次，
		所有点加起来共有（a%10*100）+(b+1)，这些点百位对应为1
	当i表示百位，且百位对应的数为0,如n=31056,i=100，
		则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30）

	综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，
	还有当百位为1(a%10==1)，需要增加局部点b+1
	之所以补8，是因为当百位为0，则a/10==(a+8)/10，
	当百位>=2，补8会产生进位位，效果等同于(a/10+1)
	*/

	int count = 0;
	long long i = 1;
	for (i = 1; i <= n; i *= 10){
		int a = n / i;
		int b = n % i;
		// a % 10 == 1）*（b+1）代表的是如果百位数字为1则需要加地位的数字
		count = count + (a + 8) / 10 * i + (a % 10 == 1)*(b + 1);
	}
	return count;
}
};
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	int len = input.size();
	if (len <= 0 || k > len) return vector<int>();
	//仿函数中的greater<T>模板，从大到小排序
	multiset<int, greater<int> > leastNums;
	vector<int>::iterator vec_it = input.begin();
	for (; vec_it != input.end(); vec_it++) {
		//将前k个元素插入集合
		if (leastNums.size() < k) {
			leastNums.insert(*vec_it);
		}
		else {
			//第一个元素是最大值
			multiset<int, greater<int> >::iterator greatest_it = leastNums.begin();
			//如果后续元素<第一个元素，删除第一个，加入当前元素
			if (*vec_it < *(leastNums.begin())) {
				leastNums.erase(greatest_it);
				leastNums.insert(*vec_it);
			}
		}
	}
	return vector<int>(leastNums.begin(), leastNums.end());
}

int main() {

	system("pause");
	return 0;
}
#endif
