#ifndef _CYCLINKLIST_H_
#define _CYCLINKLIST_H_

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
}node;

typedef struct node cyclinklist;

cyclinklist *creatcyclist();

int insertcyclist(cyclinklist *L,int i,ElemType e);

int getlength(cyclinklist *L);

int cyclistshow(cyclinklist *L);

int delcyclist(cyclinklist *L,int i);

int clearcyclist(cyclinklist *L);

int changecyclist(cyclinklist *L,ElemType oldelem,ElemType newelem);

int searchcyclist(cyclinklist *L,ElemType e);

#endif