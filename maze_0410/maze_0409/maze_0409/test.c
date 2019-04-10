#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//using namespace std;
//
//class Time
//{
//public:
//	int hour;
//	int minute;
//	int sec;
//};

int main()
{

	
	char name[100];
	int i = 0; 
	int c;
	printf("打开一个文件夹");
	scanf("%s",&name);

	FILE *fp  = fopen(name, "r");
	if (fp != NULL)
	{
		while ((c = fgetc(fp)) != EOF)
		{
			if (c == '\n')
			{
				++i;
			}
		}
	}
	fclose(fp);
	printf("行数是：%d\n", i);

	//Time t1;
	//cin >> t1.hour;
	//cin >> t1.minute;
	//cin >> t1.sec;
	//cout << t1.hour << ":" << t1.minute << ":" << t1.sec << endl;

	
	system("pause");
	return 0;
}
