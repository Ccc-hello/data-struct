/*=======================================================
*   Copyright (C) 2022 秦超 All rights reserved.
*   
*   filename：Lqueue.h
*   author：秦超
*   date：2022年08月08日
*   describption：
*
========================================================*/
#ifndef _LQUEUE_H_
#define _LQUEUE_H_

#include<stdio.h>
#include<stdlib.h>

typedef int QElemType;
typedef struct node 
{
	QElemType data;
	struct node *next;
}Lqnode;
typedef struct Squeue
{
	struct node *front,*rear;
}Lqueue;

Lqueue *Lqueue_create();

int is_empty(Lqueue *Lq);

int getlength(Lqueue *Lq);

void Lqueue_show(Lqueue *Lq);

int Lqueue_en(Lqueue *Lq,QElemType e);

QElemType Lqueue_del(Lqueue *Lq,QElemType *e);

void clear_Lqueue(Lqueue *Lq);

void destroy_Lqueue(Lqueue *Lq);

#endif
