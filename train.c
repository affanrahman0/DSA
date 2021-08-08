#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"train.h"
#include"train_que.h"
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
void delany(node *pos)
{
    if(pos==NULL) return;
    pos->prev->next=pos->next;
    pos->next->prev=pos->prev;
    free(pos);
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
void circular_del_list(node **rear)
{
    if(*rear!=NULL)
    {
        node *temp,*current;
        current=(*rear)->next;
        while(current!=*rear)
        {
            temp=current->next;
            free (current);
            current=temp;
        }
        free(*rear);
        *rear=NULL;
    }
}
void circular_traverse(node *rear)
{
    node *temp=rear->next;
    do{
        printf("Seat no:%d Name:",temp->data.no);
        puts(temp->data.name);
        temp=temp->next;

    }while(temp!=rear->next);
}

void circular_delrear(node **rear)
{
    if(*rear==NULL) return;
    else if(*rear==(*rear)->next)
    {
        *rear=NULL;
        free(*rear);
    }
    else
    {
        node *temp=*rear;
        *rear=temp->prev;
        temp->next->prev=*rear;
        (*rear)->next=temp->next;
        free(temp);
    }
}
void name(node **curr,node *rear)
{
    char name1[30];
    printf("Enter your name\n");
    fgets(name1,sizeof(name1),stdin);
    name1[strlen(name1)-1]='\0';
    node *temp=rear->next;
    if (rear!=NULL)
    {
        do
        {
            if(strcmp(temp->data.name,name1)==0)
            {
                break;
            } 
            temp=temp->next; 
        } while (temp!=rear->next);
        *curr=temp;
        
    }
}
int check(node *rear)
{
    node *temp=rear->next;
    int i=0;
    do{
        i++;
        temp=temp->next;
    }while(temp!=rear->next);
    
    return i;
}
void traverse_check(node *rear,node **curr)
{
    node *temp=rear->next;
    int i=0;
    do{
        i++;
       if(temp->data.no!=i) break;
        temp=temp->next;
        

    }while(temp!=rear->next);
    *curr=temp->prev;
}
void print(node *pos)
{
    printf("hey! %s, Your ticket is confirmed\n",pos->data.name);
    printf("Seat no:%d Name:",pos->data.no);
    puts(pos->data.name);
}
void train(node **rear)
{
    queue que;
    item i;
    init(&que,10);
    int y;
    node *curr=NULL;
    char ch,brr[100],tr[100],prr[100],*cp;
    printf("Press 'b' to book a ticket\n");
    printf("Press 'c' to cancel a ticket\n");
    printf("Press 'r' to view the resered list\n");
    printf("Press 'E' to exit\n");
    int a;
    do
    {
        printf("Please enter your choice\n");
        fgets(tr,sizeof(tr),stdin);
        sscanf(tr,"%c",&ch);
        if(ch=='c')
        {
           name(&curr,*rear);
           printf("hey! %s, your ticket is cancelled\n",curr->data.name);
           if(!isempty(&que))
           {
               cp=strdup(dequeue(&que));
               strcpy(curr->data.name,cp);
               print(curr);
           }
           else if(curr==*rear) circular_delrear(rear);
           else delany(curr);

        }   
        else if(ch=='b')
        {
            if(*rear==NULL) printf("There is 10 more tickets left\n");
            else if(check(*rear)<10) printf("There is only %d more tickets left\n",10-check(*rear));
            if(*rear==NULL || (*rear)->data.no<10)
            {
                printf("Please enter the name\n");
                fgets(brr,sizeof(brr),stdin);
                brr[strlen(brr)-1]='\0';
                strcpy(i.name,brr);
                if(*rear==NULL) i.no=1;
                else i.no=(*rear)->data.no+1;
                insertrear_circular(rear,i);
                print(*rear);
                
            }
            else if (check(*rear)<10)
            {
                printf("Please enter the name\n");
                fgets(brr,sizeof(brr),stdin);
                brr[strlen(brr)-1]='\0';
                strcpy(i.name,brr);
                traverse_check(*rear,&curr);
                i.no=curr->data.no+1;
                addafter(curr,i);
                print(curr->next);
            }
            else
            {
                printf("There's no ticket available\n");
                printf("You can still book a ticket in waiting list. But it'll only be confirmed if someone cancels a ticket\n");
                printf("Press 1 to book a ticket in waiting list or press 2 to exit\n");
                fgets(prr,sizeof(prr),stdin);
                sscanf(prr,"%d",&a);
                if(a==1)
                {
                    printf("Please enter the name\n");
                    fgets(brr,sizeof(brr),stdin);
                    brr[strlen(brr)-1]='\0';
                    enqueue(&que,brr);
                }
                else return;
            }
            
        }
        else if(ch=='r') 
        {
            if(*rear==NULL) printf("There is no reservation\n");
            else circular_traverse(*rear);
        }
        else if(ch!='E') printf("Invalid Input\n");
    } while (ch!='E');
    
}