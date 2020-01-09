#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <string>
using namespace std;

#if 0
void Test_unordered_map_find() {
	unordered_map<string, double> mymap = {
		 {"mom",5.4},
		 {"dad",6.1},
		 {"bro",5.9}
	};

	string input;
	cout << "who? ";
	getline(cin, input);
	unordered_map<string, double>::const_iterator got = mymap.find(input);
	if (got == mymap.end()) {
		cout << "not found";
	}
	else {
		cout << got->first << " is " << got->second;
	}
	cout << endl;
}

void Test_unordered_map_count() {
	unordered_map<string, double> mymap = {
		{"Burger",2.99},
		{"Fries",1.99},
		{"Soda",1.50} ,
		{"Soda",2.50} 
	};

	for (auto& x : { "Burger","Pizza","Salad","Soda" }) {
		if (mymap.count(x) > 0) {
			cout << "mymap has "<<" "<<mymap.count(x) <<" " <<x << endl;
		}
		else {
			cout << "mymap has no "<<" " << x << endl;
		}
	}
}

#endif

int main() {
	unordered_map<string, double> mymap = {
		{"Burger",2.99},
		{"Fries",1.99},
		{"Soda",1.50} ,
	};
	mymap.insert({ "maze",2.55 });
	for (auto&e:mymap) {
		cout << e.first<<":"<<e.second << endl;
	}
	cout << endl;




	system("pause");
	return 0;
}

