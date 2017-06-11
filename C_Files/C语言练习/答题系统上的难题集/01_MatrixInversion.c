#include <stdio.h>

int main()
{
    int num[4][4];
	int i,j;
	int temp;
    printf("输入12个数据，以空格区分\n");
	for(i=0; i<3; i++)
	{
	    for(j=0; j<4; j++)
        	scanf("%d",&num[i][j]);
	}
    putchar(10);
    
    printf("原矩阵输出为\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
			printf("%-3d",num[i][j]);
 	     putchar(10);
	}
    for(i=0; i<4; i++)
	{
		for(j=i; j<4; j++)
		{
        	temp = num[i][j];
            num[i][j] = num[j][i];
            num[j][i] = temp;
        }
	}
	putchar(10);
    printf("变换后矩阵为：\n");
    for(i=0; i<4; i++)
	{
    	for(j=0; j<3; j++)
        	printf("%-3d",num[i][j]);
		putchar(10);
	}
	return 0;
}

/***********************************************
运行结果：
 输入12个数据，以空格区分
 23 78 1 2 3 4 5 6 7 8 9 12
 
 原矩阵输出为
 23 78 1  2
 3  4  5  6
 7  8  9  12
 
 变换后矩阵为：
 23 3  7
 78 4  8
 1  5  9
 2  6  12
***********************************************/
