#include <stdio.h> 
#include <math.h>

double Sum(double n);

int main(void) 
{ 
	double num;
	printf("\n输入一个数，求他的阶乘结果的总位数\n");
	scanf("%lf", &num);
	printf("\n%lf的阶乘的结果的总位数为\n%d\n", num,(int)Sum(num));
	return 0;
}

double Sum(double n)
{
	if(n == 1)
		return 1;
	return Sum(n-1) + log10(n);
}
