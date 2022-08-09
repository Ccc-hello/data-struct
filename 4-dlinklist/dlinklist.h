#ifndef _DLINKLIST_H_
#define _DLINKLIST_h

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct  node
{
    ElemType data;
    struct node *next;
    struct node *prior;
}node;

typedef struct node dlinklist;

dlinklist *createdlist();

void insertdlist(dlinklist *L,int i, ElemType e);

void cleardlist(dlinklist *L);

int getlength(dlinklist *L);

void dlistshow(dlinklist *L);

int deldlist_locate(dlinklist *L,int i);

int deldlist_elem(dlinklist *L,ElemType e);

int searchdlsit_elem(dlinklist *L , ElemType e);

ElemType searchdlist_locate(dlinklist *L,int i);

int changedlist_locate(dlinklist *L, int i,ElemType newelem);

int changedlist_elem(dlinklist *L,ElemType oldelem,ElemType newelem);

#endif