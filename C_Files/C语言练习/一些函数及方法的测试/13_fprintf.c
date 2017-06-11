/*******************************
File Name: 7_fprintf.c
Author: xheng
#Company: 千锋(深圳)
Created Time: 四  2/13 14:37:38 2014
*******************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *name = "张三";
	int level = 10;
	int	blood = 1234;
	int act	  = 100;
	int def   = 99;
	char boss = 'n';

	FILE *fp = fopen("test.txt", "w");

	if (fp == NULL)
	{
		printf("打开失败\n");
		perror("open");
		exit(-1);
	}

	fprintf(fp, "%s|%d|%d|%d|%d|%c", name, level, blood, act, def, boss);

	fclose(fp);
/*
	char buf[1024] = {0};
	sprintf(buf, "%s|%d|%d|%d|%d|%c", name, level, blood, act, def, boss);
	fputs(buf, stdout);
*/

	return 0;
}






