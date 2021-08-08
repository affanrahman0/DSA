// #include<stdio.h>
// #include<stdlib.h>
#define item struct V
struct V{
    int coeff;
    int pow;
};
typedef struct ND{
    item data;
    struct ND* next;
}node;

node *newnode(item,node *);
void append(item,node**);
void begin(item,node**);
node *polyadd(node*,node*);
void del_list(node**);
node *polmultiply(node*,node*);