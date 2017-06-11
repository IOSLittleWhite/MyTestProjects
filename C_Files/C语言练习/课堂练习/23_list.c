/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stu{
	char name[127];
	char sex;
	int age;
	float weight;
	float height;
}Stu, *pStu;

typedef struct node{
	Stu Stud;//数据域

	struct node *next;//指针域
}Node, *pNode;

void Create_List(pNode *pHead);
void Show_List(pNode pHead);

int main(int argc, int *argv[])
{ 
	pNode pHead = NULL;

	Create_List( &pHead );
	Show_List( pHead );

	return 0;//返回0
}

void Create_List(pNode *pHead)
{
	pNode pTail;
	pNode pNew;
	int len = 0;//欲建链表长度
	int i = 0;

	printf("输入欲添加学生的数量\n");
	scanf("%d",&len);

	*pHead = (pNode)malloc(sizeof(Node));
	pTail = *pHead;
	pTail -> next = NULL;

	printf("\tname\tsex\tage\tweight\theight\n");
	for(i = 0; i < len; i++)
	{
		printf("第%d个:\t",i + 1);
		pNew = (pNode)malloc(sizeof(Node));
		scanf("%s\t%c\t%d\t%f\t%f",pNew->Stud.name,&pNew->Stud.sex,&pNew->Stud.age,&pNew->Stud.weight,&pNew->Stud.height);
		pNew -> next = NULL;

		pTail -> next = pNew;
		pTail = pNew;
	}
}

void Show_List(pNode pHead)
{
	pNode p = pHead;

	printf("name\tsex\tage\tweight\theight\n");
	while(p -> next != NULL)
	{
		printf("%s\t%c\t%d\t%.1f\t%.1f\n",p->next->Stud.name,p->next->Stud.sex,p->next->Stud.age,p->next->Stud.weight,p->next->Stud.height);
		p = p -> next;
	}
}
