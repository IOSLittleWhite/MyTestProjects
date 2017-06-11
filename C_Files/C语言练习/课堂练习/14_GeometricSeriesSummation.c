/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include<stdio.h>

long Sum(int n, int q);
int ppp(int q, int n);

int main()
{
    long sum;
	int n;
	int q;
	printf("\n\t\t\t等比数列求和\n输入元素个数n和公比q，空格区分\n");
	scanf("%d %d",&n,&q);
	sum = Sum(n,q);
	printf("\n等比数列和为：\n");
	printf("%ld\n",sum);
	return 0;//返回0
}

long Sum(int n, int q)
{
	if(n == 0)
	{
		ppp(q,n);
		printf("\n");
		return 1;
	}
	return Sum(n-1,q) + ppp(q,n);
}

int ppp(int q, int n)
{
	int i;
	int sum = 1;
	printf("第0项 = %d\n",sum);
	if(n)
	{
		for(i=1; i<=n; i++)
		{
			sum *= q;
			printf("第%d项 = %d\n",i,sum);
		}
		putchar(10);
		return sum;
	}
	else
		return 1;
}
