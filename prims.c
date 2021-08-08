#include<stdio.h>
#include<stdlib.h>
#define item int
#define item2 edge
//#define"adj_list.h"
typedef struct v{
    int src,dest,cost;
}edge;
typedef struct ad{
    item dest;
    int cost;
    struct ad* next;
}node;
typedef struct a{
    node* head;
}list;
typedef struct g{
    item v,e;
    list* arr;
}graph;
// typedef struct o{
//     int src,dest,cost;
// }edge;
typedef struct q
{
    item2 *arr;
    int rear,size;
}queue;
graph *create(item v,item e)
{
    graph* temp=(graph*)malloc(sizeof(graph));
    temp->v=v;
    temp->e=e;
    temp->arr=(list*)malloc(v*sizeof(list));
    for(int i=0;i<v;i++) temp->arr[i].head=NULL;
    return temp;
}
node *newnode(item dest,item cost)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->dest=dest;
    temp->cost=cost;
    temp->next=NULL;
    return temp;
}
void addbegin(graph* g,item src, item dest,int cost)
{
    node *temp=newnode(dest,cost);
    temp->next=g->arr[src].head;
    g->arr[src].head=temp;
    temp=newnode(src,cost);
    temp->next=g->arr[dest].head;
    g->arr[dest].head=temp;
}
void init(queue *que,int size)
{
    que->size=size;
    que->arr=(item2 *)malloc(que->size*sizeof(item2));
    que->rear=-1;
}
int isempty(queue *que)
{
    return que->rear==-1;
}
int isfull(queue *que)
{
    return (que->rear==que->size-1);
}
void swap(item2 *p,item2 *q)
{
    item2 temp=*p;
    *p=*q;
    *q=temp;
}
void enqueue(queue *que,item2 value)
{
    if(isfull(que)) return;
    else
    {
        que->arr[++que->rear]=value;
        int parent,child=que->rear;
        do
        {
            parent=(child-1)/2;
            if(que->arr[child].cost<que->arr[parent].cost) 
            {
                swap(&que->arr[child],&que->arr[parent]);
                child=parent;
            }
            else break;
        } while (child!=0);
        
    }
}
item2 dequeue(queue *que)
{
    item2 p;
    if(isempty(que)) return p;
    else
    {
        item2 temp=que->arr[0];
        que->arr[0]=que->arr[que->rear--];
        int child,parent=0;
        do
        {
           child= 2*parent+ 1;
           if(child<que->rear && que->arr[child].cost>que->arr[child+1].cost) child++;
           if(que->arr[child].cost<que->arr[parent].cost)
           {
               swap(&que->arr[child],&que->arr[parent]);
               parent=child;
           }
           else break;
        } while (parent<=que->rear);
        return temp;
        
    }
}
graph* prims(graph *g)
{
    graph* mst=create(g->v,g->e);
    queue q;
    init(&q,50);
    int *flag=(int*)calloc(g->v,sizeof(int));
    edge v;
    v.src=v.dest=0;
    enqueue(&q,v);
    while(!isempty(&q))
    {
        v=dequeue(&q);
        if(flag[v.dest]==0)
        {
            if(v.src!=v.dest)
            {
                addbegin(mst,v.src,v.dest,v.cost);
            }
            flag[v.dest]=1;
            for(node* ptr=g->arr[v.dest].head;ptr!=NULL;ptr=ptr->next)
            {
                if(flag[ptr->dest]==0)
                {
                    edge m;
                    m.dest=ptr->dest;
                    m.cost=ptr->cost;
                    m.src=v.dest;
                    enqueue(&q,m);
                }
            }
        }
    }
    return mst;

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
    fp=fopen("c:\\Users\\rahma\\prims.txt","r+");
    // fgets(arr,sizeof(arr),fp);
    // sscanf(arr,"%d",&j);
    graph* g=create(9,14);
    while(fgets(arr,sizeof(arr),fp)!=NULL)
    {
        sscanf(arr,"%d%d%d",&s,&d,&j);
        //printf("%d %d %d\n",s,d,j);
        addbegin(g,s,d,j);
        //printf("%d %d %d\n",s,d,j);
    }
    fclose(fp);
    printf("Adjacency list representation of graph\n");
    print(g);
    graph *m=prims(g);
    printf("Adjacency list representation of MST\n");
    print(m);
    return 0;
}