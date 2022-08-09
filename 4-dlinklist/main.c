#include<stdio.h>
#include "dlinklist.h"

int main()
{
    dlinklist *L = createdlist();
    if(L==NULL)
    {
        printf("L is null\n");
        return -1;
    }
    int i = 0;
    while (i<10)
    {
        insertdlist(L,i,(i+1)*10);
        i++;
    }
    printf("----inster-----\n");
    printf("length = %d\n",getlength(L));
    dlistshow(L);

    printf("----deldlist_locate-----\n");
    deldlist_locate(L,6);
    printf("length = %d\n",getlength(L));
    dlistshow(L);

    deldlist_elem(L,50);
    printf("----deldlist_elem-----\n");
    printf("length = %d\n",getlength(L));
    dlistshow(L);

    printf("----searchdlist_elem-----\n");
    printf("%d is in the dlinklist %d loctae\n",100,searchdlsit_elem(L,100));
    dlistshow(L);

    printf("length = %d\n",getlength(L));
    printf("----searchdlist_locate-----\n");
    printf("%d is in the dlinklist %d loctae\n",searchdlist_locate(L,2),2);
    

    printf("----changedlist_locate-----\n");
    printf("length = %d\n",getlength(L));
    changedlist_locate(L,5,22);
    dlistshow(L);

    printf("----changedlist_elem-----\n");
    printf("length = %d\n",getlength(L));
    changedlist_elem(L,100,88);
    dlistshow(L);

    printf("----cleardlinklist-----\n");
    cleardlist(L);
    printf("length = %d\n",getlength(L));

    

    return 0;
}