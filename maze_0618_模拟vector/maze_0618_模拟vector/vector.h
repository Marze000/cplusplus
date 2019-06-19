#pragma once
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
		,end_(nullptr)
		,finsh_(nullptr){}
	
	Vector(int n, const T&value = T())
		:start_(nullptr)
		,end_(nullptr)
		,finsh_(nullptr)
	{
		reserve(n);
		while (n--) {
			this->push_back(value);
		}
	}

	size_t Size() const{
		return finsh_ - start_;
	}
	size_t Capacity()const {
		return end_ - start_;
	}
	
	Iterator Being() {
		return start_;
	}
	conIterator Cbeing() const{
		return start_;
	}

	Iterator End() {
		return end_;
	}
	conIterator Cend() const {
		return start_;
	}


private:
	Iterator start_;
	Iterator end_;
	Iterator finsh_;
};