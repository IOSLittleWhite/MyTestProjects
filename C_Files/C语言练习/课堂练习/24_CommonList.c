/*******************************************
 *作者：冯生伟
 *时间：2014千锋培训期间
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
	void *data;
	int (*func) (char *);//数据域

	struct node *next;//指针域
}Node, *pNode;

void Create_List(pNode *pHead);
void Show_List(pNode pHead);
int check(char *input);

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
    int ok = 0;
	int count = 1;

	*pHead = (pNode)malloc(sizeof(Node));
	pTail = *pHead;
	pTail -> next = NULL;

	while(1)
	{
		printf("第%d个:\t",count);
		pNew = (pNode)malloc(sizeof(Node));
		pNew -> data = (char *)malloc(sizeof(char)*100);
		scanf("%s",(char *)pNew->data);
        pNew -> func = check;
		pNew -> next = NULL;
        
		pTail -> next = pNew;
		pTail = pNew;
        
        if(pNew->func(pNew->data))
            break;
		count++;
	}
}

void Show_List(pNode pHead)
{
	pNode p = pHead;

	while(p -> next != NULL)
	{
		printf("%s\n",((char *)p->next->data));
		p = p -> next;
	}
}

int check(char *input)
{
    if(strcmp(input,"100") == 0)
        return 1;
    else
        return 0;
}
