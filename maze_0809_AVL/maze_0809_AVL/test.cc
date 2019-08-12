#include <iostream>
#include <stdlib.h>
using namespace std;


template<class T>
struct AVLTreeNode{
	AVLTreeNode(const T& data = T())
		: _pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
		, _data(data)
		, _bf(0)//平衡因子
	{}

	AVLTreeNode<T>* _pLeft; // 该节点的左孩子
	AVLTreeNode<T>* _pRight; // 该节点的右孩子
	AVLTreeNode<T>* _pParent; // 该节点的双亲
	T _data;
	int _bf; // 该节点的平衡因子
};

template<class T>
class AVLTree{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree() : _pRoot(nullptr)
	{}
	bool Insert(const T& _pRoot) {
		if (nullptr == _pRoot) {
			_pRoot = new Node(data);
			return true;
		}
		//非空
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur) {
			pParent = pCur;
			if (data < pCur->_data){
				pCur = pCur->_pLeft;
			}
			else if (data > pCur->_data) {
				pCur = pCur->_pRight;
			}
			else {
				return false;
			}
		}
		//插入新节点
		pCur = new Node(data);
		if (data < pParent->_data) {
			pParent->_pLeft = pCur;
		}else {
			pParent->_pRight = pCur;
		}

		//检测平衡因子
		if (pCur == pParent->_pLeft) {
			pParent->_bf--;
		}else {
			pParent->_bf++;
		}

		//可能导致 parent 节点的平衡因子不满足 AVL树的性质
		while (pParent) {
			if (pParent->_bf == 0) {
				return true;
			}
			else if (-1 == pParent->_bf || 1 == pParent->_bf) {
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else {
				//双亲的平衡因子不满足 AVL 树的性质
				//双亲的节点的平衡因子为 2 或者 -2
				//需要对 以双亲为根的二叉树进行旋转处理
				if (pParent->_bf == 2) {
					//右子树高
					if (1 == pCur->_bf) {
						_RotateL(pParent);
					}
					else {
						//双旋
						_RotateRL(pParent);
					}
				}
				else {
					//左子树高
					if (-1 == pCur->_bf) {
						_RotateR(pParent);
					}
					else {
						//双旋
						_RotateLR(pParent);
					}
				}
			}
			break;
		}
		return true;
	}

	////////////////////////////////////////////
	//检测平衡树
	////////////////////////////////////////////
	//计算深度
	int _Height(Node* pRoot){
		if (root == NULL){
			return 0;
		}
		if (root->left == NULL && root->right == NULL){
			return 1;
		}
		int left = GetHeight(root->left);
		int right = GetHeight(root->right);
		if (left > right){
			return left + 1;
		}else{
			return right + 1;
		}
	}

	//判断是否平衡
	bool _IsBalanceTree(Node* pRoot){
		// 空树也是AVL树
		if (nullptr == pRoot) {
			return true;
		}
		// 计算pRoot节点的平衡因子：即pRoot左右子树的高度差
		int leftHeight = _Height(pRoot->_pLeft);
		int rightHeight = _Height(pRoot->_pRight);
		int diff = rightHeight - leftHeight;
		// 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
		// pRoot平衡因子的绝对值超过1，则一定不是AVL树
		if (diff != pRoot->_bf || (diff > 1 || diff < -1))
			return false;
		// pRoot的左和右如果都是AVL树，则该树一定是AVL树
		return _IsBalanceTree(pRoot->_pLeft) 
			&& _IsBalanceTree(pRoot->_pRight);
	}
	//////////////////////////////////////////////////////

	void InOrder() {
		_InOrder(_pRoot);
	}

protected:

	void _InOrder(Node* pRoot) {
		if (pRoot) {
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}

	//当根节点的平衡因子小于 -1 的时候，说明左边失衡，需要
	//右单旋
	void _RotateRight1(Node* pParent){
		// pSubL: pParent的左孩子
		// pSubLR: pParent左孩子的右孩子，注意：该
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		// 旋转完成之后，30的右孩子作为双亲的左孩子
		pParent->_pLeft = pSubLR;
		// 如果30的左子树的右孩子存在，更新亲双亲
		if (pSubLR) {
			pSubLR->_pParent = pParent;
		}
		// 60 作为 30的右孩子
		pSubL->_pRight = pParent;
		// 因为60可能是棵子树，因此在更新其双亲前必须先保存60的双亲
		Node* pPParent = pParent->_pParent;
		// 更新60的双亲
		pParent->_pParent = pSubL;
		// 更新30的双亲
		pSubL->_pParent = pPParent;
		// 如果60是根节点，根新指向根节点的指针
		if (NULL == pPParent){
			_pRoot = pSubL;
			pSubL->_pParent = NULL;
		}
		else{
			// 如果60是子树，可能是其双亲的左子树，也可能是右子树
			if (pPParent->_pLeft == pParent) {
				pPParent->_pLeft = pSubL;
			}
			else {
				pPParent->_pRight = pSubL;
			}
		}
		// 根据调整后的结构更新部分节点的平衡因子
		pParent->_bf = pSubL->_bf = 0;
	}

	void _RotateR(Node* pParent) {
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		
		//更新孩子指针域
		pParent->_pLeft = pSubL;
		if (pSubLR) {
			pSubLR->_pParent = pParent;
		}

		pSubL->_pRight = pParent;
		//更新双亲指针域
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;
		if (nullptr == pPParent) {
			_pRoot = pSubL;
		}
		//使父节点 pParent指向 pSubL
		else {
			if (pParent == pPParent->_pLeft) {
				pPParent->_pLeft = pSubL;
			}
			else {
				pPParent->_pRight = pSubL;
			}
		}
	}

	//左单旋
	void _RotateL(Node* pParent) {
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		
		pParent->_pRight = pSubRL;
		if (pSubRL) {
			pSubRL->_pParent = pParent;
		}

		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pSubR->_pParent = pPParent;
		pParent->_pParent = pSubR;

		if (pPParent == nullptr){
			_pRoot = pParent;
		}
		else {
			if (pParent = pPParent->_pLeft) {
				pPParent->_pLeft = pSubR;
			}
			else {
				pPParent->_pRight = pSubR;
			}
		}
		pParent->_bf = pSubR->_bf = 0;
	}

	void _RotateRL(Node* pParent) {
		_RotateR(pParent->_pRight);
		_RotateL(pParent);
	}

	void _RotateLR(Node* pParent) {
		_RotateL(pParent->_pLeft);
		_RotateR(pParent);
	}
private:
	Node* _pRoot;
};

void TestAVLTree() {
	int array[] = { 16,3,6,45,32,5,76,23,54,67,98 };
	AVLTree<int> t;
	for (auto e : array) {
		t.Insert(e);
	}
	t.InOrder();
}

int main() {

	TestAVLTree();
	system("pause");
	return 0;
}
