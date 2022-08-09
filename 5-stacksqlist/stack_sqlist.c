#include "stack_sqlist.h"
#include<stdlib.h>


SqStack *create_stack()
{
    SqStack *S = (SqStack *)malloc(sizeof(SqStack));
    if(S == NULL)
    {
        perror("maloc");
        return NULL;
    }
    memset(S,0,sizeof(S));
    S->top = -1;
    return S;
}

int is_empty(SqStack *S)
{
    return S->top == -1;
}

int is_full(SqStack *S)
{
    return S->top == MAXSIZE-1;
}

int getlength(SqStack *S)
{
    if(S == NULL)
    {
        printf("s is null\n");
        return -1;
    }
    int len=0;
    len = S->top+1;
    return len;
}

int SqStack_show(SqStack *S)
{
    if( S == NULL)
    {
        printf("s is null\n");
        return -1;
    }
    int i=0;
    for(i=0;i<=S->top;i++)
    {
        printf("%d ",S->data[i]);
    }
    printf("\n");
}

int SqStack_push(SqStack *S,SElemType e)
{
    if (S == NULL)
    {
        printf("s is null\n");
        return -1;
    }
    if(is_full(S))
    {
        printf(" S is full\n");
        return -1;
    }
    S->data[S->top+1] = e;
    S->top++;
    return 0;
}

int SqStack_pop(SqStack *S,SElemType *e)
{
    if(S == NULL)
    {
        printf("S is NULL\n");
        return -1;
    }
    if(is_empty(S))
    {
        printf("S is empty\n");
        return -1;
    }
    *e = S->data[S->top];
    S->data[S->top] = 0;
    S->top--;
}

void clear_stack(SqStack *S)
{
    if(S ==NULL)
    {
        printf("S is null\n");
        return ;
    }
    S->top = -1;
}

void destroy_stack(SqStack *S)
{
    free(S);
}