# include "inc.h"
# include "adminlogin.h"

int AdmtLogin()
{
	int i,j;
	int time = 3;
	pStu pHead = NULL;
	char Name[50];
	char Passwd[20];
	
	while( time )
	{
		i = 0;
        system("clear");
        liukong(6);
		printf("\t\t\t您还有%d次机会\n", time);
		printf("\t\t\t输入用户名：");
		scanf("%s", Name);
        getchar();
		system("clear");
		liukong(6);
		printf("\t\t\t您还有%d次机会\n", time);
		printf("\t\t\t输入密码：");
		scanf("%s",Passwd);
		if( (strcmp( Name, "root") == 0) && (strcmp( Passwd, "fsw123") == 0) )
		{
			system("clear");
			AdminOnLine( pHead );
			DestroyStuList( &pHead );//注销登陆时销毁内存中临时的学生信息表
			return 0;
		}
        system("clear");
        liukong(7);
		printf("\t\t\t用户不存在或密码错误!");
		getchar();
		--time;
	}
	return 0;
}

//管理员首页OpenStuListFile( &pHead );
void AdminFirstPage()
{	
	printf("\t\t\t欢迎访问教务系统\n\n");
	printf("当前位置：首页 -> 管理员\n\n");
	printf("1.管理学生信息    2.查看学生信息    3.注销登录\n");
}

//学生修改个人信息页
void AdminManagePage( pStu pHead )
{
	pStu Pst = NULL;
	char key = 0;
	while(1)
	{
		printf("\t\t\t欢迎访问教务系统\n\n");
		printf("当前位置：首页 -> 管理员 -> 管理学生信息\n\n");
		OpenStuListFile( &pHead );
		PrintfStuListAdmin( pHead);
		printf("总人数为：%d人\n\n", StuListLength( pHead ));
		printf("1.新建学生表   2.添加新学生   3.删除离校学生   4.修改学生信息   5.返回\n");
		key = getch();
		switch( key )
		{
		case '1' :
			CreatStuList( &pHead );
			CreatStuListFile( pHead );
			break;
		case '2' :
			StuListInsert( pHead );
			CreatStuListFile( pHead );
			break;
		case '3' :
			StuListDelete( pHead );
			CreatStuListFile( pHead );
			getchar();
			break;
		case '4' :
			Pst = SearchStuNumAdmin( pHead );
			putchar(10);
			
			if( Pst != NULL )
			{
				printf("%s\n",Pst->data->num);
				AdminModifyStu( pHead, Pst );
			}
			CreatStuListFile( pHead );
			getchar();
			break;
		case '5' :
			return;
		}
		system("clear");
	}
}

//管理员查看花名册页
void AdminLookPage( pStu pHead )
{
	char key;
	int k = 0;
	while(1)
	{
		printf("\t\t\t欢迎访问教务系统\n\n");
		printf("当前位置：首页 -> 管理员 -> 查看全部学生\n" );
		PrintfStuListAdmin( pHead );
		printf("总人数为：%d人\n\n", StuListLength( pHead ));
		printf( "1.姓名搜索  2.学号搜索  3.学号排序  4.语文排序  5.数学排序  6.英语排序  7.返回\n" );
		key = getch();
		switch( key )
		{
		case '1' :
			SearchStuNameAdmin( pHead );
			getchar();
			break;
		case '2' :
			SearchStuNumAdmin( pHead );
			getchar();
			break;
		case '3' :
			if(k)
				SortStuNumUp( pHead );
			else
				SortStuNumDown( pHead );
			++k;
			if( k==2 )
				k = 0;
			break;
		case '4' :
			if(k)
				SortStuChineseUp( pHead );
			else
				SortStuChineseDown( pHead );
			++k;
			if( k==2 )
				k = 0;
			break;
		case '5' :
			if(k)
				SortStuMathUp( pHead );
			else
				SortStuMathDown( pHead );
			++k;
			if( k==2 )
				k = 0;
			break;
		case '6' :
			if(k)
				SortStuEnglishUp( pHead );
			else
				SortStuEnglishDown( pHead );
			++k;
			if( k==2 )
				k = 0;
			break;
		case '7' :
			return;
		}
		system("clear");
	}
}

void AdminOnLine( pStu pHead )//学生登陆在线状态
{
	char key = 0;
	OpenStuListFile( &pHead );
	while(1)
	{ 
		AdminFirstPage();
		key = getch();
		system("clear");
		switch( key )
		{
		case '1' :
			AdminManagePage( pHead );
			break;
		case '2' :
			AdminLookPage( pHead );
			break;
		case '3' :
			return;
		}
		system("clear");
	}
}
