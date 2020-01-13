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

#include <map>

class Solution {
public:
	string frequencySort(string s) {
		for (auto&e : s) {
			mp[e]++;
		}
		for (auto p = mp.begin(); p != mp.end(); p++) {
			multi.insert(make_pair(p->second, p->first));
		}
		int n = s.size() - 1;
		for (auto p = multi.begin(); p != multi.end(); p++) {
			int a = p->first;
			char c = p->second;
			while (a-- > 0) {
				s[n--] = c;
			}
		}
		return s;
	}
private:
	map<char, int>mp;
	multimap<int, char>multi;
};

#include <unordered_map>
int main() {
	string s = "trreddeeaattttaa";
	map<char, int>mp;
	multimap<int, char>multi;
	for (auto&e : s) {
		mp[e] += 1;
	}

	for (auto p = mp.begin(); p != mp.end(); ++p) {
		multi.insert(make_pair(p->second,p->first));
	}
	
	for (auto&e : mp) {
		cout << e.first << " " << e.second << endl;
	}

	cout << endl;

	for (auto&e : multi) {
		cout << e.first << " " << e.second << endl;
	}


	/*for (auto&e : mp) {
		cout << e.first <<" " <<e.second << endl;

		a 4
		d 2
		e 3
		r 2
		t 5
	*/
	cout << endl;
	//unordered_map<string, double> mymap = {
	//	{"Burger",2.99},
	//	{"Fries",1.99},
	//	{"Soda",1.50} ,
	//};
	//mymap.insert({ "maze",2.55 });
	//for (auto&e:mymap) {
	//	cout << e.first<<":"<<e.second << endl;
	//}
	//cout << endl;




	system("pause");
	return 0;
}

