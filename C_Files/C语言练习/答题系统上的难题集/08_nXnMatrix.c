#include<stdio.h>

int main()
{
    int a[100][100]={0};
	int p = 0;//二维数组的行标
	int q = 0;//二维数组的列标
    int n,t;//矩阵边长n，赋值上限t
    int r;//向右输入的边界
	int d;//向下输入的边界
	int l;//向左输入的边界
	int u;//向上输入的边界
	int direction =0;//确定输入的方向，0-右，1-下，2-左，3-上
	int i;//循环参量

    printf("\n输入矩阵边长和赋值上限\n");
    scanf("%d %d",&n,&t);
    if(t > n*n)//防止输入的预设上限超出理论承受的上限
		t = n*n;

    r = n-1;    //向右输入的边界
    d = n-1;    //向下输入的边界
    l = 0;      //向左输入的边界
    u = 1;      //向上输入的边界

    for(i=1; i<=t; i++)
    {
        switch(direction)
        {
        case 0:
            a[p][q++] = i;
            if(q==r)
            {
                direction = 1;
                r--;
            }
            break;
        case 1:
            a[p++][q] = i;
            if(p==d)
            {
                direction = 2;
                d--;
            }
            break;
        case 2:
            a[p][q--] = i;
            if(q==l)
            {
                direction = 3;
                l++;
            }
            break;
        case 3:
            a[p--][q] = i;
            if(p==u)
            {
                direction = 0;
                u++;
            }
            break;
        }
    }

    printf("\n输出矩阵如下\n");
    for(p=0;p<n;p++)
    {
        for(q=0;q<n;q++)
            printf("%-4d",a[p][q]);
        printf("\n");
    }
    return 0;
}

/*
运行结果
 输入矩阵边长和赋值上限
 10 70
 
 输出矩阵如下
 1   2   3   4   5   6   7   8   9   10
 36  37  38  39  40  41  42  43  44  11
 35  64  65  66  67  68  69  70  45  12
 34  63  0   0   0   0   0   0   46  13
 33  62  0   0   0   0   0   0   47  14
 32  61  0   0   0   0   0   0   48  15
 31  60  0   0   0   0   0   0   49  16
 30  59  0   0   0   0   0   0   50  17
 29  58  57  56  55  54  53  52  51  18
 28  27  26  25  24  23  22  21  20  19
*/
