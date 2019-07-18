#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

#if 0
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

// new 资源的释放
template<class T>
struct DFDel {
	void operator()(const T& ptr) {
		if (ptr) {
			delete ptr;
			ptr = nullptr;
		}
	}
};

// malloc 资源的释放
template<class T>
struct Free {
	void operator()(T& ptr) {
		if (ptr) {
			free(ptr);
			ptr = nullptr;
		}
	}
};

struct Fclose {
	void operator()(FILE* pf) {
		if (pf) {
			fclose(pf);
			pf = nullptr;
		}
	}
};

namespace bite {
	template<class T>
	class shared_ptr {
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			,_pCount(nullptr)
		{
			if (_ptr) {
				_pCount = new int(1);
			}
		}
		
		~shared_ptr() {
			if (_ptr && --*_pCount == 0) {
				delete _ptr;
				delete _pCount;
			}
		}

		T& operator*() {
			return *_ptr;
		}
		T* operator->() {
			return _ptr;
		}

		//解决浅拷贝的问题
		
	private:
		T* _ptr;
		int* _pCount;
	};
	// shared_ptr 的缺陷
	// 1. 不能管理任意类型的指针，比如文件指针，析构函数中资源释放
	// 2. 线程不安全
	// 3. 循环引用

}
#endif

#include <memory>

// 循环引用
struct ListNode {
public:
	ListNode(int data)
		:_data(data)
		, _pPre(nullptr)
		, _pNext(nullptr)
	{
		cout << "ListNode(int)" << this << endl;
	}

	~ListNode() {
		cout << "~ListNode(int)" << this << endl;
	}
private:
	int _data;
	shared_ptr<ListNode> _pPre;
	shared_ptr<ListNode> _pNext;

	//ListNode* _pPre;
	//ListNode* _pNext;
};

void TestSharedPtr(){
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;>_pNext = sp2;
}
