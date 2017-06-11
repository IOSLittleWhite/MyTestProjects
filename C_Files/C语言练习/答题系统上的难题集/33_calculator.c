/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void calculator(char *str, long *result);//计算器函数
long count_in_bracket(char **p);//遇到括号时括号里的计算
long count(int num1, int num2, char ch);//基本四则运算
int count_for_bit(int num);//计算一个整数的位数

int main()//主函数
{
    char str[1024] = {0};
    long result = 0;
    
    scanf("%s", str);
    
    calculator(str, &result);
    
    printf("%ld\n", result);
	return 0;//返回0
}

void calculator(char *str, long *result)//计算器函数
{
    char *p = str;
    long temp[3] = {0};//保存操作数
    char ch[3] = {0};//保存运算符
    int countn = 0;//计算操作数个数
    int countc = 0;//计算运算符个数
    
    while(*p != 0)
    {
        if(isdigit(*p))//还原操作数
        {
            temp[countn] = atoi(p);
            p += count_for_bit(temp[countn]);
            countn++;
        }
        else if(*p != '(')//获得运算符
        {
            ch[countc] = *p;
            countc++;
            p += 1;
        }
        if(*p == '(')//如果遇到括号，调用括号计算函数
        {
            temp[countn] = count_in_bracket(&p);
            countn++;
        }
        if((countn == 3 || *p == 0) && countn > 1)//如果操作数有了3个或者已经遍历所有输入则开始计算
        {
            if((countn < 3) && (*p == 0))//如果已经遍历所有输入且当前只有两个操作数
            {
                if(countc == 2)//如果第一个数有符号
                {
                    if(ch[0] == '-')
                        temp[0] = -temp[0];
                    ch[0] = ch[1];
                }
                temp[0] = count(temp[0], temp[1], ch[0]);
            }
            else if((countn == 3) && (*p == 0))//如果已经遍历所有输入且当前操作数等于3个
            {
                if(countc == 3)//如果第一个数有符号
                {
                    if(ch[0] == '-')
                        temp[0] = -temp[0];
                    ch[0] = ch[1];
                    ch[1] = ch[2];
                }
                if((ch[1] == '*' || ch[1] == '/') && (ch[0] == '+' || ch[0] == '-'))//如果第二个符号是乘或者除，先算第二对操作数
                {
                    temp[1] = count(temp[1], temp[2], ch[1]);
                    temp[0] = count(temp[0], temp[1], ch[0]);
                }
                else//否则顺序计算
                {
                    temp[0] = count(temp[0], temp[1], ch[0]);
                    temp[0] = count(temp[0], temp[2], ch[1]);
                }
            }
            else if((countn == 3) && (*p != 0))//如果操作数个数大于3个
            {
                if(countc == 3)//如果第一个数有符号
                {
                    if(ch[0] == '-')
                        temp[0] = -temp[0];
                    ch[0] = ch[1];
                    ch[1] = ch[2];
                }
                if((ch[1] == '*' || ch[1] == '/') && (ch[0] == '+' || ch[0] == '-'))//如果第二个符号是乘或者除，先算第二对操作数
                {
                    temp[1] = count(temp[1], temp[2], ch[1]);
                    countn = 2;
                    countc = 1;
                }
                else//否则顺序计算
                {
                    temp[0] = count(temp[0], temp[1], ch[0]);
                    temp[1] = temp[2];
                    ch[0] = ch[1];
                    countn = 2;
                    countc = 1;
                }
            }
        }
    }
    *result = temp[0];
}

long count_in_bracket(char **p)//遇到括号时括号里的计算
{
    long temp[3] = {0};//保存操作数
    char ch[3] = {0};//保存运算符
    int countn = 0;//计算操作数个数
    int countc = 0;//计算运算符个数
    
    *p += 1;//跳过进入函数前的'('符
    while(**p != ')')//直到碰到对等的')'才退出循环，返回计算结果
    {
        if(**p == '(')//嵌套调用自己跳过所有的连续'('
        {
            temp[countn] = count_in_bracket(p);
            countn++;
        }
        else if(isdigit(**p))//还原操作数
        {
            temp[countn] = atoi(*p);
            *p += count_for_bit(temp[countn]);
            countn++;
        }
        else if(**p != ')' && **p != '(')//获得运算符
        {
            ch[countc] = **p;
            countc++;
            *p += 1;
        }
        if((countn == 3 || **p == ')') && countn > 1)//如果操作数达到了3个或者碰到了')'，则开始计算
        {
            if((countn < 3) && (**p == ')'))//如果当前括号内只有两个操作数
            {
                if(countc == 2)//如果括号内第一个数有符号
                {
                    if(ch[0] == '-')
                        temp[0] = -temp[0];
                    ch[0] = ch[1];
                }
                temp[0] = count(temp[0], temp[1], ch[0]);
            }
            else if((countn == 3) && (**p == ')'))//如果当前括号内操作数等于3个
            {
                if(countc == 3)//如果括号内第一个数有符号
                {
                    if(ch[0] == '-')
                        temp[0] = -temp[0];
                    ch[0] = ch[1];
                    ch[1] = ch[2];
                }
                if((ch[1] == '*' || ch[1] == '/') && (ch[0] == '+' || ch[0] == '-'))//如果第二个符号是乘或者除，先算第二对操作数
                {
                    temp[1] = count(temp[1], temp[2], ch[1]);
                    temp[0] = count(temp[0], temp[1], ch[0]);
                }
                else//否则顺序计算
                {
                    temp[0] = count(temp[0], temp[1], ch[0]);
                    temp[0] = count(temp[0], temp[2], ch[1]);
                }
            }
            else if((countn == 3) && (**p != ')'))//括号内的操作数大于3个
            {
                if(countc == 3)//如果括号内第一个数有符号
                {
                    if(ch[0] == '-')
                        temp[0] = -temp[0];
                    ch[0] = ch[1];
                    ch[1] = ch[2];
                }
                if((ch[1] == '*' || ch[1] == '/') && (ch[0] == '+' || ch[0] == '-'))//如果第二个符号是乘或者除，先算第二对操作数
                {
                    temp[1] = count(temp[1], temp[2], ch[1]);
                    countn = 2;
                    countc = 1;
                }
                else//否则顺序计算
                {
                    temp[0] = count(temp[0], temp[1], ch[0]);
                    temp[1] = temp[2];
                    ch[0] = ch[1];
                    countn = 2;
                    countc = 1;
                }
            }
        }
    }
    *p += 1;
    return temp[0];
}

long count(int num1, int num2, char ch)//基本四则运算
{
    switch (ch)
	{
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}

int count_for_bit(int num)//计算一个整数的位数
{
    int result = 0;
    int temp = num;
    while (temp)
    {
        temp /= 10;
        result++;
    }
    return result;
}
