#include <iostream>
#include <vector>
using namespace std;

int main(){
	try {
		vector<int> v(10, 5);
		 这里如果系统内存不够也会抛异常
		v.reserve(1000000000);
		 这里越界会抛异常
		v.at(10) = 100;
		 这里捕获父类对象就可以
	}catch (const exception& e) {
		cout << e.what() << endl;
	}catch (...){
		cout << "Unkown Exception" << endl;
	}

	return 0;
}
class Exception{
protected:
	string _errmsg;
	int _id;
	//list<StackInfo> _traceStack;
	// ...
};

class SqlException : public Exception{};
class CacheException : public Exception{};
class HttpServerException : public Exception{};

int main(){
	try {
		// server.Start();
		// 抛出对象都是派生类对象
	}
	catch (const Exception& e) // 这里捕获父类对象就可以
	{}

	catch (...){
		cout << "Unkown Exception" << endl;
	}

	return 0;
}
double Division(int a, int b){
	// 当b == 0时抛出异常
	if (b == 0){
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func(){
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，
	//这里捕获了再重新抛出去。
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}catch (...){
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}

	// ...
	cout << "delete []" << array << endl; 
	delete[] array;
}

int main(){
	try{
		Func();
	}catch (const char* errmsg){
		cout << errmsg << endl;
	}

	return 0;
}

double Division(int a, int b){
	// 当b == 0时抛出异常
	if (b == 0) {
		throw "Division by zero condition!";
	}else {
		return ((double)a / (double)b);
	}
}

void Func(){
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}

int main() {
	try {
		Func();
	}

	catch (const char* errmsg){
		cout << errmsg << endl;
	}

	catch (...){
		cout << "unkown exception" << endl;
	}

	return 0;
}