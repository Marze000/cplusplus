#include <iostream>
using namespace std;

#if 0
class CFather{
public:
	virtual void AA(){
		cout << "CFather :: AA()" << endl;
	}
	void BB(){
		cout << "CFather :: BB()" << endl;
	}
};

class CSon : public CFather{
public:
	void AA(){
		cout << "CSon :: AA()" << endl;
	}
	void BB(){
		cout << "CSon :: BB()" << endl;
	}
};

int main(){
	cout << sizeof(CFather) << endl;
	//测试加了虚函数的类
	system("pause");
	return 0;
}
#endif
