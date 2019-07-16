#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Date{
public:
	Date() { 
		cout << "Date()" << endl;
	}
	
	~Date() {
		cout << "~Date()" << endl;
	}

	int _year;
	int _month;
	int _day;
};

int main(){
	auto_ptr<Date> ap(new Date);
	auto_ptr<Date> copy(ap);
	// auto_ptr的问题：当对象拷贝或者赋值后，前面的对象就悬空了
	// C++98中设计的auto_ptr问题是非常明显的，
	//所以实际中很多公司明确规定了不能使用auto_ptr

	//ap->_year = 2018;
	return 0;
}

// 使用RAII思想设计的SmartPtr类
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	~SmartPtr() {
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

void MergeSort(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int)*n);
	// 讲tmp指针委托给了sp对象，
	//用时老师的话说给tmp指针找了一个可怕的女朋友！天天管着你，直到你go

	SmartPtr<int> sp(tmp);
	*sp = 100;
	cout << *sp << endl;

	// _MergeSort(a, 0, n - 1, tmp);
	// 这里假设处理了一些其他逻辑
	vector<int> v(1000000000, 10);
	// ...
}

int main() {

	try {
		int a[5] = { 4, 5, 2, 3, 1 };
		MergeSort(a, 5);
	}

	catch (const exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}

template<class T>
class AutoPtr {
public:
	AutoPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~AutoPtr() {
		if (_ptr) {
			delete _ptr;
		}
	}

	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr){
		ap._ptr = nullptr;
	}

	AutoPtr<T>& operator (AutoPtr<T>& ap) {
		if (this != &ap) {
			if (_ptr) {
				delete _ptr;
			}

			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}

	T& operator*() {
		return *_ptr;
	}
	T* operator->() {
		return _ptr;
	}

private:
	T* _ptr;
};

int main() {

	AutoPtr<int>a(new int);
	AutoPtr<int>b(a);

	*a = 10;
	*b = 20;

	return 0;
}

template<class T>
class UniquePtr{
public:
	UniquePtr(T * ptr = nullptr)
		: _ptr(ptr)
	{}

	~UniquePtr(){
		if (_ptr) {
			delete _ptr;
		}
	}
	T& operator*() { 
		return *_ptr;
	}

	T* operator->() { 
		return _ptr;
	}

private:
	// C++98防拷贝的方式：只声明不实现+声明成私有
	UniquePtr(UniquePtr<T> const &);
	UniquePtr & operator=(UniquePtr<T> const &);

	// C++11防拷贝的方式：delete
	UniquePtr(UniquePtr<T> const &) = delete;
	UniquePtr & operator=(UniquePtr<T> const &) = delete;

private:
	T * _ptr;
};


int main() {
	
	return 0;
}



template <class T>
class SharedPtr{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{}

	~SharedPtr() {
		Release();
	}

	//拷贝构造
	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		AddRefCount();
	}

	//赋值操作符重载 sp1 = sp2
	SharedPtr<T>& operator=(const SharedPtr<T>& sp){
		//if (this != &sp)
		if (_ptr != sp._ptr){
			// 释放管理的旧资源
			Release();
			// 共享管理新对象的资源，并增加引用计数
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;
			AddRefCount();
		}
		return *this;
	}

	T& operator*() { 
		return *_ptr;
	}

	T* operator->() { 
		return _ptr;
	}
	
	int UseCount() {
		return *_pRefCount;
	}

	T* Get() {
		return _ptr;
	}

	void AddRefCount(){
		// 加锁或者使用加1的原子操作
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}

private:
	void Release(){
		// 引用计数减1，如果减到0，则释放资源
		bool deleteflag = false;

		_pMutex.lock();
		if (--(*_pRefCount) == 0){
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		_pMutex.unlock();

		if (deleteflag == true) {
			delete _pMutex;
		}
	}

private:
	int* _pRefCount; // 引用计数
	T* _ptr; // 指向管理资源的指针
	mutex* _pMutex; // 互斥锁
};

int main(){
	SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(sp1);
	*sp2 = 20;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	SharedPtr<int> sp3(new int(10));
	sp2 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	sp1 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;

	return 0;
}
