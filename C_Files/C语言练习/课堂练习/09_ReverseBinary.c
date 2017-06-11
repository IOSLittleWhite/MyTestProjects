#include<stdio.h>

int main()
{
	int a;
	printf("\n");
	printf("输入一个十进制数\n");
	scanf("%d",&a);
	printf("逆序输出其二进制为\n");
	for(;a;)//while(a)
	{
		printf("%d",a%2);
		a /= 2;
	}
	printf("\n");
	printf("\n");
	return 0;//返回0
}
