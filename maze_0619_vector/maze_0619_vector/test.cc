#include <stdlib.h>
#include <algorithm>
#include <assert.h>
#include <iostream>
using namespace std;

template<class T>

class Vector {
public:
	typedef T* Iterator;
	typedef const T* conIterator;
	Vector()
		:start_(nullptr)
		, end_(nullptr)
		, finish_(nullptr) {}

	Vector(int n, const T& value)
		:start_(nullptr)
		, end_(nullptr)
		, finish_(nullptr)
	{
		Reserve(n);
		while (n--) {
			PushBack(value);
		}
	}

	//由于非const对象可以调用const 函数
	//const 实例对象可以调用const函数，所以使用const成员函数
	size_t Size() const {
		return finish_ - start_;
	}
	size_t Capacity()const {
		return end_ - start_;
	}

	//这两个接口得分为两种函数类型
	//const 类型只能由const对象去调用
	Iterator Being() {
		return start_;
	}
	conIterator C_Being() const {
		return start_;
	}

	Iterator End() {
		return end_;
	}
	conIterator C_End() const {
		return start_;
	}
	

	//赋值运算符重载
	Vector<T>& operator =(Vector<T> v) {
		Swap(v); 
		return *this;
	}

	// reserve()函数的模拟实现
	void Reserve(int n) {
		if (n > Capacity()) {
			//1.申请空间
			size_t size = Size();
			T* temp = new T[n];
			//2.往新空间搬移元素
			if (start_) {
				for (size_t i = 0; i < size; ++i) {
					temp[i] = start_[i];
				}
			}

			//3.绑定新空间属性
			start_ = temp;
			end_ = start_ + n;
			finish_ = start_ + size;
		}
	}

	//函数Resize()的模拟实现
	void Resize(size_t n,const &T value = T()) {
		if (n > Capacity()) {
			Reserve(n);
		}
		if (n <= Size()) {
			finish_ = start_ + n;
			return;
		}

		//利用迭代器将多余的空间置为 value
		//将 size 扩大到 n
		Iterator it = finish_;
		Iterator end = start_ + n;
		while (it != end){
			*it = value;
			++it;
		}
	}

	//Swap 函数的模拟实现
	void Swap(Vector<T>& v) {
		swap(start_, v.start_);
		swap(end_, v.end_);
		swap(finish_, v.finish_);
	}

	//尾插和尾删函数没有返回值，也不需要返回
	void PushBack(){
		Insert(End(), x);
	}
	void PopBack() {
		Erase(--End());
	}

	//对插入进行模拟实现
	Iterator Insert(Iterator pos, const T& s) {
		assert(pos > end_);
		if (finish_ == end_) {
			size_t size = Size();
			size_t newCapacity; 
			newCapacity = (Capacity() == 0) ? 1 : Capacity() * 2;
			Reserve(newCapacity);
			// 如果发生了增容，需要重置pos
			pos = start_ + size;
		}

		Iterator end = finish_ - 1;
		while (end >= pos){
			*(end + 1) = *end;
			--end;
		}
		*pos = x;
		++finish_;
		return pos;
	}

	Iterator Erase(Iterator pos){
		// 挪动数据进行删除
		Iterator begin = pos + 1;
		while (begin != finish_) {
			*(begin - 1) = *begin;
			++begin;
		}
		--finish_;
		return pos;
	}

	T& operator[](size_t pos){
		return start_[pos];
	}

private:
	Iterator start_;
	Iterator end_;
	Iterator finish_;
};

