#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define item int
#define item2 edge
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
typedef struct k{
    int v,e;
    edge* arr;
}kgraph;
typedef struct q
{
    item2 *arr;
    int rear,size;
}queue;
void k_init(kgraph *gr,int e,int v)
{
    gr->e=e;
    gr->v=v;
    gr->arr=(edge*)malloc(e*sizeof(edge));
}
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
int find(int parent[], int i)
{
    if(parent[i]==-1) return i;
    else return find(parent,parent[i]);
}
void un(int parent[],int u, int v)
{
    int uparent=find(parent,u);
    int vparent=find(parent,v);
    if(uparent!=vparent)
    {
        parent[vparent]=uparent;
    }
}
graph* krushkal(kgraph* gr)
{
    graph *mst=create(gr->v,gr->e);
    edge val;
    int parent[gr->v];
    memset(parent,-1,gr->v*sizeof(parent[0]));
    queue que;
    init(&que,50);
    for(int i=0;i<gr->e;i++) enqueue(&que,gr->arr[i]);
    while(!isempty(&que))
    {
        val=dequeue(&que);
        int u=find(parent,val.src);
        int v=find(parent,val.dest);
        if(u!=v)
        {
            un(parent,u,v);
            addbegin(mst,val.src,val.dest,val.cost);
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
    kgraph gr;
    k_init(&gr,14,9);
    int i=0;
    while(fgets(arr,sizeof(arr),fp)!=NULL)
    {
        sscanf(arr,"%d%d%d",&s,&d,&j);
        gr.arr[i].src=s;
        gr.arr[i].dest=d;
        gr.arr[i].cost=j;
        i++;

    }
    fclose(fp);
    graph *m=krushkal(&gr);
    printf("Adjacency list representation of MST\n");
    print(m);
    return 0;
}