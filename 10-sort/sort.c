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

//插入排序
void insersort(int *__src,int length)
{
     int i,j;
     int temp;
     for(i=1;i<length;i++)
     {
        temp = __src[i];//待排元素
        for(j=i-1;j>=0;j--)
        {
            if(temp >= __src[j])
                break;
            __src[j+1] = __src[j];
        }
        __src[j+1] = temp;
     }
}

//希尔排序
void groupsort(int *__src,int length,int l,int step)
{
     int i,j;
     int temp;
     for(i=l+step;i<length;i+=step)
     {
        temp = __src[i];//待排元素
        for(j=i-step;j>=0;j-=step)
        {
            if(temp >= __src[j])
                break;
            __src[j+step] = __src[j];
        }
        __src[j+step] = temp;
     }
}

void shellsort(int *__src,int length)
{
    int i,step;
    for (step = length/2;step>0;step/=2)
    {
        for(i=0;i<step;i++)
            groupsort(__src,length,i,step);
    }
}