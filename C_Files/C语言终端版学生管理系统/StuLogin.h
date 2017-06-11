# ifndef _STULOGIN_H
# define _STULOGIN_H

# include "stulist.h"

int StudLongin();//学生登陆过程
void StuOnLine( pStu Pst, pStu pHead );//学生登陆在线状态
void StuFirstPage( pStu pHead);//学生登陆后的操作界面
void StuModifyPage( pStu Pst );//学生修改个人信息页
void StuLookPage( pStu Pst, pStu pHead );//学生查看花名册页

# endif
