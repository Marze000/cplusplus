//#include <iostream>
//#include <stdlib.h>
//#include <string>
//
//using namespace std;
//
//struct Student 
//{
//	string name[100];//名字
//	float score[100];//分数
//	int num[100];//学号
//}	stu;
//
//
//void print_score_low()//打印信息
//{
//	cout << "下列是成绩不合格的学生信息"<<endl;
//	for (int i = 0; i < 10; ++i)
//	{
//		if (stu.score[i] < 60)
//		{
//			cout << "姓名:"<<stu.name[i] <<"分数:"
//				<<stu.score[i]<<"学号:"<< stu.num[i] << endl;
//		}
//	}
//}
//
//void get_information()//获取信息
//{
//
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << "请输入第"<<i+1<<"个学生的姓名,学号,成绩" <<endl;
//		cin >> stu.name[i] >> stu.num[i] >> stu.score[i];
//	}
//}
//
//int main()
//{
//	//输入成绩
//	get_information();
//
//	//打印成绩
//	print_score_low();
//
//
//
//
////==============================================
//	//打印成绩不合格的学生
//
//	//string name[10];
//	//int num[10];
//	//float score[10];
//	//for (int i = 0; i < 10; ++i)
//	//{
//	//	cout  <<"输入第"<<i+1<<"个学生的姓名、学号、成绩:" <<endl;
//	//	cin >> name[i] >> num[i] >> score[i] ;
//	//}
//	//cout << "以下是成绩不合格的学生信息：" << endl;
//	//for (int j = 0; j < 10; ++j)
//	//{
//	//	if (score[j] < 60)
//	//	{
//	//		cout << "姓名:"<<name[j]  << "学号："
//	//			<< num[j]  << "成绩：" << score[j] << endl;
//	//	}
//	//}
//	//int i = 0;
//	//cout << setw(-18) << "maze" <<i + 1 << setw(-14) << endl;
//	//cout << setw(-18) << "mafdsgze" << i + 2 << setw(-14) << endl;
//	//cout << setw(-18) << "mafssdfsfze" << i + 3 << setw(-14)<< endl;
//	system("pause");
//	return 0;
//}