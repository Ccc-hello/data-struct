/*=======================================================
*   Copyright (C) 2022 秦超 All rights reserved.
*   
*   filename：linklist.h
*   author：秦超
*   date：2022年08月03日
*   describption：
*
========================================================*/
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *next;
}node;

typedef struct node LinkList;

LinkList *CreateList();

int getlength(LinkList *l);

void LinkListshow(LinkList *L);

int InsertList(LinkList *L,int i, ElemType e);

int dellist(LinkList *L,int i);

int clearlist(LinkList *L);

LinkList *overturnlist(LinkList *L);

LinkList *searchlist(LinkList *L,ElemType e);

ElemType getlistelem(LinkList *L,int i);

void changelist(LinkList *L,ElemType oldelem,ElemType newelem);

int sortlist_insert(LinkList *L,ElemType e);

#endif
