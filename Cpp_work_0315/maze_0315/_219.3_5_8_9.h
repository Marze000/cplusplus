#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include<iomanip>
//编写一个函数print,打印一个学生的成绩数组,
//该数组中有5个学生的数据,每个学生的数据包括
//num(学号)		name(姓名)		score[3](3们课的成绩)
//用主函数输入这些数据,并用print输出这些数据
const int n = 5;
struct student
{
	int num;
	int score[4];
	string name;
}stu[n];

void information()//收集信息
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的成绩：" << endl;
		cout << "NO.:";
		cin >> stu[i].num;
		cout << "name:";
		cin >> stu[i].name;
		for (j = 0; j < 3; j++)
		{
			cout << "score " << j + 1 << ":";
			cin >> stu[i].score[j];
		}
		cout << endl;
	}
}

void print()//打印学生信息
{
	student stu[n];
	int i, j;
	cout << "NO.  name  score1  score2  score3" << endl;
	for (i = 0; i < n; i++)
	{
		cout << stu[i].num << "    " << setw(10) << stu[i].name << "       ";
		for (j = 0; j < 3; j++)
		{
			cout << setw(3) << stu[i].score[j] << "      ";
		}
		cout << endl;
	}
}

//======================================================================
//219页的6,7,8,9,10题

//creat函数创建结点
typedef struct Node 
{
	int value;//值
	struct Node* next;
}	Node;

void creat()//创建链表结点
{
	Node* a1 = (Node*)malloc(sizeof(int));
	Node* a2 = (Node*)malloc(sizeof(int));
	Node* a3 = (Node*)malloc(sizeof(int));
	Node* a4 = (Node*)malloc(sizeof(int));
	a1->next = a2, a1->value = 1;
	a2->next = a3; a2->value = 1;
	a3->next = a4; a3->value = 1;
	a4->next = NULL;
}

void print_Node(Node*a1)
{
	while (a1 != NULL)
	{
		a1 = a1->next;
		cout << a1->value << endl;
	}
}

void del(Node* a1,Node* a3)//删除a3所对应的结点
{
	Node* p = a1;
	while (a1->next->value != a3->value)
	{
		a1 = a1->next;
	}
	a1->next = a1->next->next;
	free(a3);
}

void insert(Node* a1, int n)//尾插插入一个结点
{
	Node* m = (Node*)malloc(sizeof(int));
	m->value = n;
	while (a1->next != NULL)
	{
		a1 = a1->next;
	}
	a1->next = m;
	m->next = NULL;
}






