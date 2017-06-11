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
		for(j=0; j<=i; j++)
			printf("%c",65+j);
		for(j=63+j; j>64; j--)
			printf("%c",j);
		putchar(10);
	}
	return 0;
}

/*
运行结果
 输入一个大写字母:G
 
       A
      ABA
     ABCBA
    ABCDCBA
   ABCDEDCBA
  ABCDEFEDCBA
 ABCDEFGFEDCBA
*/