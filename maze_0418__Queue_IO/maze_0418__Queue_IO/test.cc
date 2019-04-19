#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
using namespace std;
#include <stack>
#include <queue>

//括号匹配
class Solution
{
public:
	bool isValid(string s)
	{
		stack<char>stack_ch;
		int size = s.size();
		for (int i = 0; i < size; ++i)
		{
			char ch = s[i];
			switch (ch)
			{
			case'(':
			case'[':
			case'{':
				stack_ch.push(ch);
				break;
			case')':
			case']':
			case'}':
			{
				if (stack_ch.empty())
				{
					return false;
				}
				char left = stack_ch.top();
				if (!((ch == ')'&& left == '(') ||
					(ch == ']'&& left == '[') ||
					(ch == '}'&& left == '{')))
				{
					return false;
				}
				stack_ch.pop();
			}
			default:
				break;
			}
		}
		if (stack_ch.empty())
		{
			return true;
		}
		else { return false; }
	}
};

//用队列实现栈
class MyStack {
public:
	queue<int>	q;
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int size = q.size() - 1;
		for (int i = 0; i < size; ++i)
		{
			int m = q.front();
			q.pop();
			q.push(m);
		}
		int d = q.front();
		q.pop();
		return d;
	}

	/** Get the top element. */
	int top() {
		int size = q.size() - 1;
		for (int i = 0; i < size; ++i)
		{
			int data = q.front();
			q.pop();
			q.push(data);
		}
		int d = q.front();
		q.pop();
		q.push(d);
		return d;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};

//用栈实现队列
class MyQueue {
public:
	/** Initialize your data structure here. */
	stack<int>left;
	stack<int>right;
	MyQueue() {
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		right.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (!left.empty())
		{
			left.pop();
		}
		int size = left.size();
		for (int i = 0; i < size; ++i)
		{
			int data = right.top();
			right.pop();
			left.push(data);
		}
		int d = left.top();
		left.pop();
		return d;
	}

	/** Get the front element. */
	int peek() {
		if (left.empty())
		{
			int size = right.size();
			for (int i = 0; i < size; ++i)
			{
				int data = right.top();
				right.pop();
				left.push(data);
			}
		}
		int d = left.top();
		return d;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return left.empty() && right.empty();
	}
};

//实现一个最小栈
class MinStack {
public:
	/** initialize your data structure here. */
	stack<int>normal;
	stack<int>min;
	MinStack() {
	}

	void push(int x) {
		normal.push(x);
		if ( min.empty()||x <= min.top())
		{
			min.push(x);
		}
		else
		{
			min.push(min.top());
		}
	}

	void pop() {
		normal.pop();
		min.pop();
	}

	int top() {
		return normal.top();
	}

	int getMin() {
		return min.top();
	}
};

//设计循环队列
