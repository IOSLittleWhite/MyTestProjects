#include <stdio.h>


int main ()
{
	char a[20];
	int b,d;
	scanf("%[^\n]",a);
	b = sizeof(a);
	d = strlen(a);
	puts(a);
	putchar(10);
	printf("size = %d, len = %d",b,d);
	putchar(13);
	getchar();
	getchar();
	return 0;

}