#include"student.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
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
void sort_double_circular(node **rear)
{
    char x[100];
    node *head=(*rear)->next;
    node *curr=head,*local=NULL;
    do
    {
        local=curr->next;
        do
        {
            if(strcmp(curr->data.name,local->data.name)>0)
            {
                strcpy(x,curr->data.name);
                strcpy(curr->data.name,local->data.name);
                strcpy(local->data.name,x);
            }
            local=local->next;
        } while (local!=(*rear)->next);
        
        curr=curr->next;
    } while (curr!=*rear);
    
}
void circular_traverse(node *rear)
{
    node *temp=rear->next;
    do{
        printf("Name: %s Enrollment number: %lld Registration number: %lld Year: %d\n",temp->data.name,temp->data.roll,temp->data.reg,temp->data.year);
        temp=temp->next;

    }while(temp!=rear->next);
}
void circular_traverse1(node *rear)
{
    node *temp=rear->next;
    do{
        printf("Name: %s \n",temp->data.name);
        temp=temp->next;

    }while(temp!=rear->next);
}
void enroll(node **curr,node *rear)
{
    long long int n;
    printf("Enter the enrollment number\n");
    scanf("%lld",&n);
    node *temp=rear->next;
    if (rear!=NULL)
    {
        do
        {
            if(temp->data.roll==n)
            {
                break;
            } 
            temp=temp->next; 
        } while (temp!=rear->next);
        *curr=temp;
        
    }
}
void name(node **curr,node *rear)
{
    char name1[30];
    printf("Enter name of the student\n");
    scanf("%s",name1);
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
void circular_delrear(node **rear)
{
    if(*rear==NULL) return;
    else
    {
        node *temp=*rear;
        *rear=temp->prev;
        temp->next->prev=*rear;
        (*rear)->next=temp->next;
        free(temp);
    }
}
void name_lexico(node **rear)
{
    item i;
    node *temp=(*rear)->next,*local=NULL;
    do
    {
        if(local==NULL || strcmp((local->data.name),temp->data.name)<0 )insertrear_circular(&local,temp->data);
        else
        {
            node *curr=local->next;
            do
            {
                if(strcmp(curr->data.name,temp->data.name)==0)
                {
                    break;
                }
                else if(strcmp((curr->data.name),temp->data.name)<0) curr=curr->next;
                else break;
            } while (curr!=local->next);
            if(strcmp((curr->data.name),temp->data.name)!=0) addbefore(curr,temp->data);
        
        }
        temp=temp->next;
    } while ((*rear)->next!=temp);
    circular_traverse1(local);
}
void update(node *pos)
{
    int m,s;
    char arr[30];
    long long int h;
    printf("Press 1 to update name\n");
    printf("Press 2 to update Enrollment number\n");
    printf("Press 3 to update registration number\n");
    printf("Press 4 to update year\n");
    scanf("%d",&m);
    if(m==1)
    {
        printf("Enter new name\n");
        scanf("%s",arr);
        strcpy(pos->data.name,arr);
    }
    else if(m==2)
    {
        printf("Enter new enrollment number\n");
        scanf("%lld",&h);
        pos->data.roll=h;
    }
    else if(m==3)
    {
        printf("Enter new registration number\n");
        scanf("%lld",&h);
        pos->data.reg=h;
    }
    else if(m==4)
    {
        printf("Enter new registration number\n");
        scanf("%d",&s);
        pos->data.year=s;
    }
    else printf("Invalid choice\n");

}
void student(node **rear)
{
    char ch;
    item j;
    int i;
    node *curr=NULL;
    do
    {
        printf("Enter your choice\n");
        scanf(" %c",&ch);
        switch(ch)
        {
            case 'a':
                printf("Enter name ,enrollment number, registration and year of the student respectively\n");
                scanf("%s%lld%lld%d",&j.name,&j.roll,&j.reg,&j.year);
                insertrear_circular(rear,j);
                break;
            case 'b':
                if(*rear==NULL) printf("The list is empty\n");
                else
                {
                    printf("press 1 to search by enrollment number\n");
                    printf("press 2 to search by name of the student\n");
                    scanf("%d",&i);
                    if(i==1) enroll(&curr,*rear);
                    else if(i==2) name(&curr,*rear);
                    else printf("Invalid choice\n");
                    if(curr!=*rear) delany(curr);
                    else circular_delrear(rear);
                }
                break;
            case 'c':
                if(*rear==NULL) printf("The list is empty\n");
                else
                {
                    printf("press 1 to search by enrollment number\n");
                    printf("press 2 to search by name of the student\n");
                    scanf("%d",&i);
                    if(i==1) enroll(&curr,*rear);
                    else if(i==2) name(&curr,*rear);
                    else printf("Invalid choice\n");
                    update(curr);
                }
                break;
            case 'd':
                if(*rear==NULL) printf("The list is empty\n");
                else
                {
                    printf("press 1 to search by enrollment number\n");
                    printf("press 2 to search by name of the student\n");
                    scanf("%d",&i);
                    if(i==1) enroll(&curr,*rear);
                    else if(i==2) name(&curr,*rear);
                    else printf("Invalid choice\n");
                    if(i==1 || i==2) printf("Name: %s Enrollment number: %lld Registration number: %lld Year: %d\n",curr->data.name,curr->data.roll,curr->data.reg,curr->data.year);
                }
                break;
            case 'e':
                if(*rear==NULL) printf("The list is empty\n");
                else name_lexico(rear);
                break;
            case 'f':
                if(*rear==NULL) printf("The list is empty\n");
                else circular_traverse(*rear);
                break;    
            default :
                if(ch!='E') printf("Invalid Input");       
        }
    } while (ch!='E');
    
}  