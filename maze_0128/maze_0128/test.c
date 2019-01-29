#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct S
//{
//	int date[1000];
//	int num;
//};
//
//struct S s = { {1,2,3,4},1000 };
//
////结构体传参
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
//
////结构体地址传参
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//
//struct A   //大小为8
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 20;
//
//};

int main()
{	

	//union Un1     //8
	//{
	//	char c[5];
	//	int i;
	//};
	//
	//union Un2     //16
	//{
	//	short c[7];
	//	int i;
	//};

	//printf("%d\n", sizeof(union Un1));
	//printf("%d\n", sizeof(union Un2));

	//printf("%d", sizeof(struct A));//8
	//print1(s); //1000
	//print2(&s);//1000
	//结构体传参的时候选择传地址，不要传结构体，那样会太大，增加额外的成本。

	
	//32位操作系统，int占4字节，char占1字节，double占8字节，float占4字节
	//64位操作系统，int占  字节，char 占字节，double占 字节，float占 字节

	//struct str
	//{
	//	char c1;
	//	int i ;
	//	char c2;
	//};
	//printf("%d", sizeof(struct str));//12

	//struct str
	//{
	//	char c1;
	//	char c2;
	//	int i;
	//};
	//printf("%d", sizeof(struct str));//8

	//struct str
	//{
	//	double d;
	//	char i;
	//	int a;
	//};
	//printf("%d", sizeof(struct str));//16



	system("pause");
	return 0;
}