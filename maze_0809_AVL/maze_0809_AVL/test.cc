#include <iostream>
#include <stdlib.h>

template<class T>
struct AVLTreeNode{
	AVLTreeNode(const T& data)
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
class BSTree{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree() : _pRoot(nullptr)
	{}
	~BSTree();
	
	//当根节点的平衡因子小于 -1 的时候，说明左边失衡，需要
	//右单旋
	void _RotateR(PNode pParent){
		// pSubL: pParent的左孩子
		// pSubLR: pParent左孩子的右孩子，注意：该
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;
		// 旋转完成之后，30的右孩子作为双亲的左孩子
		pParent->_pLeft = pSubLR;
		// 如果30的左子树的右孩子存在，更新亲双亲
		if (pSubLR) {
			pSubLR->_pParent = pParent;
		}
		// 60 作为 30的右孩子
		pSubL->_pRight = pParent;
		// 因为60可能是棵子树，因此在更新其双亲前必须先保存60的双亲
		PNode pPParent = pParent->_pParent;
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


private:
	PNode _pRoot;
};
