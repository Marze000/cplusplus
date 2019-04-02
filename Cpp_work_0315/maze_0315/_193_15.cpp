//#include <iostream>
//#include <stdlib.h>
//#include <string>
//using namespace std;
//
////有一个班,4个学生,5门课,求:
//struct student

//{
//	string name[100];//名字
//	float score1[100];//分数;
//	int num[100];//学号
//}	S;
//
//struct xiaobiao
//{
//	int i;		//人
//}	course;
//
////1.第一门课的平均分?
//void average(float students_score[4][5])
//{
//	float average = 0;
//	float sum = 0;
//	float s = 0;
//	int i = 0;
//	for (int j = 0; j < 5; ++j)
//	{
//		s = students_score[i][j];
//		sum = s + sum;
//	}
//	average = sum / 5;
//	cout << "第一门语言的平均成绩为" << average << endl;
//}
//
////2.找出两门以上课程不及格的同学,
////	输出他们的学号以及全部课程成绩和平均成绩
//void sucess_2_bujige(float students_score[4][5])
//{
//	int j = 0;
//	int i = 0;
//	for (i = 0; i < 4; ++i)
//	{
//		int count = 0;
//		for (int j = 0; j < 5; ++j)
//		{
//			if (students_score[i][j] < 60)
//			{
//				++count;
//			}
//		}
//		if (count > 2)
//		{
//			float s = 0;
//			float sum = 0;
//			cout << "第" << i+1 << "个" << "同学有" << count
//				<< "门课程不及格" << endl;
//			cout << "姓名:"<<" " << S.name[i] << "学号：" << S.num[i]<<"  " ;
//			for (int l = 0; l < 5; ++l)
//			{
//				s = students_score[i][l];
//				sum = sum + s;
//				cout<<" "<<students_score[i][l]<< " ";
//			}
//			cout << "平均成绩是：" << sum/5 << endl;
//		}
//	}
//}
//
////3.找出平均成绩在90分以上或全部课程在85分以上的同学
//void excllent90_or85(float students_score[4][5])
//{
//	float sum = 0;
//	int i = 0;
//	int j = 0;
//	float s = 0;
//	float average = 0;
//	for (i = 0; i < 4; ++i)
//	{
//		int count = 0;
//		for (j = 0; j < 5; ++j)
//		{
//			if (students_score[i][j]>85)
//			{
//				++count;
//			}
//			s = students_score[i][j] ;
//			sum = s + sum;
//		}
//		average = sum / 5;
//		if (average > 90 &&  count == 5)
//		{
//			cout<<S.name[i]<<"学生平均成绩在90分以上或每门课在85以上"<<endl;
//		}
//	}
//}
//
//void all_students_info(float students_score[4][5])
//{
//	for (int i = 0; i < 4; ++i)
//	{
//		cout << "请输入第" << i + 1 << "个学生的姓名,学号" << endl;
//		cin >> S.name[i] >> S.num[i];
//	}
//	for (int j = 0; j < 4; ++j)
//	{
//		cout << "第" << j + 1 << "个学生的姓名是:"
//			<< S.name[j]<<"   "<< "学号是:" << S.num[j]<<"  " ;
//		
//		for (int l = 0; l < 5; ++l)
//		{
//			cout << "  " << students_score[j][l] << "  ";
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	//先对成绩进行初始化
//	float students_score[4][5] = 
//	{
//		{40,30,60,70,80},
//		{50,20,10,80,90},
//		{60,70,80,90,99},
//		{86,87,88,89,95}
//	};
//
//	all_students_info(students_score);
//	cout << endl;
//
//	//1.第一门课的平均分?
//	average(students_score);
//	cout << endl;
//	//2.找出两门以上课程不及格的同学,
//	//  输出他们的学号以及全部课程成绩和平均成绩
//	sucess_2_bujige(students_score);
//	cout << endl;
//	//3.找出平均成绩在90分以上或全部课程在85分以上的同学
//	excllent90_or85(students_score);
//
//	system("pause");
//	return 0;
//}