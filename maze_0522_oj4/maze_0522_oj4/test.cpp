#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
	int N = 0;
	int M = 0;
	cin >> N;
	cin >> M;
	int num = 0;
	int array[10];
	while (N)
	{
		N %= M;
		N /= M;
		array[num++] = N;
	}

	for (int i = num - 1; i >= 0; --i)
	{
		if (M >= 10)
		{
			cout << (char)(array[i] + 55);
		}
		else
		{
			cout << array[i];
		}
	}

	system("pause");
	return 0;
}

int main()
{
	vector <int> a;
	int i = 0;
	a.resize(4);
	for (; i < 4; ++i)
	{
		cin >> a[i];
	}

	a[0] = A - B;
	a[1] = B - C;
	a[2] = A + B;
	a[3] = B + C;
	int A = (a[0] + a[2]) / 2;
	int B = a[2] - A;
	int C = a[3] - B;
	cout << A << " " << B << " " << C;
	system("pause");
	return 0;
}