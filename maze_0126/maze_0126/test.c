#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//strcat 后一个字符串接在前一个字符串的后面，
	//并删除前一个的字符串结束‘\0’,最后加上‘\0’   

	//strncat(str1, str2, 6)
	//6所代表的是：在str2里面有几个字符被传进去

	//strcpy 后一个字符串覆盖前一个字符串。
	//strncpy 

	//strcmp （int* str1,int* str2）
	//数组的字符串的比较，如果前面大，则返回正数，否则返回负数或0

	//strncmp(int* str1,int* str2,size_num)
	//后面的参数是只比较num个字符，至于后面的字符不做比较
	//例如：strncmp("shd1","shd23",3)这个结果为0，因为只比前三个字符

	//strlen 测字符串的实际长度，不计算‘\0’的长度
	//strlwr 大写字母转换为小写字母，其余不变。
	//strupr 小写字母转换为大写字母，其余不变。

	//strstr(char* str1, char* str2)
	//返回指向在str1中第一次出现str2的指针，
	//如果在str1中没有str2，则返回一个空指针。

	//int str1[] = { 'd','s','e','r','d','g' };
	//int str2[] = { 'd','f','s','a','f','g','s' };
	//if (strncmp(str1, str2, 2) > 0)//   <0
	//{
	//	printf("ok！");
	//}
	//else
	//{
	//	printf("no！");
	//}

	//char str1[20];
	//char str2[20];
	//strcpy(str1, "To be a ");
	//strcpy(str2, "or not to be");
	//strncat(str1, str2, 6);
	//puts(str1);

	//printf("%s", str1);


	//char str[][5] = { "R2D2" , "RxPO" , "R2A6" };
	//int n = 0;
	//puts("Looking for R2 astromech droids...");
	//for (n = 0; n < 3; n++)
	//{
	//	if (strncmp(str[n], "Rxxx", 2) == 0)
	//	{
	//		printf("found %s\n", str[n]);
	//	}
	//}
	//char str[] = "This is a simple string";
	//char* pch;
	//pch = strstr(str, "simple");
	//int arr = strncpy(pch, "sample", 6);
	////puts(str);
	////puts(pch);
	////printf("%s", strncpy(pch, "sample", 6));
	//printf("%s", arr);

	//char str1[30] = { "thissmaze" };
	//char str2[20] = {"mynameismaze"};

	//int arr[] = { strncpy(str1, str2, 5) };

	//puts(str1);
	//printf("%s\n", str2);
	//printf("%s\n", str1);
	//printf("%s", arr);
	
	//char str[] = "This is a simple string";
	//char pc[20] = { 0 };
	////pch = strstr(str, "simple");
	//strncpy(pc, str, 6);
	////puts(str);
	//printf("\n");
	//printf("%s",pc);

	//char name[] = "Chinanet";
	//char dest[20] = { 0 };

	//strncpy(dest, name, 10);

	//printf("%s", dest);

	system("pause");
	return 0;
}