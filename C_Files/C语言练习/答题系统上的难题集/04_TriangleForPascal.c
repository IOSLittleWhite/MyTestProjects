#include	<stdio.h>
int main()
{
	int a[100][100];
	int i,j;
    int num;
    
	printf("\n输入杨辉三角的边长:\n");
    scanf("%d",&num);
    
	for(i=0; i<num; i++)
	{
        a[i][0] = 1;
        a[i][i] = 1;
    }
	for(i=2; i<num; i++)
	{
		for(j=1; j<i; j++)
			a[i][j]=a[i-1][j]+a[i-1][j-1];
	}
    
    printf("\n得到杨辉三角如下:\n");
	for(i=0; i<num; i++)
	{
		for(j=0; j<=i; j++)
		printf("%-5d",a[i][j]);
		printf("\n");
	}
	return 0;
}

/*
运行结果
 输入杨辉三角的边长:
 5
 
 得到三角如下:
 1
 1    1
 1    2    1
 1    3    3    1
 1    4    6    4    1
*/