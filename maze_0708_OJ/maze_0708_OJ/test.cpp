#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void  CaculateWeekDay(int yy, int mm, int dd) {
	if (mm == 1 || mm == 2) {
		mm += 12;
		yy--;
	}
	int iweek = (dd + 2 * mm + 3 * (mm + 1) / 5 + 
		yy + yy / 4 - yy / 100 + yy / 400) % 7;
	switch (iweek) {
	case 0:
		cout << "星期一" << endl;
		break;
	case 1:
		cout << "星期二" << endl;
		break;
	case 2:
		cout << "星期三" << endl;
		break;
	case 3:
		cout << "星期四" << endl;
		break;
	case 4:
		cout << "星期五" << endl;
		break;
	case 5:
		cout << "星期六" << endl;
		break;
	case 6:
		cout << "星期日" << endl;
		break;
	}
}

int main() {
	int y, m, d;
	while (cin >>y>>m>>d) {
		CaculateWeekDay(y, m, d);
	}

	system("pause");
	return 0;
}

int v[8] = {2, 3, 5, 7, 11, 13, 17, 19};
int MultFen(int n) {
	int j = 0;
	int i = 0;
	int a = n;
	int arr[20] = { 0 };
	while (n != 1) {
		if (n % v[i] == 0) {
			n = n / v[i];
			arr[j++] = v[i];
		}
		else {
			v[++i];
		}
	}
	cout << a <<" = ";
	for (int i = 0; i < j; ++i) {
		if (i == j-1) {
			cout << arr[i];
		}else {
			cout << arr[i]<<"*";
		}
	}
	cout << endl;

	system("pause");
	return 0;
}

int main() {
	int a;
	while (cin >> a) {
		MultFen(a);
	}
	return 0;
}