/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include<stdio.h>
#include<ctype.h>

int main(int argc, int *argv[])
{
	char s[100] = {0};
	int ch = 0;
	int num = 0;
	int space = 0;
	char *p = s;
		
	printf("\n输入一个字符串\n");
	scanf("%[^\n]",s);

	while(*p != 0)
	{
		if(isalpha(*p))
			ch ++;
		else if(isdigit(*p))
			num ++;
		else if(isspace(*p))
			space ++;
		p++;
	}
	printf("\n字母数 = %d\n空格数 = %d\n数字数 = %d\n",ch, space, num);
	return 0;//返回0
}
