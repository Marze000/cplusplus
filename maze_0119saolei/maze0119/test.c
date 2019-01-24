#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 9
#define COL 9
#define MINE_COUNT 10
//1.地雷布局地图，0表示不是地雷，1表示是地雷
//  玩家布局地图，‘ ’表示未翻开，数字表示已翻开。
//2.初始化
//3.打印玩家地图，并提示玩家输入坐标，
//  校验玩家的输入数据是否合理，
//4.如果踩雷，游戏结束。
//5.如果没踩雷，并且格子是地图上的最后一个位置，扫雷成功。  
//6.如果未踩雷，把地图位置设为展开，并更新位置


int Menu()
{
	printf("*************\n");
	printf("1.开始游戏\n");
	printf("2.结束游戏\n");
	printf("3.游戏帮助\n");
	printf("*************\n");
	printf("请输入你的选择：\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Init(char show_map[ROW + 2][COL + 2],
		  char mine_map[ROW + 2][COL + 2])
{
	//1.把show_map初始化空格
	for (int row = 0; row < ROW+2; ++row)
	{
		for (int col = 0; col < COL+2; ++col)
		{
			show_map[row][col] = ' ';
		}
	}
	//2.把mine_map初始化‘0’
	for (int row = 0; row < ROW+2; ++row)
	{
		for (int col = 0; col < COL+2; ++col)
		{
			mine_map[row][col] = '0';
		}
	}
	//3.把 mine_map哪些位置是地雷，排布
	int mine_count = MINE_COUNT;//10
	while (mine_count > 0)
	{
		//随机数[1,9]
		int row = rand() % ROW + 1;
		int col = rand() % COL + 1;
		if (mine_map[row][col] == '1')//保证有十颗雷被排布好
		{	//如果没有if，则有极小的可能性雷数小于10		
			continue;
		}
		mine_map[row][col] = '1';
		--mine_count;
	}
}

void DisplayMap(char map[ROW + 2][COL + 2])//打印地图，
{
	//打印左上角的空格
	printf("   ");

	//打印列的坐标
	for (int i = 1; i <= ROW; ++i)
	{
		printf("%d  ", i);
	}
	printf("\n");

	//打印上边框
	for (int i = 1; i <= ROW; ++i)
	{
		printf("----");
	}
	printf("\n");

	//按行打印地图内容
	for (int row = 1; row <= ROW; ++row)
	{
		printf("%d|", row);		
		for (int col = 1; col <= COL; ++col)
		{
			printf("%c ", map[row][col]);
			printf("|", col);
			
		}
		printf("\n");
		for (int col = 1; col <= COL; ++col)
		{
			printf("---");
		}
		printf("\n");
	}
}

void UpdateShowMap(char show_map[ROW + 2][COL + 2], int row,
				   char mine_map[ROW + 2][COL + 2], int col)
{
	int count = 0;
	if (mine_map[row - 1][col - 1] == '1')
	{
		++count;
	}
	if (mine_map[row - 1][col] == '1')
	{
		++count;
	}
	if (mine_map[row - 1][col + 1] == '1')
	{
		++count;
	}
	if (mine_map[row][col - 1] == '1')
	{
		++count;
	}
	if (mine_map[row][col + 1] == '1')
	{
		++count;
	}
	if (mine_map[row + 1][col - 1] == '1')
	{
		++count;
	}
	if (mine_map[row + 1][col] == '1')
	{
		++count;
	}
	if (mine_map[row +1][col + 1] == '1')
	{
		++count;
	}
	show_map[row][col] = '0' + count;
	//加上‘0’就说明该变量的类型被改成char型
	//如果不加，则count是int型，不符合函数类型。	

}

void Game()
{
	char show_map[ROW + 2][COL + 2];
	char mine_map[ROW + 2][COL + 2];
	Init(show_map, mine_map);//传参的时候可以不用取地址。数组可以隐式转换为指针。
	
	int safe_blank_count = 0;
	while (1)
	{
		DisplayMap(show_map);//打印地图
		int row = 0;
		int col = 0;
		printf("输入坐标：\n");
		scanf("%d %d", &row, &col);

		if (row < 1 || row > ROW || col<1 || col>COL)
		{
			printf("您输入的坐标非法，请重新输入：\n");
			continue;
		}
		//验证是否踩到地雷
		if (mine_map[row][col] == '1')
		{
			printf("扫雷失败\n");
			break;
		}
		//验证是否扫雷成功
		++safe_blank_count;
		if (safe_blank_count == ROW * COL - MINE_COUNT)
		{
			printf("扫雷成功\n");
			return;
		}
		//更新地图的状态
		UpdateShowMap(show_map ,row, mine_map,col);
		system("cls");
	}
	DisplayMap(mine_map);
}

int main()
{
	srand((unsigned int)time(0));
	while (1)
	{
		int choice = Menu();
		if (choice == 2)
		{
			break;
		}
		else if (choice == 1)
		{
			Game();
		}
		else if (choice == 3)
		{
			printf("共有十个雷，全部扫完即过关；若踩中雷则游戏失败。\n");
			printf("小技巧：当出现数字则表示周围八个格或五个格（边）有几颗雷。\n");
			printf("按数字“1”键则返回主菜单\n");
			int a = 0;
			scanf("%d", &a);
		}
		else
		{
			printf("你的输入非法，请重新输入\n");
		}
	}

	system("pause");
	return 0;
}