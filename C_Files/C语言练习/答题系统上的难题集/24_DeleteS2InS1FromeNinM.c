#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main(void) 
{ 
	char *p[10] = {NULL}; 
	char s[15] = {}; 
	int n;  
	int m;  
	int i;  
	int j;  
	int num = 0;  

	printf("\n输入多个字符串\n");
	while(1) 
	{   
		p[num] = (char *) malloc(15); 
		scanf("%s",p[num]); 
		if(getchar() == '\n') 
			break; 
		num++; 
	}
	printf("\n输入要搜索删除的字符串\n");
	scanf("%s", s); 
	printf("\n输入搜索起点与范围\n");
	scanf("%d %d",&n,&m); 

	for(i=0; i<m; i++) 
	{   
		if(strcmp(p[i+n], s) == 0)  
		{   
			free(p[i+n]); 
			for(j=i+n; j<num; j++) 
				p[j] = p[j+1]; 
			num--; 
			i--; 
			m--;
		}   
	}   
	printf("\n删除后输出为:\n");
	for(i=0; i<=num; i++) 
		printf("%s\n" , p[i]); 
	return 0;  
}
