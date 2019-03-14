#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//查找所有在一个给定字符集合中出现的字符
char* find_char(char const* source, char const* chars)
{
	assert(source != NULL);
	assert(chars != NULL);
	
	char* pchars = (char*)chars;//XRCQEF// “初始化”: 不同的“const”限定符

	while (*pchars!= '\0')
	{
		char* psource = (char*)source;//ABCDEF	“初始化”: 不同的“const”限定符
		while (*psource != '\0')
		{
			if (*psource != *pchars)
			{
				++psource;
			}
			else
			{
				return psource;//“return”:“char *”与“char”的间接级别不同
			}
		}
		pchars++;
	}
	return 0;
}//“find_char”: 不是所有的控件路径都返回值

int del_substr(char* str, char const *substr)
{
	assert(str != NULL);
	assert(substr != NULL);

	while (*str != '\0')
	{
		char* psubstr = (char*)substr;//CDE//ACD
		char* pstr = (char*)str;//ABCDEFGH
		while (*psubstr != '\0')
		{
			if (*psubstr != *pstr)
			{
				break;
			}
			else
			{
				++pstr;
				++psubstr;
			}
		}
		if (*psubstr == '\0')
		{
			return 1;
		}
		++str;
	}

	return 0;
}

int main()
{
	char str1[] = "ABCDEFGH";
	char str2[] = "CDE";
	char str3[] = "ACD";
	int n = del_substr(str1, str2);
	if (n == 1)
	{
		printf("%s", str1);
	}

	//char str1[] = "ABGDEF";//“初始化”: 从“char *”到“int *”的类型不兼容
	//char str2[] = "XRCQEF"; //“printf”: 格式字符串“%c”需要类型“int”的参数，
	//						//但可变参数 1 拥有了类型“int *”
	//char* p = find_char(str1, str2);
	//printf("%c", *p);
	//

	//char str[] = "This is a sample string";
	//char keys[] = "aeiouh";
	//printf("%s\n", str);
	//char *pch = strpbrk(str, keys);
	
	//while (pch != NULL)
	//{
	//	printf("%c", *pch);//iiaaei
	//	pch = strpbrk(pch + 1, keys);
	//}
	
	//getchar();
	//int *p = NULL;
	//printf("%d", sizeof(p));
	//printf("%d", sizeof(int));
	



	system("pause");
	return 0;
}
