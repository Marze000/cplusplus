//#include "test.h"
#include <stdio.h>
#include <stdlib.h>

//
//void Test()
//{
//	char array[] = { 'A','B','#','D','#','#','C','#','#'};
//	int len = sizeof(array) / sizeof(array[0]);
//	CreateBinTree(array, len);
//	PreOrder(array, len);
//
//	//BTNode* a1 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a2 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a3 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a4 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a5 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a6 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a7 = (BTNode*)malloc(sizeof(BTNode));
//
//	//BTNode* a8 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a9 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a10 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a11 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a12 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a13 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a14 = (BTNode*)malloc(sizeof(BTNode));
//	//BTNode* a15 = (BTNode*)malloc(sizeof(BTNode));
//	//a1->_data = 'A'; a2->_data = 'B'; a3->_data = 'C';
//	//a4->_data = 'D'; a5->_data = 'E'; a6->_data = 'F'; a7->_data = 'G';
//
//	//a8->_data = '#'; a9->_data = '#'; a10->_data = '#';
//	//a11->_data = '#'; a12->_data = '#'; a13->_data = '#';
//	//a14->_data = '#'; a15->_data = '#';
//
//	//a1->_pLeft = a2; a1->_pRight = a3;
//	//a2->_pLeft = a4; a2->_pRight = a5;
//	//a3->_pLeft = a7; a3->_pRight = a8;
//	//a4->_pLeft = a10; a4->_pRight = a9;
//	//a5->_pLeft = a6; a5->_pRight = a13;
//	//a6->_pLeft = a11; a6->_pRight = a12;
//	//a7->_pLeft = a15; a7->_pRight = a14;
//	//printf("前序遍历为");
//	//PreOrder(a1);
//	//printf("\n");
//	//printf("中序遍历为");
//	//InOrder(a1);
//	//printf("\n");
//	//printf("后序遍历为");
//	//PostOrder(a1);
//	//printf("\n");
//}
//
int main()
{
	//Test();

	int array[] = { 1,5,2,7,9,8,3,4,6,0 };
	int len = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < len; ++i) {
		printf("%d ", array[i]);
	}

	printf("\n");
	for (int i = 0; i < len-1; ++i) {
		for (int j = 0 ; j < len - i -1; ++j) {
			if (array[j] > array[j+1]) {
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}

	for (int i = 0; i < len; ++i) {
		printf("%d ", array[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}