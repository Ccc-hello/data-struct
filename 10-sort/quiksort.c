#include"sort.h"


void produce_arr(int *__src,int length)
{
    srand(time(NULL));
    for(int i = 0;i<length;i++)
        __src[i] = rand()%100;
}

void traversal_arr(int *__src,int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ",__src[i]);
    }
    printf("\n");
}

void swap(int *__src,int *__dest)
{
    int temp = *__src;
    *__src = *__dest;
    *__dest = temp;
}

//快速排序；
void quick_sort(int *__src,int l,int r)
{
    if(l<r)
    {
        int i=l,j=r,x = __src[l];
        while(i<j)
        {
            while (i<j && __src[j] >= x)
                j--;

            if(i<j)
                __src[i++] = __src[j];

            while(i<j && __src[i]<x)
                i++;
                
            if(i<j)
                __src[j--]= __src[i];
        }
        __src[i] = x;
        quick_sort(__src,l,i-1);
        quick_sort(__src,i+1,r);
    }
}

//堆排序;
void heapadjust(int *__src,int length,int i)
{
    int max = i;
    int lchild = i*2+1;
    int rchild = i*2+2;
    if(lchild < length && __src[max] < __src[lchild])
        max = lchild;
    if (rchild < length && __src[max] < __src[rchild])
        max = rchild;
    if(max != i)
    {
        swap(&__src[max],&__src[i]);
        heapadjust(__src,length,max);
    }
}

void heapsort(int *__src,int length)
{
    int i;
    for(i=length/2-1;i>=0;i--)
        heapadjust(__src,length,i);
    for(i=length-1;i>0;i--)
    {
        swap(&__src[i],&__src[0]);
        heapadjust(__src,i,0);
    }
}