#include<stdio.h>
#include<stdlib.h>
#include"adj_list.h"
#define item int
typedef struct st
{
    item *arr;
    int top,size;
}stack;
void init(stack *ptst,int max_size)
{
    ptst->size=max_size;
    ptst->arr=(item *)malloc(ptst->size*sizeof(item));
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
void push(stack *ptst,item value)
{
    if(isfull(ptst)) return;
    else ptst->arr[++ptst->top]=value;
}
item pop(stack *ptst)
{
    if(isempty(ptst)) return -999999 ;
    else return ptst->arr[ptst->top--];
}
item peek(stack *ptst)
{
    if(isempty(ptst)) return -999999;
    else return ptst->arr[ptst->top];
}
void dfs(graph* g)
{
    stack st;
    init(&st,g->v);
    node* temp;
    int *flag=(int*)calloc(g->v,sizeof(int));
    //for(int j=0;j<g->v;j++) printf("\n%d",flag[j]);
    push(&st,2);
    while(!isempty(&st))
    {
        int i=pop(&st);
        if(flag[i]!=1)
        {
            printf("%d ",i);
            flag[i]=1;
            temp=g->arr[i].head;
            while(temp)
            {
                if(flag[temp->dest]!=1) push(&st,temp->dest);
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
        printf("->NULL\n");
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
    dfs(g);
    return 0;
}