/*=======================================================
*   Copyright (C) 2022 秦超 All rights reserved.
*   
*   filename：main.c
*   author：秦超
*   date：2022年08月03日
*   describption：
*
========================================================*/
#include<stdio.h>
#include"linklist.h"
int main(int argc, char *argv[])
{
	LinkList *L= CreateList();
	
	if(L == NULL)
	{
		printf("failed to create\n");
	}
	else
	{
		printf("creat success\n");
	}
	int i=0;
/*	while(i<10)
	{
		InsertList(L,i,(i+1)*10);
		i++;
	}
	printf("length = %d\n",getlength(L));
	LinkListshow(L);
	printf("\n");
	dellist(L,5);
	printf("length = %d\n",getlength(L));
	LinkListshow(L);
	printf("\n");
	printf("---overrurn----\n");
	overturnlist(L);
	LinkListshow(L);
	printf("\n");
	printf("---searchlist----\n");
	LinkList *p=searchlist(L,10);
	printf("%d\n",p->data);
	printf("---getelemlist----\n");
	printf("%d\n",getlistelem(L,5));
	printf("---changelem----\n");
	changelist(L,10,111);
	LinkListshow(L);
	printf("\n");
	printf("---sortlist----\n");
	sortlist_insert(L,36);
	LinkListshow(L);
	printf("\n");

	clearlist(L);
	printf("length = %d\n",getlength(L));
*/
	sortlist_insert(L,80);
	sortlist_insert(L,21);
	sortlist_insert(L,19);
	sortlist_insert(L,38);
	sortlist_insert(L,43);
	return 0;
}

