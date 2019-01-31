#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str1[30];
	char str2[20];
	char* p1 = str1; 
	char* p2 = str2; 
	
	gets(str1);
	gets(str2);
	while (*p1 != '\0')
	{
		p1++;
	}
	while (*p2 != '\0')
	{
		*p1++ = *p2++;
	}
	*p1 = '\0';
	printf("连接后的字符是\n");
	puts(str1);


	//int i;
	//double* a;
	//a = &i;
	//printf("%d\n", a);
	//a++;
	//printf("%d\n", a);

	//int i;
	//long* p;
	//printf("please input:\n");
	//scanf("%d", &i);

	//p = &i;
	//printf("%d\n", p);
	//p++;
	//printf("%d\n",p);

	//long i;
	//long* p;
	//printf("please input the number:\n");
	//scanf("%ld", &i);
	//p = &i;

	//printf("%ld\n", *&i);//i
	//printf("%ld\n", i);//i
	//printf("%ld\n", *p);//i



	//long i = 0;
	//long* p;
	//scanf("%d", &i);

	//p = &i;
	//printf("%ld\n",&*p);
	//printf("ld\n", &i);

	//int a = 0;
	//int b = 0;
	//int* p1;
	//int* p2;
	//scanf("%d %d", &a, &b);
	//p1 = &a;
	//p2 = &b;
	//printf("%d %d", *p1, *p2);

	system("pause");
	return 0;
}