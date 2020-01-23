#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class A{
public:
	void print(){
		cout << "A:print()";
	}
};
class B : private A{
public:
	void print(){
		A::print();
		cout << "B:print()";
	}
};
class C : public B{
public:
	void print(){
		//A::print();
	}
};

int main(){
	B b;
	b.print();

	system("pause");
	return 0;
}


#if 0
int f(int n) {
	static int i = 1;
	if (n >= 5) {
		return n;
	}
	n = n + i;
	i++;
	return f(n);
}

//void increment_ints(int p[], int n){
//	assert(p != NULL);
//	assert(n >= 0); 
//	while (n--){
//		*p++;
//		p++;
//	}
//}

int main() {
	f(1);

	system("pause");
	return 0;
}
#endif
