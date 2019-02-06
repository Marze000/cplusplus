#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void paixu(char* str1, char* str2)
{
	char* s;
	char arr[30];
	s = arr;
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 < *str2)
		{
			*s = *str1;
			++str1;
		}
		else
		{
			*s = *str2;
			++str2;
		}
		++s;
	}
	if (*str1 == '\0')
	{
		while (*str2 != '\0')
		{
			*s++ = *str2++;
		}
	}
	if(*str2=='\0')
	{
		while (*str1 != '\0')
		{
			*s++ = *str1++;
		}
	}
	*s = '\0';
	s = arr;
	printf("%s", s);

}


int main()
{
	//char* s1 = "adhlnqrto";
	//char* s2 = "cefksxz";

	//paixu(s1,s2);
	






	system("pause");
	return 0;
}