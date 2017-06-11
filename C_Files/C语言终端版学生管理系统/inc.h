/*包含所有标准库头文件*/
#ifndef _INC_H
#define _INC_H

# include <string.h>    // 字符数组的函数定义的头文件
# include <ctype.h>     // 字符处理函数库
# include <limits.h>    // INT_MAX等
# include <stdio.h>     // EOF(=^Z或F6),NULL
# include <stdlib.h>    // atoi()
# include <math.h>      // floor(),ceil(),abs()
# include <termios.h>   //终端设置

/* 函数结果状态代码 */
# define TRUE 1
# define FALSE 0
# define OK 0
# define SUCCESS 0
# define INFEASIBLE -1

typedef int Status;        // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int Boolean;       // Boolean是布尔类型,其值是TRUE或FALSE

void liukong( int k );//k表示换行的行数
char getch(void);

#endif

