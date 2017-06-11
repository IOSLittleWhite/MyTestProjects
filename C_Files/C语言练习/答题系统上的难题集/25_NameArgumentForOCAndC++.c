#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 

void change(char *s, int flag); 
void judege(char *s, int *flag); 

int main(int argc,char *argv[]) 
{ 
	char input[1024] = {0}; 
	int flag = 0; 

	printf("\n输入一个首字母大写,或有下划线无大写字母的字符串\n");
	fgets(input,1024,stdin); 
	if(input[strlen(input) - 1] == '\n')
		input[strlen(input) - 1] = '\0';

	judege(input,&flag); 
	if(flag == 2) 
		printf("不符合任何命名规则!!!\n"); 
	else
	{
		change(input, flag); 
		printf("\n转换后的字符串为\n%s\n",input); 
	}
	return 0; 
} 

void judege(char *s,int *flag) 
{ 
	int len = strlen(s);
	int i;
	int flag_upper = 0;//大写字母检测标志
	int flag_ch = 0;//下划线检测标志
	char *p = s;

	for(i=0; i<len; i++) 
	{ 
		if(isupper(p[i])) 
		{ 
			flag_upper = 1; 
		} 
		if(p[i] == '_') 
		{ 
			flag_ch = 1; 
		} 
		if(flag_upper && flag_ch) 
		{ 
			*flag = 2;//下划线和大写同事存在
			return; 
		} 
	} 
	if(flag_upper) 
	{ 
		*flag = 1;//有大写字母没有下划线
		return; 
	} 
	*flag = 0;//有大写字母没有下划线
	return; 
} 

void change(char *s, int flag) 
{ 
	int len = strlen(s);
	int i = 0;
	int j = 0; 
	char *p = s;
	char ss[1024] = {0};
	char *q = ss;

	switch(flag) 
	{ 
		case 0 : 
			for(i=0; i<len; i++) 
			{ 
				if(p[i] == '_') 
				{ 
					i++; 
					q[j++] = toupper(p[i]); 
				} 
				else 
				{ 
					q[j++] = p[i]; 
				} 
			}
			break;
		case 1 : 
			for(i=0; i<len; i++) 
			{ 
				if(isupper(p[i])) 
				{ 
					q[j++] = '_'; 
					q[j++] = tolower(p[i]); 
				} 
				else 
				{ 
					q[j++] = p[i]; 
				} 
			} 
	} 
	bzero(s, len);
	strcpy(s,ss);
}
