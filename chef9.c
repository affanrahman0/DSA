#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define item struct V
struct V{
    int freq;
    char  arr[30];
};
typedef struct ND{
    item data;
    struct ND* next;
    struct ND* prev;
}node;
node *newnode(item value)
{
    node *temp=(node*)malloc(sizeof(node));
    //value.freq=1;
    strcpy(temp->data.arr,value.arr);
    temp->data.freq=value.freq;
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
void insert_lexico(node **rear,item value)
{
    int m=0,p=0;
    if(*rear==NULL)insertrear_circular(rear,value);
    else
    {
        node *curr=(*rear)->next;
        do
        {
            if(strcmp((curr->data.arr),value.arr)==0)
            {
                curr->data.freq+=value.freq;
                m=1;
                break;
            }
            curr=curr->next;
            // else if((curr->data.freq)>=value.freq) curr=curr->next;
            // else break;
        } while (curr!=(*rear)->next);
        if(m!=1)
        {
            node *curr=(*rear)->next;
            do
            {
                if((curr->data.freq)>=value.freq) curr=curr->next;
                else{
                    p=1;
                    break;
                }
            } while (curr!=(*rear)->next);

            if(p==1)addbefore(curr,value);
            else insertrear_circular(rear,value);
            
        }
        
    }
}
void circular_traverse(node *rear)
{
    node *temp=rear;
    do{
        printf("%d ",temp->data.freq);
        temp=temp->prev;

    }while(temp!=rear);
}
int main()
{
    int t;
    char x[1000];
    fgets(x,sizeof(x),stdin);
    sscanf(x,"%d",&t);
    while(t--)
    {
        node* rear=NULL;
        item a;
        char z[100],y[100];
        int b,i,j=0,q=0,u;
        fgets(z,sizeof(z),stdin);
        sscanf(z,"%d",&b);
        b*=3;
        while(b--)
        {
            fgets(y,sizeof(y),stdin);
            sscanf(y,"%s%d",a.arr,&a.freq);
            insert_lexico(&rear,a);
        }
        circular_traverse(rear);
        printf("\n");
        
    }
    return 0;
}