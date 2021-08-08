#include<stdlib.h>
#define item char*
#define item2 tnode*
typedef struct ND{
    item data;
    struct ND *left,*right;
}tnode;
typedef struct st
{
    item2 *arr;
    int top,size;
}stack;
void print_preorder(tnode* );
void print_inorder(tnode* );
void print_postorder(tnode* );
void init(stack *,int );
int isfull(stack *);
int isempty(stack *);
void push(stack *,item2 );
item2 pop(stack *);
item2 peek(stack *);
int pred(char );
void popnpush(stack *,stack *);
int calculate(int ,int ,char);
int evaluate(tnode *);
int tree_eval(char *);
int evaluate_multi(tnode *);
int tree_eval_multidigit(char *);
