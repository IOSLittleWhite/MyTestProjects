#include <stdio.h>

int main()
{
	int num = 1401001;
    int start = 0;

    while(1)
    {
        printf("%d\n",num);
        num++;
        if(num == 1401031)
            num = 1401001;
	}
}