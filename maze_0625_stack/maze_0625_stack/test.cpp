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

template<class T>
int main(){

	Stack<int> s;
	s.StackPush(1);
	s.StackPush(2);
	s.StackPush(3);
	s.StackPush(4);
	s.StackPush(5);
	s.StackPush(6);
	s.StackPop();
	s.StackSize();
	s.StackTop();
	s.StackEmpty();

	system("pause");
	return 0;
}