#include <stdio.h>  
      
int main(void)
{  
	int n;//总人数  
    int m;//用来去除人的那个数  
    int remain;//剩余人数        
    int a[100]; //用来保存人  
    int i;//循环临时变量  
    int count = 0;//依次计数  
      
    //输入人数，并初始化数组  
    printf("\n输入围圈人数，和报道退出的编号：\n");
    scanf("%d %d",&n,&m);
    for(i=0; i<n; i++)  
        a[i] = i+1;  
      
    //依次删除，并打印删除过程
    remain = n;//当前剩余的人数  
    printf("依次报道退出的人为：\n");  
    while(remain > 1)
	{  
        for(i=0; i<n; i++)
		{  
            if(a[i]!=0)
			{  
                count++;  
                if(count == m)
				{  
                    printf("%d 号\n",a[i]);//打印被删除的人  
                    a[i]=0;  
                    count=0;  
                    remain--;  
                }  
            }  
        }  
    }
    //打印最后剩下的人  
    for(i=0; i<n; i++)
	{  
        if(a[i]!=0)
			printf("最后剩下的人是：%d号\n",a[i]);    
    }
    return 0;  
}

/*
运行结果
 
 输入围圈人数，和报道退出的编号：
 12 5
 
 
 依次被删除的号码为：
 5
 10
 3
 9
 4
 12
 8
 7
 11
 2
 6
 
 最后剩下的人是 1 号
 

*/
