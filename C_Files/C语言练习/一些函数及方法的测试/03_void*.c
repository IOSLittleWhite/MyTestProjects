/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include<stdio.h>

int main(int argc, int *argv[])
{
    int a = 100;
	void *p = &a;
	printf("int a = 100;\nvoid *p = &a;\n");
	printf("*p = %d\n",*((int*)p));
	printf("p = %p   p + 1 = %p\n",p,p+1);
	return 0;//返回0
}
