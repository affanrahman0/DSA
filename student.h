#include<stdio.h>
#include<stdlib.h>
#define item struct V
struct V{
    long long int roll;
    long long int reg;
    int year;
    char  name[30];
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
void enroll(node **,node *);
void name(node **,node *);
void circular_traverse(node *);
void circular_delrear(node **);
void update(node *);
void name_lexico(node **);
void circular_traverse1(node *);
void student(node **);
