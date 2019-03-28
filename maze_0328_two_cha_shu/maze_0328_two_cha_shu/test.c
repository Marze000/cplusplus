#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
	int value;
	struct Node* left;
	struct Node* right;
}	Node;

void PreorderTraversal(Node* root)
{
	//root == NULL;空树
	if (root == NULL)
	{
		return;
	}

	printf("%d", root->value);
	//if (root->left != NULL)
	//{
	//	PreorderTraversal(root->left);
	//}

	//if (root->right!= NULL)
	//{
	//	PreorderTraversal(root->right);
	//}
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}

void Inorder(Node* root)
{
	//左子树  根  右子树
	if (root == NULL)
	{
		return;
	}

	Inorder(root->left);

	printf("%d", root->value);

	Inorder(root->right);
}


void Postorder2(Node* root)
{
	//左子树 右子树   根  
	if (root == NULL)
	{
		return;
	}

	Postorder2(root->left);

	Postorder2(root->right);

	printf("%d", root->value);

}

//计算结点数
int Size(Node* root)
{

}

//递推的方式，求叶子结点个数
int LeaftSize(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	int left = LeaftSize(root->left);
	int right = LeaftSize(root->right);
	return left + right;

}

int GetHeight(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{ 
		return 1;
	}

	int left = GetHeight(root->left);
	int right = GetHeight(root->right);

	if (left > right)
	{
		return left + 1;
	}
	else
	{
		return right + 1;
	}

}

//求第K层结点个数
int GetKlevel(Node* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)//隐含前提root!=NULL
	{
		return 1;
	}

	int left = GetKlevel(root->left,k-1);
	int right = GetKlevel(root->right ,k - 1);

	return left + right;
}

//二叉树结点所有的value都不重复
//找如果结点的value是v的结点，返回v所在的结点地址，否则返回NULL
//查找顺序：	1.根结点	2.左子树	3.右子树
Node* Find(Node* root, int v)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->value == v)
	{
		return root;
	}
	
	Node* result = Find(root->left, v);
	if (result != NULL)
	{
		//左子树找到了
		return result;
	}

	result = Find(root->right, v);
	if(result!=NULL)
	{
		return result;
	}
	else
	{
		return NULL;
	}
}

//bool isMirror(struct TreeNode* p, struct TreeNode* q)
//{
//	if (p == NULL && q == NULL)
//	{
//		return true;
//	}
//
//	if (p == NULL || q == NULL)
//	{
//		return false;
//	}
//
//	return p->val == q->val
//		&& isMirror(p->left, q->right)
//		&& isMirror(p->right, q->left);
//}
//
//bool isSynmetric(struct TreeNode* root)
//{
//	if (root == NULL)
//	{
//		return true;
//	}
//}

void  

int main()
{

	//1.空树的情况：return

	//前：A B C D F I E G H
	//中: B A D I F C G E H 
	//后: B I F D G H E C A



	//节点的度：一个节点含有的子树的个数称为该节点的度； 如上图：A的为6
	
	//叶节点或终端节点：度为0的节点称为叶节点； 如上图：B、C、H、I...等节点为叶节点
	
	//非终端节点或分支节点：度不为0的节点； 如上图：D、E、F、G...等节点为分支节点
	
	//双亲节点或父节点：若一个节点含有子节点，则这个节点称为其子节点的父节点； 
	//					如上图：A是B的父节点
	
	//孩子节点或子节点：一个节点含有的子树的根节点称为该节点的子节点； 
	//					如上图：B是A的孩子节点

	//兄弟节点：具有相同父节点的节点互称为兄弟节点； 如上图：B、C是兄弟节点
	
	//树的度：一棵树中，最大的节点的度称为树的度； 如上图：树的度为6
	
	//节点的层次：从根开始定义起，根为第1层，根的子节点为第2层，以此类推；
	
	//树的高度或深度：树中节点的最大层次； 如上图：树的高度为4
	
	//堂兄弟节点：双亲在同一层的节点互为堂兄弟；如上图：H、I互为堂兄弟节点
	
	//节点的祖先：从根到该节点所经分支上的所有节点；如上图：A是所有节点的祖先
	
	//子孙：以某节点为根的子树中任一节点都称为该节点的子孙。
	//		如上图：所有节点都是A的子孙
	
	//森林：由m（m >= 0）棵互不相交的树的集合称为森林；


	system("pause");
	return 0;
}