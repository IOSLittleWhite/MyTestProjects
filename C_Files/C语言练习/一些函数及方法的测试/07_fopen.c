/*******************************
File Name: 1_fopen.c
Author: xheng
#Company: 千锋(深圳)
Created Time: 四  2/13 09:28:12 2014
*******************************/

#include <stdio.h>
#include <stdlib.h>
//io == input/output
//bios == basic input/output system
//ios == i operator system
//Google I/O 

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


	//保存并且关闭文件
	fclose(fp);

	return 0;
}






