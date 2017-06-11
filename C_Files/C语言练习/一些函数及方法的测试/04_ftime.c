/*********************************************************************
 名称：测试ftime()函数
 
 功能：完成60秒计时
 
 知识补充：
 ftime()函数等的说明：
 函数定义：int ftime(struct timeb *tp);
 函数说明：ftime()将目前日期由tp所指的结构返回。
 tp结构定义：
 struct timeb
 {
 time_t time;              //为1970-01-01至今的秒数
 unsigned short millitm;   //千分之一秒即毫秒0-999
 short timezonel;          //为目前时区和Greenwich相差的时间，单位为分钟
 short dstflag;            //为日光节约时间的修正状态，如果为非0代表启用日光节约时间修正
 };
 返回值 ：无论成功或失败都返回0
 
 完成时间：2013年8月14日0:30:13
 *********************************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <sys/timeb.h>

int main ()
{
	struct timeb t1,t2;
	int time = 0;
	printf("%d",time);
	while( time < 59)
	{
		ftime( &t1 );
		ftime( &t2 );
		while( t2.time == t1.time )
			ftime( &t2 );
		time++;
		system("clear");//清除屏幕显示
		printf("%d\n",time);
	}
	return 0;
}