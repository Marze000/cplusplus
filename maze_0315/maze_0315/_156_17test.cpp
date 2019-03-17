#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
using namespace std;

//struct Student 
//{
//	string name[10];
//	float score[2];
//	int num;
//}stu;

//
//void score_low()
//{
//	cout << "下列是成绩不合格的学生信息"<<endl;
//	for (int i = 0; i < 3; ++i)
//	{
//		if (score[i] < 60)
//		{
//			cout << stu.name[i] << " "<<stu.score<< " "<< stu.num << endl;
//		}
//	}
//}

int main()
{
	//string name[10];
	//int num[10];
	//float score[10];
	//for (int i = 0; i < 10; ++i)
	//{
	//	cout  <<"输入第"<<i+1<<"个学生的姓名、学号、成绩:" <<endl;
	//	cin >> name[i] >> num[i] >> score[i] ;
	//}
	//cout << "以下是成绩不合格的学生信息：" << endl;
	//for (int j = 0; j < 10; ++j)
	//{
	//	if (score[j] < 60)
	//	{
	//		cout << "姓名:"<<name[j] << setw(8) << "学号：" << num[j] << setw(8) << "成绩：" << score[j] << endl;
	//	}
	//}
	int i = 0;
	cout << setw(-18) << "maze" <<i + 1 << setw(-14) << endl;
	cout << setw(-18) << "mafdsgze" << i + 2 << setw(-14) << endl;
	cout << setw(-18) << "mafssdfsfze" << i + 3 << setw(-14)<< endl;
	system("pause");
	return 0;
}