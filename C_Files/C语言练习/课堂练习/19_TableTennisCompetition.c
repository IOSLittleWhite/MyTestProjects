#include <stdio.h>
int main()
{
	char i,j,k;   /*i是a的对手，j是b的对手，k是c的对手*/
	for(i='x';i<='z';i++)
		for(j='x';j<='z';j++)
		{
			if(i!=j)
				for(k='x';k<='z';k++)
				{
					if(i!=k && j!=k)
					{
						if(i!='x' && k!='x'&& k!='z')
							printf("三队赛手的对决名单为\n a--%c\t b--%c\t c--%c\n",i,j,k);
					}
				}
		}
	return 0;
}
//       order is a--z    b--x    c--y
//       //       请按任意键继续. . .
