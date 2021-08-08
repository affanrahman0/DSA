#include"music.h"
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
void jumpto(node **curr,node *rear,int n)
{
    node *temp=rear->next;
    if (rear!=NULL)
    {
        do
        {
            if(temp->data.no==n)
            {
                break;
            } 
            temp=temp->next; 
        } while (temp!=rear->next);
        *curr=temp;
    }
    
}
void trackafter(node **rear,item j,int n)
{
    node *temp=(*rear)->next;
    do
    {
        if(temp->data.no==n)
        {
            break;
        } 
        temp=temp->next; 
    } while (temp!=(*rear)->next);
    if((*rear)!=temp)
    {
        addafter(temp,j);
        node *local=temp->next->next;
        do
        {
            local->data.no+=1;
            local=local->next;
        } while (local!=(*rear)->next);

    }
    else insertrear_circular(rear,j);
}
void trackbefore(node **rear,item j,int n)
{
    node *temp=(*rear)->next;
    do
    {
        if(temp->data.no==n)
        {
            break;
        } 
        temp=temp->next; 
    } while (temp!=(*rear)->next);
    if((*rear)->next!=temp)
    {
        addbefore(temp,j);
        temp->prev->data.no+=1;
        node *local=temp->next->prev;
        do
        {
            local->data.no+=1;
            local=local->next;
        } while (local!=(*rear)->next);
    }
    else 
    {
        insertfront_circular(rear,j);
        node *curr=(*rear)->next;
        do
        {
            curr->data.no+=1;
            curr=curr->next;
        } while (curr!=(*rear)->next);
        
    }
}
void del_cur_track(node **rear,int n)
{
    node *temp=(*rear)->next;
    do
    {
        if(temp->data.no==n)
        {
            break;
        } 
        temp=temp->next; 
    } while (temp!=(*rear)->next);
    if(temp!=*rear) 
    {
        node *local=temp->next;
        delany(temp);
        do
        {
            local->data.no-=1;
            local=local->next;
        } while (local!=(*rear)->next);
    }
    else circular_delrear(rear);

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
void trackchange(int n,int m,node **rear)
{
    node *temp=(*rear)->next;
    node *local=(*rear)->next;
    char c[30];
    do
    {
        if(temp->data.no==n)
        {
            break;
        } 
        temp=temp->next; 
    } while (temp!=(*rear)->next);
    do
    {
        if(local->data.no==m)
        {
            break;
        } 
        local=local->next; 
    } while (local!=(*rear)->next);
    strcpy(c,temp->data.arr);
    strcpy(temp->data.arr,local->data.arr);
    strcpy(local->data.arr,c);
}
void circular_traverse(node *rear)
{
    node *temp=rear->next;
    do{
        printf("%d%s\n",temp->data.no,temp->data.arr);
        temp=temp->next;

    }while(temp!=rear->next);
}
void musicplayer(node **rear,FILE *fp)
{
    item i,j;
    i.no=1;
    int n,m;
    char ch;
    do{
            
        printf("\nEnter your choice\n");
        scanf(" %c",&ch);
        switch(ch)
        {
            case 's':
                while(fgets(i.arr,sizeof(i.arr),fp)!=NULL)
                {
                    insertrear_circular(rear,i);
                    i.no+=1;
                }
                node *curr =(*rear)->next;
                printf("%s\n",curr->data.arr);
                break;
            case 'j':
                if(*rear==NULL) printf("You need to first start the player\n");
                else
                {
                    printf("Enter the desired track number\n");
                    scanf("%d",&n);
                    jumpto(&curr,*rear,n);
                    printf("%s\n",curr->data.arr);
                }
                break;
            case 'n':  
                if(*rear==NULL) printf("You need to first start the player\n");
                else
                { 
                    curr=curr->next;
                    printf("%s\n",curr->data.arr);
                } 
                break;
            case 'p':
                if(*rear==NULL) printf("You need to first start the player\n");
                else
                { 
                    curr=curr->prev;
                    printf("%s\n",curr->data.arr);
                }    
                break;   
            case 'f':
                if(*rear==NULL) printf("You need to first start the player\n");
                else
                {
                    curr =(*rear)->next;
                    printf("%s\n",curr->data.arr);
                }
                break;    
            case 'l':
                if(*rear==NULL) printf("You need to first start the player\n");
                else
                {
                    curr =*rear;
                    printf("%s\n",curr->data.arr);
                } 
                break;  
            case 'a':
                if(*rear==NULL) printf("You need to first start the player\n");
                else
                {
                    printf("Enter the track and track no. of the track after which it's to be inserted\n");
                    scanf("%s%d",j.arr,&n);
                    j.no=n+1;
                    trackafter(rear,j,n);
                }
                break;   
            case 'b':
                if(*rear==NULL) printf("You need to first start the player\n");
                else
                {
                    printf("Enter the track and track no. of the track before which it's to be inserted\n");
                    scanf("%s%d",j.arr,&n);
                    j.no=n-1;
                    trackbefore(rear,j,n);
                }
                break;
            case 'r': 
                if(*rear==NULL) printf("You need to first start the player\n");
                else
                {
                    printf("Enter the track no. to be deleted\n");
                    scanf("%d",&n);
                    del_cur_track(rear,n);
                }   
                break;
            case 't': 
                if(*rear==NULL) printf("You need to first start the player\n");
                else  circular_del_list(rear);
                break;
            case 'c': 
                if(*rear==NULL) printf("You need to first start the player\n");
                else
                {
                    printf("Enter the current track no. and the new track the no to which it's to be shifted\n");
                    scanf("%d%d",&n,&m);
                    trackchange(n,m,rear);
                }
                break;
            case 'o' :
                if (*rear==NULL) printf("You need to first start the player\n");
                sort_double_circular(rear);      
                break;
            case 'd':
                if (*rear==NULL) printf("You need to first start the player\n");
                else circular_traverse(*rear);
                break;
            default: 
                if(ch!='E')printf("Invalid Input\n");
                break;                                                                                  
        }
   
    }while(ch!='E');
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
            if(strcmp(curr->data.arr,local->data.arr)>0)
            {
                strcpy(x,curr->data.arr);
                strcpy(curr->data.arr,local->data.arr);
                strcpy(local->data.arr,x);
            }
            local=local->next;
        } while (local!=(*rear)->next);
        
        curr=curr->next;
    } while (curr!=*rear);
    
}
