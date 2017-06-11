#include <stdio.h>

int main()
{
	int m,n;//m是围圈人数n是报到删除的数
	int num[100] = {};//预留围圈人序号
	int *p = num;
	int last;//用于保存最后一个人
	int empty = 0;//用于检测数组是否为空，初始化为0表示非空
	int over = 0;//围圈最后一个人报道了n的标志
	int i;//用于for循环

	printf("\n输入围圈人数和报到退出的编号：\n");
	scanf("%d %d",&m,&n);
	for(i=0; i<m; i++)
    	num[i] = i+1;

	printf("依次报道退出的人为：\n");
	while(! empty)
	{
    	for(i=0; i<n; i++)//报道第n的人则退出，对应位置元素清零，退出for循环
    	{
    	    while(*p == 0)//跳过所有已经为0的元素
    	    {
    	        p++;
        	    if(p == num + m)//若p指针已经超出了数组范围
        	        p = num;//指针回到数组首地址
        	}
        	p++;//指针下移
			
        	if(p == num + m)//如果指针溢出
        	{
        	    p = num;//指针回到数组首地址
        	    if(i == n-1)//若刚好最后一个元素报道n退出
        	        over = 1;//最后一个人退出标志有效
        	}
		}	
    	if(over == 1)//若最后一个人退出标志有效
    	{
       		over = 0;
        	last = num[m-1];
        	num[m-1] = 0;
    	}
    	else
    	{
    	    last = *(p - 1);
       	 	*(p - 1) = 0;
    	}
        
        //大循环退出条件判断，遍历整个数组
    	for(i=0; i<m; i++)
    	{
    	    if(num[i] != 0)//若存在不为0的元素则数组不为空，empty = 0，则大循环不会被退出
    	    {
    	        empty = 0;
    	        break;
    	    }
    	    if(i == m-1)//若数组已经为空，empty = 1，则大循环退出条件成立
    	        empty = 1;
    	}
        if(!empty)//打印出报道退出的人的编号
            printf("%d 号\n",last);
	}
    printf("最后剩下的人是：%d号\n",last);
	return 0;
}

/*
运行结果
 输入围圈人数和报到退出的编号：
 11 4
 依次报道退出的书序为：
 4
 8
 1
 6
 11
 7
 3
 2
 5
 10
 
 最后剩下的人是:
 9
*/
