#include <stdio.h>

double fun(int n)
{
	double pi = 2;
	for (int i = 1; i < n + 1; ++i) 
	{
		pi = pi* 4* i*i / ((2*i-1)*(2*i+1));
	}
	return pi;
}

int main()
{
	double a = fun(10);
	double b = fun(100);
	printf("%f %f\n",a,b);
	return 0;
}