#include <stdio.h>
#include <stdlib.h>


//InitQueue(&Q);//构造一个空队列

//运行以下一段代码会出现什么？
void GetMemory(char **p)
{
	*p = (char *)malloc(100);
}

//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}

//void test1()
//{
//	unsigned char array[MAX_CHAR + 1];
//	int i = 0;
//	for (i = 0; i <= MAX_CHAR; i++)
//	{
//		array[i] = i;
//	}
//}
//
//char * test2()
//{
//	char p[] = "hello world";
//	return p;		
//}
//
//char* p = test2();
//
//void test3()
//{
//	char str[10];
//	str++;
//	*str = '0';
//}






int main()
{	
	//int x = 1;
	//int y = 1;
	//printf("%d", (!x || y--));
	char* str = NULL;
	GetMemory(&str);
	strcpy(str, "hello world");
	printf(str);

	//char s[] = "123";
	//char* p = s;
	//printf("%c %c %c \n", *p++, *p++, *p++);
	//3 2 1


		
	//int x = 0;
	//int y = 5;
	//int z = 3;
	//while (z-->0 && ++x < 5)
	//{
	//	y = y - 1;
	//}
	//printf("%d %d %d\n", x, y, z);
	//x==3  y==2  z==-1
	//“z-->”代表的是：(z--)>



	system("pause");
	return 0;
}