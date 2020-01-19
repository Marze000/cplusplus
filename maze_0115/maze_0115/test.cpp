#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

#if 0
int findMinArrowShots(vector<vector<int>>& points) {
	int res = points.size();
	sort(points.begin(), points.end());
	for (int i = 1; i < points.size(); i++) {
		// 如果小于前一个的末尾，则箭少用一支
		if (points[i][0] <= points[i - 1][1]) {
			// 选出公共区间
			points[i] = {
				max(points[i - 1][0], points[i][0]),
				min(points[i - 1][1], points[i][1])
			};
			res -= 1;
		}
	}
	return res;
}

string toLowerCase(string str) {
	int n = str.size();
	string res = str;
	for (int i = 0; i < n; ++i) {
		if (res[i] <= 92 && res[i] >= 65) {
			res[i] -= '32';
		}
	}
	return res;
}

int searchInsert(vector<int>& nums, int target) {
	int n = nums.size();
	if (n == 0) {
		return 0;
	}
	int left = 0;
	int right = n;
	while (left < right) {
		int mid = left + ((right - left) >> 1);
		// 注意不要把 /2 写成 >>1 因为 right-left 可能等于0
		// 当==0的时候，右移就会变成一个大数
		if (nums[mid] > target) {
			right = mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	return left;
}

#include <map>
//bool canConstruct(string ransomNote, string magazine) {
//	map<char, int>mp;
//	for (size_t i = 0; i < magazine.size(); ++i) {
//		mp[magazine[i]] += 1;
//	}
//	for (size_t i = 0; i < ransomNote.size(); ++i) {
//		if (mp.find(ransomNote[i]) == mp.end()) {
//			return false;
//		}
//		mp[i].second -= 1;
//		if (mp[i].second == 0) {
//			return false;
//		}
//	}
//	return true;
//}

int lengthOfLastWord(string s) {
	int left = 0;
	int right = 0;
	int n = s.size();
	while (right < s.size()) {
		while (right < n && s[right] != ' ') {
			++right;
		}
		if (right != n) {
			left = right + 1;
			right = left + 1;
		}
	}
	return right - left;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (m == 0 && n == 0) {
		nums1[0] = 1;
		return;
	}
	n = n - 1;
	int n1 = nums1.size() - 1;
	for (; n >= 0; --n) {
		if (nums2[n] > nums1[m - 1]) {
			nums1[n1] = nums2[n];
			n1 -= 1;
		}
		else {
			int x = n1 - m + 1;
			int j = m - 1;
			while (x--) {
				if (nums2[n] < nums2[j]) {
					nums1[j + 1] = nums1[j];
					j -= 1;
				}
			}
			nums1[j + 1] = nums2[n];
		}
	}
}


int fun(int a) {
	int b;
	switch (a) {
	case 1: b = 30;
	case 2: b = 20;
	case 3: b = 10;
	case 4: b = 0;
	}
	return b;
}

vector<int> sortArrayByParity(vector<int>& A) {
	int start = 0;
	int end = A.size() - 1;
	while (start < end) {
		if (A[start] % 2 == 0) {
			++start;
		}
		if (A[end] % 2 != 0) {
			--end;
		}
		if ((A[start] % 2 != 0) && (A[end] % 2 == 0)) {
			swap(A[start++], A[end--]);
		}
	}
	return A;
}
#include <algorithm>
#include <math.h>

vector<int> plusOne(vector<int>& digits) {
	int n = digits.size() - 1;
	if (digits[n] < 9) {
		digits[n] += 1;
		return digits;
	}
	for (int i = digits.size() - 1; i >= 0; --i) {
		if (digits[i] + 1 == 10) {
			digits[i] = 0;
		}
		else {
			digits[i] += 1;
		}
	}
	if (digits[0] == 0) {
		digits[0] = 1;
		digits.push_back(0);
	}
	return digits;
}

typedef long long ll;
int thirdMax(vector<int>& nums) {
	ll one = LLONG_MIN;
	ll two = LLONG_MIN;
	ll three = LLONG_MIN;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > one) {
			three = two;
			two = one;
			one = nums[i];
		}
		if (nums[i] < one) {
			if (nums[i] > two) {
				three = two;
				two = nums[i];
			}
		}
		if (nums[i] < two) {
			three = max(three, (ll)nums[i]);
		}
	}

	return nums.size() <= 2 ? one : (three != LLONG_MIN ? three : one);
}
int f(int n) {
	if (n) {
		return n + f(n - 1);
	}
	else {
		return n;
	}
}

int fun(int x, int y){
	if (x == y) {
		return (x);
	}
	else {
		return ((x + y) / 2);
	}
}

#include <map>
vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int> m;
	for (int i = 0; i<nums.size();++i){
		m[nums[i]] = i;
		// m.count  存在返回1，不存在返回0
		if (m.find(target-nums[i])!=m.end()) {
			return {m[target-nums[i]],i};
		}
	}
	return { -1, -1 };
}


vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> hash;
	for (int i = 0; i < nums.size(); i++) {
		if (hash.count(target - nums[i]))
			return { hash[target - nums[i]], i };
		hash[nums[i]] = i;
	}
	return { -1, -1 };
}

string reverse(string& str) {
	int start = 0;
	int end = str.size() - 1;
	while (start < end) {
		swap(str[start++], str[end--]);
	}
	return str;
}
string addBinary(string a, string b) {
	a = reverse(a);
	b = reverse(b);
	int i = 0, carry = 0;
	string res = "";
	int top,bottom;
	while (i < a.size() || i < b.size()) {
		if (i < a.size()) {top = a[i] - '0';}
		else {top = 0;}
		if (i < b.size()) {bottom = b[i] - '0';}
		else {bottom = 0;}

		int sum = top+ bottom + carry;

		carry = sum / 2;
		res += to_string(sum % 2);
		i++;
	}
	if (carry) {
		res += to_string(carry);
	}
	return reverse(res);
}

int a, b;
void fun() {
	a = 100;
	b = 200;
}

struct HAR{ 
	int x,y;
	struct HAR *p;
}h[2];

bool isdigit(char s) {
	if ((s <= '9' && s >= '0') || (s == '-') || (s == '+')) {
		return true;
	}
	else {
		return false;
	}
}
int myAtoi(string str) {
	string res = "";
	for (size_t i = 0; i < str.size(); ++i) {
		if (isdigit(str[i])) {
			res += str[i];
		}
	}

	int ret = atoi(res.c_str());
	return min(ret,max(INT_MIN, ret));
}

bool idalphadigit(char c) {
	if (c <= 'z' && c >= 'a') {
		return true;
	}
	if (c <= 'Z' && c >= 'A') {
		return true;
	}
	if (c <= '9' && c >= '0') {
		return true;
	}
	return false;
}
bool ishowen(string str) {
	int start = 0;
	int end = str.size() - 1;
	while (start < end) {
		if (str[start] != str[end]) {
			return false;
		}
		end--;
		start++;
	}
	return true;
}
bool isPalindrome(string s) {
	string res = "";
	for (size_t i = 0; i < s.size(); ++i) {
		if (idalphadigit(s[i])) {
			if (s[i] <= 'z' && s[i] >= 'a') {
				s[i] -= 32;
			}
			res += s[i];
		}
	}
	return ishowen(res);
}

#endif
int func(int i, int j){
	if (i <= 0 || j <= 0)
		return 1;
	return 2 * func(i - 3, j / 2);
}

#include <stack>
#include <math.h>
int min(int a, int b) {if (a < b) {	return a;} return b;}
int max(int a, int b) {if (a > b) {	return a;} return b;}

int main() {
	vector<int>nums{2, 6, 4, 8, 10, 9, 15};
	stack<int>s;
	int left = nums.size();
	for (size_t i = 0; i < nums.size(); ++i) {
		while (!s.empty() && s.top() > nums[i]) {
			left = min(left, s.size()-1);
			s.pop();
			i += 1;
		}
		s.push(nums[i]);
	}

	while (!s.empty()) {
		s.pop();
	}
	int right = 0;
	for (int i = nums.size()-1; i >= 0; --i) {
		while (!s.empty() && s.top() < nums[i]) {
			right = max(right, s.size()-1);
			s.pop();
			i -= 1;
		}
		s.push(nums[i]);
	}
	right = nums.size() - right;
	cout << right - left +1<< endl;

	// return right - left > 0 ? right - left + 1 : 0;
	//int a = 1; int b = 2;
	//for (; a < 8; a++){

	//	b += a; a += 2;
	//}
	//printf("%d，%d\n", a, b);

	//int a[] = { 2,4,6,8 }, *p = a, i;
	//for (i = 0; i < 4; i++) {
	//	a[i] = *p++;
	//}
	//printf("%d\n", a[2]);

	// cout << func(15, 20) << endl;
	//vector<int>v{ 'a','a','a','a','g','g','b','b','c','c','f','f','d','d' };
	//unordered_map<char, int>mp;
	//for (auto&e : v) {
	//	mp[e]++;
	//}
	//for (int i = 0; i < v.size(); ++i) {
	//	cout << mp[v[i];
	//}

	/*for (auto&e : mp) {
		cout << e.first << ':' << e.second;
	}
	cout << endl;
*/
#if 0
	string s = "A man, a plan, a canal: Panama";
	if (isPalindrome(s)) {
		cout << "true";
	}
	cout << "false";


	//char s[] = "abcdefgh";
	//char*p = s;
	//p += 3;
	//printf("%d\n", strlen(strcpy(p, "ABCD")));
	//char e[] = "abcdedfas";
	//strcpy(p, "ABCdajkfhdkajh");


	int a, b;
	scanf("%d,%d", &a, &b);
	if (a > b) {
		a = b;
		b = a;
	}
	else {
		a++;
		b++;
	}
	printf("%d,%d", a, b);

	// string str = "-91283472332";
	// cout << myAtoi(str) << endl;
	/*long long a = LONG_MIN;
	cout << a << endl;
*/
	//h[0].x = 1; h[0].y = 2;
	//h[1].x = 3; h[1].y = 4;
	//h[0].p = &h[1]; 
	//h[1].p = h;//h 代表的是 h[0]的地址
	//printf("%d,%d \n", (h[0].p)->x, (h[1].p)->y);

	//int a = 5, b = 7;
	//fun();
	//printf("%d %d\n", a, b);

	 // cout << addBinary("11", "1");
	//vector<int>num{ 3,2,4 };
	//for (auto&e : twoSum(num, 6)) {
	//	cout << e << ' ';
	//}
	//cout << endl;
#endif
	system("pause");
	return 0;
}