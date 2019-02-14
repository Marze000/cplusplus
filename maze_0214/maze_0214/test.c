#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void move(char x, int n, char y)
{
	int c = 0;
	printf("第%d次：将第%d号盘子从%c移到%c\n",++c,n,x,y);
}

void hannuota(int n, char x, char y, char z)
{
	//利用y将x上的移到z上
	if (n == 1)
	{
		move(x, 1, z);
	}
	else
	{
		hannuota(n - 1, x, z, y);
		move(x, n, z);
		hannuota(n - 1, y, x, z);
	}

}


int main()
{
	printf("输入要转移的盘子数：\n");
	int n = 0;
	scanf("%d", &n);
	hannuota(n, 'a', 'b', 'c');

	//fputc()的函数一般形式：ch = fputc(ch,fp);
	//该函数的作用是把一个字符写到磁盘文件中（fp所指向的文件）
	//其中ch是要输出的字符，可以字符常量或字符变量。
	//fp是文件指针变量，如果函数输出成功的话则返回值就是输出的字符
	//否则输出失败返回EOF
	//FILE* fp;
	//char ch;
	//char filename[50]; 
	//printf("please input filename:\n");
	//scanf("%d", filename);
	//fp = fopen(filename, "w");
	//if (fp == NULL)
	//{
	//	printf("cannot open file\n");
	//	exit(0);
	//}
	//ch = getchar();
	//ch = getchar();
	//while (ch != '#')
	//{
	//	fputc(ch, fp);
	//	ch = getchar();
	//}

	//fclose(fp);
	















	system("pause");
	return 0;
}