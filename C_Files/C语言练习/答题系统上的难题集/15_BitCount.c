#include <stdio.h>

#define BIT(x) (1 << x)

int main(void)
{
	int i;
	int a;
	int n;
	int m;
	int out = 0;
	scanf("%d %d %d",&a,&n,&m);
	for(i=m; i>=n; i--)
	{
		out *= 2;
		if(a & BIT(i))
			out++;
	}
	printf("%d\n",out);
	return 0;
}
