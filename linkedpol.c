#include"linkedpol.h"
#include<stdlib.h>
#define item struct V
node *newnode(item data,node *next)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=next;
    return temp;
}
void append(item data,node** head)
{
    node *new= newnode(data,NULL);
    if(*head==NULL)
    {
        *head=new;
    }
    else
    {
        node *temp = *head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
   
}
void begin(item data,node** head)
{
    node *new=newnode(data,*head);
    *head=new;
}
node *polyadd(node* l1,node* l2)
{
    node *l3=NULL;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->data.pow>l2->data.pow)
        {
            append(l1->data,&l3);
            l1=l1->next;
        }
        else if(l1->data.pow<l2->data.pow)
        {
            append(l2->data,&l3);
            l2=l2->next;
        }
        else
        {
            item temp;
            temp.coeff=l1->data.coeff+l2->data.coeff;
            temp.pow=l1->data.pow;
            append(temp,&l3);
            l1=l1->next;
            l2=l2->next;
        }

    }
    while(l1!=NULL)
    {
        append(l1->data,&l3);
        l1=l1->next;
    }
    while(l2!=NULL)
    {
        append(l2->data,&l3);
        l2=l2->next;
    }
    return l3;
}
void del_list(node **head)
{
    node *temp=NULL;
    while(*head!=NULL)
    {
        temp=*head;
        *head=temp->next;
        free(temp);
    }
}
node *polmultiply(node* l1,node* l2)
{
    node *l3=NULL,*t=NULL,*l=l2;
    item temp;
        while(l1!=NULL)
        {
            while(l2!=NULL)
            {
                temp.pow=l1->data.pow+l2->data.pow;
                temp.coeff=l1->data.coeff*l2->data.coeff;
                append(temp,&t);
                l2=l2->next;
            }
            l2=l;
            l3=polyadd(l3,t);
            del_list(&t);
            l1=l1->next;
        }
    return l3;
}