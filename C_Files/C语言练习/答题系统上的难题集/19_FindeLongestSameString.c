#include <stdio.h>  
#include <string.h> 

void LongNumSon(char *str,char *result);

int main()  
{ 
	char str[100] = {};  
	char result[50] = {};
	int i = 0;
	printf("\n输入一串数字，以空格或逗号隔开\n");
	while(1)
	{
		scanf("%c",&str[i]);
		if(getchar() == '\n')
			break;
		i++;
	}
	LongNumSon(str,result);
	printf("%s\n",result);
	return 0;  
}

void LongNumSon(char *str,char *result)
{ 
	char *p = str; 
	char *start = NULL;
	char num = 0;
	char temp = 0;
	int count = 1;

	while(*p!='\0')
	{  
		if( *(p+1) == *p )
		{
			count ++;
			temp = *p;
		}
		else
		{  
			if(temp > num)
			{  
				num = temp;
				bzero(result,strlen(result));//清空原来保存的最长字符串
				start = p-(count-1);//p当前指向最后一个连续相等的字符
				strncpy(result,start,count);//取出所有相等连续相等字符串
			}
			count = 1;  
		}  
		p++;  
	}
}  
