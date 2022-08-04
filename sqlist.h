#ifndef _SQLIST_H_
#define _SQLIST_H_

#define MAXSIZE 100

typedef int data_t;

typedef struct 
{
    data_t data[MAXSIZE];
    int last;
}sqlist_t;

sqlist_t *sqlist_create();

void sqlist_init (sqlist_t **L);

void sqlist_clear(sqlist_t *L);

int is_empty(sqlist_t *L);

int is_full(sqlist_t *L);

int set_empty(sqlist_t *L);

int get_length(sqlist_t *L);

void sqlist_show (sqlist_t *L);

int sqlist_insert(sqlist_t *L,data_t x,int pos);

int  sqlist_del(sqlist_t *L,int pos);

int sqlist_change(sqlist_t *L,data_t x,int pos);

int sqlist_search(sqlist_t *L,data_t x);

#endif