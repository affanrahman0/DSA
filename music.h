#include<stdio.h>
#include<stdlib.h>
#define item struct V
struct V{
    int no;
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
void delany(node *);
void insertrear_circular(node **,item);
void insertfront_circular(node **,item );
void circular_del_list(node **);
void jumpto(node **,node *,int );
void trackafter(node **,item ,int );
void trackbefore(node **,item ,int);
void del_cur_track(node **,int );
void circular_delrear(node **);
void trackchange(int ,int ,node **);
void circular_traverse(node *);
void musicplayer(node **,FILE *);
void sort_double_circular(node **);
