#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	string temp;
	while (cin >> str) {
		int len = str.size();
		for (int i = len - 1; i >= 0; --i) {
			temp += str[i];
		}
		cout << temp << endl;
		temp = "";
	}
	return 0;
}

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	string str1;
	string str2;
	while (cin >> str1, cin >> str2) {
		int count = 0;
		int max = 0;
		size_t i = 0;
		size_t j = 0;
		while (j < str2.size() && i < str1.size()) {
			if (str1[i] != str2[j]) {
				++j;
				if (count > max) {
					max = count;
				}
				count = 0;
			}
			else {
				++i; ++j;
				++count;
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int Function(unsigned int n) {
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
	return n;
}

int main()
{
	int a = Function(197);
	cout << a << endl;

	char ccString1[] = "Is Page Fault??";
	char ccString2[] = "No Page Fault??";
	strcpy(ccString1, "No");
	if (strcmp(ccString1, ccString2) == 0) {
		cout << ccString2;
	}
	else {
		cout << ccString1;
	}

	char dog[] = "wang\0miao";

	int a = sizeof(dog);
	int b = strlen(dog);
	printf("a = %d\nb = %d\n", a, b);
	fflush(stdout);
	system("pause");
	return 0;
}