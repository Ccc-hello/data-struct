#include"slqueue.h"

SLqueue *create_Queue()
{
    SLqueue *Q = (SLqueue *)malloc(sizeof(SLqueue));
    if(Q == NULL)
    {
        perror("malloc");
        return NULL;
    }
    memset(Q,0,sizeof(SLqueue));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

int is_empty(SLqueue *Q)
{
    return Q->front == Q->rear;
}

int is_full(SLqueue *Q)
{
    return (Q->rear + 1) % MAXSIZE == Q->front;
}

int getlength(SLqueue *Q)
{
    if(Q == NULL)
    {
        printf("Q is null\n");
        return -1;
    }
    return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

QElemType enqueue(SLqueue *Q,QElemType e)
{
    if (is_full(Q))
    {
        printf("SLqueue is full\n");
        return -1;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1) % MAXSIZE;
    return 0;
}

QElemType delqueue(SLqueue *Q,QElemType *e)
{
    if(is_empty(Q))
    {
        printf("SLqueue is empty\n");
        return -1;
    }
    *e = Q->data[Q->front];
    Q->data[Q->front] = 0;
    Q->front = (Q->front+1) % MAXSIZE;
    return 0;
}

void show_queue(SLqueue *Q)
{
    if(is_empty(Q))
    {
        printf("slqueue is empty\n");
        return;
    }
    int i;
    i=Q->front;
    while ( Q->front != Q->rear)
    {
        printf("%d ",Q->data[Q->front]);
        Q->front = (Q->front + 1) % MAXSIZE;
    }
    Q->front = i;
    printf("\n");
}

void clear_queue(SLqueue *Q)
{
    Q->front = Q->rear = 0;
}

void destory_slqueue(SLqueue *Q)
{
    free(Q);
}