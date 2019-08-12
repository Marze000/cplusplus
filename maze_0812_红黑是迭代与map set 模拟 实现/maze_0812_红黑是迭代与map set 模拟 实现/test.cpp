#include <iostream>
using namespace std;

enum Color { RED, BLACK };
// 红黑树节点的定义
template<class ValueType>
struct RBTreeNode{
	RBTreeNode(const ValueType& data = ValueType()，Color color = RED)
		: _pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
		, _data(data), _color(color)
	{}
	RBTreeNode<ValueType>* _pLeft; // 节点的左孩子
	RBTreeNode<ValueType>* _pRight; // 节点的右孩子
	RBTreeNode<ValueType>* _pParent; // 节点的双亲(红黑树需要旋转，
									 //为了实现简单给出该字段)
	ValueType _data; // 节点的值域
	Color _color; // 节点的颜色
};

template<class ValueType>
class RBTree{
	// 找迭代器的下一个节点，下一个节点肯定比其大
	void Increasement(){
		//分两种情况讨论:_pNode的右子树存在和不存在
		// 右子树存在
		if (_pNode->_pRight){
			// 右子树中最小的节点，即右子树中最左侧节点
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft) {
				_pNode = _pNode->_pLeft;
			}
		}
		else{
			// 右子树不存在，向上查找，直到_pNode != pParent->right
			PNode pParent = _pNode->_pParent;
			while (pParent->_pRight == _pNode){
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			// 特殊情况：根节点没有右子树
			if (_pNode->_pRight != pParent) {
				_pNode = pParent;
			}
		}
	}
	// 获取迭代器指向节点的前一个节点
	void Decreasement(){
		//分三种情况讨论：_pNode 在head的位置，_pNode 左子树存在，_pNode 左子树不存在
		// 1. _pNode 在head的位置，--应该将_pNode放在红黑树中最大节点的位置
		if (_pNode->_pParent->_pParent == _pNode 
				&& _pNode->_color == RED){

			_pNode = _pNode->_pRight;
		}
		else if (_pNode->_pLeft) {
			// 2. _pNode的左子树存在,在左子树中找最大的节点，
			//    即左子树中最右侧节点
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight) {
				_pNode = _pNode->_pRight;
			}
		}
	}
	else{
		// _pNode的左子树不存在，只能向上找
		PNode pParent = _pNode->_pParent;
		while (_pNode == pParent->_pLeft){
			_pNode = pParent;
			pParent = _pNode->_pParent;
		}
		_pNode = pParent;
	}

//……

private:
	PNode& GetRoot() { 
		return _pHead->_pParent;
	}
	// 获取红黑树中最小节点，即最左侧节点
	PNode LeftMost();
	// 获取红黑树中最大节点，即最右侧节点
	PNode RightMost();
private:
	PNode _pHead;
};
#if 0
// 因为关联式容器中存储的是<key, value>的键值对，因此
// k为key的类型，
// ValueType: 如果是map，则为pair<K, V>; 如果是set，则为k
// KeyOfValue: 通过value来获取key的一个仿函数类
template<class K, class ValueType, class KeyOfValue>
class RBTree
{
	typedef RBTreeNode<ValueType> Node;
	typedef Node* PNode;
public:
	typedef RBTreeIterator<ValueType, ValueType*, ValueType&> Iterator;
	
	RBTree();
	~RBTree();
		///////////////////////////////////////////////
		// Iterator
	Iterator Begin() {
		return Iterator(_pHead->_pLeft); 
	}
	Iterator End() { return Iterator(_pHead); }
	//////////////////////////////////////////////////////////////////
	// Modify
	pair<Iterator, bool> Insert(const ValueType& data)
	{
		// 插入节点并进行调整
		// 参考上文...
		return make_pair(Iterator(pNewNode), true);
	}
	// 将红黑树中的节点清空
	void Clear();
	Iterator Find(const K& key);

	/////////////////////
	// capacity
	/////////////////////
	size_t Size()const;
	bool Empty()const;
	// ……
private:
	PNode _pHead;
	size_t _size; // 红黑树中有效节点的个数

};

#endif
// map 的模拟实现
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
