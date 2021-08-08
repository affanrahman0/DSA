#include<stdio.h>
#include<stdlib.h>
#define item struct V
#define item2 char
struct V{
    int no;
    char  name[100];
};
typedef struct ND{
    item data;
    struct ND* next;
    struct ND* prev;
}node;
/*struct a{
    char arr[30][100];
};*/
typedef struct st
{
    item2 *arr;
    int top,size;
}stack;
void init(stack *,int );
int isfull(stack *);
int isempty(stack *);
void push(stack *,item2 );
item2 pop(stack *);
item2 peek(stack *);
char *intopostconvert(char *);
char *intopostconvert_multidigit(char *);
int calculate(int ,int ,char );
int postfix_evaluator(char *);
int findmin(stack *,int,stack *);
node *newnode(item);
void addrear(node **,node **,item );
void addfront(node **,node **,item);
void addbefore(node *,item);
void addafter(node *,item);
void delany(node *);
void insertrear_circular(node **,item);
void insertfront_circular(node **,item );
void circular_del_list(node **);
void search(node **,node *);
void circular_traverse(node *);
void circular_delrear(node **);
void order_update(node *,node *);
void print();
void edlin(node **,int);