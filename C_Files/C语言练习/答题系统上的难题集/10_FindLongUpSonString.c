# include <stdio.h>  
# include <string.h> 
# include <ctype.h>
        
void getSubStr(char *str,char *result)
{ 
	char *p = str;//引用字符串  
    char *start = NULL;//字串开始位置的字符指针  
    int sublen = 1;//sublen连续递增数字子串的长度
	int count = 1;//count字符出现的次数，因为最后不满足条件的那个数也要计算在内，所以初始化为1
    int i;

    printf("打印出所有连续递增数字子串如下：\n");
	while(*p != 0)
	{  
        if(isdigit(*p) && isdigit(*(p+1)) && (*(p+1) == *p + 1))
            count ++;
		else
		{
            if(count > 1)//如果存在连续递增数字子串，将其打印出来
            {
                start = p-(count-1);//p是最后一个递增数字的指针位置，通过字符长度，计算字串的开始指针位置。
                for(i=0; i<count; i++)
                    printf("%c",start[i]);
                putchar(10);
            }

            if(count > sublen)//如果新得到的连续递增子串比前一个大，目的是打印出最大的串
			{  
                sublen = count;//sublen总是等于当前检测到的最长一个子串的长度
                strncpy(result,start,sublen);//复制满足条件的字串到新字符数组中。
            }
			count = 1;//计数器置为1  
        }  
   		p++;  
    }
}  
      
int main()  
{ 
    char str[100] = {0};  
    char result[50] = {0};
    printf("输入一个含有连续递增数字子串的字符串：\n");
    scanf("%[^\n]",str);  
    getSubStr(str,result);
    printf("最长的连续递增数字子串为：\n%s\n",result);
    return 0;  
}  
