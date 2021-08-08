#include"double_link.h"
#include<stdlib.h>
#define item int
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
void delfront(node **rear,node **front)
{
    node *temp= *front;
    if(*front==NULL) return;
    else
    {
        if(*front==*rear) *rear=*front=NULL;
        else
        {
            *front=(*front)->next;
            (*front)->prev=NULL;
        }
        free(temp);
    }
}
void delany(node *pos)
{
    if(pos==NULL) return;
    pos->prev->next=pos->next;
    pos->next->prev=pos->prev;
    free(pos);
}
void delrear(node **rear,node **front)
{
    node *temp=*rear;
    if(*rear==NULL) return;
    else
    {
        if(*front==*rear) *rear=*front=NULL;
        else
        {
            *rear=(*rear)->prev;
            (*rear)->next=NULL;
        }
        free(temp);
    }
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
void delfront_circular(node **rear)
{
    node *temp;
    if(*rear==NULL) return;
    else
    {
        temp=(*rear)->next;
        if(*rear==(*rear)->next) *rear=NULL;
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
        }
        free(temp);
    }
}
void delrear_circular(node **rear)
{
    node *temp;
    if(*rear==NULL) return;
    else
    {
        temp=*rear;
        if(*rear==(*rear)->next) *rear=NULL;
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            *rear=temp->prev;
        }
        free(temp);
    }
}
void insert_sort_list(node **rear,item value)
{
    if(*rear==NULL || ((*rear)->data)<value) insertrear_circular(rear,value);
    else
    {
        node *curr=(*rear)->next;
        do
        {
            if(value>curr->data) curr=curr->next;
            else break;
        } while (curr!=(*rear)->next);
        addbefore(curr,value);
        
    }
}