/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, int *argv[])
{
	int i;
	char s[100] = "hello world!!!";
	char s1[100] = "abcd";
	printf("%s\n",strncpy(s,s1,4));
	printf("%s\n",strcpy(s,s1));
	for(i=0; i<100; i++)
		printf("%c",s[i]);
	putchar(10);
	printf("s[4] = %d   s[5] = %d\n",s[4],s[5]);
	return 0;//返回0
}
