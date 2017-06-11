#include<stdio.h>

int main()
{
	int num = 0;
	int i = 2;
	int out[20] = {0};
	int j = 0;
	printf("输入一个整数\n");
	scanf("%d",&num);
	printf("用所有质因数的积表示为\n%d = ",num);
	while(num != 1)
	{
		if(num % i == 0)
		{
			out[j] = i;
			num /= i;
			//保证每次都从最小的质数2开始
			i = 1;
			j++;
		}
		i++;
	}
	for(i=0; i<j-1; i++)
		printf("%d * ", out[i]);
	printf("%d",out[i]);
	putchar(10);
	return 0;//返回0
}
