#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Find_finger(int arr[][3],int find)
{
	int row = 0;
	int col = 2;
	while ((col >= 0) && (row <= 2))
	{
		if (arr[row][col] == find)
		{
			return 1;
		}
		else if (arr[row][col] < find)
		{
			++row;
		}
		else
		{
			--col;
		}
		return 0;
	}



	//for (int row = 0; row < 3; ++row)
	//{
	//	for (int col = 0; col < 3; ++col)
	//	{
	//		if (arr[row][col] == find)
	//		{
	//			return 1;
	//		}		
	//	}
	//}
	//return 0;
}

int main()
{







	//const char str1[] = "abcdef";
	//const char str2[] = "bbb";
	//if (strlen(str2) - strlen(str1) > 0)
	//{
	//	printf("str2>str1\n");
	//}
	//else
	//{
	//	printf("srt1>str2\n");
	//}

	//int arr[3][3] = { 1,2,3,2,3,4,3,4,5 };
	//int find = 0;
	//printf("请输入需要查找的数：\n");
	//scanf("%d", &find);

	//if (Find_finger(arr,find))
	//{
	//	printf("找到了！\n");
	//}
	//else
	//{
	//	printf("没找到！\n");
	//}


	system("pause");
	return 0;
}
//杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
