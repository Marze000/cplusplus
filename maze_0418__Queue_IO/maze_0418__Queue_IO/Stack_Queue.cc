#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
using namespace std;
#include <stack>
#include <queue>

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

//栈是个容器，要存入数据，存的是int类型的数据
//std::stack<int>	s;
//	std		命名空间		namespace
//	<>		模板编程		

//	s.push(1);   类和对象
//	s.pop();
//	int v = s.top();
//	int size = s.size();
//	s.empy();
//	string 字符串类型

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> stack_ch;//定义一个栈
		int size = s.size();//返回字符串的长度
		for (int i = 0; i < size; ++i)
		{
			char ch = s[i];
			switch (ch)
			{
			case'(':
			case'[':
			case'{':
				stack_ch.push(ch);//压入
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
				if (!((left == '('&& ch == ')') ||
					(left == '['&& ch == ']') ||
					(left == '{'&& ch == '}')))
				{
					return false;
				}
				stack_ch.pop();
				break;
			}
			default:
				break;
			}
		}
		if (!stack_ch.empty())
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

//用队列实现栈
class MyStack {
public:
	queue<int>	q;//成员变量
	
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
			int data = q.front();
			q.pop();
			q.push(data);
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
	stack<int> left;
	stack<int> right;
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		right.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (left.empty())
		{
			int size = right.size();
			for (int i = 0; i < size; ++i)
			{
				int d = right.top();
				right.pop();
				left.push(d);
			}
		}
		int v = left.top();
		left.pop();
		return v;
	}

	/** Get the front element. */
	int peek() {
		if (left.empty())
		{
			int size = right.size();
			for (int i = 0; i < size; ++i)
			{
				int d = right.top();
				right.pop();
				left.push(d);
			}
		}
		int v = left.top();
		return v;
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
	stack<int>	normal;
	stack<int>  min;
	MinStack() {
	}

	void push(int x) {
		normal.push(x);
		if (min.empty() || x <= min.top())
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
class MyCircularQueue {
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	int* array;
	int size;
	int capacity;
	int front;//队首下标
	int rear;//队尾下标
	MyCircularQueue(int k) {
		array = new int[k];
		capacity = k;
		front = 0;
		rear = 0;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (size == capacity)
		{
			return false;
		}
		array[rear] == value;
		rear = (rear + 1) % capacity;
		size++;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (size == 0)
		{
			return false;
		}
		front = (front + 1) % capacity;
		size--;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (size == 0)
		{
			return -1;
		}
		return array[front];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (size == 0)
		{
			return -1;
		}
		int index = (rear + capacity - 1) % capacity;
		return array[index];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return size == 0;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return size == capacity;
	}
};

int main()
{
	system("pause");
	return 0;
}