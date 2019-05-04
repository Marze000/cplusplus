#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
	int count = 0;
	int find = 0;
	int arr[] = { 1,3,5,6,23,34,54,56,76,87,89,91,92,93,95,99 };
	printf("要找到数字是%d\n",find);
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]);
	
	while (left < right)
	{
		++count;//计数,计算一个找了多少次
		int mid = (left + right) / 2;

		if (arr[mid] < find)
		{
			left = mid + 1;
		}

		if (arr[mid] > find)
		{
			right = mid - 1;
		}

		if (arr[mid] == find)
		{
			printf("找到了!!数组下标是%d\n", mid);
			break;
		}
	}

	if (left == right)
	{
		printf("没找到\n");
	}

	printf("一共找了 %d 次\n", count);

	//char ch = getchar();
	//printf("%c\n", ch);

	//printf("%d\n", getchar());

	//char ch = _getch();
	//printf("%c\n", ch);

	system("pause");
	return 0;
}
