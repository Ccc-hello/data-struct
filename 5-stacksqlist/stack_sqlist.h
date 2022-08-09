#ifndef _STACK_SQLIST_H_
#define _STACK_SQLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100

typedef int SElemType;
typedef struct 
{
    SElemType data[MAXSIZE];
    int top;
}SqStack;

SqStack *create_stack();

int is_empty(SqStack *S);

int is_full(SqStack *S);

int getlength(SqStack *S);

int SqStack_show(SqStack *S);

int SqStack_push(SqStack *S,SElemType e);

int SqStack_pop(SqStack *S,SElemType *e);

void clear_stack(SqStack *S);

void destroy_stack(SqStack *S);

#endif