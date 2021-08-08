#include<stdlib.h>
#include<stdio.h>
#define item struct V
#define item2 tnode*
struct V{
    int id;
    int index;
};
typedef struct ND{
    item data;
    struct ND *left,*right;
    int bfact;
}tnode;
tnode *newnode(item );
void print_preorder(tnode* );
void print_inorder(tnode* );
void print_postorder(tnode* );
void leftrotate(tnode **);
void rightrotate(tnode **);
int depth(tnode* );
void cal_bfact(tnode* );
void balance(tnode **);
void insert(tnode **root,item value);
void delnode(tnode **,int );
void record(FILE* ,FILE* ,tnode** );