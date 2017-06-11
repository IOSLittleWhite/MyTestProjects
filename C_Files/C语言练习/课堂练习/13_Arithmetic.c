/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include<stdio.h>

int Count(int a, char ch, int b)
{
	int sum;
 	switch(ch)
	{
		case '+':
				sum = a + b; 
				break;
		case '-':
				sum = a - b;
				break;
		case '*':
				sum = a * b;
				break;
		case '/':
				sum = a / b;
				break;
	}
	return sum;
}

int main()
{
	int a,b;
	char ch;
	int sum;
	printf("\n\t\t\t四则运算\n");
	scanf("%d%c%d",&a,&ch,&b);
	sum = Count(a,ch,b);
	printf("%d\n",sum);
	return 0;//返回0
}
