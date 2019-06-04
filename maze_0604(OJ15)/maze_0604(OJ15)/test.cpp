#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int count = 0;
	while (cin >> n) {
		while (n) {
			if ((n & 1) == 1) {
				++count;
			}
			n = n >> 1;
		}
		cout << count;;
	}
	return 0;
}


//Ë¼Â·£º
