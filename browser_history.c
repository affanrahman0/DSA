#include"browser.h"
#include<stdlib.h>
#include<string.h>
#define item struct V
node *newnode(item value)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=value;
    return temp;
}
void addrear(node **front,node **rear,item value)
{
    node *temp=newnode(value);
    temp->next=NULL;
    if(*front==NULL)
    {
        temp->next=NULL;
        *front=temp;
    }
    else
    {
        temp->prev=*rear;
        (*rear)->next=temp;
    }
    *rear=temp;

}
void addfront(node **front,node **rear,item value)
{
    node *temp=newnode(value);
    temp->prev=NULL;
    if(*front==NULL)
    {
        temp->prev=NULL;
        *rear=temp;
    }
    else
    {
        temp->next=*front;
        (*front)->prev=temp;
    }
    *front=temp;
}
void addbefore(node *pos,item value)
{
    node *temp=newnode(value);
    temp->next=pos;
    temp->prev=pos->prev;
    pos->prev->next=temp;
    pos->prev=temp;
}
void addafter(node *pos,item value)
{
    node *temp=newnode(value);
    temp->prev=pos;
    temp->next=pos->next;
    pos->next->prev=temp;
    pos->next=temp;
}
void insertrear_circular(node **rear,item value)
{
    node *temp=newnode(value);
    if(*rear==NULL) temp->next=temp->prev=temp;
    else
    {
        temp->prev=*rear;
        temp->next=(*rear)->next;
        (*rear)->next->prev=temp;
        (*rear)->next=temp;
    }
    *rear=temp;
}
void insertfront_circular(node **rear,item value)
{
    node *temp=newnode(value);
    if(*rear==NULL)
    {
        temp->next=temp->prev=temp;
        *rear=temp;
    }
    else
    {
        temp->prev=*rear;
        temp->next=(*rear)->next;
        (*rear)->next->prev=temp;
        (*rear)->next=temp;
    }
}
