#include <iostream>
#include <stdlib.h>

using namespace std;
class Student
{
public:
	Student(int n, float s) :num(n), score(s) {}
	void change(int n, float s)
	{
		num = n;
		score = s;
	}
	void display()
	{
		cout << num << " " << score << endl;
	}
private:
	int num;
	float score;
};

void fun(Student &ps)
{
	ps.display();
	ps.change(101, 80.5);
	ps.display();
}

int main()
{
	//修改第6题的程序，改写fun函数；
	Student stud(101, 78.5);
	fun(stud);


	system("pause");
	return 0;
}