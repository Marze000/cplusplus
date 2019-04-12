#include <iostream>
#include <stdlib.h>
using namespace std;

//307 页12题
//将9.14改写为类模板外定义的各成员函数
template <class numtype>//声明类模板,虚拟类型名是numtype
class Compare//类模板名称为Compare
{
public:
	Compare(numtype a, numtype b)
	{
		x = a;
		y = b;
	}
	numtype max();
	numtype min();
private:
	numtype x, y;
};

template <class numtype>
numtype Compare <numtype>::min()
{
	return x < y ? x : y;
}



int main()
{
	Compare<int>cam(3, 7);
	cout << cam.max() << endl;

	//一般形式为：类模板名 <实际类型名> 对象名（参数表）
	system("puase");
	return 0;
}