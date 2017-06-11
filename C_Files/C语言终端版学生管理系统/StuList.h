/**********************************************************************
名称：对学生信息表的基本操作
功能：创建学生空表
	  销毁学生表
	  删除学生表全部信息
	  计算表中记录的学生个数
	  返回第i个学生的信息
作者：冯生伟
	
**********************************************************************/
# ifndef _STULIST_H
# define _STULIST_H

# include "inc.h"

//定义一个记录的数据结构（以学生信息为例）
typedef struct str
{
	char name[50];	//姓名
	char num[20];	//学号
	int age;		//年龄
	char passwd[20];//密码	
	float english;	//英语成绩
	float math;		//数学成绩
	float chinese;	//语文成绩
}Str, *pStr;

//记录表节点结构
typedef struct stu
{
	pStr data;			//数据域
	struct stu *next;	//指针域
}Stu, *pStu;


void CreatStuList( pStu *pHead );//手动创建学生信息表
Status StuListInsert(pStu pHead);//添加学生函数
Status StuListDelete(pStu pHead);//删除学生函数
Status ClearStuList(pStu pHead );//将学生信息表重置为空
Status DestroyStuList( pStu *pHead );//销毁学生信息表
Status CreatStuListFile( pStu pHead );//创建文件名为StuList的txt文件，用以保存学生信息表
Status OpenStuListFile( pStu *pHead );//打开保学生信息表的文件，并读取到新的学生信息表中
int AvoidRepeatNum( pStu pHead, pStu pNew );//防学号重复判断,pHead为已经存在的链表，pNew为预添加的新节点
void AdminModifyStu( pStu pHead, pStu Pst );//修改学生信息，Pst为等待修改的学生的节点地址
void ModifyStuSelf( pStu Pst );//学生修改自己个人信息,Pst为等待修改的学生的节点地址

void SortStuNumDown( pStu pHead );//对学生信息表按学号进行降序排列
void SortStuNumUp( pStu pHead );//对学生信息表按学号进行升序排列
void SortStuChineseUp( pStu pHead );//对学生信息表按语文成绩进行升序排列
void SortStuChineseDown( pStu pHead );//对学生信息表按语文成绩进行降序排列
void SortStuMathUp( pStu pHead );//对学生信息表按数学成绩进行升序排列
void SortStuMathDown( pStu pHead );//对学生信息表按数学成绩进行降序排列
void SortStuEnglishUp( pStu pHead );//对学生信息表按英语成绩进行升序排列
void SortStuEnglishDown( pStu pHead );//对学生信息表按英语成绩进行降序排列

void PrintfStuList( pStu pHead);//在屏幕上为学生打印出链表每个学生的信息
void PrintfStuListAdmin( pStu pHead);//在屏幕上为管理员打印出学生表中每个学生信息
int StuListLength(pStu pHead);//求表长，即学生个数
pStu SearchStuName(pStu pHead);//为学生进行关键词为姓名的搜索，并返符合条件的学生的节点地址
pStu SearchStuNum(pStu pHead);//为学生进行关键词为学号的搜索，并返符合条件的学生的节点地址
pStu SearchStuNameAdmin(pStu pHead);//为管理员进行关键词为姓名的搜索，并返符合条件的学生的节点地址
pStu SearchStuNumAdmin(pStu pHead);//为管理员进行关键词为学号的搜索，并返符合条件的学生的节点地址
void ShowStuMessage( pStu Pst );//显示学生个人信息

#endif
