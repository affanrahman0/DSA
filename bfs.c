#include<stdio.h>
#include<stdlib.h>
#include"adj_list.h"
#define item int
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
    //for(int j=0;j<g->v;j++) printf("\n%d",flag[j]);
    enqueue(&que,0);
    while(!isempty(&que))
    {
        int i=dequeue(&que);
        if(flag[i]!=1)
        {
            printf("%d ",i);
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
int main()
{
    FILE* fp;
    char arr[100];
    int s,d,j;
    fp=fopen("c:\\Users\\rahma\\graph.txt","r+");
    fgets(arr,sizeof(arr),fp);
    sscanf(arr,"%d",&j);
    graph* g=create(j);
    while(fgets(arr,sizeof(arr),fp)!=NULL)
    {
        sscanf(arr,"%d%d",&s,&d);
        //printf("%d %d\n",s,d);
        addbegin(g,s,d);
    }
    fclose(fp);
    /*addbegin(g, 0, 1);
    addbegin(g, 0, 4);
    addbegin(g, 1, 2);
    addbegin(g, 1, 3);
    addbegin(g, 1, 4);
    addbegin(g, 2, 3);
    addbegin(g, 3, 4);*/
    print(g);
    bfs(g);
    return 0;
}