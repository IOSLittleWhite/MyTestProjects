#include <stdio.h>

int main()
{
	int num[10];
	int i;
	int j;
	int temp;
	printf("\n\t\t\t选择排序法\n输入是个数，以空格隔开\n");
	for(i=0; i<10; i++)
		scanf("%d",&num[i]);
	for(i=0; i<9; i++)
	{
		for(j=i+1; j<10; j++)
		{
			if(num[i] > num[j])
			{
				temp = num[j];
				num[j] = num[i];
				num[i] = temp;
			}
		}
	}
	printf("\n输出排序后的数字为：\n");
	for(i=0; i<10; i++)
		printf("%d ",num[i]);
	putchar(10);
	return 0;
}



