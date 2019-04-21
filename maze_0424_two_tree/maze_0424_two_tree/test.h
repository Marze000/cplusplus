#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#define NULL '#'
//1. 熟悉树的概念以及相关概念
//2. 了解树的存储方式以及其区别
//3. 了解树的应用场景
//4. 熟悉二叉树的基本概念以及性质
//5. 熟悉满二叉树和完全二叉数，并掌握其区别
//6. 熟悉二叉树的静态存储与链式存储
//7. 实现链式数据结构的以下基本操作：
typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}	BTNode;



// 1. 创建二叉树 
BTNode* CreateBinTree(BTDataType* array, int size)
{
	if (size == 0 || array[0] == '#')
	{
		return NULL;
	}
	//'A', 'B', '#', 'D', '#', '#', 'C', '#', '#'
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = array[0];

	BTDataType l = CreateBinTree(array + 1, size - 1);



}

// 拷贝二叉树 
BTNode* CopyBinTree(BTNode* pRoot);

// 销毁二叉树 
void DestroyBinTree(BTNode** pRoot)
{
	if (*pRoot == NULL || pRoot == NULL)
	{
		return;
	}
	free(pRoot);
	DestroyBinTree(*(pRoot->_pLeft));

}
// 二叉树的三种遍历方式 
//前序遍历递归
void PreOrder(BTNode* pRoot)
{
	if (pRoot->_data == '#')
	{
		printf("# ");
		return;
	}

	printf("%c ", pRoot->_data);
	PreOrder(pRoot->_pLeft);
	PreOrder(pRoot->_pRight);
}

void PreOrderNor(BTNode* pRoot);


//中序遍历二叉树--递归
void InOrder(BTNode* pRoot)
{
	if (pRoot->_data == '#')
	{
		printf("# ");
		return;
	}

	InOrder(pRoot->_pLeft);
	printf("%c ", pRoot->_data);
 	InOrder(pRoot->_pRight)	;
}
void InOrderNor(BTNode* pRoot);


//后序遍历二叉树
void PostOrder(BTNode* pRoot)
{
	if (pRoot->_data == '#')
	{
		printf("# ");
		return;
	}

	PostOrder(pRoot->_pLeft);
	PostOrder(pRoot->_pRight);
	printf("%c ", pRoot->_data);
}

void PostOrderNor(BTNode* pRoot);
void LevelOrder(BTNode* pRoot);

// 获取二叉树中节点的个数 
int GetNodeCount(BTNode* pRoot);

// 求二叉树的高度 
int Height(BTNode* pRoot);

// 检测二叉树是否平衡O(N^2) 
int IsBalanceTree(BTNode* pRoot);
// 检测二叉树是否平衡O(N) 
int IsBalanceTree_P(BTNode* pRoot, int* height);

// 获取二叉数中叶子节点的个数 
int GetLeafNodeCount(BTNode* pRoot);

// 获取二叉树第K层节点的个数 
int GetKLevelNodeCount(BTNode* pRoot, int K);

// 获取二叉树中某个节点的双亲节点 
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);

// 求二叉树的镜像 
void Mirror(BTNode* pRoot);








//8. 完成二叉树部分的在线OJ题目
//9. 将本节内容写博客(可以分成多个博客写)

