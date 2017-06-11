#include<stdio.h>

int main()
{
	int n,m;
	int i;
	long sum = 1;
	printf("\n输入两个数据，以空格区分\n");
	scanf("%d %d",&n,&m);
	for(i=0; i<m; i++)
		sum *= n;
	printf("\n%d^%d = %ld\n",n,m,sum);
	return 0;//返回0
}
