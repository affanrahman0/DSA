#include<stdlib.h>
#define item int
#define item2 tnode*
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
void delnode(tnode **,item );