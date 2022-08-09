#include"slqueue.h"

int main()
{
    SLqueue *Q = create_Queue();
    if (Q==NULL)
    {
        printf("Q is null\n");
        return -1;
    }

    printf("----enslqueue-----\n");
    int i=0,k=0;
    QElemType e;
    while (i<10)
    {
        enqueue(Q,(i+1));
        i++;
    }
    show_queue(Q);
    printf("length = %d\n",getlength(Q));
    
    printf("----delslqueue-----\n");
    while (k<3)
    {
        delqueue(Q,&e);
        k++;
        printf("the delslqueue element is %d\n",e);
        show_queue(Q);
        printf("length = %d\n",getlength(Q));
    }
    
    printf("----clear-----\n");
    clear_queue(Q);
    show_queue(Q);
    printf("length = %d\n",getlength(Q));

    destory_slqueue(Q);
}