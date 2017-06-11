/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include <stdio.h>
#include <string.h>

char *addstring(char *s1, char *s2);

int main(int argc, int *argv[])
{
	char s1[1024] = {};
	char s2[1024] = {};
	int i;
	fgets(s1,1024,stdin);
	if(s1[strlen(s1)-1] == '\n')
		s1[strlen(s1)-1] = '\0';
	fgets(s2,1024,stdin);
	if(s2[strlen(s2)-1] == '\n')
		s2[strlen(s2)-1] = '\0';
    
    printf("\n%s + %s = \n",s1,s2);

	printf("%s\n",addstring(s1,s2));
	return 0;//返回0
}

char *addstring(char *s1, char *s2)
{
	int i = 0;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	char temp;

	//字符串逆转
	for(i=0; i<len1/2; i++)
	{
		temp = s1[i];
		s1[i] = s1[len1 - 1 - i];
		s1[len1 - 1 - i] = temp;
	}
	for(i=0; i<len2/2; i++)
	{
		temp = s2[i];
		s2[i] = s2[len2 - 1 - i];
		s2[len2 - 1 - i] = temp;
	}

	//字符串相加
	for(i=0; i<len2; i++)
	{
		temp = s1[i] + s2[i];
		if(temp >= 96)
			temp -= 48;
		if(temp > 57)
		{
			s1[i] = temp - 10;
			s1[i+1]++;
			if(s1[i+1] < 49)
				s1[i+1] += 48;
		}
		else
			s1[i] = temp;
	}
	while(s1[i] > 57)
	{
		s1[i] -= 10;
		s1[++i]++;
		if(s1[i] < 49)
			s1[i] += 48;
	}

	//字符串翻转还原
	for(i=0; i<strlen(s1)/2; i++)
	{
		temp = s1[i];
		s1[i] = s1[strlen(s1) - 1 - i];
		s1[strlen(s1) - 1 - i] = temp;
	}

	return s1;
}
