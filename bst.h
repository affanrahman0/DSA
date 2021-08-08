#include<stdlib.h>
#define item int
#define item2 tnode*
typedef struct ND{
    item data;
    struct ND *left,*right;
}tnode;
tnode *newnode(item );
void print_preorder(tnode* );
void print_inorder(tnode* );
void print_postorder(tnode* );
void insert(tnode **,item );
void delnode(tnode **,item );