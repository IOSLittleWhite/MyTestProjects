/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include<stdio.h>

unsigned long Factorial(int n);
unsigned long Sum( int n);

int main(int argc, int *argv[])
{ 
	int n; 
	scanf("%d",&n);
	printf("累乘相加的和为\n%lu\n",Sum(n));
	return 0;//返回0
}

unsigned long Sum(int n)
{
	if(n == 1)
		return 1;
	return Sum(n-1) + Factorial(n);
}

unsigned long Factorial(int n)
{
	int i;
	unsigned long sum = 1;
	for(i=1; i<=n; i++)
		sum *= i;
	return sum;
}
