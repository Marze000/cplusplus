#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

#if 0
namespace bite{
	template<class K, class V>
	class map{
		typedef pair<K, V> ValueType;
		// 作用：将value中的key提取出来
		struct KeyOfValue{
			const K& operator()(const ValueType& v){
				return v.first;
			}
		};
		typedef RBTree<K, ValueType, KeyOfValue> RBTree;
	public:
		typedef typename RBTree::Iterator iterator;
	public:
		map() {}
		/////////////////////////////////////////////
		// Iterator
		iterator begin() { return _t.Begin(); }
		iterator end() { return _t.End(); }
		/////////////////////////////////////////////////
		// Capacity
		size_t size()const { return _t.Size(); }
		bool empty()const { return _t.Empty(); }
		/////////////////////////////////////////////////
		// Acess
		V& operator[](const K& key){
			return (*(_t.Insert(ValueType(key, V()))).first).second;
		}
		const V& operator[](const K& key)const;
		////////////////////////////////////////////////////
		// modify
		pair<iterator, bool> insert(const ValueType& data) {
			return _t.Insert(data);
		}
		void clear() {
			_t.Clear(); 
		}
		iterator find(const K& key) {
			return _t.Find(key);
		}
	private:
		RBTree _t;
	};
}

// 模拟实现 set
namespace bit{
	template<class K>
	class set{
		typedef K ValueType;
		// 作用是：将value中的key提取出来
		struct KeyOfValue{
			const K& operator()(const ValueType& key){
				return key;
			}
		};
		// 红黑树类型重命名
		typedef RBTree<K, ValueType, KeyOfValue> RBTree;
	public:
		typedef typename RBTree::Iterator iterator;
	public:
		Set() {}
		/////////////////////////////////////////////
		// Iterator
		iterator Begin();
		iterator End();
		/////////////////////////////////////////////////
		// Capacity
		size_t size()const;
		bool empty()const;
		////////////////////////////////////////////////////
		// modify
		pair<iterator, bool> insert(const ValueType& data){
			return _t.Insert(data);
		}
		void clear();
		iterator find(const K& key);
	private:
		RBTree _t;
	};
}

class A{
public:
	int _a;
};
// class B : public A
class B : virtual public A{
public:
	int _b;
};
// class C : public A
class C : virtual public A{
public:
	int _c;
};
class D : public B, public C{
public:
	int _d;
};

int main(){
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	system("pause");
	return 0;
}

class Car{
public:
	virtual void Drive() final {}
};
class Benz :public Car{
public:
	virtual void Drive() {
		cout << "Benz-舒适" << endl;
	}
};


#endif
