#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

template<class T>
class UniquPtr {
public:
	UniquPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~UniquPtr() {
		if (_ptr) {
			delete _ptr;
		}
	}

	//实现指针的解引用
	T& operator*() {
		return *_ptr;
	}
	T* operator->() {
		return _ptr;
	}

private:
	//拷贝构造
	UniquPtr(UniquPtr<T> const&);
	//赋值操作符重载
	UniquPtr& operator=(UniquPtr<T> const&);

	//c++11 里面的做法是后面加 delete
	//UniquPtr(UniquPtr<T> const&) = delete;
	//UniquPtr& operator=(UniquPtr<T> const&) = delete;
private:
	T* _ptr;
};


template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~SmartPtr() {
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
	T* _ptr;
};

class Date{
public:
	Date(int year = 2018, int month = 7,int days = 17)
		:_year(year)
		,_month(month)
		,_days(days)
	{}

	int _year;
	int _month;
	int _days;
};


class Date {
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


#include <mutex>
#include <thread>

template<class T>
class SharedPtr {
public:
	SharedPtr(T* ptr = nullptr)
		:_ptr(ptr)
		,_pRefCount(new int(1))
		,_pMutex(new mutex)
	{}

	T& operator*() {
		return *_ptr;
	}
	T* operator->() {
		return _ptr;
	}

	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		,_pRefCount(sp._pRefCount)
		,_pMutex(sp._pMutex)
	{
		//计数器加1
		AddRefCount();
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& ssp) {
		if (this != &ssp) {
			//释放原来的资源
			Release();

			_ptr = ssp._ptr;
			_pMutex = ssp._pMutex;
			_pRefCount = ssp._pRefCount;

			// 计数器加1
			AddRefCount();
		}
		return *this;
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

	~SharedPtr() {
		Release();
	}

private:
	void Release() {
		bool deleteflag = false;

		// 引用计数减1，如果减到0，则释放资源
		_pMutex->lock();
		if (--(*_pRefCount) == 0){
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		_pMutex->unlock();

		if (deleteflag == true) {
			delete _pMutex;
		}
	}
private:
	int* _pRefCount; // 引用计数
	T* _ptr; // 指向管理资源的指针
	mutex* _pMutex; // 互斥锁
};


class Date {
public:
	Date(int year = 2018, int month = 7, int days = 17)
		:_year(year)
		, _month(month)
		, _days(days)
	{}

	int _year;
	int _month;
	int _days;
};
