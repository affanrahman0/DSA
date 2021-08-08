#include<stdio.h>
#include<stdlib.h>
#define item int
typedef struct ND{
    item data;
    struct ND* next;
}node;
node *newnode(item,node *);
void append(item,node**);
void begin(item,node**);
node *searchbykey(item,node*);
void addafter(node *,item );
void after(item,node**,item );
node *searchbypred(item,node*);
void before(item,node**,item);
void delbeg(node**);
void delafter(node *);
void delcurrent(node**,item);
void reverse(node **);
void insertrear(node **,item);
void circular_delbeg(node **);
node* serchbypos(node *,int );
//void circular_traverse(node *);
void insert_sort_list(node **,item );