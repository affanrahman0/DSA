#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"adj_list.h"
#define item int
char** brr;
typedef struct q
{
    item *arr;
    int front,rear,size;
}queue;
void init(queue *que,int size)
{
    que->size=size;
    que->arr=(item *)malloc(que->size*sizeof(item));
    que->rear=que->front=-1;
}
int isempty(queue *que)
{
    return que->rear==-1;
}
int isfull(queue *que)
{
    return (((que->rear==que->size-1) && que->front==0)||que->front==que->rear+1);
}
void enqueue(queue *que,item value)
{
    if(isfull(que)) return;
    else
    {
        if(que->front==-1) que->front=0;
        if(que->rear!=que->size-1) que->rear++;
        else que->rear=0;
        que->arr[que->rear]=value;
    }
}
item dequeue(queue *que)
{
    if(isempty(que)) return -9999;
    else
    {
        item temp=que->arr[que->front];
        if(que->front==que->rear) que->front=que->rear=-1;
        else if(que->front!=que->size-1) que->front++;
        else que->front=0;
        return temp;
    }
}
void bfs(graph* g)
{
    queue que;
    init(&que,30);
    node* temp;
    item *flag=(item*)calloc(g->v,sizeof(item));
    char m[100];
    int k;
    printf("Please enter the ip address which will deliver the message to the neighbouring nodes\n");
    scanf("%s",m);
    for( k=0;k<g->v;k++)
    {
        if(strcmp(brr[k],m)==0)
        {
            break;
        }
    }
    enqueue(&que,k);
    while(!isempty(&que))
    {
        int i=dequeue(&que);
        if(flag[i]!=1)
        {
            printf("%s->",brr[i]);
            flag[i]=1;
            temp=g->arr[i].head;
            while(temp)
            {
                if(flag[temp->dest]!=1) enqueue(&que,temp->dest);
                temp=temp->next;
            }
        }
    }

}
void print(graph* g)
{
    for (int i = 0; i < g->v; ++i)
    {
        printf("[%d]",i);
        node* temp = g->arr[i].head;
        while(temp)
        {
            printf("->%d",temp->dest);
            temp=temp->next;
        }
        printf("\n");
    }    
}
//char** brr;
int main()
{
    FILE* fp;
    char arr[100],x[15],y[15];
    int s,d,j,m=0;
    fp=fopen("c:\\Users\\rahma\\ip_address.txt","r+");
    fgets(arr,sizeof(arr),fp);
    sscanf(arr,"%d",&j);
    graph* g=create(j);
    brr=(char**)malloc(j*sizeof(char*));
    for(int i=0;i<j;i++) brr[i]=(char*)malloc(100*sizeof(char));
    for(int i=0;i<j;i++) brr[i][0]='\0';
    
    while(fgets(arr,sizeof(arr),fp)!=NULL)
    {
        sscanf(arr,"%s%s",x,y);
        for(int k=0;k<5;k++)
        {
            if(strcmp(brr[k],x)==0)
            {
                s=k;
                break;
            }
            else if(brr[k][0]=='\0')
            {
                strcpy(brr[k],x);
                s=k;
                break;
            }
        }
        for(int k=0;k<5;k++)
        {
            if(strcmp(brr[k],y)==0)
            {
                d=k;
                break;
            }
            else if(brr[k][0]=='\0')
            {
                strcpy(brr[k],y);
                d=k;
                break;
            }
        }
        //printf("%d %d\n",s,d);
        addbegin(g,s,d);
    }
    fclose(fp);
    //print(g);
    bfs(g);
    return 0;
}