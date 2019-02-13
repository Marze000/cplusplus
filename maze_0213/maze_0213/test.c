#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int c = 0;
void move(char x, int n, char z)
{
	//第n个圆盘从塔座x搬到塔座z
	
	printf("第%-2d步：将%d号盘从%c移到%c\n", ++c, n, x, z);

}

void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
	{
		move(x, 1, z);
	}
	else
	{
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}
}

int main()
{
	
	int n = 0;
	printf("输入圆盘数：\n");

	scanf("%d", &n);
	hanoi(n, 'a', 'b', 'c');


	system("pause");
	return 0;
}