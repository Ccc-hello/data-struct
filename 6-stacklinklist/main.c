#include"stack_linklist.h"

int main()
{
    Linkstack *S = create_Lstack();
    if(S == NULL)
    {
        printf("S is null\n");
        return -1;
    }

    printf("-----pushLstack-------\n");
    SElemType e;
    int i = 0,k=0;
    while(i<10)
    {
        push_Lstack(S,(i+1)*10);
        i++;
    }
    show_Lstack(S);
    printf("length = %d\n",getlength(S));

    printf("-----pop_Lstack-------\n");
    while(k<3)
    {
        pop_Lstack(S,&e);
        show_Lstack(S);
        printf("the pop element is %d\n",e);
        k++;
    }
    printf("length = %d\n",getlength(S));

    clear_Lstack(S);
    printf("length = %d\n",getlength(S));
    return 0;
}

