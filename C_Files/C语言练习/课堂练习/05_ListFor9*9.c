#include<stdio.h>

int main()
{
	int i,j;
    printf("\n\n\t\t\t9九九乘法表");
	for(i=1; i<10; i++)
	{
		for(j=1; j<=i; j++)
			printf("%dX%d = %-2d  ", j,i,i*j);
		putchar(10);
	}
	return 0;//返回0
}
