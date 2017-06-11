/*输入10个数，找出出现次数最多的数 */
#include<stdio.h>

//遍历记录数组，检测x是否在数组Array中存在，不存在返回-1，存在则返回下标
int check(int *Array,int len,int x)
{
	int i;
    for(i=0; i<len; i++)
    {
    	if(Array[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int i;
    int arr[100];//保存输入的数字
	int len = 0;//保存输入元素的个数
    int not_re_appear[100] = {0};//记录输入的数字中不重复的数字
    int appear_times[100] = {0};//记录每个不重复元素在输入数组中出现的次数
    int count = 0;//记录不重复数组长度
    int largest_times = 0;//最大出现的次数

    printf("\n输入不多于100个整数\n");
	for(i=0; i<100; i++)
	{
        scanf("%d",&arr[i]);
		if(getchar() == '\n')
			break;
		len++;
	}

    for(i=0; i<=len; i++)
    {
        if( check(not_re_appear,count,arr[i]) == -1 )//如果arr[i]不在re的前count个元素中
        {
            not_re_appear[count] = arr[i];
            appear_times[count]++;
            count++;
        }
		else
            appear_times[check(not_re_appear,count,arr[i])]++;
    }

	printf("得到不重复的数组为:\n");
	for(i=0; not_re_appear[i] != 0; i++)
		printf("%d ",not_re_appear[i]);
	putchar(10);
	printf("不重复数组中每个元素在输入数组中出现的次数对应为:\n");
	for(i=0; appear_times[i] != 0; i++)
		printf("%d ",appear_times[i]);
	putchar(10);

    for(i=0; i<count; i++)
    {
        if(appear_times[i] > largest_times)
            largest_times = appear_times[i];
    }
	printf("\n出现最多的是：\n");
    for(i=0; i<count; i++)//打印出所有出现次数最多的数据
    {
        if(appear_times[i] == largest_times)
            printf("%d ",not_re_appear[i]);
    }

    putchar(10);
    return 0;
}

/*
运行结果
 输入10个数据
 23 23 23 12 12 12 3 4 5 6
 
 出现最多的是：
 23 12
*/
