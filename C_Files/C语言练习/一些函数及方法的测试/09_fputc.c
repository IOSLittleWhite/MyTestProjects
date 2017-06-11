/*******************************
File Name: 3_fputc.c
Author: xheng
#Company: 千锋(深圳)
Created Time: 四  2/13 11:00:16 2014
*******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *path = "test.txt";
	char *mode = "at";
	FILE *fp = fopen(path, mode);
	
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		perror("open"); //打印出上一个函数执行失败的原因
		exit(-1); //退出程序
	}

	//文件读写操作
	printf("打开成功\n");
	char str[] = "千锋";
	int len = strlen(str);
	int i = 0;
	char ret = -1;
	
	for (i = 0; i < len; ++i)
	{
		ret = fputc(str[i], fp);
		if (ret == -1)
		{
			printf("写入失败\n");
			perror("write");
			break;
		}

		printf("ret = %c\n", ret);
	}
	


	//保存并且关闭文件
	fclose(fp);

	return 0;
}






