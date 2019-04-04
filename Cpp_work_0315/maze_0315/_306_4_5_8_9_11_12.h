#pragma once
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