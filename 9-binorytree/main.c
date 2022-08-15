#include"btree.h"
int main()
{
    Bitree *T = bitree_init();
    printf("----preoder_traversal------\n");
    preorder_traversal(T);
    printf("\n----midoredr_traversal------\n");
    midorder_traversal(T);
    printf("\n----postoder_traversal------\n");
    postorder_traversal(T);
    
    Lstack *S = create_Lstack();
    if (S == NULL)
    {
        printf("S is null\n");
        return -1;
    }
    printf("\n----midorder_traversal_stack------\n");
    midorder_traversal_satck(T,S);

    return 0;
}