#include <stdio.h>  
#include <string.h> 
        
void DeleteChar(char *str, char ch)
{ 
    int len = strlen(str);
    int i = 0;
    int j;
    
    for(i=len-1; i>=0; i--) 
    {     
        if(str[i] == ch)
        {
            for(j=i; j<len-1; j++)
                str[j] = str[j+1];
            str[j] = 0;
            len--;
        }  
    }
}  
      
int main()  
{ 
    char str[50] = {};
    char ch;
	printf("\n输入字符串和欲删除掉的字符，以空格隔开\n");
    scanf("%s %c",str,&ch);  
    DeleteChar(str,ch);
    printf("\n删除后的字符串为：\n%s\n",str);
    return 0;  
}
