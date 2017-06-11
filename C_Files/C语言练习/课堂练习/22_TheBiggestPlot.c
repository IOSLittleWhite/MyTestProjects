/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include<stdio.h>

int main(int argc, int *argv[])
{
	int n; 
	int i,j,k;
	int a[3] = {0};
	long plot = 0;
	long max = 0;

	printf("\n\t\t\t输入一个数n，找出和为n且乘积最大的三个整数\n");

	scanf("%d",&n);

	printf("\n所有的组合为\n");
	for(i=0; i<=n; i++)
	{
		for(j=0; j<=n; j++)
		{
			for(k=0; k<=n; k++)
			{
				if(i + j + k == n)
				{
					plot = i*j*k;
					printf("%d=%d+%d+%d\t %ld=%d*%d*%d\n",n,i,j,k,plot,i,j,k);
					if(plot >= max)
					{
						max = plot;
						a[0] = i;
						a[1] = j;
						a[2] = k;
					}
				}
			}
		}
	}
	printf("\n其中乘积最大的为%ld\n",max);
	printf("此时三个数分别为%d %d %d\n",a[0],a[1],a[2]);
	return 0;//返回0
}
