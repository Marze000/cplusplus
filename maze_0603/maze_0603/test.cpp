#include <iostream>
#include <stdlib.h>
using namespace std;

struct str_t {
	long long len;
	char data[32];
};

struct data1_t {
	long long len;
	int data[2];
};
struct data2_t {
	long long len;
	char *data[1];
};
struct data3_t {
	long long len;
	void *data[];
};

int main(void)
{
	struct str_t str;
	memset((void*)&str, 0, sizeof(struct str_t));
	str.len = sizeof(struct str_t) - sizeof(int);
	snprintf(str.data, str.len, "hello");//VSÏÂÎª_snprintf
	
	struct data3_t * pData = (struct data3_t *)&str;
	printf("data:%s%s\n", str.data, (char*)(&(pData->data[0])));
	return 0;
}

class A
{
public:
	A() { ++_scount; }
	A(const A& t) { ++_scount; }
	void display(){}
	static int GetACount() {
		display();
		return _scount; 
	}
private:
	static int _scount;
};

int A::_scount = 0;

void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}


int main()
{

	
	system("pause");
	return 0;
}