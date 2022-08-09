#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack_sqlist.h"

int main()
{
    SqStack *S = create_stack();
    if(S == NULL)
    {
        printf("S isNULL\n");
        return -1;
    }
    int i=0;
    SElemType e;
    while (i<10)
    {
        SqStack_push(S,(i+1)*10);
        i++;
    }
    SqStack_show(S);
    printf("length = %d\n",getlength(S));

    SqStack_pop(S,&e);
    SqStack_show(S);
    printf("the pop element is %d\n",e);
    printf("length = %d\n",getlength(S));

    clear_stack(S);
    SqStack_show(S);
    printf("length = %d\n",getlength(S));

    destroy_stack(S);
    SqStack_show(S);
    return 0;
}