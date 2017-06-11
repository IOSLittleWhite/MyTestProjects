#include <stdio.h>
#include <string.h>

void unite(char *s);
void shortcut(char *s);

int main()
{
	char s[100] = {};
    printf("\n输入一个字符串\n");
	scanf("%s",s);
	unite(s);
    printf("\n字符串归并后输出为：\n");
	printf("%s\n\n字符串压缩后输出为：\n",s);
	shortcut(s);
	return 0;
}

//字符串归并函数，按出现先后将相同字符归并到一起
void unite(char *s)
{
	int len = strlen(s);
	int i;
	int j,k;
	int tab = 1;
	for(i=0; i<len-1;)
	{
		tab = 1;
		for(j=i+1; j<len; j++)
		{
			if( s[i] == s[j] )
			{
				for(k=j; k>i+tab; k--)
					s[k] = s[k-1];
				s[k] = s[i];
				tab++;
			}
		}
		i += tab;
	}
}

//字符串压缩函数
void shortcut(char *s)
{
	int i;
	int len = strlen(s);
	char count = 1;

	printf("%c",s[0]);
	for(i=0; i<len-1; i++)
	{
		if(s[i] == s[i+1])
		{
			count++;
			if(i == len-2)
				printf("%d",count);
		}
		else
		{           
			printf("%d",count);
			count = 1;
			printf("%c",s[i+1]);
			if(i == len-2)
				printf("%d",count);
		}
	}
	putchar(10);
}
