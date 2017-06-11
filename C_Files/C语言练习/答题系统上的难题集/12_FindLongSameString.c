#include <stdio.h>
#include <string.h>

void FindSon(char *s1, char *s2, char *result);

int main()
{
    char s1[100] = {};
    char s2[100] = {};
    char result[50] = {};
    printf("\n输入连个字符串\n");
    scanf("%s %s",s1,s2);
    
    FindSon(s1,s2,result);
    printf("\n最长子串为：\n");
    printf("%s\n",result);
    
    return 0;
}

void FindSon(char *s1, char *s2, char *result)
{
    char *p = s1;
    char *start = NULL;
    int len = strlen(s2);
    int count = 1;
    int longest = 0;//最长子串
    int i,j;

    printf("\n打印出所有共同子串如下：\n");
    while(*p != '\0')
    {
        for(i=0; i<len; i++)
        {
            if(*p == s2[i] && *(p+1) == s2[i+1] && *(p+1) != 0)
            {
                count ++;
                p ++;
            }
            else if(count >1)
            {
                start = p - (count - 1);
                for(j=0; j<count; j++)//长度大于1的不论长短，打印所有相同子串
                    printf("%c",start[j]);
                putchar(10);
            
				if(count > longest)
                {
                    longest = count;
                    result = strncpy(result, start, longest);
                }
                count = 1;
            }
        }
        p ++;
    }
}

