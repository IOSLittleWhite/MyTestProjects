/*******************************
File Name: 4_fgets.c
Author: xheng
#Company: 千锋(深圳)
Created Time: 四  2/13 11:27:30 2014
*******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *path = "test.txt";
	char *mode = "r+";
	FILE *fp = fopen(path, mode);
	
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		perror("open"); //打印出上一个函数执行失败的原因
		exit(-1); //退出程序
	}

	//文件读写操作
	printf("打开成功\n");
	char buf[1024] = "";

	//循环结束 fgets == NULL
	char *p = fgets(buf, 1024, fp);
	printf("buf = %p, p = %p\n", buf, p);
	printf("%s\n",buf);
	p = fgets(buf, 10, fp);
	printf("buf = %p, p = %p\n", buf, p);
	printf("%s\n",buf);
	p = fgets(buf, 10, fp);
	printf("buf = %p, p = %p\n", buf, p);
	printf("%s\n",buf);
	p = fgets(buf, 30, fp);
	printf("buf = %p, p = %p\n", buf, p);
	printf("%s\n",buf);

	fputs(buf, fp);
	p = fgets(buf, 30, fp);
	printf("buf = %p, p = %p\n", buf, p);
	printf("%d\n",fputs(buf, stdout));
	//保存并且关闭文件
	fclose(fp);

	return 0;
}






