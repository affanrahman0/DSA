#include<stdlib.h>
#include<stdio.h>
#include"p_que.h"
void init(queue *que,int size)
{
    que->size=size;
    que->arr=(item *)malloc(que->size*sizeof(item));
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
void swap(item *p,item *q)
{
    item temp=*p;
    *p=*q;
    *q=temp;
}
void enqueue(queue *que,item value)
{
    if(isfull(que)) return;
    else
    {
        que->arr[++que->rear]=value;
        int parent,child=que->rear;
        do
        {
            parent=(child-1)/2;
            if(que->arr[child]>que->arr[parent]) 
            {
                swap(&que->arr[child],&que->arr[parent]);
                child=parent;
            }
            else break;
        } while (child!=0);
        
    }
}
item dequeue(queue *que)
{
    item p;
    if(isempty(que)) return p;
    else
    {
        item temp=que->arr[0];
        que->arr[0]=que->arr[que->rear--];
        int child,parent=0;
        do
        {
           child= 2*parent+ 1;
           if(child<que->rear && que->arr[child]<que->arr[child+1]) child++;
           if(que->arr[child]>que->arr[parent])
           {
               swap(&que->arr[child],&que->arr[parent]);
               parent=child;
           }
           else break;
        } while (parent<=que->rear);
        return temp;
        
    }
}
void heapify(int arr[],int n)
{
    for(int i=n-1;i>=0;i--)
    {
        int c,p=i;
        do
        {
            c=2*p+1;
            if(c>=n) break;
            else
            {
                if(c<n-1 && arr[c]<arr[c+1]) c++;
                if(arr[p]<arr[c])
                {
                    swap(&arr[p],&arr[c]);
                    p=c;
                }
                else break;
                
            }
        } while(c<n);
        
    }
}
void heap_sort(int arr[],int n)
{
    heapify(arr,n);
   for(int i=n-1;i>0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i);
    }
}
