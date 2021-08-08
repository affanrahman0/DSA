#include<stdlib.h>
#include<stdio.h>
#include"p_doc.h"
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
            if(que->arr[child].no>que->arr[parent].no) 
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
           if(child<que->rear && que->arr[child].no<que->arr[child+1].no) child++;
           if(que->arr[child].no>que->arr[parent].no)
           {
               swap(&que->arr[child],&que->arr[parent]);
               parent=child;
           }
           else break;
        } while (parent<=que->rear);
        return temp;
        
    }
}
void hospital(queue *que)
{
    item j,k;
    char ch,tr[10],a[100];
    do
    {
        printf("Please enter 'u' for appointment of a serious patient\n");
        printf("Please enter 'n' for a normal appointment\n");
        printf("Press 'e' to exit\n");
        fgets(tr,sizeof(tr),stdin);
        sscanf(tr,"%c",&ch);
        switch(ch)
        {
            case 'n':
            printf("Please enter name and age of the patient\n");
            fgets(a,sizeof(a),stdin);
            sscanf(a,"%s%s%d",j.name,j.sur,&j.no);
            k=dequeue(que);
            printf("Our next patient is %s %s, Age :%d\n",k.name,k.sur,k.no);
            enqueue(que,j);
            break;
            case 'u':
            printf("Please enter name and age of the patient\n");
            fgets(a,sizeof(a),stdin);
            sscanf(a,"%s%s%d",j.name,j.sur,&j.no);
            printf("Our next patient is %s %s, Age :%d\n",j.name,j.sur,j.no);
            break;
            default: if(ch!='e')printf("Invalid input\n");
            break;
        }
    } while (ch!='e');
    
}