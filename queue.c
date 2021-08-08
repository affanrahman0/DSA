#include<stdlib.h>
#include<stdio.h>
#include"queue.h"
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