#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n;
	while (n--)
	{
		cin >> s;
	}
	return 0;
}
/*include <iostream>
using namespace std;

int main()
{
	int A, B;
	cin >> A;
	cin >> B;
	for (int i = 1; i <= A * B; ++i)
	{
		if (i%A == 0 && i%B == 0)
		{
			cout << i;
			break;
		}
	}

	return 0;
}*/
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <stdlib.h>
//#include <string>
//#include <assert.h>
//using namespace std;
//
//class String
//{
//public:
//	String(const char* str1 = "")
//	{
//		if (str1 == nullptr)
//		{
//			assert(str1);
//			return;
//		}
//
//		_str = new char [strlen(str1) + 1];
//		strcpy(_str, str1);
//	}
//
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//
//int main()
//{
//	#include <iostream>
//using namespace std;
//
//int main()
//{
//    int A,B;
//    cin>>A;
//    cin>>B;
//    if(A%B ==0)  
//    {
//        cout<<A;
//    }
//    else if(B%A == 0)
//    {
//        cout<<B;
//    }
//    else
//    {
//        for(int i = 0;i<A*B;++i)
//        {
//            if(i%A==0 && i%B ==0)
//            {
//                cout<<i;
//                break;
//            }
//        }
//    }
//    
//    return 0;
//}
//
//    //resize :改变元素个数  可能会增容
//	//reserve : 改变底层空间
//
//	//string s;
//	//s[0] = 'H';
//	
//	//String str1("aaa");
//
//	system("pause");
//	return 0;
//}

