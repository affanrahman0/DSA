#include<stdio.h>
#include<stdlib.h>
#define item struct V
#define item2 char*
struct V{
    int no;
    char  name[100];
};
typedef struct ND{
    item data;
    struct ND* next;
    struct ND* prev;
}node;
node *newnode(item);
void addrear(node **,node **,item );
void addfront(node **,node **,item);
void addbefore(node *,item);
void addafter(node *,item);
void delany(node *);
void insertrear_circular(node **,item);
void insertfront_circular(node **,item );
void circular_del_list(node **);
void circular_traverse(node *);
void circular_delrear(node **);
void name(node **,node *);
int check(node *);
void traverse_check(node *,node **);
void print(node *);
void train(node **);