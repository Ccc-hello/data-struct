/*=======================================================
 *   Copyright (C) 2022 秦超 All rights reserved.
 *   
 *   filename：linklist.c
 *   author：秦超
 *   date：2022年08月03日
 *   describption：
 *
 ========================================================*/
#include"linklist.h"
#include<stdlib.h>
#include<stdio.h>

LinkList *CreateList()
{
	LinkList *L = (LinkList *)malloc(sizeof(node));
	if(L==NULL)
	{
		perror("malloc");
		return NULL;
	}
	L->next = NULL;
	return L;
}

int getlength(LinkList *L)
{
	if(L == NULL)
	{
		printf("LinkList is NULL\n");
		return -1;
	}
	int len=0;
	LinkList *p = L->next;
	while(p)
	{
		len++;
		p=p->next;
	}
	return len;
}

void LinkListshow(LinkList *L)
{
	LinkList *p=L->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

int InsertList(LinkList *L,int i,ElemType e)
{
	if(L == NULL)
	{
		printf("the linklist is null\n");
		return -1;
	}
	if(i<0 || i>getlength(L))
	{
		printf("insert locate is error\n");
		return -1;
	}
	LinkList *s = (LinkList *)malloc(sizeof(node));
	LinkList *p;
	p=L;
	int k=1;
	while(p && k<=i)
	{
		k++;
		p=p->next;

	}
	s->data = e;
	s->next = p->next;
	p->next = s;

	return 0;
}

int dellist(LinkList *L,int i)
{
	if(L == NULL)
	{
		printf("linklist is null\n");
	}
	if(i<0 || i>getlength(L))
	{
		printf("the locate is error\n");
	}
	int k=1;
	LinkList *p,*q;
	p=L->next;
	while(p && k<=i )
	{
		p=p->next;
		k++;
	}
	q=p->next;
	p->next = q->next;
	free(q);
	return 0;
}

int clearlist(LinkList *L)
{
	if(L==NULL)
	{
		printf("the linklist is null\n");
		return -1;
	}
	LinkList *p,*q;
	p=L->next;
	while (p)
	{	
		q=p->next;
		free(p);
		p=q;
	}
	L->next =NULL;
	return 1;
}

LinkList *searchlist(LinkList *L,ElemType e)
{
	if(L==NULL)
	{
		printf("linklist is null\n");

	}
	LinkList *p=L->next;
	while (p)
	{
		if (p->data==e)
		{
			return p;
		}
		p=p->next;	
	}
	return L;
}

ElemType getlistelem(LinkList *L,int i)
{
	if(L==NULL)
	{
		printf("linklist is null\n");
		return -1;
	}
	if(i<0 || i>getlength(L))
	{
		printf("the locate is error\n");
	}
	LinkList *p=L->next;
	int k=1;
	while(p && k<i)
	{
		p=p->next;
		k++;
	}
	return p->data;


}

LinkList *overturnlist(LinkList *L)
{
	LinkList *p,*q;
	if(L==NULL)
	{
		printf("linklist is null\n");
	}
	p=L->next;
	L->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		q->next =L->next;
		L->next = q;
	}
	return L;
}

void changelist(LinkList *L,ElemType oldelem,ElemType newelem)
{	
	if(L==NULL)
	{
		printf("linklist is null\n");
	}
	LinkList *p =L->next;
	while(p)
	{
		if(p->data == oldelem)
			p->data = newelem;
		p=p->next;
	}
}

void sortlist(LinkList *L)
{
	if(L==NULL)
	{
		printf("linklist is null\n");
	}
	LinkList *p,*q,*r;
	p=L->next;
	L->next = NULL;
	while(p)
	{
		q=p;
		p=p->next;
		r=L;
		while(r->next && r->next->data < q->data)
			r=r->next;
		q->next = r->next;
		r->next = q;

	}
}

int sortlist_insert(LinkList *L,ElemType e)
{
	if(L==NULL)
	{
		printf("linklist is null\n");
		return -1;
	}
	LinkList *p = (LinkList *)malloc(sizeof(node));
	p=L;
	p->data=e;
	LinkList *q;	
	q=p->next;
	while(p && q->data > q->next->data)
			p=p->next;
	p->next = q->next;
	q->next = p;
}
