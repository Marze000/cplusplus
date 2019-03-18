#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

int main()
{
	member m;
	Init(&m);

	typedef void(*T)(member *m);
	T menu[] = { Insert,Delete,Display,Find,Modify,Clear};
	int choice = 0;
	Menu();
	printf("\n请输入接下来要操做的选项!\n");
	scanf("%d", &choice);

	while (1)
	{
		if (choice == 0)
		{
			printf("再见！\n");
			system("pause");
			break;
		}
		menu[choice - 1](&m);
		printf("\n请输入接下来要操做的选项!\n");
		scanf("%d", &choice);
	}

	system("pasuse");
	return 0;
}

void Menu()
{
	printf("************\n");
	printf("1.添加联系人\n");
	printf("2.删除联系人\n");
	printf("3.显示联系人\n");
	printf("4.查找联系人\n");
	printf("5.修改联系人\n");
	printf("6.清空联系人\n");
	printf("0.退出\n");
	printf("************\n");
}

void Init(member *m)//初始化联系人
{
	if (m == NULL)
	{
		return;
	}
	m->mem_index = 1;
}

void Insert(member* m)//添加联系人
{
	if (m == NULL)
	{
		return;
	}

	infor *p = &(m->mem[m->mem_index]);
	printf("亲,输入新的联系人的姓名\n");
	scanf("%s", p->name);

	printf("输入联系电话号码\n");
	scanf("%s", p->num);

	++(m->mem_index);//下标加1
	printf("添加成功！\n");
	Menu();
}

void Delete(member *m)//删除联系人
{
	if (m == NULL)
	{
		return;
	}
	int serial_number = 1;

	printf("请输入要删除联系人的编号？");
	scanf("%d", &serial_number);
	if ((serial_number < 0) || (serial_number >= m->mem_index))
	{
		printf("输入有误！");
		return;
	}
	if(serial_number== m->mem_index-1)
	{
		--m->mem_index;
		printf("删除成功！");
		return;
	}
	m->mem[serial_number] = m->mem[m->mem_index - 1];
	--m->mem_index;
	printf("删除联系人成功！");
}

void Display(member *m)//显示联系人
{
	if(m==NULL)
	{
		return;
	}
	for (int i = 1; i < m->mem_index; ++i)
	{
		printf("%d.姓名：%s\t电话：%s\n",
			i, m ->mem[i].name, m->mem[i].num);
	}
}

void Find(member *m)//查找联系人
{
	if (m == NULL)
	{
		return;
	}

	int index = 0;
	while (1)
	{
		printf("请输入你要查找的联系人的编号：\n");
		scanf("%d", &index);
		if (index<0 || index>m->mem_index - 1)
		{
			printf("输入有误！\n请重新输入：\n");
			continue;
		}
		break;
	}
	printf("%d.姓名：%s\t电话：%s\n", 
		index, m->mem[index].name, m->mem[index].num);
	printf("查找成功！\n");
}

void Modify(member *m)//修改联系人
{
	if (m == NULL)
	{
		return;
	}
	int index;
	int type;

	printf("请输入你要修改的联系人的编号：");
	scanf("%d", &index);
	if (index < 0 || index >( m->mem_index - 1))
	{
		printf("输入有误!");
		return;
	}
	infor *p = &m->mem[index];
	printf("1.姓名\n");
	printf("2.电话\n");
	printf("请输入你要修改的类型");
	scanf("%d", &type);
	if (type < 1 || type>2)
	{
		printf("输入有误！");
		return;
	}
	if (type == 1)
	{
		char new_name[256] = { 0 };
		printf("亲输入联系人的姓名：");
		scanf("%s", new_name);
		strcpy(p->name, new_name);
	}
	else
	{
		char new_num[256] = { 0 };
		printf("请输入要修改的联系人的电话：");
		scanf("%s", new_num);
		strcpy(p->num, new_num);
	}
	printf("修改成功！");
}

void Clear(member *m)//清空通讯录
{
	if (m == NULL)
	{
		return;
	}
	m->mem_index = 0;
	printf("通讯录已经清空！");
}
