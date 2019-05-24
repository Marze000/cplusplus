#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;
	 如果是负数，则转成正数，并标记一下
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}
	 按进制换算成对应的字符添加到s
	while (m)
	{
		s += table[m%n];
		m /= n;
	}
	if (flag)
		s += '-';
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}


#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};

void Test1()
{
	 申请单个Test类型的空间
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);
	 申请10个Test类型的空间
	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
	free(p2);
}

void Test2()
{
	 申请单个Test类型的对象
	Test* p1 = new Test;
	delete p1;
	 申请10个Test类型的对象
	Test* p2 = new Test[10];
	delete[] p2;
}

5. new和delete的实现原理
5.1 内置类型
如果申请的是内置类型的空间，new和malloc，delete和free基本类似，不同的地方是：new / delete申请和
释放的是单个元素的空间，new[]和delete[]申请的是连续空间，而且new在申请空间失败时会抛异常，
malloc会返回NULL。
5.2 自定义类型
new的原理
1. 调用operator new函数申请空间
2. 在申请的空间上执行构造函数，完成对象的构造
delete的原理
1. 在空间上执行析构函数，完成对象中资源的清理工作
class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};
int main()
{
	List l;
	return 0;
}
class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
void Test()
{
	 pt现在指向的只不过是与Test对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt) Test; // 注意：如果Test类的构造函数有参数时，此处需要传参
}

template<typename T,class T2 >
void Swap(T& left, T2& right)
{
	T2 temp = left;
	left = right;
	right = temp;
}

int main()
{
	int a[5] = { 1,3,5,7,9 };
	
	int *p = (int *)(&a + 1);

	printf("%d, %d", *(a + 1),*(p - 1));

	
	int a = 10;
	int b = 20;
	double c = 30.1;

	Swap(a, c);
	cout << a << " " << b << endl;

	int a = 10;
	int b = 20;
	Swap(1,2.0);
	cout << a << " " << b << endl;

	Test1();
	Test2();

	int* p1 = (int*)malloc(sizeof(int) * 10);
	free(p1);

	char* p2 = new char;
	delete p2;


	int* p1 = new int;
	int* p2 = new int(10);
	int* p3 = new int[3];
	int* p4 = new int;
	cout << "p1:" << p1 << endl;
	cout << "p2:" << p2 << endl;
	cout << "p3:" << p3 << endl;
	cout << "p4:" << p4 << endl;
	cout << endl;
	delete p1;
	delete p2;
	delete[] p3;
	delete p4;

	system("pause");
	return 0;
}
template <class M>
void Swap(M& a, M& b)
{
	int temp = a;
	a = b;
	b = temp;
}


template<class T>
class / typename 没啥区别  
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}


int main()
{
	Add(10, 20);


	int a = 10;
	int b = 20;
	Swap(a,b);

	system("pause");
	return 0;
}

#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

typedef int T;
template<class T>

class SeqList
{
public:
	SeqList(size_t capacity = 10)
		:_array (new T [capacity])
		,_capacity(capacity)
		,_size(0)
	{}

	void PushBack(const T& data);
	void PopBack()
	{
		--_size;
	}

	size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	bool Empty()const
	{
		return _size == 0;
	}

	[] :下标运算符重载
	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
protected:
	T* _array;
	size_t _capacity;
	size_t _size;
};

template<class T>
SeqList 不是一个类，是一个模板 SeqList<int>才是类
void SeqList<T>::PushBack(const T& data)
{
	CheckCapacity
	_array[_size++] = data;
}

int main()
{
	汇编名字为 SeqList<int>::SeqList<int>
	SeqList<int> s1;	
	s1.PushBack(1); 
	s1.PushBack(2); 
	s1.PushBack(3);
	cout << s1[0] << endl;

	汇编名字为 SeqList<int>::SeqList<int>
	SeqList<double> s2;

	system("pause");
	return 0;
}