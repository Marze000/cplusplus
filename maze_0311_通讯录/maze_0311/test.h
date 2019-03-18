#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <assert.h>

typedef struct infor//通讯录个人信息												
{
	char name[256];
	char num[256];
}infor;

typedef struct
{
	infor mem[50];//通讯录人数
	int mem_index;	//通讯录索引--下标
}member;

void Menu();//菜单
void Init(member *m);//初始化通讯录
void Insert(member *m);//添加联系人
void Delete(member *m);//删除联系人
void Display(member *m);//显示联系人
void Find(member *m);//查找联系人
void Modify(member *m);//修改联系人
void Clear(member *m);//清空联系人
