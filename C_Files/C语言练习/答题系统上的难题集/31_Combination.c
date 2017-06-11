/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/
# include <stdio.h>

typedef struct mb{
	int id;
	char data[100];
}*pmember, member;

int find_replace(pmember arr, int index, int max, int tap);
void find_next(pmember arr, int index);
void combination(pmember arr, int len, int n);

int main()
{
	int len = 0;
	int i;
	int num;
	member arr[1024] = {0};
    
	printf("输入n个人的姓名，以空格区分，以回车结束输入\n");
	for(i=0; i<1024; i++)
	{
		scanf("%s", arr[i].data);
		arr[i].id = i + 1;
		len++;
		if(getchar() == '\n')
			break;
	}
	printf("输入要从中抽取的人数\n");
	scanf("%d", &num);
    
	printf("从%d个人中抽取%d的所有组合为\n", len, num);
	combination(arr, len, num);
	
	return 0;
}

//打印所有组合函数，每种组合以id递增的顺序链接
void combination(pmember arr, int len, int n)
{
	int i;//循环变量
	int sub = n - 2;//subscript下标
	int tap = 1;//id上限差
	int done = 0;//所有组合查找完成标志
	int flag;//交换成功标志
	int count = 0;//组合种类数量统计
    
	do
	{
		for(i=0; i<n; i++)//打印出一个组合
			printf("%s ", arr[i].data);
		printf("\n");
		count++;//组合统计器加1
        
		if(arr[0].id == len - n + 1)//如果当前组合中第一个元素的id已经到达上限
			done = 1;//完成所有组合的查找标志有效
        
		flag = 1;//交换完成标志失效
		while(flag && (arr[0].id != len - n + 1))//直到一次成功的交换完成或所有组合查找完成
		{
			flag = find_replace(arr, n-1, len, 0);//交换更改每种组合中的最后一个元素
			if(flag)//如果最后一个元素交换失败
			{
				while(flag)//直到交换成功
				{
					flag = find_replace(arr, sub, len, tap);//交换更改下标为sub的的元素
					for(i=sub; i<sub+tap; i++)//使sub以后的元素id号连续递增
						find_next(arr, i);
					if(flag)//如果下标为sub的元素交换失败
					{
						tap++;
						sub--;//sub前移一个
					}
				}
				sub = n - 2;//sub回归
				tap = 1;
			}
		}
	}while(!done);
    
	printf("共有%d种组合\n", count);
}

//查找并替换的函数
//将arr数组中下标为index的元素替换为id比它大1的元素，查找id的上限为max - tap
int find_replace(pmember arr, int index, int max, int tap)
{
	int i = index + 1;
	member temp;
	while(arr[i].id != 0)
	{
		if((arr[i].id == arr[index].id + 1) && (arr[i].id <= max - tap))
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			return 0;
		}
		i++;
	}
	return 1;
}

//将arr数组中下标为index+1的元素替换为id号比下标为index的元素的id大1的元素
void find_next(pmember arr, int index)
{
	int i = index + 2;
	member temp;
	if(arr[index].id + 1 != arr[index + 1].id)
	{
		while(arr[i].id != 0)
		{
			if(arr[i].id == arr[index].id + 1)
			{
				temp = arr[i];
				arr[i] = arr[index+1];
				arr[index+1] = temp;
			}
			i++;
		}
	}
}