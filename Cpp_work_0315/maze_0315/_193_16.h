#pragma once
#include<iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
using namespace std;

//输入一个字符串,内有数字和非数字字符 a123x456__17960?302tab5876
//将其中的连续数字做为一个整数依次存放到一维数组a中
//例如:123放在a[0],456放在a[1]统计共有多少个整数,并且输出这些数

void isfinger()
{
	char b[100] = "a123x456__17960?302tab5876";
	int q = 0;
	char *p = b;
	char a[100];
	int num = 0;
	
	for(;*p!='\0';++p)
	{
		if (*p > '0' && *p <= '9')
		{
			q = (*p) - '0';
			p++;
			while (*p >= '0'&& *p <= '9')
			{
				q = (q) * 10 + (*p) - '0';
				p++;
			}
			++num;
			cout << "a[" << num - 1 << "]=" << q << endl;
			//printf("a[%d] = %d\n",num-1, q);
		}
	}
	//printf("共有%d个整数\n", num);
	cout << "共有"<<num<<"个整数" << endl;
}

