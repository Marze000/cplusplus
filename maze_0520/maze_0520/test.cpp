#define _CRT_SECURE_NO_WARNINGS
////#include <iostream>
////#include <stdlib.h>
////#include <string>
////#include <vector>
////#include<algorithm>
////
////using namespace std;
////
////int main()
////{
////	int n;
////	while (cin >> n)
////	{
////		long long sum = 0;
////		vector<int> a;
////		a.resize(3 * n);
////		for (int i = 0; i < (3 * n); i++)
////		{
////			cin >> a[i];
////		}
////		std::sort(a.begin(), a.end());
////
////		for (int i = n; i <= 3 * n - 2; i += 2)
////		{
////			sum += a[i];
////		}
////		cout << sum << endl;
////	}
////	system("pause");
////	return 0;
////}
//
////
////int main()
////{
////	string s("hello");
////	cout << s.size() << endl;
////	cout << s.length() << endl;
////	cout << s.capacity() << endl;
////	cout << s << endl;
////	//s.clear();
////	cout << s.size() << endl;
////	cout << s.capacity() << endl;
////	if (s.empty())
////	{
////		cout << "ÊÇ¿Õ×Ö·û´®" << endl;
////	}
////	else { cout << "²»ÊÇ¿Õ×Ö·û´®" << endl; }
////	cout << s[0] << endl;
////
////	s[1] = 'H';
////	cout << s[1] << endl;
////	cout << s << endl;
////
////
////	system("pause");
////	return 0;
////}
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	while (scanf("%d", &n))
	{
		int *array = (int*)malloc(sizeof(int) * 3 * n);
		scanf("%d ", array);
		scanf("%d ", ++array);
	}
	//scanf("%d", &n);
	//int m = 3 * n;
	//int array[] = { 0 };
	//for (int i = 0; i < 3 * n; ++i)
	//{
	//	scanf("%d", &array[i]);
	//}
	//
	//for (int i = 0; i < m-1; ++i)
	//{
	//	for (int j = 1; j < m - i; ++j)
	//	{
	//		if (array[j] > array[j-1])
	//		{
	//			int temp = array[j];
	//			array[j] = array[j-1];
	//			array[j-1] = temp;
	//		}
	//	}
	//}

	//int sum = 0;
	//m = 1;
	//while (n--)
	//{
	//	sum += array[m];
	//	m += 2;
	//}

	//printf("%d\n", sum);

	system("pause");
	return 0;
}

