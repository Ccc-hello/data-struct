#include"stack_linklist.h"

Linkstack *create_Lstack()
{
    Linkstack *S = (Linkstack *)malloc(sizeof(Snode));
    if (S == NULL)
    {
        perror("malloc");
        return NULL;
    }
    S->next = NULL;
    return S;
}

int is_empty(Linkstack *S)
{
    return S==NULL;
}

int getlength(Linkstack *S)
{
    if(is_empty(S))
    {
        printf("Linkstack is null\n");
        return -1;
    }
    int len = 0;
    Linkstack *p = S->next;
    while(p)
    {
        p=p->next;
        len++;
    }
    return len;
}

void show_Lstack(Linkstack *S )
{
    if(is_empty(S))
    {
        printf("Lstack is NULL\n");
        return ;
    }
    Linkstack *p = S->next;
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void clear_Lstack(Linkstack *S)
{
    if (is_empty(S))
    {
        printf("linkstack is null\n");
        return;
    }
    Linkstack *p = S->next;
    while (p)
    {
        S->next = p->next;
        free(p);
        p=S->next;
    }
}

void push_Lstack(Linkstack *S,SElemType e)
{
    if (S == NULL)
    {
        printf("S is null\n");
        return ;
    }
    Linkstack *n = (Linkstack *)malloc(sizeof(Snode));
    if(n == NULL)
    {
        perror("malloc");
        return;
    }
    n->next = S->next;
    S->next = n;
    n->data = e;
}

void pop_Lstack(Linkstack *S,SElemType *e)
{
    if(S == NULL)
    {
        printf("S is null\n");
        return ;
    }
    Linkstack *p=S->next;
    *e = p->data;
    S->next = p->next;
    free(p);
}