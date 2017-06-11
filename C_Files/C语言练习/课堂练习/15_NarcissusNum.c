/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include<stdio.h>

int Cube(int n);

int main(int argc, int *argv[])
{
	int a = 100;
	while(a < 1000)
	{
		if(a == Cube(a/100) + Cube(a%10) + Cube(a%100/10))
			printf("%d\n",a);
		a++;
	}
	return 0;//返回0
}

int Cube( int n )
{
	return n*n*n;
}
