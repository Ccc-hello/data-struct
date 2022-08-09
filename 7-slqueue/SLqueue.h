#ifndef _SLQUEUE_H_
#define _SLQUEUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100

typedef int QElemType;

typedef struct queue 
{
    QElemType data[MAXSIZE];
    int front;
    int rear;
}SLqueue;

SLqueue *create_Queue();

int is_empty(SLqueue *Q);

int getlength(SLqueue *Q);

QElemType enqueue(SLqueue *Q,QElemType e);

QElemType delqueue(SLqueue *Q,QElemType *e);

void show_queue(SLqueue *Q);

void clear_queue(SLqueue *Q);

void destory_slqueue(SLqueue *Q);

#endif