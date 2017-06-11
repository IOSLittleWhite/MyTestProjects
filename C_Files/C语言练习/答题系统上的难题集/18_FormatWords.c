#include <stdio.h>
#include <ctype.h>

int main()
{
	char s[100] = {0};
	char *p = s;
	int first_flag = 1;
	
	printf("\n输入一个字符串\n");
	scanf("%s",s);
    printf("\n首字母大写,其他字母小写转换后输出为：\n");
	while(*p != 0)
	{
		if(isalpha(*p) != 0)//如果是英文字母
		{
			if(first_flag)
			{
				if(islower(*p) != 0)
					*p = toupper(*p);
				first_flag = 0;
			}
			else if(*p>64 && *p<91)
				*p = tolower(*p);
		}
		p++;
	}
	printf("%s\n",s);
	return 0;
}
