#include<stdio.h>
#include<stdlib.h>
#define item int
typedef struct ND{
    int data;
    struct ND* next;
    struct ND* prev;
}node;
node *newnode(item);
void addrear(node **,node **,item );
void addfront(node **,node **,item);
void addbefore(node *,item);
void addafter(node *,item);
void delfront(node **,node **);
void delrear(node **,node **);
void insertrear_circular(node **,item);
void insertfront_circular(node **,item );
void delfront_circular(node **);
void delrear_circular(node **);
void insert_sort_list(node **,item );