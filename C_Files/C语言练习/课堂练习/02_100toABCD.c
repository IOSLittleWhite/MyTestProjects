#include<stdio.h>

int main()
{
	int score;
	scanf("%d",&score);
	switch(score / 10)
	{
		case 6:printf("D\n");break;
		case 7:printf("C\n");break;
		case 8:printf("B\n");break;
		case 9:printf("A\n");break;
		default :break;
	}
	return 0;//返回0
}
