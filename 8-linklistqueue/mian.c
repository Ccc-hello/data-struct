/*=======================================================
*   Copyright (C) 2022 秦超 All rights reserved.
*   
*   filename：mian.c
*   author：秦超
*   date：2022年08月08日
*   describption：
*
========================================================*/
#include "Lqueue.h"

int main(int argc, char *argv[])
{
	Lqueue *Lq = Lqueue_create();
	if(Lq == NULL)
	{
		printf("Lq is null\n");
		return -1;
	}
	int i=0,k=0;
	while(i<10)
	{
		Lqueue_en(Lq,(i+1)*10);
		i++;
	}
	Lqueue_show(Lq);
	printf("length = %d\n",getlength(Lq));
	
	QElemType e;
	while(k<3)
	{
		Lqueue_del(Lq,&e);
		Lqueue_show(Lq);
		printf("the del element is %d\n",e);
		printf("length = %d\n",getlength(Lq));
		k++;
	}
	clear_Lqueue(Lq);
	printf("length = %d\n",getlength(Lq));
	destroy_Lqueue(Lq);
	return 0;
}
