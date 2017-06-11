# include "inc.h"

void liukong( int k )
{
	int i;
	for(i=0; i<k;i++)
		putchar(10);
}

char getch(void)
{
	struct termios raw,save;
	tcgetattr(0,&save);
	cfmakeraw(&raw);
	tcsetattr(0,0,&raw);
	char ch;
	system("stty -icanon");
	ch=getchar();
	system("stty icanon");
	fflush(NULL);
	tcsetattr(0,0,&save);
	return ch;
}