#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"train_que.h"

void init(queue *que,int size)
{
    que->size=size;
    que->arr=(item2 *)malloc(que->size*sizeof(item2));
    for(int i=0;i<que->size;i++) que->arr[i]=(item2)malloc(100*sizeof(char));
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
void enqueue(queue *que,item2 value)
{
    // item2 *i;
    // m=(item2*)malooc(q->size*sizeof(item2));
    // for(int j=0;j<que->size;j++) m[j]=(item2)malloc(100*sizeof(item2));
    if(isfull(que)) return;
    else
    {
        
        if(que->front==-1) que->front=0;
        if(que->rear!=que->size-1) que->rear++;
        else que->rear=0;
        //strcpy(que->arr[que->rear],value);
        que->arr[que->rear]=strdup(value);
    }
}
item2 dequeue(queue *que)
{
    //item2 i,m;
    // m=(item2*)malooc(que->size*sizeof(item2));
    // for(int j=0;j<que->size;j++) m[j]=(item2)malloc(100*sizeof(item2));
    //i=(item2)malloc(100*sizeof(char));
    if(isempty(que)) return "";
    else
    {
        item2 temp=(item2)malloc(100*sizeof(char));
        strcpy(temp,que->arr[que->front]);
        if(que->front==que->rear) que->front=que->rear=-1;
        else if(que->front!=que->size-1) que->front++;
        else que->front=0;
        return temp;
    }
}