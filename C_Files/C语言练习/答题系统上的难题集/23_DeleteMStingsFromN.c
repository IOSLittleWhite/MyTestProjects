#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *p[10] = {NULL};
	int n;
	int m;
	int i;
	int num = 0;

	printf("\n输入多个字符串，以空格隔开\n");
	while(1)
	{
		p[num] = (char *) malloc(15);
		scanf("%s",p[num]);
		if(getchar() == '\n')
			break;
		num++;
	}
	printf("\n输入删除起点和个数\n");
	scanf("%d %d", &n, &m);

	for(i=0; i<m; i++)
	{
		free(p[i+n]);
		p[i+n] = p[i+n+m];
	}
	for(; i+n<=num; i++)
		p[i+n] = p[i+n+m];
	printf("\n删除后输出为\n");
	for(i=0; i<=num-m; i++)
		printf("%s\n" , p[i]);
	return 0;
}
