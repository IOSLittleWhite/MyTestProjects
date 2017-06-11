#include <stdio.h>

int num[6] = {0};

void insert(int input)
{
	int i;
	int j;
	for(i=0; i<5; i++)
	{
   		if(input < num[i])
   		{
     		for(j=5; j>i; j--)
         		num[j] = num[j-1];
      		num[j] = input;
      		break;
  		}
	}
    if(i == 5)
        num[i] = input;
}

int main()
{
	int i;
    int input;
	printf("\n按从小到大顺序输入5个数构成数组\n");
	for(i=0; i<5; i++)
		scanf("%d",&num[i]);
	printf("输入欲插入数据\n");
	scanf("%d",&input);
	insert(input);
    printf("\n插入后的数组输出为：\n");
	for(i=0; i<6; i++)
		printf("%d\n",num[i]);
	return 0;
}
/*
运行结果
 按从小到大顺序输入5个数构成数组
 4 5 6 7 8
 输入欲插入数据
 2
 
 插入后的数组输出为：
 2
 4
 5
 6
 7
 8
*/