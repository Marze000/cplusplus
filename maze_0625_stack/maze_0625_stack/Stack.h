#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
template<class T>
class Stack {
public:
	Stack() {
		_array = new int;
		_capacity = 10;
		_top = 0;
	}
	void StackPush(int data) {
		_array[_top++] = data;
	}

	void StackPop() {
		--_top;
	}

	T StackTop() {
		static T top = _array[_top];
		return top;
	}

	int StackSize() {
		return _top;
	}

	bool StackEmpty() {
		if (_top == 0) {
			return true;
		}
		return false;
	}
	
	~Stack() {
		_capacity = 0;
		_top = 0;
		if (_array == nullptr) {
			return;
		}
		else {
			_array = nullptr;
			delete _array;
		}
	}
private:
	T* _array;
	T _capacity;
	T _top;
};

//emplate<class T>
//
//class Stack {
//public:
//	Stack() {
//		_array = new int;
//		_capacity = 10;
//		_top = 0;
//	}
//	void StackPush(int data) {
//		_array[_top++] = data;
//	}
//
//	void StackPop() {
//		--_top;
//	}
//
//	int StackTop() {
//		static int top = _array[_top];
//		return top;
//	}
//
//	int StackSize() {
//		return _top;
//	}
//
//	bool StackEmpty() {
//		if (_top == 0) {
//			return true;
//		}
//		return false;
//	}
//	
//	~Stack() {
//		_capacity = 0;
//		_top = 0;
//		if (_array == nullptr) {
//			return;
//		}
//		else {
//			_array = nullptr;
//			delete _array;
//		}
//	}
//private:
//	int* _array;
//	int _capacity;
//	int _top;
//};

//
//class Stack {
//public:
//	Stack() {
//		_array = new int;
//		_capacity = 10;
//		_top = 0;
//	}
//	void StackPush(int data) {
//		_array[_top++] = data;
//	}
//
//	void StackPop() {
//		--_top;
//	}
//
//	T StackTop() {
//		static T top = _array[_top];
//		return top;
//	}
//
//	int StackSize() {
//		return _top;
//	}
//
//	bool StackEmpty() {
//		if (_top == 0) {
//			return true;
//		}
//		return false;
//	}
//	
//	~Stack() {
//		_capacity = 0;
//		_top = 0;
//		if (_array == nullptr) {
//			return;
//		}
//		else {
//			_array = nullptr;
//			delete _array;
//		}
//	}
//private:
//	T* _array;
//	T _capacity;
//	T _top;
//};
//
