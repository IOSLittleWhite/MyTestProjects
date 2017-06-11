/*********************************************************************************
名称：对学生信息表的基本操作

功能：
		构造一个空的线性单链表 
		销毁线性单链表
		将线性单链表重置为空表
		判断线性单链表是否为空，若为空表，则返回TRUE，否则返回FALSE
		返回线性单链表中数据元素个数
		用e返回线性单链表中第i个元素的值
		返回线性单链表中满足某种关系的元素的位序
		返回线性单链表中某元素的前驱
		返回线性单链表中某元素的后继
		在表线性单链表插入元素
		删除线性单链表中某元素
		依次对线性单链表中每个元素调用某函数
		手动写入生成线性单链表
		遍历显示链表内容
		线性单链表排序（升序和降序）
		将创建好的线性单链表以txt保存
		将保存在txt里的线性单链表读取出来，并创建对应的线性单链表

作者：冯生伟

完成时间：
*********************************************************************************/
# include "stulist.h"


/*******************************************************************************
一下为学生表内容进行更改的基本操作函数
包括表的创建，插入，删除，清空，销毁，
保存成文件和从文件中读取，学号防重复判断
修改学生信息
*******************************************************************************/
//初始条件：学生信息表不存在
//操作结果：手动创建学生信息表
void CreatStuList( pStu *pHead )
{
	int i, j;
	int count = 0;//链表长度
	pStu pTail, pNew;

	DestroyStuList( pHead );//在新建表前先销毁之前的废表
	*pHead = ( pStu )malloc( sizeof( Stu ) );//创建一个表头，返回头节点地址
	if( !(*pHead) )
		exit(OVERFLOW); // 存储分配失败
	pTail = *pHead;
	pTail->next = NULL;//头结点指针域指针指向空
	pTail->data = NULL;//头结点数据域指针指向空

	printf("请输入要创建的学生信息表的学生数量: ");	
	scanf("%d", &count);
	printf("\t姓名\t学号\t\t年龄\t密码\t\t语文\t数学\t英语\n");
	for( i=0; i<count; i++ )
	{
		j=1;
		pNew = ( pStu  )malloc( sizeof( Stu ) );//创建一个新节点
		if( !pNew )
			exit(OVERFLOW); // 存储分配失败
		pNew->data = ( pStr )malloc( sizeof( Str ));//分配数据域空间
		if( !pNew->data )
			exit(OVERFLOW); // 存储分配失败
		while( j )
		{
			printf("第%d个:  ", count-(count-1-i));
			scanf("%s\t%s\t%d\t%s\t%f\t%f\t%f", pNew->data->name,pNew->data->num,&pNew->data->age,pNew->data->passwd,&pNew->data->chinese,&pNew->data->math,&pNew->data->english );
			j = AvoidRepeatNum( *pHead, pNew );
		}
		pTail->next = pNew;//让pHead指向了pNew
		pNew->next = NULL;
		pTail = pNew;
	}
}

//添加学生函数
Status StuListInsert(pStu pHead)
{ 
	int i, j;
	int count = 0;//链表长度
	pStu pNew;

	printf("请输入要添加的学生数量: ");	
	scanf("%d", &count);
	printf("\t姓名\t学号\t\t年龄\t密码\t\t语文\t数学\t英语\n");
	for( i=0; i<count; i++ )
	{
		j=1;
		pNew = ( pStu  )malloc( sizeof( Stu ) );//创建一个新节点
		if( !pNew )
			exit(OVERFLOW); // 存储分配失败
		pNew->data = ( pStr )malloc( sizeof( Str ));//分配数据域空间
		if( !pNew->data )
			exit(OVERFLOW); // 存储分配失败
		while( j )
		{
			printf("第%d个:  ", count-(count-1-i));
			scanf("%s\t%s\t%d\t%s\t%f\t%f\t%f", pNew->data->name,pNew->data->num,&pNew->data->age,pNew->data->passwd,&pNew->data->chinese,&pNew->data->math,&pNew->data->english );
			j = AvoidRepeatNum( pHead, pNew );
		}
		pNew->next = pHead->next;
		pHead->next = pNew;
	}
	return OK;
}

//删除学生函数
Status StuListDelete(pStu pHead)
{ 
	int i;
	char num[20];
	int count = 0;
	pStu p = pHead;//p指向头节点
	pStu pTemp = NULL;

	if( p->next !=NULL )//如果学生表非空
	{
		printf("请输入要删除的学生数量: ");
		scanf( "%d", &count );
		for( i=0; i<count; ++i)
		{
			printf("请输入第%d个要删除的学生学号: ", count-(count-1-i));
			scanf( "%s", num );
			p = pHead;
			while( strcmp(p->next->data->num,num) != 0 )
			{
				p = p->next; 
				if(p->next == NULL)//到最后一个节点还没有与输入学号对应的学生
				{
					printf("表中没有学号为%s的学生\n", num);
					--i;//使得可以重新输入预删学生学号
					break;
				}
			}
			if(p->next != NULL)
			{
				printf("删除的学生信息为：\n");
				printf("姓名\t学号\t\t年龄\t密码\t\t语文\t数学\t英语\n");
				printf("%s\t%s\t%d\t%s\t%.1f\t%.1f\t%.1f\n", p->next->data->name,p->next->data->num,p->next->data->age,p->next->data->passwd,p->next->data->chinese,p->next->data->math,p->next->data->english );
				getchar();//等待确认
				pTemp = p->next->next;//pTemp指向预删除的学生节点的下一位学生节点
				free(p->next->data);
				free(p->next);//两步销毁了该学生所占节点
				p->next = pTemp;
			}
		}
	}
	else
	{
		system("clear");
		putchar(10);
		putchar(10);
		putchar(10);
		printf("\t\t\t操作失败！\n");
		printf("\t\t\t当前学生信息表为空！\n");
		getchar();
		return 1;
	}
	return OK;
}

//初始条件：学生信息表存在
//操作结果：将学生信息表重置为空
Status ClearStuList(pStu pHead )
{ 
	pStu p,q;
	p = pHead->next; //p指向首结点
	while(p) //没到表尾
	{
		q = p->next;//q指向首节点的直接后继
		free(p->data);//清空首节点的数据域
		free(p);//释放首节点
		p = q;//首节点的后继成为新的首节点
	}//最终保留头节点不被释放
	pHead->next = NULL; //头结点指针域为空
	return OK;
} 

//初始条件：学生信息表已存在。
//操作结果：销毁学生信息表
Status DestroyStuList( pStu *pHead )//因为函数的对外部链表进行操作，所以定义为*L以接收外部头节点的地址（重要函数）
{ 
	pStu q;
	while( *pHead )//从表头开始逐个销毁
	{
		q = (*pHead)->next;//q指向首节点
		free( (*pHead)->data );//先释放数据域
		free( *pHead );//释放头节点
		*pHead = q;//首节点成为新的头节点
	}//最终群补释放
	return OK;
}

//初始条件：学生信息表存在
//操作结果：创建文件名为StuList的txt文件，用以保存学生信息表
Status CreatStuListFile( pStu pHead )
{	
	FILE *fp = NULL;
	pStu p = pHead->next;//p指向首节点
	if((fp = fopen("StuList","wt")) == NULL)//只写或创建并打开文件StuList.txt
	{
		system("clear");
		putchar(10);
		putchar(10);
		putchar(10);
		printf("\t\t\t文件打开时出错!\n");
		getchar();
		return 1;
	}
	while( p != NULL )//如果线性单链表不为空
	{
		if((int)fwrite(p->data,sizeof(Str),1,fp) != 1)//将当前节点的数据域写入到StuList.txt文本文件
		{			
			system("clear");
			putchar(10);
			putchar(10);
			putchar(10);
			printf("\t\t\t文件写入时出错!\n");
			getchar();
			return 1;
		}
		p = p->next;
	}
	fclose(fp);//保存并关闭文件
	return OK;
}

//初始条件：保存学生信息表的txt文件存在
//操作结果：打开保存学生信息表的文件，并读取到新的学生信息表中
Status OpenStuListFile( pStu *pHead )
{
	FILE *fp = NULL;
	pStu pTail, pNew;
	pStr pTemp = NULL;//用于临时存放学生信息

	DestroyStuList( pHead );//在新建表前先销毁之前的废表	
	*pHead = ( pStu )malloc( sizeof( Stu ) );//创建一个表头，返回头节点地址
	if( !(*pHead) )
		exit(OVERFLOW); //存储分配失败
	pTail = *pHead;
	pTail->next = NULL;//头结点指针域指针指向空
	pTail->data = NULL;//头结点数据域指针指向空
	pTemp = ( pStr )malloc( sizeof( Str ));//分配临时数据域空间，临时存放学生信息

	if((fp = fopen("StuList","rt")) == NULL)//只读打开文件StuList.txt
	{
		system("clear");
		putchar(10);
		putchar(10);
		putchar(10);
		printf("\t\t\t文件打开时出错!\n");
		getchar();
		return 1;
	}

	while((int)fread(pTemp,sizeof(Str),1,fp) == 1 )//将StuList.txt文本文件写入到临时数据域空间pTemp
	{
		pNew = ( pStu  )malloc( sizeof( Stu ) );//创建一个新节点
		if( !pNew )
			exit(OVERFLOW); // 存储分配失败
		pNew->data = ( pStr )malloc( sizeof( Str ));//分配数据域空间
		if( !pNew->data )
			exit(OVERFLOW); // 存储分配失败
		*pNew->data = *pTemp;//把临时学生信息写入到新节点
		pTail->next = pNew;//让pHead指向了pNew
		pNew->next = NULL;
		pTail = pNew;
	}
	fclose(fp);//保存并关闭文件
	if((*pHead)->next == NULL)
	{
		system("clear");
		putchar(10);
		putchar(10);
		putchar(10);
		printf("\t\t\t当前学生信息表为空！\n");
		getchar();
	}
	return OK;
}

//防学号重复判断
int AvoidRepeatNum( pStu pHead, pStu pNew )//pHead为已经存在的链表，pNew为预添加的新节点
{
	pStu p = NULL;
	for( p=pHead; p->next!=NULL; p=p->next)
	{
		if(p->next != pNew)
		{
			if( (strcmp( p->next->data->num,pNew->data->num ) == 0) )//匹配姓名
			{
				printf("该学号已经被占用！\n");
				return 1;
			}
		}
	}	
	return 0;
}

//学生修改自己个人信息
void ModifyStuSelf( pStu Pst )//Pst为等待修改的学生的节点地址
{
	int time, i;
	char key = 0;
	printf("1.改姓名    2.改年龄    3.改密码    4.返回\n");
	printf("请输入要修改的项数：");
	scanf("%d", &time);
	for(i=0; i<time; i++)
	{
		printf("选择第%d项修改内容\n", time-(time-1-i));
		key = getchar();
		switch( key )
		{
		case '1': 
			printf("输入新姓名：");
			scanf("%s", Pst->data->name);
			break;
		case '2': 
			printf("输入新年龄：");
			scanf("%d", &Pst->data->age);
			break;
		case '3': 
			printf("输入新密码：");
			scanf("%s", Pst->data->passwd);
			break;
		case '4': 
			return;
		}
	}
	printf("修改后的内容为：\n");
	printf("姓名\t学号\t\t年龄\t密码\t\t语文\t数学\t英语\n");
	printf("%s\t%s\t%d\t%s\t%.1f\t%.1f\t%.1f\n", Pst->data->name,Pst->data->num,Pst->data->age,Pst->data->passwd,Pst->data->chinese,Pst->data->math,Pst->data->english );
	getchar();
}

//修改学生信息
void AdminModifyStu( pStu pHead, pStu Pst )//Pst为等待修改的学生的节点地址
{
	int time, i;
	int j;
	char key = 0;
	printf("1.改姓名  2.改学号  3.改年龄  4.改密码  5.改语文  6.改数学  7.改英语  8.返回\n");
	printf("请输入要修改的项数：");
	scanf("%d", &time);
	getchar();
	for(i=0; i<time; i++)
	{
		j = 1;
		printf("选择第%d项修改内容：\n", time-(time-1-i));
		key = getchar();
		switch( key )
		{
		case '1': 
			printf("输入新姓名：");
			scanf("%s", Pst->data->name);
			break;
		case '2': 
			while(j)
			{
				printf("输入新学号：");
				scanf("%s", Pst->data->num);
				j = AvoidRepeatNum( pHead, Pst );
			}
			break;
		case '3': 
			printf("输入新年龄：");
			scanf("%d", &Pst->data->age);
			break;
		case '4': 
			printf("输入新密码：");
			scanf("%s", Pst->data->passwd);
			break;
		case '5': 
			printf("输入新语文成绩：");
			scanf("%f", &Pst->data->chinese);
			break;
		case '6': 
			printf("输入新数学成绩：");
			scanf("%f", &Pst->data->math);
			break;
		case '7': 
			printf("输入新英语成绩：");
			scanf("%f", &Pst->data->english);
			break;
		case '8': 
			return;
		}
	}
	printf("修改后的内容为：\n");
	printf("姓名\t学号\t\t年龄\t密码\t\t语文\t数学\t英语\n");
	printf("%s\t%s\t%d\t%s\t%.1f\t%.1f\t%.1f\n", Pst->data->name,Pst->data->num,Pst->data->age,Pst->data->passwd,Pst->data->chinese,Pst->data->math,Pst->data->english );
	getchar();//等待确认
}

/**************************************************************************
一下是对学生信息表进行排序的基本操作
分别按：学号，语文，数学，英语成绩降、升序排列
**************************************************************************/
//初始条件：线性单链表存在
//操作结果：对学生信息表按学号进行降序排列(交换指针的方法)
void SortStuNumDown( pStu pHead )
{
	pStu pTemp = NULL;
	pStu pLast = NULL;//用于一轮比较截止地址，初始为表尾
	pStu p = NULL;	
	while(pLast != pHead->next->next)//如果pLast不指向第二个元素
	{
		for( p = pHead; p->next->next!=pLast; p=p->next )//排序条件至少有两个节点
		{
			if( strcmp(p->next->data->num, p->next->next->data->num)<0 )//数值大小比较
			{
				pTemp = p->next->next;
				p->next->next = pTemp->next;
				pTemp->next = p->next;
				p->next = pTemp;
			}
		}
		pLast = p->next;//一次循环出来后p->next保存的都是本次循环的最后一个地址，使循环逐渐向表头逼近
	}
}

//初始条件：线性单链表存在
//操作结果：对学生信息表按学号进行升序排列(交换指针的方法)
void SortStuNumUp( pStu pHead )
{
	pStu pTemp = NULL;
	pStu pLast = NULL;//用于一轮比较截止地址，初始为表尾
	pStu p = NULL;	
	while(pLast != pHead->next->next)//如果pLast不指向第二个元素
	{
		for( p = pHead; p->next->next!=pLast; p=p->next )//排序条件至少有两个节点
		{
			if( strcmp(p->next->data->num, p->next->next->data->num)>0 )//数值大小比较
			{
				pTemp = p->next->next;
				p->next->next = pTemp->next;
				pTemp->next = p->next;
				p->next = pTemp;
			}
		}
		pLast = p->next;//一次循环出来后p->next保存的都是本次循环的最后一个地址，使循环逐渐向表头逼近
	}
}

//初始条件：线性单链表存在
//操作结果：对学生信息表按语文成绩进行升序排列(交换指针的方法)
void SortStuChineseUp( pStu pHead )
{
	pStu pTemp = NULL;
	pStu pLast = NULL;//用于一轮比较截止地址，初始为表尾
	pStu p = NULL;	
	while(pLast != pHead->next->next)//如果pLast不指向第二个元素
	{
		for( p = pHead; p->next->next!=pLast; p=p->next )//排序条件至少有两个节点
		{
			if( p->next->data->chinese > p->next->next->data->chinese )//数值大小比较
			{
				pTemp = p->next->next;
				p->next->next = pTemp->next;
				pTemp->next = p->next;
				p->next = pTemp;
			}
		}
		pLast = p->next;//一次循环出来后p->next保存的都是本次循环的最后一个地址，使循环逐渐向表头逼近
	}
}

//初始条件：线性单链表存在
//操作结果：对学生信息表按语文成绩进行降序排列(交换指针的方法)
void SortStuChineseDown( pStu pHead )
{
	pStu pTemp = NULL;
	pStu pLast = NULL;//用于一轮比较截止地址，初始为表尾
	pStu p = NULL;	
	while(pLast != pHead->next->next)//如果pLast不指向第二个元素
	{
		for( p = pHead; p->next->next!=pLast; p=p->next )//排序条件至少有两个节点
		{
			if( p->next->data->chinese < p->next->next->data->chinese )//数值大小比较
			{
				pTemp = p->next->next;
				p->next->next = pTemp->next;
				pTemp->next = p->next;
				p->next = pTemp;
			}
		}
		pLast = p->next;//一次循环出来后p->next保存的都是本次循环的最后一个地址，使循环逐渐向表头逼近
	}
}

//初始条件：线性单链表存在
//操作结果：对学生信息表按数学成绩进行升序排列(交换指针的方法)
void SortStuMathUp( pStu pHead )
{
	pStu pTemp = NULL;
	pStu pLast = NULL;//用于一轮比较截止地址，初始为表尾
	pStu p = NULL;	
	while(pLast != pHead->next->next)//如果pLast不指向第二个元素
	{
		for( p = pHead; p->next->next!=pLast; p=p->next )//排序条件至少有两个节点
		{
			if( p->next->data->math > p->next->next->data->math )//数值大小比较
			{
				pTemp = p->next->next;
				p->next->next = pTemp->next;
				pTemp->next = p->next;
				p->next = pTemp;
			}
		}
		pLast = p->next;//一次循环出来后p->next保存的都是本次循环的最后一个地址，使循环逐渐向表头逼近
	}
}

//初始条件：线性单链表存在
//操作结果：对学生信息表按数学成绩进行降序排列(交换指针的方法)
void SortStuMathDown( pStu pHead )
{
	pStu pTemp = NULL;
	pStu pLast = NULL;//用于一轮比较截止地址，初始为表尾
	pStu p = NULL;	
	while(pLast != pHead->next->next)//如果pLast不指向第二个元素
	{
		for( p = pHead; p->next->next!=pLast; p=p->next )//排序条件至少有两个节点
		{
			if( p->next->data->math < p->next->next->data->math )//数值大小比较
			{
				pTemp = p->next->next;
				p->next->next = pTemp->next;
				pTemp->next = p->next;
				p->next = pTemp;
			}
		}
		pLast = p->next;//一次循环出来后p->next保存的都是本次循环的最后一个地址，使循环逐渐向表头逼近
	}
}

//初始条件：线性单链表存在
//操作结果：对学生信息表按英语成绩进行升序排列(交换指针的方法)
void SortStuEnglishUp( pStu pHead )
{
	pStu pTemp = NULL;
	pStu pLast = NULL;//用于一轮比较截止地址，初始为表尾
	pStu p = NULL;	
	while(pLast != pHead->next->next)//如果pLast不指向第二个元素
	{
		for( p = pHead; p->next->next!=pLast; p=p->next )//排序条件至少有两个节点
		{
			if( p->next->data->english > p->next->next->data->english )//数值大小比较
			{
				pTemp = p->next->next;
				p->next->next = pTemp->next;
				pTemp->next = p->next;
				p->next = pTemp;
			}
		}
		pLast = p->next;//一次循环出来后p->next保存的都是本次循环的最后一个地址，使循环逐渐向表头逼近
	}
}

//初始条件：线性单链表存在
//操作结果：对学生信息表按英语成绩进行降序排列(交换指针的方法)
void SortStuEnglishDown( pStu pHead )
{
	pStu pTemp = NULL;
	pStu pLast = NULL;//用于一轮比较截止地址，初始为表尾
	pStu p = NULL;	
	while(pLast != pHead->next->next)//如果pLast不指向第二个元素
	{
		for( p = pHead; p->next->next!=pLast; p=p->next )//排序条件至少有两个节点
		{
			if( p->next->data->english < p->next->next->data->english )//数值大小比较
			{
				pTemp = p->next->next;
				p->next->next = pTemp->next;
				pTemp->next = p->next;
				p->next = pTemp;
			}
		}
		pLast = p->next;//一次循环出来后p->next保存的都是本次循环的最后一个地址，使循环逐渐向表头逼近
	}
}

/*******************************其他操作***********************************/
//初始条件：线性单链表存在
//操作结果：在屏幕上为管理员打印出学生表中每个学生信息
void PrintfStuListAdmin( pStu pHead)
{	
	pStu p = pHead->next;
	if(p == NULL)
		printf("学生信息表为空！\n");
	else
	{
		printf("当前学生表内容为：\n");
		printf("姓名\t学号\t\t年龄\t密码\t\t语文\t数学\t英语\n");
		while(p)
		{
			printf("%s\t%s\t%d\t%s\t%.1f\t%.1f\t%.1f\n", p->data->name,p->data->num,p->data->age,p->data->passwd,p->data->chinese,p->data->math,p->data->english );
			p = p->next;
		}
	}
}

//初始条件：线性单链表存在
//操作结果：在屏幕上为学生打印出学生表中每个学生信息
void PrintfStuList( pStu pHead)
{	
	pStu p = pHead->next;
	if(p == NULL)
		printf("学生信息表为空！\n");
	else
	{
		printf("当前学生表内容为：\n");
		printf("姓名\t学号\t\t年龄\t语文\t数学\t英语\n");
		while(p)
		{
			printf("%s\t%s\t%d\t%.1f\t%.1f\t%.1f\n", p->data->name,p->data->num,p->data->age,p->data->chinese,p->data->math,p->data->english );
			p = p->next;
		}
	}
}

//初始条件：线性表L已存在。
//操作结果：返回L中数据元素个数
int StuListLength(pStu pHead)//即完成一次便利（重要函数）
{ 
	int i = 0;
	pStu p = pHead->next; //p指向首结点
	while(p) //没到表尾
	{
		i++;
		p = p->next;
	}
	return i;
}

//为学生进行关键词为姓名的搜索，并返符合条件的学生的节点地址
pStu SearchStuName(pStu pHead)
{ 
	char temp[50];
	pStu p = NULL;//p指向头节点

	if( pHead->next != NULL )//如果学生表非空
	{
		printf("输入学生姓名: ");//搜索条件输入部分
		scanf( "%s", temp );
		for( p=pHead; p->next!=NULL; p=p->next)
		{
			if( (strcmp(p->next->data->name,temp) == 0) )//匹配姓名
			{
				printf("搜索结果为：\n");
				printf("姓名\t学号\t\t年龄\t语文\t数学\t英语\n");
				printf("%s\t%s\t%d\t%.1f\t%.1f\t%.1f\n", p->next->data->name,p->next->data->num,p->next->data->age,p->next->data->chinese,p->next->data->math,p->next->data->english );
				getchar();//等待确认
				return p->next;
			}
		}					
		system("clear");
		putchar(10);
		putchar(10);
		putchar(10);
		printf("\t\t\t搜索结束\n");
		printf("\t\t\t列表中没有名字为%s的学生\n", temp);
		getchar();//等待确认
		return NULL;
	}
	else
	{
		system("clear");
		putchar(10);
		putchar(10);
		putchar(10);				
		printf("\t\t\t当前学生信息表为空！\n");
		printf("\t\t\t无法执行搜索！\n");
		getchar();//等待确认		
		return NULL;
	}
}

//为学生进行关键词为学号的搜索，并返符合条件的学生的节点地址
pStu SearchStuNum(pStu pHead)
{ 
	char temp[20];
	pStu p = NULL;//p指向头节点

	if( pHead->next != NULL )//如果学生表非空
	{
		printf("输入学生学号: ");//搜索条件输入部分
		scanf( "%s", temp );
		for( p=pHead; p->next!=NULL; p=p->next)
		{
			if( (strcmp(p->next->data->num,temp) == 0) )//匹配姓名
			{
				printf("搜索结果为：\n");
				printf("姓名\t学号\t\t年龄\t语文\t数学\t英语\n");
				printf("%s\t%s\t%d\t%.1f\t%.1f\t%.1f\n", p->next->data->name,p->next->data->num,p->next->data->age,p->next->data->chinese,p->next->data->math,p->next->data->english );
				getchar();//等待确认
				return p->next;
			}
		}					
		system("clear");
		putchar(10);
		putchar(10);
		putchar(10);
		printf("\t\t\t搜索结束\n");
		printf("\t\t\t列表中没有学号为%s的学生\n", temp);
		getchar();//等待确认
		return NULL;
	}
	else
	{
		system("clear");
		putchar(10);
		putchar(10);
		putchar(10);				
		printf("\t\t\t当前学生信息表为空！\n");
		printf("\t\t\t无法执行搜索！\n");
		getchar();//等待确认		
		return NULL;
	}
}

//为管理员进行关键词为姓名的搜索，并返符合条件的学生的节点地址
pStu SearchStuNameAdmin(pStu pHead)
{ 
	char temp[50];
	pStu p = NULL;//p指向头节点

	if( pHead->next != NULL )//如果学生表非空
	{
		printf("输入学生姓名: ");//搜索条件输入部分
		scanf( "%s", temp );
		for( p=pHead; p->next!=NULL; p=p->next)
		{
			if( (strcmp(p->next->data->name,temp) == 0) )//匹配姓名
			{
				printf("搜索结果为：\n");
				printf("姓名\t学号\t\t年龄\t密码\t\t语文\t数学\t英语\n");
				printf("%s\t%s\t%d\t%s\t%.1f\t%.1f\t%.1f\n", p->next->data->name,p->next->data->num,p->next->data->age,p->next->data->passwd,p->next->data->chinese,p->next->data->math,p->next->data->english );
				getchar();//等待确认
				return p->next;
			}
		}					
		system("clear");
		putchar(10);
		putchar(10);
		putchar(10);
		printf("\t\t\t搜索结束\n");
		printf("\t\t\t列表中没有名字为%s的学生\n", temp);
		getchar();
		getchar();//等待确认
		return NULL;
	}
	else
	{
		system("clear");
		putchar(10);
		putchar(10);
		putchar(10);				
		printf("\t\t\t当前学生信息表为空！\n");
		printf("\t\t\t无法执行搜索！\n");
		getchar();
		getchar();//等待确认		
		return NULL;
	}
}

//为管理员进行关键词为学号的搜索，并返符合条件的学生的节点地址
pStu SearchStuNumAdmin(pStu pHead)
{ 
	char temp[20];
	pStu p = NULL;//p指向头节点

	if( pHead->next != NULL )//如果学生表非空
	{
		printf("输入学生学号: ");//搜索条件输入部分
		scanf( "%s", temp );
		for( p=pHead; p->next!=NULL; p=p->next)
		{
			if( (strcmp(p->next->data->num,temp) == 0) )//匹配姓名
			{
				printf("搜索结果为：\n");
				printf("姓名\t学号\t\t年龄\t密码\t\t语文\t数学\t英语\n");
				printf("%s\t%s\t%d\t%s\t%.1f\t%.1f\t%.1f\n", p->next->data->name,p->next->data->num,p->next->data->age,p->next->data->passwd,p->next->data->chinese,p->next->data->math,p->next->data->english );
				getchar();//等待确认
				return p->next;
			}
		}					
		system("clear");
		putchar(10);
		putchar(10);
		putchar(10);
		printf("\t\t\t搜索结束\n");
		printf("\t\t\t列表中没有学号为%s的学生\n", temp);
		getchar();
		getchar();//等待确认
		return NULL;
	}
	else
	{
		system("clear");
		putchar(10);
		putchar(10);
		putchar(10);				
		printf("\t\t\t当前学生信息表为空！\n");
		printf("\t\t\t无法执行搜索！\n");
		getchar();
		getchar();//等待确认		
		return NULL;
	}
}

//显示学生个人信息
void ShowStuMessage( pStu Pst )
{
	printf("%s的个人信息如下：\n", Pst->data->name );
	printf("姓名\t学号\t\t年龄\t密码\t\t语文\t数学\t英语\n");
	printf("%s\t%s\t%d\t%s\t%.1f\t%.1f\t%.1f\n", Pst->data->name,Pst->data->num,Pst->data->age,Pst->data->passwd,Pst->data->chinese,Pst->data->math,Pst->data->english );
}

