#include<stdio.h>
#include<stdlib.h>
#define item int
typedef struct ND{
    item data;
    struct ND* next;
}node;
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
//merge sort
node *merging(node* l1,node *l2)
{
    node* l3=NULL;
    if(l1==NULL) return l2;
    else if(l2==NULL) return l1;
    else
    {
        if(l1->data<=l2->data)
        {
            l3=l1;
            l3->next=merging(l1->next,l2);
        }
        else
        {
            l3=l2;
            l3->next=merging(l1,l2->next);
        }
    }
    return l3;
}
void divide(node *head,node **l1,node **l2)
{
    node *slow =head;
    node * fast=head->next;
    while(fast!=NULL)
    {
        fast=fast->next;
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    *l1=head;
    *l2=slow->next;
    slow->next=NULL;
}
void mergesort(node** head)
{
    if(*head==NULL || (*head)->next==NULL) return;
    node* l1;
    node* l2;
    divide(*head,&l1,&l2);
    mergesort(&l1);
    mergesort(&l2);
    *head=merging(l1,l2);
}
void print(node* head)
{
    node *temp=head;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
//insertion sort
void insertion(node **head)
{
    node *outc,*outp,*inc,*inp;
    outp=*head;
    outc=(*head)->next;
    while(outc!=NULL)
    {
        inp=NULL;
        inc=*head;
        while(inc!=outc && inc->data<=outc->data)
        {
            inp=inc;
            inc = inc->next;
        }
        if(inc==outc)
        {
            outp=outc;
            outc=outc->next;
        }
        else
        {
            if(inp==NULL)
            {
                outp->next=outc->next;
                outc->next=inc;
                *head=outc;
            }
            else
            {
                outp->next=outc->next;
                outc->next=inc;
                inp->next=outc;
            }
            outc=outp->next;
        }
    }
}
int main()
{
    node* head=NULL;
    append(5,&head);
    append(7,&head);
    append(9,&head);
    append(1,&head);
    append(4,&head);
    append(3,&head);
    append(6,&head);
    print(head);
    printf("\n");
    insertion(&head);
    print(head);
    return 0;
}