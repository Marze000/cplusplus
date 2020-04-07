#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
	heights.push_back(0);
	stack<int> stk;
	int maxArea = 0;
	for (int i = 0; i < heights.size(); i++) {
		while (!stk.empty() && heights[i] < heights[stk.top()]) {
			int top = stk.top();
			stk.pop();
			maxArea = max(maxArea, heights[top] * (stk.empty() ? i : (i - stk.top() - 1)));
		}
		stk.push(i);
	}
	return maxArea;
}
int main() {
	vector<int>heights = { 2,1,5,6,2,3 };
	cout << largestRectangleArea(heights) << endl;


	system("pause");
	return 0;
}