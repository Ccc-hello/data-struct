#include<stdio.h>
#include<stdlib.h>
#include"dlinklist.h"

dlinklist *createdlist()
{
    dlinklist *L = (dlinklist *)malloc(sizeof(node));
    if(L == NULL)
    {
        perror("malloc");
        return NULL;
    }
    L->next = NULL;
    L->prior = NULL;
    return L;
}

void insertdlist(dlinklist *L,int i, ElemType e)
{
    if(L ==NULL)
    {
        printf("L is null\n");
        return ;
    }
    dlinklist *s = (dlinklist *)malloc(sizeof(node));
    dlinklist *p = L;
    if(s==NULL)
    {
        perror("malloc");
        return ;
    }
    s->next = NULL;
    s->prior = NULL;
    s->data = e;
    int k=0;
    while(p && k<i)
    {
        p=p->next;
        k++;
    }
    if(p->next == NULL)
    {
        p->next = s;
        s->prior = p;
    }
    else
    {
        s->next = p->next;
        p->next->prior = s;
        s->prior = p;
        p->next =s;
    }
    
}

void cleardlist(dlinklist *L)
{
    if(L == NULL)
    {
        printf("L is null\n");
        return;
    }
    dlinklist *p = L->next;
    while (p)
    {
       L->next = p->next;
       free(p);
       p = L->next;
    }
}

int getlength(dlinklist *L)
{
    if(L == NULL)
    {
        printf("L is null\n");
        return -1;
    }
    int len=0;
    dlinklist *p = L->next;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

void dlistshow(dlinklist *L)
{
    if(L == NULL)
    {
        printf("L is null\n");
        return ;
    }
    dlinklist *p = L->next;
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int deldlist_locate(dlinklist *L,int i)
{
    if(L == NULL)
    {
        printf("L is null\n");
        return -1;
    }
    if ( i < 0 || i>getlength(L))
    {
        printf("delete locate is error\n");
        return -1;
    }
    int k=1;
    dlinklist *p = L->next;
    while (k<i && p)
    {
        p=p->next;
        k++;
    }
    p->next->prior = p->prior;
    p->prior->next = p->next;
    free(p);
    return 0;
}

int deldlist_elem(dlinklist *L,ElemType e)
{
    if(L == NULL)
    {
        printf("L is null\n");
        return -1;
    }
    dlinklist *p = L->next;
    while (p)
    {
        if(e == p->data)
        {
            p->next->prior = p->prior;
            p->prior->next = p->next;
            free(p);
            return 1;
        }
        p=p->next;
    }
    printf("the %d is not in dlinklist\n"),e;
    return 0;
}

int searchdlsit_elem(dlinklist *L , ElemType e)
{
    if(L == NULL)
    {
        printf("L is null\n");
        return -1;
    }
    int k = 1;
    dlinklist *p=L->next;
    while (p)
    {
        if(p->data == e)
        {
            return k;
        }
        k++;
        p=p->next;
    }
    printf("%d is not dlinlist\n");
    return 0;
}

ElemType searchdlist_locate(dlinklist *L,int i)
{
    if(L == NULL)
    {
        printf("L is null\n");
        return -1;
    }
    if(i<0 || i>getlength(L))
    {
        printf("search in locate error\n");
        return -1;
    }
    int k=1;
    dlinklist *p = L->next;
    while (k < i && p)
    {
        p=p->next;
        k++;
    }
    return p->data;
}

int  changedlist_locate(dlinklist *L, int i,ElemType newelem)
{
    if(L == NULL)
    {
        printf("L is null\n");
        return -1;
    }
    if(i<0 || i>getlength(L))
    {
        printf("changdlist locate error\n");
        return -1;
    }
    dlinklist *p = L->next;
    int k=1;
    while(k<i && p)
    {
        p=p->next;
        k++;
    }
    p->data = newelem;
    return 0;
}

int changedlist_elem(dlinklist *L,ElemType oldelem,ElemType newelem)
{
    if(L == NULL)
    {
        printf("L is null\n");
        return -1;
    }
    dlinklist *p = L->next;
    while (p)
    {
        if (p->data == oldelem)
        {
            p->data = newelem;
            return 0;
        }
        p=p->next;
    }
    printf("%d is not in dlinklist\n",oldelem);
    return 0;
}