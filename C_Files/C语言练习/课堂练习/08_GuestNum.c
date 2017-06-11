#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(0));
	int n = rand()%100;
 	int in;
	int chance = 10;
	do
	{
		system("clear");
    	printf("\n\n\n\n\n\n");
    	printf("\t\t\t你还有%d次机会\n",chance--);
    	printf("\t\t请输入猜测数字并按回车确认\n");
    	printf("\t\t");
    	scanf("%d",&in);
		if(n>in)
		{
			system("clear");
			printf("\n\n\n\n\n\n\n\n");
            printf("\t\t猜小了！");
		}
        else if(n<in)
		{
			system("clear");
			printf("\n\n\n\n\n\n\n");
       		printf("\t\t猜大了！");
		}
		else
		{
			system("clear");
 	        printf("\n\n\n\n\n\n");
            printf("\t\t随机数 = %d\n\t\t恭喜猜中！\n",n);
		}
		getchar();
		getchar();
	}
	while((n != in) && chance);
	if(chance == 0 && n != in)
	{
		system("clear");
		printf("\n\n\n\n\n\n");
		printf("\t\t随机数 = %d\n\t\t对不起，你的机会用完了！\n",n);
	}
	return 0;//返回0
}
/***************************************************
计算机没有办法产生真正的随机数的，是用算法模拟，所以你只调用rand，每次出来的东西是一样的。设置一个种子后，根据种子的不同，就可以产生不同的数了。而怎么保证种子的不同呢？最简单的办法当然是用永远在向前的时间。
srand(time(0)) ;//先设置种子
rand();//然后产生随机数
Srand是种下随机种子数，你每回种下的种子不一样，用Rand得到的随机数就不一样。为了每回种下一个不一样的种子，所以就选用Time(0)，Time(0)是得到当前时时间值（因为每时每刻时间是不一样的了）。
srand(time(0)) ;
就是给这个算法一个启动种子，也就是算法的随机种子数，有这个数以后才可以产生随机数, 
用1970.1.1至今的秒数，初始化随机数种子。
***************************************************/
