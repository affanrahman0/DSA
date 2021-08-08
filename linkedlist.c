#include"link.h"
#include<stdlib.h>
#define item int
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
node *searchbykey(item key,node*head)
{
   while(head!=NULL)
   {
       if(head->data==key)
       {
           return head;
       }
       else head=head->next;
   }
   return head;
   
}
void addafter(node *pos,item value)
{
	node *temp;
	temp=newnode(value,pos->next);
	//temp->next=pos->next;
	pos->next=temp;
}
void after(item data,node **head,item prev_value)
{
    node *prev=searchbykey(prev_value,*head);
    if(prev!=NULL)
    {
        node *temp=newnode(data,prev->next);
        prev->next=temp;
    }
    
}
node *searchbypred(item key,node *head)
{
    node *cur=head, *prev=NULL;
    while(cur!=NULL)
    {
        if(cur->data==key) return prev;
        else
        {
            prev=cur;
            cur=cur->next;
        }
    }
    return cur;
}
void before(item data,node** head,item value)
{
    node *prev=searchbypred(value,*head);
    if(prev!=NULL)
    {
        node *temp=newnode(data,prev->next);
        prev->next=temp;
    }
    else 
    {
        if((*head)->data==value)
        begin(data,head);
    }
}
void delbeg(node**head)
{
    node *temp;
    if(*head==NULL) return;
    temp=(*head);
    *head=temp->next;
    free(temp);
}
node* serchbypos(node *pos,int n)
{
	int i;
	for(i=1;i<n&&pos!=NULL;i++)
		pos=pos->next;
	return pos;
}
void delafter(node *pos)
{
    if(pos==NULL || pos->next==NULL) return;
    node *temp=pos->next;
    pos->next=temp->next;
    free(temp);
}
void delcurrent(node**head,item key)
{
    node *prev=searchbypred(key,*head);
    if(prev!=NULL) delafter(prev);
	else
    {
        if((*head)->data==key) delbeg(head);
    }
}
void reverse(node **head)
{
    node* cur=*head;
    node *prev=NULL;
    node *temp=NULL;
    if(*head==NULL) return;
    do
    {
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }while(temp!=NULL);
    *head=prev;
}
void insertrear(node **rear,item value)
{
    node* temp=newnode(value,NULL);
    if(*rear==NULL)
    {
        temp->next=temp;
    }
    else
    {
        temp->next=(*rear)->next;
        (*rear)->next=temp;
    }
    *rear=temp;
}
void circular_delbeg(node **rear)
{
    node *temp=NULL;
    if(*rear==NULL) return;
    else
    {
        temp=(*rear)->next;
        if(*rear==(*rear)->next) *rear=NULL;
        else (*rear)->next=temp->next;
        free(temp);
    }
}
void insert_sort_list(node **head,item value)
{
    node *curr=*head,*pred=NULL;
    if(*head==NULL) begin(value,head);
    else
    {
        while(curr!=NULL)
        {
            if(value>curr->data)
            {
                pred=curr;
                curr=curr->next;
            }
            else break;
        }
        if(pred==NULL) begin(value,head);
        else addafter(pred,value);
    }
}
