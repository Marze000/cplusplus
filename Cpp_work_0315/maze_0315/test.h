#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Student
{
	string name[100];//名字
	float score[100];//分数
	int num[100];//学号
}	stu;


void print_score_low()//打印信息
{
	cout << "下列是成绩不合格的学生信息" << endl;
	for (int i = 0; i < 10; ++i)
	{
		if (stu.score[i] < 60)
		{
			cout << "姓名:" << stu.name[i] << "分数:"
				<< stu.score[i] << "学号:" << stu.num[i] << endl;
		}
	}
}

void get_information()//获取信息
{

	for (int i = 0; i < 10; ++i)
	{
		cout << "请输入第" << i + 1 << "个学生的姓名,学号,成绩" << endl;
		cin >> stu.name[i] >> stu.num[i] >> stu.score[i];
	}
}

