//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int yy, mm, dd;
//	cin >> yy;
//	cin >> mm;
//	cin >> dd;
//
//	int array[12] = {0, 31,59,90,120,151,181,212,243,273,304,334 };
//	int days = 0;
//	days = array[mm - 1];
//	days += dd;
//	if (mm > 2) {
//		if ((yy % 100 != 0 && yy % 4 == 0) || yy % 400 == 0) {
//			days += 1;
//		}
//	}
//	cout << days << endl;
//
//	system("pause");
//	return 0;
//}

#include <vector>
#include <iostream>
using namespace std;

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		int array[] = { 0 };
		for (size_t i = 0; i < gifts.size(); ++i) {
			array[gifts[i]++];
		}

		for (size_t i = 0; i < gifts.size(); ++i) {
			if (array[gifts[i]] > (n / 2)) {
				return gifts[i];
			}
		}
		return 0;
	}
};
