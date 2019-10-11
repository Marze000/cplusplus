#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void test1() {
	char string[10];
	const char* str1 = "0123456789";
	strcpy(string, str1);
	for (int i = 0; i < 11; ++i) {
		cout << string[i] << ' ';
	}
	cout << endl;
}

int main() {
	test1();
	
	system("pause");
	return 0;
}

#if 0
union temp{
	int a;
	char b;
}temp;

int main(){
	int a = 0x12345;

	if (*(char*)&a == 0x45) {
		cout << "小端模式" << endl;
	}
	else {
		cout << "大端模式" << endl;
	}

	system("pause");
	return 0;
}
#endif	