#include<stdio.h>
#include<string.h>

int main()
{
	char s1[50] = {};
	char s2[50] = {};
	char s[100] = {};
	int n,i;
	printf("\n输入第一个字符串，不超过50个字符\n");
	fgets(s1,50,stdin);
	s1[ strlen(s1) - 1 ] = '\0';
	printf("\n输入第二个字符串，不超过50个字符\n");
	fgets(s2,50,stdin);
	s2[ strlen(s2) - 1 ] = '\0';
	printf("\n输入插入位置\n");
	scanf("%d",&n);
	for(i=0;i<(int)strlen(s1);i++)
		s[i]=s1[i];
	for(i=0;i<(int)strlen(s2);i++)
	{
		s1[n+strlen(s2)+i]=s[n+i];
		s1[n+i]=s2[i];
	}
	for(; i+n<(int)strlen(s); i++)
		s1[n+strlen(s2) + i] = s[n+i];
	puts(s1);
	return 0;
}
