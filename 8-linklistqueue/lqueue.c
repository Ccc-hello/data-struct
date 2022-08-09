/*=======================================================
*   Copyright (C) 2022 秦超 All rights reserved.
*   
*   filename：Lqueue.c
*   author：秦超
*   date：2022年08月08日
*   describption：
*
========================================================*/
#include "Lqueue.h"

Lqueue *Lqueue_create()
{
	Lqueue *Lq = (Lqueue *)malloc(sizeof(Lqueue));
	if(Lq == NULL)
	{
		perror("malloc Lqueue\n");
		return NULL;
	}
	Lqnode *head = (Lqnode *)malloc(sizeof(Lqnode));
	if(head == NULL)
	{
		perror("malloc Lqnode\n");
		return NULL;
	}
	head->next = NULL;
	Lq->front = head;
	Lq->rear = head;
	return Lq;
}

int is_empty(Lqueue *Lq)
{
	return Lq->front == Lq->rear;
}

int getlength(Lqueue *Lq)
{
	if(is_empty(Lq))
	{
		printf("Lq is empty\n");
		return -1;
	}
	int len = 0;
	Lqnode *p = Lq->front->next;
	while(p)
	{
		p=p->next;
		len ++;
	}
	return len;
}

void Lqueue_show(Lqueue *Lq)
{
	if(is_empty(Lq))
	{
		printf("Lq is empty\n");
		return;
	}
	Lqnode *p = Lq->front->next;
	while(p)
	{
		printf("%p---%d\n",p,p->data);
		p=p->next;
	}
}

int Lqueue_en(Lqueue *Lq,QElemType e)
{
	if(Lq == NULL)
	{
		printf("head is null\n");
		return -1;
	}
	Lqnode *s = (Lqnode *)malloc(sizeof(Lqnode));
	if(s == NULL)
	{
		perror("malloc");
		return -1;
	}
	s->next = NULL;
	Lq->rear->next = s;
	Lq->rear = s;
	s->data = e;
}

QElemType Lqueue_del(Lqueue *Lq,QElemType *e)
{
	if(Lq == NULL)
	{
		printf("Lq is null\n");
		return -1;
	}
	Lqnode *p = Lq->front->next;
	*e = p->data;
	Lq->front->next = p->next;
	free(p);
}

void clear_Lqueue(Lqueue *Lq)
{
	if(Lq == NULL)
	{
		printf("Lq is NULL\n");
		return;
	}
	Lq->rear = Lq->front;
	Lqnode *p = Lq->front->next;
	while(p)
	{
		Lq->front->next = p->next;
		free(p);
		p = Lq->front->next;
	}
	Lq->front->next = NULL;
}

void destroy_Lqueue(Lqueue *Lq)
{
	Lq->rear = Lq->front->next;
	free(Lq->rear);
	free(Lq);
}
