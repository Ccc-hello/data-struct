#ifndef _SORT_H_
#define _SORT_H_

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void produce_arr(int *__src,int length);

void traversal_arr(int *__src,int length);

void swap(int *__src,int *__dest);

void quick_sort(int *__src,int l,int r);

void heapadjust(int *__src,int length,int i);

void heapsort(int *__src,int length);

void insersort(int *__src,int length);

void shellsort(int *__src,int length);

void groupsort(int *__src,int length,int l,int step);

#endif