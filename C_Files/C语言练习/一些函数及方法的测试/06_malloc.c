/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, int *argv[])
{
	char s[1024];
	char (*p)[1024];
	while(1)
	{
		p = (char *)malloc(sizeof(s));
		printf("p = %p\n",p);
		p++;
	}
	return 0;//返回0
}
