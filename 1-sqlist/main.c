#include<stdio.h>
#include"sqlist.h"

int main()
{
    sqlist_t *L= sqlist_create();
    printf("L:%p\n",L);

    if(is_full(L)== 1)
    {
        printf("full!\n");
    }
    else
    {
        printf("no full\n");
    }

    int i=1;
    while(i<11)
    {
        sqlist_insert(L,i*10,i-1);
        i++;
    }
    sqlist_show(L);
    sqlist_del(L,5);
    sqlist_show(L);
    sqlist_change(L,999,2);
    sqlist_show(L);
    sqlist_search(L,80);
    //printf("------------\n");
    sqlist_clear(L);
    //printf("-----------\n");
    sqlist_show(L);
    printf("%p\n",L);
    L=NULL;
    return 0;
}