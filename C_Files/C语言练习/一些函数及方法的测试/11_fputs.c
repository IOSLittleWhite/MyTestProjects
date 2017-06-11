/*******************************
File Name: 5_fputs.c
Author: xheng
#Company: 千锋(深圳)
Created Time: 四  2/13 14:07:25 2014
*******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *path = "test.txt";
	char *mode = "w";
	FILE *fp = fopen(path, mode);
	
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		perror("open"); //打印出上一个函数执行失败的原因
		exit(-1); //退出程序
	}

	//文件读写操作
	printf("打开成功\n");
	char *str = "qian\nfeng";
	
	int ret = fputs(str, fp);
	printf("实际写入的字符数:%d\n", ret);


	//保存并且关闭文件
	fclose(fp);

	return 0;
}







