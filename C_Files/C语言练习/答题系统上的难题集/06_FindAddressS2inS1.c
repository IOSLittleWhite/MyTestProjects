#include <stdio.h>
#include <string.h>

int main()
{
	char s1[100];
	char s2[100];
	char *p = s1;
	char *q = s1;
	printf("\n输入两个字符串\n");
	scanf("%[^\n] %[^\n]",s1,s2);
    printf("\n%s在%s中出现的位置有：\n",s2,s1);
	while(q != NULL)
	{
		q = strstr(p,s2);
		if(q != NULL)
		{
			printf("%d ",(int)(q-s1+1));
			p = q+1;
		}
		else if(p == s1)
		printf("0");
	}
 	putchar(10);
	return 0;
}
/*
运行结果
 输入两个字符串
 abheioab haehabiue
 ab
 
 ab在abheioab haehabiue中出现的位置有：
 1 7 14
*/