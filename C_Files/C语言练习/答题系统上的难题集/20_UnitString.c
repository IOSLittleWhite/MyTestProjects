#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *p[10] = {NULL};
	char s[15] = {0};
	char out[100] = {0};
	int i;
	int num;
	printf("\n输入不多于是个字符串，没串字符不多于14个,串间用空格隔开\n");
	for(i=0; i<10; i++)
	{
		p[i] = (char *) malloc(15);
		scanf("%s",p[i]);
		if(getchar() == '\n')
			break;
	}
	printf("\n输入一个用于连接的字符串\n");
	scanf("%s" , s);
	num = i;

	for(i = 0; i<num; i++)
	{
		strcat(out, p[i]);
		strcat(out, s);
	}
	strcat(out, p[i]);
	printf("\n连接后得到字符串为\n%s\n" , out);
	return 0;
}
