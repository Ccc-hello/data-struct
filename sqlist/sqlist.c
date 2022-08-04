#include<stdio.h>
#include<stdlib.h>
#include "sqlist.h"

sqlist_t *sqlist_create()
{
    sqlist_t *L = (sqlist_t *)malloc(sizeof(sqlist_t));
    if(L == NULL)
    {
        perror("malloc");
        return NULL;
    }
    L->last = -1;
    return L;
}

void sqlist_init (sqlist_t **L)
{
    *L = (sqlist_t *)malloc(sizeof(sqlist_t));
    if(L == NULL)
    { 
        perror("malloc");
        return ;
    }
    (*L)->last = -1;
}

void sqlist_clear(sqlist_t *L)
{
     if(L ==NULL)
    {
        printf("lis no exist\n");
        return ;
    }
    L->last = -1;
    free(L);
}


int is_empty(sqlist_t *L)
{
    if(L ==NULL)
    {
        printf("lis no exist\n");
        return -1;
    }
    return L-> last == -1 ? 1 : 0;
}

int is_full(sqlist_t *L)
{
    if(L == NULL)
    {
        printf("list no exist\n");
        return -1;
    }
    return L->last == MAXSIZE - 1;
}

int set_empty(sqlist_t *L)
{
    if(L == NULL)
    {
        printf("list no exist\n");
        return -1;
    }
    return L->last = -1;
}

int get_length(sqlist_t *L)
{
    if(L == NULL)
    {
        printf("list no exist\n");
        return -1;
    }
    int length ;
    length = L->last + 1 ;
    return length;
}

void sqlist_show (sqlist_t *L)
{
    if(L == NULL)
    {
        printf("list is no exist\n");
        return ;
    }
    int i;
    for(i =0;i<L->last+1;i++)
    {
        printf("L->data[%d]: %d\n",i,L->data[i]);
    }
    printf("***************\n");
}

int sqlist_insert(sqlist_t *L,data_t x,int pos)
{
    if(L == NULL)
    {
        printf("list no exist\n");
        return -1;
    }
    if( is_full(L) || pos < 0 ||  pos > (L->last+1))
    {
        printf("sqlist can not insert\n");
        return -1;
    }
    int i=0;
    for(i = L->last ;i>=pos ;i--)
    {
        L->data[i+1]=L->data[i];
    }
    L->data[pos]=x;
    L->last += 1;

}

int  sqlist_del(sqlist_t *L,int pos)
{
    if(L == NULL)
    {
        printf("list no exist\n");
        return -1;
    }
    if(is_empty(L) || (pos < 0) || (pos >L->last))
    {
        printf("sqlist can not delete\n");
        return -1;
    }
    int i;
    for( i = pos ; i< L->last;i++)
    {
        L->data[i] = L->data[i+1];
    }
    L->last -=1;
    return 0;
}

int sqlist_change(sqlist_t *L,data_t x,int pos)
{
    if(L == NULL)
    {
        printf ("list no exist\n");
        return -1;
    }
    if( pos < 0 || pos > L-> last )
    {
        printf("sqlist can not change\n");
        return -1;
    }
    L->data[pos] = x;
    return 0; 
}

int sqlist_search(sqlist_t *L,data_t x)
{
    if(L == NULL)
    {
        printf ("list no exist\n");
        return -1;
    }
    int i;
    for(i=0;i<= L->last;i++)
    {
        if(L->data[i]==x)
        {
            printf("search success,pos = %d\n",i);
            return i;
        }
    }
    printf("no such data %d\n",x);
    return -1;
} 