#include<stdio.h>
#include<stdlib.h>
#include"adj_list.h"
#define item int
node *newnode(item dest)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->dest=dest;
    temp->next=NULL;
    return temp;
}
graph *create(item v)
{
    graph* temp=(graph*)malloc(sizeof(graph));
    temp->v=v;
    temp->arr=(list*)malloc(v*sizeof(list));
    for(int i=0;i<v;i++) temp->arr[i].head=NULL;
    return temp;
}
void addbegin(graph* g,item src, item dest)
{
    node *temp=newnode(dest);
    temp->next=g->arr[src].head;
    g->arr[src].head=temp;
    temp=newnode(src);
    temp->next=g->arr[dest].head;
    g->arr[dest].head=temp;
}
