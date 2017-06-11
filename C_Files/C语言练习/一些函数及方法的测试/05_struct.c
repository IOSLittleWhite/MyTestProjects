/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct student
{
	char name[100];
	int age;
	char sex[5];
	float weight;
	void (*motto)(char *);//座右铭
	struct student *mom;
}*pStu, Stu;

void Motto(char *s)
{
	printf("%s\n",s);
}

int main(int argc, int *argv[])
{
	pStu stu2 = (pStu)malloc(sizeof(Stu));
	char motto[100] = {};
	scanf("%s",motto);
	stu2->motto = Motto;
	stu2->motto(motto);
	strcpy(stu2->name,"xiaobai");
	printf("%s\n",stu2->name);
	return 0;//返回0
}
