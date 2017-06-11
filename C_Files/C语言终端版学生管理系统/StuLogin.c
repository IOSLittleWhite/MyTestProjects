# include "stulogin.h"

int StudLongin()
{
	int i,j;
	int time = 3;
	pStu pHead = NULL;
	pStu p = NULL;
	char Name[50];
	char Passwd[20];

	OpenStuListFile( &pHead );
	while( time )
	{
		i = 0;
        system("clear");
        liukong(7);//空7行
		printf("\t\t\t您还有%d次机会\n", time);
		printf("\t\t\t输入用户名：");
		scanf("%s", Name);
        getchar();
		system("clear");
		liukong(6);
		printf("\t\t\t您还有%d次机会\n", time);
		printf("\t\t\t输入密码：");
		scanf("%s",Passwd);
		for( p=pHead; p->next!=NULL; p=p->next)
		{
			if( (strcmp(p->next->data->name, Name) == 0) && (strcmp(p->next->data->passwd, Passwd) == 0) )
			{
				system("clear");
				StuOnLine( p->next, pHead );//学生登陆在线状态
				DestroyStuList( &pHead );//注销登陆时销毁内存中临时的学生信息表
				return 0;
			}
		}
        system("clear");
        liukong(7);//空7行
		printf("\t\t\t用户不存在或密码错误!");
		getchar();
		--time;
	}
	return 0;
}

//学生首页
void StuFirstPage( pStu Pst )
{
	printf("\t\t\t欢迎访问教务系统\n");
	putchar(10);
	printf("当前位置：首页 -> 学生 -> %s\n", Pst->data->name );	
	putchar(10);
	ShowStuMessage( Pst );
	putchar(10);
	printf("1.修改个人信息    2.查看其他学生    3.注销登录\n");
	putchar(10);
}

//学生修改个人信息页
void StuModifyPage( pStu Pst )
{
	printf("\t\t\t欢迎访问教务系统\n");
	putchar(10);
	printf("当前位置：首页 -> 学生 -> %s -> 修改个人信息\n", Pst->data->name );	
	putchar(10);
	ShowStuMessage( Pst );
	putchar(10);
}

//学生查看花名册页
void StuLookPage( pStu Pst, pStu pHead )
{
	char key;
	int k = 0;
	while(1)
	{
		printf("\t\t\t欢迎访问教务系统\n");
		putchar(10);
		printf("当前位置：首页 -> 学生 -> %s -> 查看全部学生\n", Pst->data->name );	
		putchar(10);
		PrintfStuList( pHead );
		printf("总人数为：%d人\n", StuListLength( pHead ));
		putchar(10);
		printf( "1.姓名搜索  2.学号搜索  3.学号排序  4.语文排序  5.数学排序  6.英语排序  7.返回\n" );
		key = getch();
		switch( key )
		{
		case '1' :
			SearchStuName( pHead );
			getchar();
			break;
		case '2' :
			SearchStuNum( pHead );
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

void StuOnLine( pStu Pst, pStu pHead )//学生登陆在线状态
{
	char key = 0;
	while(1)
	{ 
		StuFirstPage( Pst );
		key = getch();
		system("clear");
		switch( key )
		{
		case '1' :
			StuModifyPage( Pst );
			ModifyStuSelf( Pst );//修改个人信息
			CreatStuListFile( pHead );//保存到文件
			getchar();
			break;
		case '2' :
			StuLookPage( Pst, pHead );
			break;
		case '3' :
			return;
		}
		system("clear");
	}
}
