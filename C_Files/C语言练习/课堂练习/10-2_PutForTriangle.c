/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include<stdio.h>

int main(int argc, int *argv[])
{
	int n;
	int line = 0;
	int qian = 0;
	int hou = 1;
	printf("\n输入打印行数\n");
	scanf("%d",&n);
	for(; line<n; )
	{
		if(line != n-1)
		{
			if(hou == qian + 1 )
			{
				qian = hou;
				hou = 0;
				printf("*\n");
				line ++;
			}
			if(hou == 0)
			{
				printf("*");
				hou++;
			}
			else
				printf(" ");
		}
		else
		{
			printf("*");
			if(hou > qian)
				line ++;
		}
		hou ++;
	}
	putchar(10);
	return 0;//返回0
}
