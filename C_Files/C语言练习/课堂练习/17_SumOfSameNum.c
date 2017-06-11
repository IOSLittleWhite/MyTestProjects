/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include<stdio.h>

long count(int num, int n);
long sum(int num, int n);

int main(int argc, int *argv[])
{ 
	int num;
	int n;
	scanf("%d %d", &num, &n);
	printf("%ld\n",sum(num,n));
	return 0;//返回0
}

long sum(int num, int n)
{
	if(n == 1)
		return num;
	return sum(num, n-1) + count(num, n);
}

long count(int num, int n)
{
	long sum = 0;
	int i;
	for(i=0; i<n; i++)
		sum = sum * 10 + num;
	return sum;
}
