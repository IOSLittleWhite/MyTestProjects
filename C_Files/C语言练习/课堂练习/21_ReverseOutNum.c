/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include<stdio.h>

int main(int argc, int *argv[])
{
	int num;
	int count = 0;

	printf("\n输入一个整数，将其逆序输出，并算出位数\n");
	scanf("%d",&num);

	printf("\n%d逆序打印输出为:\n",num);
	while(num)
	{
		printf("%d",num%10);
		num /= 10;
		count ++;
	}
	printf("\n该数共有%d位\n",count);
	return 0;//返回0
}
