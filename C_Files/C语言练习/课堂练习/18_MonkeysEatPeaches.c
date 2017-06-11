/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include<stdio.h>

unsigned long Sum( int days);

int main(int argc, int *argv[])
{ 
	int days;
	printf("\n输入共吃了多少天\n");
	scanf("%d",&days);
	printf("\n每天吃前一天剩下的一半还多一个，第%d天时还剩下1个，",days);
	printf("\n则第一天共有 %lu 个桃子\n",Sum(days));
	return 0;//返回0
}

unsigned long Sum(int days)
{
	if(days == 1)
		return 1;
	return (Sum(days - 1) + 1) * 2;
}
