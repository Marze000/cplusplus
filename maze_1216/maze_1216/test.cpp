#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <map>
using namespace std;

int main(){
	std::unordered_set<std::string> myset ={ 
		"Mars",
		"Mars",
		"Saturn",
		"Saturn",
		"Saturn",
		"Neptune"
	};

	std::cout << "myset contains:" << endl;
	for (auto it = myset.begin(); it != myset.end(); ++it) {
		std::cout << " " << *it << endl;
	}
	std::cout << std::endl;

#if 0
	std::cout << "myset's buckets contain:\n";
	for (unsigned i = 0; i < myset.bucket_count(); ++i) {
		std::cout << "bucket #" << i << " contains:";
		for (auto local_it = myset.begin(i); local_it != myset.end(i); ++local_it)
			std::cout << " " << *local_it;
		std::cout << std::endl;
	}
#endif
	
	system("pause");
	return 0;
}

