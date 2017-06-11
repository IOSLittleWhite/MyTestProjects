/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *addstring(char *s1, char *s2);
char *multiplystring(char *s1, char *s2);

int main(int argc, int *argv[])
{ 
	char s1[1024] = {0};
	char s2[1024] = {0};

	fgets(s1, 1024, stdin);
	if(s1[strlen(s1) - 1] == '\n')
		s1[strlen(s1) - 1] = '\0';
	fgets(s2, 1024, stdin);
	if(s2[strlen(s2) - 1] == '\n')
		s2[strlen(s2) - 1] = '\0';
    
    printf("\n%s * %s = \n",s1,s2);    
    printf("%s\n",multiplystring(s1,s2));
    
	return 0;//返回0
}

char *multiplystring(char *s1, char *s2)
{
    char *p = s1;
    char *q = s2;
    char temp[1024] = {};
    char ttp;
    int i;
   
	if((strlen(s1) == 1 && *p == '0'))
		return s1;

	//字符串反转
    for(i=0; i<strlen(s1)/2; i++)
    {
        ttp = s1[i];
        s1[i] = s1[strlen(s1) - 1 -i];
        s1[strlen(s1) - 1 -i] = ttp;
    }
    for(i=0; i<strlen(s2)/2; i++)
    {
        ttp = s2[i];
        s2[i] = s2[strlen(s2) - 1 -i];
        s2[strlen(s2) - 1 -i] = ttp;
    }
    
    strcpy(temp, s1);
	bzero(s1, strlen(s1));

	//完成字符串相乘
    while(*q != 0)
    {
        for(i=0; i<*q-48; i++)
            addstring(p,temp);
        q++;
		if(*p == 0)
			*p = 48;
        p++;
    }

	//反转还原字符串
    for(i=0; i<strlen(s1)/2; i++)
    {
        ttp = s1[i];
        s1[i] = s1[strlen(s1) - 1 -i];
        s1[strlen(s1) - 1 -i] = ttp;
    }
    
    return s1;
}

char *addstring(char *s1, char *s2)
{
	int i = 0;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	char temp;
    
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
    
	return s1;
}
