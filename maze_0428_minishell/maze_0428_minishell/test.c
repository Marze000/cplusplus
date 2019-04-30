#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define MAX_CMD 1024
char command[MAX_CMD];

int do_face()
{
	memset(command, 0x00, MAX_CMD);
	//memset：作用是在一段内存块中填充某个给定的值，
	//		  它是对较大的结构体或数组进行清零操作的一种最快方法 [1] 
	//memset()函数原型是extern void *memset(void *buffer, int c, int count)
	//buffer：为指针或是数组, c：是赋给buffer的值, count：是buffer的长度.

	printf("minishell$ ");
	fflush(stdout);//刷新标准输出缓冲区，把缓冲区里的东西打印到标准设备上

	if (scanf("%[^\n]%*c", command) == 0)//从缓冲区取数据直到遇到\n，把\n取出来丢弃
	{
		//如果等于0解析失败
		getchar();	//获取换行符，计算机只能接收一个字符
		return -1;
	}
	//scanf(%[^\n]%*c)表示读入一行字符串
	return 0;
}

char **do_parse(char *buff)
{
	int argc = 0;
	static char *argv[32];
	char *ptr = buff;
	while (*ptr != '\0')//在没有越界的情况下
	{
		if (!isspace(*ptr))//如果ptr第一个不是空白字符的话
		{
			argv[argc++] = ptr;//首先把ptr赋值给argv[argc] ；argc++;
			
			//
			while ((!isspace(*ptr)) && (*ptr) != '\0')
			{
				ptr++;
			}
		}

		else
		{
			while (isspace(*ptr))
			{
				*ptr = '\0';
				ptr++;
			}
		}
	}

	argv[argc] = NULL;
	return argv;
}

int do_exec(char *buff)
{
	char **argv = { NULL };
	int pid = fork();
	
	//	在继续学习新知识前，我们来思考函数和进程之间的相似性
	//	exec / exit就像call / return
	//	一个C程序有很多函数组成。一个函数可以调用另外一个函数，同时传递给它一些参数。被调用的函数执行一定的
	//	操作，然后返回一个值。每个函数都有他的局部变量，不同的函数通过call / return系统进行通信。
	//	这种通过参数和返回值在拥有私有数据的函数间通信的模式是结构化程序设计的基础。Linux鼓励将这种应用于程
	//	序之内的模式扩展到程序之间。如下图
	//	一个C程序可以fork / exec另一个程序，并传给它一些参数。这个被调用的程序执行一定的操作，然后通过exit(n)来
	//	返回值。调用它的进程可以通过wait（&ret）来获取exit的返回值。
		if (pid == 0) {
			argv = do_parse(buff);
			if (argv[0] == NULL) {
				exit(-1);
			}
			execvp(argv[0], argv);
		}
		else {
			waitpid(pid, NULL, 0);
		}
	return 0;
}

int main(int argc, char *argv[])
{
	while (1) {
		if (do_face() < 0)
			continue;
		do_exec(command);
	}
	return 0;
}