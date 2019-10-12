#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#if 0
void LoopMove(char* pStr,int steps){
	if (pStr == nullptr) {
		return;
	} 
	int len = strlen(pStr);
	char temp[1024];
	strcpy(temp, pStr + len - steps);
	strcpy(temp + steps, pStr);
	*(temp + len) = '\0';
	strcpy(pStr, temp);
}
#endif

// 编写一个函数作用是把一个char组成
// 的字符串循环右移n个
// 比如：原来的abcdefghi 如果n = 2,
// 移位后 应该是 hiabcdefg 
#if 1
void LoopMove(char* pStr,int steps){
	if (pStr == nullptr) {
		return;
	} 
	char temp[1024];
	int len = strlen(pStr);
	memcpy(temp, pStr + len-steps, steps);
	memcpy(temp + steps, pStr, len - steps);
	memcpy(pStr, temp, len);
}
#endif
int main() {
	char a[1024] = "abcdefghi";
	char* str = a;
	LoopMove(str, 2);
	cout << str << endl;

	//char p[10] = "abcd";
	//char m[10] = "ef";
	//strcat(p, m);
	//printf("%s\n", p);

	system("pause");
	return 0;
}

#if 0
int  a = 10;
class {
	int a = 10;
}
//#ifndef  __INCvxWorksh

//
//#define __INCvxWorksh
//
//#ifdef __cplusplus
//
//extern "C" {
//
//}
//#endif // __cplusplus
//
//#endif // ! __INC

void Func(char str[100]) {
	//输出多少？
	printf("%d\n",sizeof(str));

	char string[100] = { 0 };
	//输出多少？
	printf("%d\n", sizeof(string));

	void* p = malloc(100);
	//输出多少？
	printf("%d\n", sizeof(p));
	free(p);p = nullptr;
}


int main() {

	system("pause");
	return 0;
}

char* Strcpy(char* pStrDest,const char* pStrSrc) {
	//代码的鲁棒性判断
	if (pStrDest == nullptr || pStrSrc == nullptr) {
		return nullptr;
	}
	char* add = pStrDest;
	while ((*pStrDest = *pStrSrc) != '\0') {
		++pStrDest;
		++pStrSrc;
	}
	return add;
}

void GetMemory(char** p,int num) {
	if (num <= 0) {
		printf("申请的内存太小了\n");
	}
	*p = (char*)malloc(num);
	if (*p == nullptr) {
		return;
	}
}

void test() {
	char* str = nullptr;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	free(str);
	printf("%s",str);
}

void Test() {
	char*str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
}

void swap1(int *p1, int* p2) {
	int *p = p1;
	int *n = p2;
	*p1 = *p;
	p2 = p;
}

void swap2(int& p1, int& p2) {
	int p = p1;
	p1 = p2;
	p2 = p;
}

void isfloatequal(float n1, float n2) {
	const float EPSINON = 0.00001;
	int x = n1 - n2;
	if ((x <= EPSINON)&&(x>=-EPSINON)) {
		printf("可以判断两个数相等\n");
	}
	else {
		printf("不等\n");
	}
}

int main() {
	isfloatequal(0.0000001,0.00000002);
	isfloatequal(0.0001,1);
	isfloatequal(100,100.0000001);

	system("pause");
	return 0;
}

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