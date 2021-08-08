#include<stdio.h>
#include<stdlib.h>
#define item struct V
struct V{
    char  arr[30];
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
void insertrear_circular(node **,item);
void insertfront_circular(node **,item );