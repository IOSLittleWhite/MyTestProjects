#include <stdio.h>

int main()
{
	int num[10];
	int i;
	int j;
	int temp;
	printf("\n\t\t\t冒泡排序法\n输入是个数，以空格隔开\n");
	for(i=0; i<10; i++)
		scanf("%d",&num[i]);
	for(i=0; i<9; i++)
	{
		for(j=0; j<9-i; j++)
		{
			if(num[j] > num[j+1])
			{
				temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
			}
		}
	}
	printf("\n排序后输出为：\n");
	for(i=0; i<10; i++)
		printf("%d ",num[i]);
	putchar(10);
	return 0;
}
