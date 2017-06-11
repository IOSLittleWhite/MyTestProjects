#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[100] = {0};
	char s2[100] = {0};
	char *p = s1;
	char *q = s1;
	char out[100] = {0};
	printf("\n输入字符串1\n");
	scanf("%[^\n]", s1);
	printf("\n输入字符串2\n");
	scanf("%s", s2);
	printf("\n以字符串%s分割后\n",s2);
	while(q != NULL)
	{
		q = strstr(p, s2);
		if(q != NULL )
		{
			strncpy(out, p, q-p );
			printf("%s\n",out);
			p = q+(int)strlen(s2);
			bzero(out, strlen(out));//清空out
		}        
	}
	strncpy(out ,p, (int)strlen(s1) - (p - s1) );
	printf("%s\n",out);
	bzero(out, strlen(out));//清空out
	return 0;
}
