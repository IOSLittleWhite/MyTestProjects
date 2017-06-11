/*******************************
File Name: 2_fgetc.c
Author: xheng
#Company: 千锋(深圳)
Created Time: 四  2/13 10:18:29 2014
*******************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *path = "test.txt";
	char *mode = "r";
	FILE *fp = fopen(path, mode);
	
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		perror("open"); //打印出上一个函数执行失败的原因
		exit(-1); //退出程序
	}

	//文件读写操作
	printf("打开成功\n");

	//feof
	//循环结束 fgetc == -1
	char ch = EOF; //end of file

	while (1)
	{
		ch = fgetc(fp);	
		if (ch == EOF)
		{
			break;
		}
		printf("%c", ch);
	}
/*
	while ( (ch = fgetc(fp)) != -1 )
	{
		printf("%c", ch);
	}
*/
	printf("\n");



	//保存并且关闭文件
	fclose(fp);
	return 0;
}



