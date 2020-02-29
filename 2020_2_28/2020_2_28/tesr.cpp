#include <iostream>
#include <vector>
using namespace std;

void replaceSpace(char *str, int length) {
	if (str == nullptr) {
		return;
	}
	int blank = 0;
	for (int i = 0; i < length; ++i) {
		if (str[i] == ' ') {
			++blank;
		}
	}
	int newlength = length + 2 * blank;
	int size = newlength - 1;
	for (int i = length - 1; i >= 0; --i) {
		if (str[i] != ' ') {
			str[size--] = str[i];
		}
		else {
			str[size] = '0';
			str[size - 1] = '2';
			str[size - 2] = '%';
			size -= 3;
		}
	}
	str[newlength] = '\0';
}

int main() {
	char str[] = "we are happy";
	int len = strlen(str);
	replaceSpace(str, len);
	printf("%s\n", str);

	system("pause");
	return 0;
}
