#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void SortWords(char *p[20], int num);

int main()
{
    char *p[20] = {NULL};
    int i = 0;
	printf("\n输入不超过20个长度不超过10的单词，空格隔开\n");
    while(1)
    {
        p[i] = malloc(10);
        scanf("%s",p[i]);
        if(getchar() == '\n')
            break;
        i ++;
    }
    SortWords(p,i);
    i = 0;
	printf("\n排序后输出：\n");
    while(p[i] != NULL)
        printf("%s\n",p[i++]);
    return 0;
}

void SortWords(char *p[20], int num)
{
	int i;
	int j;
	char temp[20] = {};
	
	for(i=0; i<num; i++)
	{
		for(j=i+1; j<=num; j++)
		{
			if(strcmp(p[i],p[j]) > 0)
			{
				bzero(temp, strlen(temp));
				strcpy(temp,p[j]);
				bzero(p[j], strlen(p[j]));
				strcpy(p[j],p[i]);
				bzero(p[i], strlen(p[i]));
				strcpy(p[i],temp);
			}
		}
	}
}
