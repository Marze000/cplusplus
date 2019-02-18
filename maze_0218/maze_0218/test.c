#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{	
	//操作符重载=>把已经定义过的操作符进行重新定义，来完成更细致的运算功能
	//【.】【.*】【::】【?:】【sizeof】【typeid】不能被重载，其余都可以被重载      

	//int i = 010;//特别注意010为八进制的数，转换为10进制为8
	//int j = 10;
	//printf("%d.%d\n", ++i, j--);

	//FILE* fp;//声明fp为指针，用来指向FLIE类型的对象（文件）
	//long int n;//长整型
	//fp = fopen("wj.txt", "rb");//只读打开一个二进制的文件，只永许读数据
	//fseek(fp, 0, SEEK_END);//将文件指针fp定位到文件末尾
	//n = ftell(fp);//计算当前文件指针fp相对于文件头的距离
	//fclose(fp);//关闭fp指向的文件
	//printf("%ld", n);//打印的内容是：文件字节数


	//对于基类相同的两个指针变量之间：
	// ' < ' 比较指针所存地址的大小
	//‘ - ’计算相隔多少个这种类型
	//‘ = ’赋值，而加法没有任何意义


	//signed char a = 0xe0;
	//unsigned int b = a;
	//unsigned char c = a;
	//A:a>0 && c>0为真
	//B:a==c为真 
	//C:b的十六进制表示为：0xffffffe0   [对]
	//D：上面都不对

	//解析：将0xe0转换成二进制是1110 0000，因为0xe0的最高位是1，
	//所以作为有符号数的时候就是负数，作为无符号数的时候就是正数，
	//因此A选项是错的，同时B也是错误的。
	//负数的高位用1补齐，正数的高位用0补齐，
	//所以b（0xe0）的二进制表示形式是1111 1111 1111 1111 1111 1111 1110 0000，
	//十六进制的表示形式是0xffffffe0

	//char a[80] = "AB";
	//char b[80] = "LMNP";
	//int i = 0;
	//strcat(a, b);//a = ABLBMNP  b = LBMNP 
	//while (a[i] != '\0')
	//{
	//	++i;
	//	b[i] = a[i];
	//}
	//puts(b);

	//int a = 5;
	//int b = 2;
	//int c = 0;
	//c = (a > b ? a++ : b++, a + b);
	//	printf("%d", c);

	system("pause");
	return 0;
}