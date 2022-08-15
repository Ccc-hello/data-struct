#ifndef _BTREE_H_
#define _BTREE_H_

#include<stdio.h>
#include<stdlib.h>

typedef char TElemType;

typedef struct bnode
{
    TElemType data;
    struct bnode *lchild,*rchild;
}bnode;
typedef struct bnode Bitree;

typedef char SElemType;
typedef struct snode
{
    SElemType s_data;
    struct snode *next;
}snode;
typedef struct snode Lstack;

Bitree *bitree_init();

void preorder_traversal(Bitree *T);

void preorder_traversal(Bitree *T);

void midorder_traversal(Bitree *T);

void postorder_traversal(Bitree *T);

//-----链栈------
Lstack *create_Lstack();

int is_empty(Lstack *S);

int push_Lstack(Lstack *S,SElemType e);

SElemType pop_Lstack(Lstack *S);

void show_Lstack(Lstack *S );

int midorder_traversal_satck(Bitree *T,Lstack *S);

#endif