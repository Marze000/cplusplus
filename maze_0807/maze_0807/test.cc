#include <iostream>
#include <stdlib.h>
using namespace std;

#if 0
void Test()
{
	int i = 1;
	// 隐式类型转换
	double d = i;
	printf("%d, %.2f\n", i, d);

	int* p = &i;
	// 显示的强制类型转换
	int address = (int)p;
	printf("%x, %d\n", p, address);
}

int main() {
	Test();

	system("pause");
	return 0;
}
int main()
{
	double d = 12.34;
	int a = static_cast<int>(d);
	cout << a << endl;

	system("pause");
	return 0;
}

typedef void(*FUNC)();
int DoSomething(int i){
	cout << "DoSomething" << endl;
	return 0;
}

void Test(){
	// reinterpret_cast可以编译 以FUNC的定义方式去看待DoSomething函数
	// 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用
	// C++不保证所有的函数指针都被一样的使用，
	// 所以这样用有时会产生不确定的结果
	FUNC f = reinterpret_cast<FUNC>(DoSomething);
	f();
}

int main() {
	Test();
	
}

void Test(){
	const int a = 2;
	int* p = const_cast<int*>(&a);
	*p = 3;
	cout << a << endl;
	cout << *p << endl;
}

int main() {
	Test();

	system("pause");
	return	0;
}

class A{
public:
	virtual void f() {}
};

class B : public A
{};

void fun(A* pa){
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}

int main(){
	A a;
	B b;
	fun(&a);
	fun(&b);
	return 0;
}

class A{
public:
	explicit A(int a){
		cout << "A(int a)" << endl;
	}
	A(const A& a){
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};

int main(){
	A a1(1);
	// 隐式转换-> A tmp(1); A a2(tmp);
	//A a2 = 1;
	return 0;
}
#include <set>
void TestSet(){
	int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7 };
	// 注意：multiset在底层实际存储的是<int, int>的键值对
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : s) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
	TestSet();

	system("pause");
	return 0;
}

//统计前 k 个高频单词
#include <vector>
#include <map>
#include <set>
class Solution {
public:
	class Compare{
	public:
		// 在set中进行排序时的比较规则
		bool operator()(const pair<string, int>& left,
			const pair<string, int>& right){
			return left.second > right.second;
		}
	};
	vector<string> topKFrequent(vector<string>& words, int k){
		// 用<单词，单词出现次数>构建键值对，
		//然后将vector中的单词放进去，统计每个单词出现的次数
		map<string, int> m;
		for (size_t i = 0; i < words.size(); ++i) {
			++(m[words[i]]);
		}
		// 将单词按照其出现次数进行排序，出现相同次数的单词集中在一块
		multiset<pair<string, int>, Compare> ms(m.begin(), m.end());
		// 将相同次数的单词放在set中，然后再放到vector中
		set<string> s;
		size_t count = 0; // 统计相同次数单词的个数
		size_t leftCount = k;
		vector<string> ret;
		for (auto& e : ms){
			if (!s.empty()){
				// 相同次数的单词已经全部放到set中
				if (count != e.second){
					if (s.size() < leftCount){
						ret.insert(ret.end(), s.begin(), s.end());
						leftCount -= s.size();
						s.clear();
					}else{
						break;
					}
				}
			}
			count = e.second;
			s.insert(e.first);
		}
		for (auto& e : s){
			if (0 == leftCount) {
				break;
			}
			ret.push_back(e);
			leftCount--;
		}
		return ret;
	}
};
#endif

///////////////////////////////////////////
//// 二叉搜索树
///////////////////////////////////////////

template<class T>
struct BSTNode{
	BSTNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _data(data)
	{}

	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};

template<class T>
class BSTree{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree() : _pRoot(nullptr)
	{}

	//销毁
	void _Destroy(Node*& pRoot) {
		if (pRoot) {
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}

	// 根据二叉搜索树的性质查找：找到值为data的节点在二叉搜索树中的位置
	PNode Find(const T& data) {
		Node* pCur = _pRoot;
		while (pCur) {
			if (data == pCur->_data) {
				return pCur;
			}
			else if (data > _pRoot->_data) {
				_pRoot = _pRoot->_pRight;
			}
			else {
				_pRoot = _pRoot->_pLeft;
			}
		}
		return false;
	}

	bool Insert(const T& data){
		// 如果树为空，直接插入
		if (nullptr == _pRoot){
			_pRoot = new Node(data);
			return true;
		}
		// 按照二叉搜索树的性质查找data在树中的插入位置
		PNode pCur = _pRoot;
		// 记录pCur的双亲，因为新元素最终插入在pCur双亲左右孩子的位置
		PNode pParent = nullptr;
		while (pCur){
			pParent = pCur;
			if (data < pCur->_data) {
				pCur = pCur->_pLeft;
			}
			else if (data > pCur->_data) {
				pCur = pCur->_pRight;
			}
			else {
				// 元素已经在树中存在
				return false;
			}
		}
		// 插入元素
		pCur = new Node(data);
		if (data < pParent->_data) {
			pParent->_pLeft = pCur;
		}else {
			pParent->_pRight = pCur;
		}
		return true;
	}

	//删除树中的某一个节点
	bool Erase(const T& data){
		// 如果树为空，删除失败
		if (nullptr == _pRoot) {
			return false;
		}
		// 查找在data在树中的位置
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur){
			if (data == pCur->_data) {
				break;
			}
			else if (data < pCur->_data){
				pParent = pCur;
				pCur = pCur->_pLeft;
			}else{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		// data不在二叉搜索树中，无法删除
		if (nullptr == pCur) {
			return false;
		}

		if (nullptr == pCur->_pRight) {
			// 当前节点只有左孩子或者左孩子为空---可直接删除
			if (pParent == nullptr) {
				_pRoot = pCur->_pLeft;
			}
			else {
				if (pCur == pParent->_pLeft) {
					pParent->_pLeft = pCur->_pLeft;
				}
				else {
					pParent->_pRight = pCur->_pLeft;
				}
			}
			delete pCur;
		}
		else if (pCur->_pLeft == nullptr){
			// 当前节点只有右孩子---可直接删除
			if (pParent == nullptr) {
				_pRoot = pCur->_pRight;
			}
			else {
				if (pCur == pParent->_pLeft){
					pParent->_pLeft = pCur->_pRight;
				}
				else {
					pParent->_pRight = pCur->_pRight;
				}
			}
			delete pCur;
		}
		else{
			// 当前节点左右孩子都存在，直接删除不好删除，
			// 可以在其子树中找一个替代结点，比如：
			// 找其左子树中的最大节点，即左子树中最右侧的节点，
			// 或者在其右子树中最小的节点，即右子树中最小的节点
			// 替代节点找到后，将替代节点中的值交给待删除节点，
			// 转换成删除替代节点
			Node* pMostLeft = pCur->_pRight;
			pParent = pMostLeft;
			while (pMostLeft->_pLeft) {
				pParent = pMostLeft;
				pMostLeft = pMostLeft->_pLeft;
			}

			pCur->_data = pMostLeft->_data;
			//删除替代节点

			if (pMostLeft == pParent->_pLeft) {
				pParent->_pLeft = pMostLeft->_pRight;
			}
			else {
				pParent->_pRight = pMostLeft->_pRight;
			}
			delete pMostLeft;
		}
		return true;
	}

	int LeftMost() {
		if (_pRoot == nullptr) {
			return 0;
		}

		Node* pCur = _pRoot;
		while (pCur->_pLeft) {
			pCur = pCur->_pLeft;
		}
		int cur = pCur->_data;
		return cur;
	}

	int RightMost() {
		if (_pRoot == nullptr) {
			return 0;
		}

		Node* pCur = _pRoot;
		while (pCur->_pRight) {
			pCur = pCur->_pRight;
		}
		int cur = pCur->_data;
		return cur;
	}

	//封装简单
	void InOrder() {
		_InOrder(_pRoot);
	}

private:
	void _InOrder(Node* pRoot) {
		if (pRoot) {
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}
private:
	PNode _pRoot;
};
 
void TestBsTree() {
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	BSTree<int>t;
	for (auto e : a) {
		t.Insert(e);
	}
	cout << t.LeftMost() << endl;
	cout << t.RightMost() << endl;
	t.InOrder();
	cout << endl;

	//删除的测试
	t.Erase(8);
	t.InOrder();
}

int main() {
	TestBsTree();

	system("pause");
	return 0;
}
