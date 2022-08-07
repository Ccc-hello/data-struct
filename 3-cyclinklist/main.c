#include<stdio.h>
#include<stdlib.h>
#include "cyclinklist.h"

int main()
{
    cyclinklist *L = creatcyclist();
    if(L == NULL)
    {
        printf("L is NULL\n");
        return -1;
    }
    int i=0;
    while (i<10)
    {
        insertcyclist(L,i,(i+1)*10);
        i++;
    }
    printf("----insert-------\n");
    printf("length = %d\n",getlength(L));
    cyclistshow(L);
    printf("\n");

    printf("----delete-------\n");
    delcyclist(L,6);
    printf("length = %d\n",getlength(L));
    cyclistshow(L);
    printf("\n");

    printf("----change-------\n");
    changecyclist(L,50,66);
    cyclistshow(L);
    printf("\n");

    printf("----search-------\n");
    searchcyclist(L,71);

    printf("----clear-------\n");
    clearcyclist(L);
    printf("length = %d\n",getlength(L));
    cyclistshow(L);
    return 0;
}