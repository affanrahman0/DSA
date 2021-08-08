#include"edlin.h"
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
void init(stack *ptst,int max_size)
{
    ptst->size=max_size;
    ptst->arr=(item2 *)malloc(ptst->size*sizeof(item2));
    ptst->top=-1;
}
int isfull(stack *ptst)
{
    return ptst->top==ptst->size-1;
}
int isempty(stack *ptst)
{
    return ptst->top==-1;
}
void push(stack *ptst,item2 value)
{
    if(isfull(ptst)) return;
    else ptst->arr[++ptst->top]=value;
}

item2 pop(stack *ptst)
{
    if(isempty(ptst)) return '\0' ;
    else return ptst->arr[ptst->top--];
}
item2 peek(stack *ptst)
{
    if(isempty(ptst)) return '\0';
    else return ptst->arr[ptst->top];
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
        printf("%d\t",temp->data.no);
        puts(temp->data.name);
        printf("\n");
        temp=temp->next;

    }while(temp!=rear->next);
}
void search(node **curr,node *rear)
{
    int n;
    char arr[30];
    printf("Enter the line number\n");
    fgets(arr,sizeof(arr),stdin);
    sscanf(arr,"%d",&n);
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
void circular_delrear(node **rear)
{
    if(*rear==NULL) return;
   /*else if(*rear==((*rear)->next))
    {
        free(*rear);
        *rear=NULL;
    }*/
    else
    {
        node *temp=*rear;
        *rear=temp->prev;
        temp->next->prev=*rear;
        (*rear)->next=temp->next;
        free(temp);
    }
}
void order_update(node *curr,node *rear)
{
    node *local=curr;
    do
    {
        local->data.no+=1;
        local=local->next;
    }while(local!=rear->next);
}
void order_update2(node *curr,node *rear)
{
    node *local=curr;
    do
    {
        local->data.no-=1;
        local=local->next;
    }while(local!=rear->next);
}
void print()
{
    printf("Press a to append\n");
    printf("Press i to insert a new text line\n");
    printf("Press d to delete a text\n");
    printf("Press z  to delete the last line\n");
    printf("Press p to print a line \n");
    printf("Press c  to replace a line \n");
    printf("Press q to truncate from character \n");
    printf("Press m to merge consequtive lines\n");
    printf("Press x to extend a line\n");
    printf("Press u to undo the last command\n");
    printf("Press r to redo the last the undone command\n");
    printf("Press l to load a file\n");
    printf("Press s to save a file\n");
    printf("Press e to exit the application\n");
}
void edlin(node **rear,int n)
{
    stack undo,redo;
    init(&undo,30);
    init(&redo,30);
    char ch,q,h;
    item i,j;
    int m;
    char arr[100],arr1[100],brr[30];
    node *curr=NULL,*local=NULL;
    printf("PLEASE PRESS h TO GET HELP\n");
    
    do
    {
        printf("Enter your choice\n");
        //scanf(" %c",&ch);
        fgets(arr,sizeof(arr),stdin);
        sscanf(arr,"%c",&ch);
        if(ch!='u' && ch!='r') push(&undo,ch);
        switch(ch)
        {
            case 'a':
                printf("Please enter the text to be inserted\n");
                fgets(i.name,sizeof(i.name),stdin);
                i.name[strlen(i.name)-1]='\0';
                i.no=(*rear)->data.no+1;
                insertrear_circular(rear,i);
                circular_traverse(*rear);
                break;
            case 'i':
                search(&curr,*rear);
                if(*rear==NULL) printf("The list is empty\n");
                else
                {
                    local=curr->prev;
                    printf("Please enter the text to be inserted\n");
                    fgets(j.name,sizeof(j.name),stdin);
                    j.no=curr->data.no;
                    addafter(local,j);
                    order_update(curr,*rear);
                    circular_traverse(*rear);
                }
                break;
            case 'd':
                search(&curr,*rear);
                if(*rear==NULL) printf("The list is empty\n");
                else if(curr==(*rear)) circular_delrear(&curr);
                else
                {
                    local=curr->next;
                    delany(curr);
                    order_update2(local,*rear);
                }
                circular_traverse(*rear);
                break;
            case 'z':
                curr=*rear;
                circular_delrear(rear);
                circular_traverse(*rear);
                break;
            case 'p':
                search(&curr,*rear);
                puts(curr->data.name);
                break;
            case 'c':
                if(*rear==NULL) printf("The list is empty\n");
                else
                {
                    search(&curr,*rear);
                    printf("Please enter the text to be replaced with\n");
                    fgets(curr->data.name,sizeof(curr->data.name),stdin);
                    circular_traverse(*rear);
                }
                break;
            case 'q':
                search(&curr,*rear);
                printf("please enter a valid index number for truncation\n");
                fgets(brr,sizeof(brr),stdin);
                sscanf(brr,"%d",&m);
                curr->data.name[strlen(curr->data.name)-(strlen(curr->data.name)-m-1)]='\0'; 
                circular_traverse(*rear);
                break;
            case 'm':
                search(&curr,*rear);
                if(*rear==NULL)  printf("The list is empty\n");
                else if(curr==*rear) printf("It's the last line of the list\n");
                else
                {
                    strcat(curr->data.name,curr->next->data.name);
                    if(curr->next==*rear) circular_delrear(&(curr->next));
                    else delany(curr->next);
                    order_update2(curr->next,*rear);
                    circular_traverse(*rear);
                }
                break;
            case 'x':
                if(*rear==NULL)  printf("The list is empty\n");
                else
                {
                    search(&curr,*rear);
                    printf("Please type your sentence for extension\n");
                    fgets(arr1,sizeof(arr1),stdin);
                    arr1[strlen(arr1)-1]='\0';
                    strcat(curr->data.name,arr1);
                    circular_traverse(*rear);
                }
                break;
            case 'u':
                q=pop(&undo);
                push(&redo,q);
                //printf("The last command is undone\n");
                switch(q)
                {
                    case 'a' : printf("The last appended line is deleted\n");
                        break;
                    case 'i': printf("The last inserted line is deleted\n");
                        break;
                    case 'd' : printf("The last deleted line is restored\n");  
                        break;
                    case 'z' : printf("The last line is restored\n");  
                        break;
                    case 'c' : printf("The previous line is restored\n");
                        break;    
                    case 'x' : printf("The extended portion is truncated\n");
                        break;
                    default  : printf("Undo command is not applicable for the previous command\n");
                        break;         
                }
                break;
            case 'r':
                if(isempty(&redo)) printf("No action was undone\n");
                else
                {
                    h=pop(&redo);
                    switch(h)
                    {
                        case 'a' : printf("The last appended line is restored again\n");
                        break;
                        case 'i': printf("The last inserted line is restored again\n");
                        break;
                        case 'd' : printf("The last deleted line is deleted again\n");  
                        break;
                        case 'z' : printf("The last line is deleted again\n");  
                        break;
                        case 'c' : printf("Previous replacement is sucessfully redone\n");
                        break;    
                        case 'x' : printf("Previous extension is sucessfully redone\n");
                        break;
                        default  : printf("Redo command not applicable for the last command\n");
                        break;         
                    }

                }
                //printf("The last undone command is redone\n");
                break;
            case 'l':
                printf("Please enter file name\n");
                fgets(brr,sizeof(brr),stdin); 
                printf("The file is being loaded\n");
                break;
            case 's':
                printf("Please enter file name\n");
                fgets(brr,sizeof(brr),stdin);
                printf("The file is being saveded\n");
                break;
            case 'h': 
                print();
                break;
            default : if(ch!='e') printf("Invalid input\n");
                break;       
        }
    } while (ch!='e');
    
}