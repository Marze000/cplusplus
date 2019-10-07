#include <stdio.h>
#include <stdlib.h>
//using namespace std;

void Permutation(char* pStr,char* pBegin) {
	if (*pBegin == '\0') {
		printf("%s\n", pStr);
	}
	else {
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh) {
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}
int main() {
	const char* str = "abcdef";
	Permutation(str,str);

	system("pause");
	return 0;
}