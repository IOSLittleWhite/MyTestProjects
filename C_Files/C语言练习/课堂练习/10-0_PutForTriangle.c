#include<stdio.h>

int main()
{
	char i,j,k;
	int line;
	putchar(10);
	printf("输入三角输出的边长,注意应不大于26\n");
	scanf("%d",&line);
	if(line > 26)
		line = 26;
	printf("三角形式输出为：\n");
	for(i=0; i<line; i++)
	{
		for(j=65; j<65+line-i; j++)
			printf("%c",j);
		for(j=0; j<i*2; j++)
			printf(" ");
		for(j=64+line-i; j>64; j--)
			printf("%c",j);
		printf("\n");
	}
	for(i=2; i<=line; i++)
    {   
        for(j=65; j<65+i; j++)
            printf("%c",j);
		for(j=0; j<(line-i)*2; j++)
            printf(" ");
		for(j=64+i; j>64; j--)
            printf("%c",j);
        printf("\n");
    }   
	putchar(10);
	return 0;//返回0
}
