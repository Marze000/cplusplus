#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

#if 1

#include <memory>
//循环引用
class ListNode {
public:
	ListNode(int data)
		:_data(data)
		//, _pPre(nullptr)
		//, _pNext(nullptr)
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode() {
		cout << "~ListNode(int):" << this << endl;
	}

	int _data;

	//weak_ptr 是为了解决shared_ptr 循环引用的问题
	weak_ptr<ListNode> _pPre; 
	weak_ptr<ListNode> _pNext;
	//shared_ptr<ListNode> _pPre; 
	//shared_ptr<ListNode> _pNext;
};

void TestSharefptr() {
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	sp1->_pNext = sp2;
	sp2->_pPre = sp1;

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}

int main() {
	
	TestSharefptr();

	system("pause");
	return 0;
}

int findMaxGap(vector<int> A, int n) {
	// write code here
	int end = n - 1;
	int max = 0;
	while (--n) {
		int start = 0;
		while (start <= end) {
			if (A[start] - abs(A[end]) > max) {
				max = A[start] - abs(A[end]);
			}
			++start;
		}
		--end;
	}
	return max;
}

int main() {
	int b[5] = { 2,7,3,1,1 };
	vector<int>a(b , b + 5);
		
	int res = findMaxGap(a,5);
	cout << res << endl;
	
	system("pause");
	return 0;
}
#endif

#if 1
#include <thread>
#include <mutex>
// C++11的库中也有一个lock_guard，
//下面的LockGuard造轮子其实就是为了学习他的原理

template<class Mutex>
class LockGuard{
public:
	LockGuard(Mutex& mtx)
		:_mutex(mtx)
	{
		_mutex.lock();
	}

	~LockGuard(){
		_mutex.unlock();
	}

	LockGuard(const LockGuard<Mutex>&) = delete;

private:
	// 注意这里必须使用引用，否则锁的就不是一个互斥量对象
	Mutex& _mutex;
};

mutex mtx;
static int n = 0;

void Func(){
	for (size_t i = 0; i < 1000000; ++i){
		LockGuard<mutex> lock(mtx);
		++n;
	}
}

int main(){
	int begin = clock();
	thread t1(Func);
	thread t2(Func);
	t1.join();
	t2.join();
	int end = clock();
	cout << n << endl;
	cout << "cost time:" << end - begin << endl;

	system("pause");
	return 0;
}
#endif

// 模拟实现一份简答的UniquePtr,了解原理

template<class T>
class UniquePtr{
public:
	UniquePtr(T * ptr = nullptr)
		: _ptr(ptr)
	{}
	~UniquePtr(){
		if (_ptr)
			delete _ptr;
	}
	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
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