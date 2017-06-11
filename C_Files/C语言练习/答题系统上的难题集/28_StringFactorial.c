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
char *factorialstring(char *result, int n;);

int main(int argc, int *argv[])
{
	char result[1024] = {0};
    int n;
    
    scanf("%d",&n);
    
    result[0] = '0';
    factorialstring(result,n);
    
    printf("%d! = %s\n%d!共有%d位\n",n,result,n,(int)strlen(result));
    
	return 0;//返回0
}

char *factorialstring(char *result, int n)
{
    int i;
    char num[1024] = {};
    char ttp;
    
    if(n)
    {
        result[0] = '1';
        num[0] = '1';
        for(i=0; i<n; i++)
        {
            multiplystring(result, num);
            addstring(num, "1");
        }
    }
    
    //反转还原字符串
    for(i=0; i<strlen(result)/2; i++)
    {
        ttp = result[i];
        result[i] = result[strlen(result) - 1 -i];
        result[strlen(result) - 1 -i] = ttp;
    }
    
    return result;
}

char *multiplystring(char *s1, char *s2)
{
    char *p = s1;
    char *q = s2;
    char temp[1024] = {};
    int i;

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
