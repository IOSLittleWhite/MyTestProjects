#include <stdio.h>
int main()
{
	char input;
	int i,j;
	printf("\n输入一个大写字母:\n");
	scanf("%c",&input);
	for(i=0; i<input-64; i++)
	{
		for(j=0; j<input-65-i; j++)
    		printf(" ");
		for(j=input-i; j<=input; j++)
    		printf("%c",j);
		for(j=1; j<i+1; j++)
		    printf("%c",input - j);
		putchar(10);
	}
	return 0; 
}
