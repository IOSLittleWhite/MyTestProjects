/*******************************
File Name: 6_printf.c
Author: xheng
#Company: 千锋(深圳)
Created Time: 四  2/13 14:18:24 2014
*******************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	char buf[100];
	fgets(buf, 100, stdin);//scanf("%[^\n]", buf);
	int ret = fputs(buf, stdout);//printf("%s", buf);
	ret = fputs(buf, stderr); //错误输出

	ret = printf("hello world");
	printf("ret = %d\n", ret);

	return 0;
}








