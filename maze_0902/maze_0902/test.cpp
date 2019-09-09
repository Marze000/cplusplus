#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main() {
	int T = 0;
	int K = 0;
	int M = 0;
	while (cin >> T) {
		cin >> K >> M;
		vector<int>vec(M, 0);
		for (int i = 0; i < M; ++i) {
			cin >> vec[i];
		}
		int count = 1;
		for (int i = vec[0]; i >= 1; i = i - K - 1) {
			++count;
		}
		for (int i = vec[M - 1]; i <= 30; i = i + K + 1) {
			++count;
		}

		//for(int i = vec[0];i <= vec[M-1];++i){

		//}
		printf("%d\n", count + M);
	}
	return 0;
}










#if 0
//饿汉单例模式
template<class T>
class SingLeton {
public:
	// 调用对象 data
	static T* getsingleton() {
		return &data;
	}
private:
	//在类还没有实例化对象前就有一个对象了
	static T data;
};

template<class T>
class Singleton {
public:
	static T* GetSingleton() {
		if (data == nullptr) {
			data = new T();
		}
		return data;
	}
private:
	static T* data;
};

int main() {

	return 0;
}
#endif