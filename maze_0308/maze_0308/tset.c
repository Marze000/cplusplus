#include <stdio.h>
#include <stdlib.h>


//void print_arr1(int arr[3][5], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}

//void print_arr2(int(*arr)[5], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}

//void test1(int arr[])//ok?
//{}
//void test2(int arr[10])//ok?
//{}
//void test3(int *arr)//ok?
//{}
//void test4(int *arr[20])//ok?
//{}
//void test5(int **arr)//ok?
//{}

//void test(int** ptr)
//{
//	printf("num = %d\n", **ptr);
//}

//void test(char **p)
//{
//	printf("%c",**p);
//}

//void test()
//{
//	printf("hehe\n");
//}

int int_cmp(const void * p1, const void * p2)
{
	return (*(int *)p1 > *(int *)p2);
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;

	qsort(arr, 10, 4, int_cmp);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	//printf("%p\n", test);
	//printf("%p\n", &test);
	////00A213C5
	////00A213C5

	//char c = 'b';
	//char*pc = &c;
	//char**ppc = &pc;
	//char* arr[10];
	//test(&pc);
	//test(ppc);
	//test(arr);//Ok?

	//int n = 10;
	//int* p = &n;
	//int** pp = &p;
	//test(pp);//10
	//test(&p);//10

	//int arr[10] = { 0 };
	//int *arr2[20] = { 0 };
	//test1(arr);
	//test2(arr);
	//test3(arr);
	//test4(arr2);
	//test5(arr);

	//int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
	////{ 1,2,3,4,5  }
	////{ 6,7,8,9,10 }
	////{ 0,0,0,0,0  }
	//for (int i = 0; i < 3; ++i)
	//{
	//	for (int j = 0; j < 5; ++j)
	//	{
	//		printf("%d ", arr[i][j]);
	//	}
	//	printf("\n");
	//}

	//print_arr1(arr, 3, 5);
	//数组名arr，表示首元素的地址
	//但是二维数组的首元素是二维数组的第一行
	//所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址

	//可以用数组指针来接收
	//print_arr2(arr, 3, 5);

	
	//int arr[10] = { 0 };
	//printf("arr = %p\n", arr);		//arr = 012FFCEC
	//printf("&arr= %p\n", &arr);	   //&arr = 012FFCEC
	//printf("arr+1 = %p\n", arr + 1); // arr + 1 = 012FFCF0
	//printf("&arr+1= %p\n", &arr + 1);//&arr + 1 = 012FFD14
	////&arr+1 = 表示数组的地址：直接从首地址跳到尾地址的后面
	//共10个数，每个数占4个字节，跳过40个字节大小
	
	

	//char str1[] = "hello bit.";
	//char str2[] = "hello bit.";
	//char *str3 = "hello bit.";
	//char *str4 = "hello bit.";
	//if (str1 == str2)
	//{
	//	printf("str1 and str2 are same\n");
	//}
	//else
	//{
	//	printf("str1 and str2 are not same\n");//ok
	//}
	//if (str3 == str4)
	//{
	//	printf("str3 and str4 are same\n");//ok
	//	printf("%p\n%p\n", str3, str4);
	//}
	//else
	//{
	//	printf("str3 and str4 are not same\n");
	//}


	system("pause");
	return 0;
}