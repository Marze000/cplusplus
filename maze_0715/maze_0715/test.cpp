#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 使用RAII思想设计的SmartPtr类
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	~SmartPtr(){
		if (_ptr) {
			delete _ptr;
		}
	}

	T& operator* () {
		return *_ptr;
	}
	T& operator->() {
		return _ptr;
	}

private:
	T* _ptr;
};

void MergeSort(int* a, int n){
	int* tmp = (int*)malloc(sizeof(int)*n);
	// 讲tmp指针委托给了sp对象，
	//用时老师的话说给tmp指针找了一个可怕的女朋友！天天管着你，直到你go

	SmartPtr<int> sp (tmp);
	*sp = 100;
	cout << *sp << endl;

	// _MergeSort(a, 0, n - 1, tmp);
	// 这里假设处理了一些其他逻辑
	vector<int> v(1000000000, 10);
	// ...
}

int main() {

	try{
		int a[5] = { 4, 5, 2, 3, 1 };
		MergeSort(a, 5);
	}

	catch (const exception& e){
		cout << e.what() << endl;
	}

	return 0;
}