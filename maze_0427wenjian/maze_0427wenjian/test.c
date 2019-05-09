#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{

	FILE* fp = fopen("d:/tex.txt", "wb");
	fwrite("aa", 1, 4, fp);
	fclose(fp);
	fp = NULL;
	system("pause");
	return 0;
}

//int main()
//{
//
//	//第一个参数是一个路径（绝对和相对都行）
//	//第二个参数是打开方式，r只读  w只写  a追加
//	//文件指针也可以叫 句柄
//	FILE* fp = fopen("d:/text.txt","w");
//	//strerror
//	if (fp == NULL)
//	{
//		printf("文件打开失败！%s\n",strerror(errno));
//		system("pause");
//		return 1;
//	}
//	//把数据从内存中写到磁盘中
//	//char buf[1024] = "maze";
//	//fwrite(buf,1,strlen(buf),fp);
//
//	fprintf(fp, "a=%d\n", 10);
//	
//	//文件的随机读写
//	//fseek(fp,);
//
//	////fread把磁盘读到内存中
//	//char buf[1024] = { 0 };
//	//fread(buf,1,4,fp);
//	//printf("%s\n", buf);
//	//如果打开文件，忘记关闭，会咋办？
//	//一个文件打开的数量是有限的，会造成句柄泄露（资源泄露/文件描述符泄露）
//	fclose(fp);
//
//	system("pause");
//	return 0;
//}

//程序文件
//数据文件
//文件名

//C:\Users\lenovo\Desktop\C语言进阶
//绝对路径

//.txt  .c   
//文本文件   二进制文件

//缓冲区：

//10000
//当成字符串写入文件需要5个字节（文本文件），
//当成整数，是二进制文件需要写入2个字节
