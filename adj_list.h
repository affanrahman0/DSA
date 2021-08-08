#include<stdio.h>
#include<stdlib.h>
#define item int
typedef struct ad{
    item dest;
    struct ad* next;
}node;
typedef struct a{
    node* head;
}list;
typedef struct g{
    item v;
    list* arr;
}graph;
node *newnode(item );
graph *create(item );
void addbegin(graph* ,item, item );