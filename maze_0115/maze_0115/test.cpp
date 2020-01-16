#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

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

#if 0
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
#endif

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
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

int main() {
	vector<int>nums1 = {0};
	vector<int>nums2 = {1};
	merge(nums1,0, nums2, 1);
	for (auto &e : nums1) {
		cout << e << ' ';
	}
	cout << endl;
/*	int res = lengthOfLastWord("Hello world");
	cout << res << endl;
	*/// N = 2 M = 3  4*3/2 = 6
	//if (canConstruct("aa", "aab")) {
	//	cout << "True" << endl;
	//}
	//else {
	//	cout << "false" << endl;
	//}

/*	int i = 0, a = 0;
	while (i < 20){
		for (;;) {
			if (i % 10 == 0) {
				break;
			}
			else {
				i -= 1;
			}
		}
		i += 11, a += i;
	}
	printf("%d\n", a);
	*///vector<int>nums = {1,3,5,6};
	//int res = searchInsert(nums,7);
	//cout << res << endl;

/*	int a = 0;
	int b = a >> 1;
	cout << b << endl;
	*///string str = "Hello";

	//string res = toLowerCase(str);
	//cout << res << endl;

	//vector<vector<int>>arr = { {2,8},{3,6},{10,16},{7,12} };

	//sort(arr.begin(), arr.end());
	//int row = arr.size();
	//int col = arr[0].size();
	//for (int i = 0; i < row; ++i) {
	//	for (int j = 0; j < col; ++j) {
	//		cout << arr[i][j] << ',';
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	system("pause");
	return 0;
}