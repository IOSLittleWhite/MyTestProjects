#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_extract(char *s, int n, int m);
void insert(char *s1, char *s2, int n);

int main(void)
{
	char s1[100] = {};
	char s2[100] = {};
	char *result = NULL;
	int n,m;
	printf("\n输入两个字符串s1和s2，和两个整数n和m\n");
	printf("从s1的第n个字符开始的m个字符从s2的第n位插入\n");
	scanf("%s %s %d %d",s1,s2,&n,&m);

	result = _extract(s1,n,m);
	insert(s2, result, n);

	printf("\n插入后得到的s2为\n%s\n",s2);
	return 0;
}

char *_extract(char *s, int n, int m)
{
	int i; 
	char *result = (char *)malloc(50);
	for(i=0; i<m; i++)
		result[i] = s[n+i];
	return result;
}

void insert(char *s1, char *s2, int n) 
{ 
	char s[100] = {}; 
	int i; 
	for(i=0;i<(int)strlen(s1);i++) 
		s[i]=s1[i]; 
	for(i=0;i<(int)strlen(s2);i++) 
	{ 
		s1[n+strlen(s2)+i]=s[n+i]; 
		s1[n+i]=s2[i]; 
	}
	for(; i+n<(int)strlen(s); i++)
		s1[n+strlen(s2) + i] = s[n+i];
} 
