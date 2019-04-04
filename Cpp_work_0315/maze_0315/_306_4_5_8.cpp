#include <stdlib.h>
#include<iostream>
using namespace std;

class Student
{
public:
	void input();
	void display();
private:
	int num;
	float score;
};

void Student::input()
{
	cin >> num >> score;
}

void Student::display()
{
	cout << num << ' ' << score << endl;
}

int main()
{
	Student stu[5], *p;
	int i;
	for (i = 0; i < 5; ++i)
	{
		cout << "please" << i + 1 << endl;
		stu[i].input();
	}
	for (p = stu; p < stu + 5; p += 2)
	{
		p->display();
		cout << endl;
	}

	system("pause");
	return 0;
}