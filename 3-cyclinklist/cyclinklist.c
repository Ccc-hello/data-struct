#include "cyclinklist.h"
#include<stdio.h>
#include<stdlib.h>

cyclinklist *creatcyclist()
{
	cyclinklist *L = (cyclinklist *)malloc(sizeof(node));
	if(L==NULL)
	{
		perror("malloc");
		return NULL;
	}
	L->next = L;
	return L;
}

int insertcyclist(cyclinklist *L,int i,ElemType e)
{
	if(L==NULL)
	{
		printf("cyclinklist is null\n");
		return -1;
	}
	if(i<0 || i>getlength(L))
	{
		printf("locate is error\n");
		return -1;
	}
	cyclinklist *s = (cyclinklist *)malloc(sizeof(node));
	if(s==NULL)
	{
		perror("malloc");
		return -1;
	}
	int k=0;
	cyclinklist *p = L;
	while(p->next != L && k<i)
	{
        p=p->next;
		i++;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;

	return 0;
}

int getlength(cyclinklist *L)
{
	if(L==NULL)
	{
		printf("cyclinklist is null\n");
		return -1;
	}
	int len=0;
	cyclinklist *p=L->next;
	while(p!=L)
	{
		len++;
		p=p->next;
	}
	return len;
}

int clearcyclist(cyclinklist *L)
{
	if(L == NULL)
	{
		printf("L == NULL\n");
		return -1;
	}
	cyclinklist *p=L->next;
	while (p != L)
	{
		L->next = p->next ;
		free(p);
		p=L->next;
	}
	return 1;
}

int cyclistshow(cyclinklist *L)
{
	if(L == NULL)
	{
		printf("cyclist is NULL\n");
		return -1;
	}
	cyclinklist *p=L->next;
	while(p != L)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	return 1;
}

int delcyclist(cyclinklist *L,int i)
{
    if(L == NULL)
    {
        printf("cyclinklist is null\n");
        return -1;
    }
    if(i <0 || i>getlength(L))
    {
        printf("the delete locate is error\n");
        return -1;
    }
    cyclinklist  *q,*p;
    p = L;
    int k=1;
	
    while( p->next != L && k < i)
    {
        p=p->next;
        k++;
    }
	q = p->next;
    p->next = q->next;
    free(q);
	return 0;
}

int changecyclist(cyclinklist *L,ElemType oldelem,ElemType newelem)
{
	if(L == NULL)
	{
		printf("L is null\n");
		return -1;
	}
	cyclinklist *p = L->next;
	while (p != L)
	{
		if(p->data == oldelem)
		{
			p->data = newelem;
		}
		p=p->next;
	}
	return 1;
}

int searchcyclist(cyclinklist *L,ElemType e)
{
	if(L == NULL)
	{
		printf("L is null\n");
		return -1;
	}
	int i=1;
	cyclinklist *p = L->next;
	while( p != L)
	{
		if(p->data == e)
		{
			printf("%d\n",i);
			return 1;
		}
		i++;
		p=p->next;
	}
	printf("%d is not in cyclinklist\n",e);
	return 1;
}