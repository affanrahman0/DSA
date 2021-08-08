#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define item int
typedef struct st
{
    item *arr;
    int top,size;
}stack;
void init(stack *,item );
int isfull(stack *);
int isempty(stack *);
void push(stack *,item );
item pop(stack *);
item peek(stack *);
void findmin(int);
void delete();
void init(stack *ptst,item max_size)
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
stack ptst,st;
void findmin(int value)
{
    if(!isempty(&st))
    {
        if(peek(&st)>value) push(&st,value);
    }
    else push(&st,value);
    push(&ptst,value);
}
void delete()
{
    if(peek(&ptst)==peek(&st))
    {
        pop(&st);
        pop(&ptst);
    }
    else pop(&ptst);
}
int main()
{
    int s;
    printf("please enter the size of the stack\n");
    scanf("%d",&s);
    init(&ptst,s);
    init(&st,s);
    while(s--)
    {
        int a;
        printf("Please enter a value\n");
        scanf("%d",&a);
        findmin(a);
    }
    printf("%d\n",peek(&st));
    delete();
    printf("%d\n",peek(&st));
    delete();
    printf("%d\n",peek(&st));
    return 0;
}