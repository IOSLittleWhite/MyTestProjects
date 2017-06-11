#include <stdio.h>
int main()
{
	int mm = 1;
	int zz = 0;
	int m1,z1,m2,z2;
	int gg = 2;
	printf("\n输入两个分数，以空格区分\n");
	scanf("%d/%d %d/%d",&z1,&m1,&z2,&m2);
    
    //找分母的公倍数,通分求和
	while(1)
	{
		if((mm%m1==0) && (mm%m2==0))
            break;
		mm++;
	}
	zz = z1 * mm / m1 + z2 * mm/m2;//计算通分后的分子和
    
    //约分
	if(zz == mm)
		printf("\n两分数和为:\n1\n");
	else
	{
		while(gg != mm)
		{
			if((mm%gg==0) && (zz%gg==0))
			{
				mm /= gg;
				zz/= gg;
				gg = 1;
			}
			gg++;
		}
		if(zz%mm == 0)
			printf("\n两分数和为:\n%d\n",zz/mm);
		else
			printf("\n两个分数的和为:\n%d/%d\n",zz,mm);
	}
	return 0; 
}
/*
运行结果
 输入两个分数，以空格区分
 3/4 13/44
 
 两个分数的和为:
 23/22
*/