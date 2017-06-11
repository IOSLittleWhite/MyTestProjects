#include<stdio.h> 

int count(int n);

int main(void) 
{ 
	int num;
	int sum = 0;
	int i;

	printf("\n输入一个整数，计算出其阶乘结果末尾有多少个0\n");
	scanf("%d", &num);

	for(i=5; i<=num; i += 5)
	{
		sum = sum + count(i);
	}

	printf("%d的阶乘结果末尾共有 %d 个0\n",num,sum);

	return 0;
}

int count(int n)
{
	int cnt = 0;
	int temp = n;
	while(1)
	{
		if(temp%5 == 0)
			cnt ++;
		else
			break;
		temp /= 5;       
	}
	return cnt;
}
