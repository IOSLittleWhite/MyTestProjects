#include <stdio.h>
int main()
{
	char input;
	int i,j;
	printf("\n输入一个大写字母:");
	scanf("%c",&input);
    putchar(10);
	for(i=0; i<input-64; i++)
	{
		for(j=0; j<input-65-i; j++)
    		printf(" ");
		for(j=input-i; j<=input; j++)
    		printf("%c",j);
		for(j=1; j<i+1; j++)y
		    printf("%c",input - j);
		putchar(10);
	}
	return 0; 
}

/*
运行结果
输入一个大写字母:F
 
     F
    EFE
   DEFED
  CDEFEDC
 BCDEFEDCB
ABCDEFEDCBA
*/