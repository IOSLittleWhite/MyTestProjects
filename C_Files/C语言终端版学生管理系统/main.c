/****************************************************************
名称：教务管理系统
身份设置：管理员，学生
功能：管理员登陆后可以
		  1.添加删除学生
		  2.查看所有学生，按学号，按年龄，按成绩排名查看
		  3.修改任意学生的任何信息
		  4.搜索学生
	  学生登陆后可以
		  1.查看自己信息，修改除学号和成绩意外的信息
		  2.查看其他人的信息
****************************************************************/
# include "inc.h"
# include "stuList.h"
# include "adminlogin.h"
# include "stulogin.h"

int main()
{
	char key = 0;//键值保存
	while(1)
	{
		system("clear");
        printf("\t\t\t欢迎访问教务系统\n");
		putchar(10);
		printf("当前位置：首页\n");	
		putchar(10);
		printf("\t\t\t\t声明\n");
		printf("\t\t\t本软件所有权归海沫所有\n");
		printf("\t\t\t不得用于商业用途\n");
		printf("\t\t\t违者必究\n");
		putchar(10);//换行
		printf("\t\t\t\t操作说明\n");
		printf("\t\t\t按屏幕提示，选择1,2,3...进行操作\n");
		liukong(2);//换行
		printf("1.管理员登陆\t\t2.学生登陆\t\t3.退出\n");			
		key = getch();
		system("clear");
		switch(key)
		{
			case '1':
				AdmtLogin();
				system("clear");
				break;

			case '2':
				StudLongin();
				system("clear");
				break;

			case '3':
				liukong(5);
				printf("\t\t\t您已经安全退出本系统\n");
				putchar(10);
				printf("\t\t\t   感谢您的使用\n");
				putchar(10);
				printf("\t\t\t   祝您生活愉快\n");
				liukong(13);
				exit(0);				
		}
	}
	return 0;
}
