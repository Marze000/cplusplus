#include <iostream>
#include <stdlib.h>

//T为类类型模板参数，n为非类型参数
template<class T,size_t n = 10>

class Array {
public:
	T& operator[](size_t index) {
		return _array[index];
	}
	
	const T& operator[](size_t index)const {
		return _array[index];
	}

	bool Empty()const {
		return _size == 0;
	}
	size_t Size()const {
		return _size;
	}

private:
	size_t _size;
	T _array[n];
};

template<class T>
bool IsEqual(T& left, T& right){
	return left == right;
}

void Test(){
	const char* p1 = "hello";
	const char* p2 = "world";
	if (IsEqual(p1, p2)){
		std::cout << p1 << std::endl;
	}
	else {
		std::cout << p2 << std::endl;
	}
}

int main(){
	Test();

	return 0;
}