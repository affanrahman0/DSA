#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"adj_list.h"
#define item int
char** brr;
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
    init(&st,30);
    node* temp;
    int *flag=(int*)calloc(g->v,sizeof(int));
    char m[100];
    int k;
    printf("Please enter the station name\n");
    scanf("%s",m);
    for( k=0;k<g->v;k++)
    {
        if(strcmp(brr[k],m)==0)
        {
            break;
        }
    }
    push(&st,k);
    while(!isempty(&st))
    {
        int i=pop(&st);
        if(flag[i]!=1)
        {
            printf("%s->",brr[i]);
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
        printf("\n");
    }    
}
//char** brr;
int main()
{
    FILE* fp;
    char arr[100],x[15],y[15];
    int s,d,j,m=0;
    fp=fopen("c:\\Users\\rahma\\metro.txt","r+");
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
    dfs(g);
    return 0;
}