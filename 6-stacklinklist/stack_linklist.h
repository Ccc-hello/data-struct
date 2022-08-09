#ifndef _STACK_LINKLIST_H_
#define _STACK_LINKLIST_H_

#include<stdlib.h>
#include<stdio.h>

typedef int SElemType;

typedef struct stack_node
{
    SElemType data;
    struct stack_node *next;
}Snode;

typedef struct stack_node Linkstack;

Linkstack *create_Lstack();

int is_empty(Linkstack *S);

int getlength(Linkstack *S);

void show_Lstack(Linkstack *S );

void clear_Lstack(Linkstack *S);

void push_Lstack(Linkstack *S,SElemType e);

void pop_Lstack(Linkstack *S,SElemType *e);

#endif
