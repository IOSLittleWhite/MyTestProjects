#include <stdio.h>

int main()
{
	int ip[4] = {};
	char ch[4] = {};
	int okip = 1;
	int okch = 1;
	int i = 0;
	printf("\n\t\t\t判断输入的IP地址是否合法\n输入一个IP地址\n");
	for(i=0; i<4; i++)
	{
		scanf("%d", &ip[i]);
		ch[i] = getchar();
	}

	for(i=0; i<4; i++)
	{
		if(ip[i] > 255 || ip[0] == 0)
			okip = 0;
	}
	for(i=0; i<3; i++)
	{
		if(ch[i] != '.')
			okch = 0;
	}
    
	if(okip && okch)
		puts("OK");
	else
		puts("NO");
	return 0;
}
