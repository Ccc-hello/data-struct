#include "btree.h"

Bitree *bitree_init()
{
    TElemType ch;
    scanf("%c",&ch);
    if(ch == '#')
    {
        return NULL;
    }
    else
    {
        Bitree *T = (Bitree *)malloc(sizeof(bnode));
        if(T == NULL)
        {
            perror("malloc");
            return NULL;
        }
        T->data = ch;
        T->lchild = bitree_init();
        T->rchild = bitree_init();
        return T;
    }
}

void preorder_traversal(Bitree *T)
{
    if(T == NULL)
    {
        return;
    }
    printf("%c",T->data);
    preorder_traversal(T->lchild);
    preorder_traversal(T->rchild);
}

void midorder_traversal(Bitree *T)
{
    if (T == NULL)
    {
        return;
    }
    midorder_traversal(T->lchild);
    printf("%c",T->data);
    midorder_traversal(T->rchild);
}

void postorder_traversal(Bitree *T)
{
    if (T == NULL)
    {
        return ;
    }
    postorder_traversal(T->lchild);
    postorder_traversal(T->rchild);
    printf("%c",T->data);
}

//-------------------链栈---------------

Lstack *create_Lstack()
{
    Lstack *S = (Lstack *)malloc(sizeof(snode));
    if(S == NULL)
    {
        perror("malloc");
        return NULL;
    }
    S->next = NULL;
    return S;
}

int is_empty(Lstack *S)
{
    return S == NULL;
}

int push_Lstack(Lstack *S,SElemType e)
{
    if(S == NULL)
    {
        printf("S is null\n");
        return -1;
    }
    Lstack *p = (Lstack *)malloc(sizeof(snode));
    if(p == NULL)
    {
        perror("malloc");
        return -1;
    }
    p->s_data = e;
    p->next = S->next;
    S->next = p;
}

SElemType pop_Lstack(Lstack *S)
{
    if(is_empty(S))
    {
        printf("S is empty\n");
        return -1;
    }
    Lstack *p = S->next;
    S->s_data = p->s_data;
    S->next = p->next;
    free(p);
    return S->s_data;
}

void show_Lstack(Lstack *S )
{
    if(is_empty(S))
    {
        printf("Lstack is NULL\n");
        return ;
    }
    Lstack *p = S->next;
    while (p)
    {
        printf("%c ",p->s_data);
        p=p->next;
    }
    printf("\n");
}

/*int midorder_traversal_satck(Bitree *T,Lstack *S)
{
    
    Lstack *q ;
    if(T->lchild)
    {
        while(T)
        {
            push_Lstack(S,T->data);
            T = T->lchild;
        }
        
    }
    else
    {
        while(q)
       { 
            printf("%c",pop_Lstack(S));
            q=S->next;
       }
    }
    p = T;
    if(p->rchild)
    {
        while(p)
        {
            push_Lstack(S,p->data);
            p = p->rchild;
            q = S->next;
        }
    }
    else
    {
        while(q)
       { 
            printf("%c",pop_Lstack(S));
            q=S->next;
       }
    }
}*/

int midorder_traversal_satck(Bitree *T,Lstack *S)
{
    while(T)
    {
        push_Lstack(S,T->data);
        T=T->lchild;
        if(T->lchild == NULL)
        {
            pop_Lstack(S);
            while (T->rchild)
            {
                T = T->rchild;
                push_Lstack(S,T->data);
                
            }

        }
    }
}