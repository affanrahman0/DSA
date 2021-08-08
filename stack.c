#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
//#define item char
#include <ctype.h>
#include<string.h>
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
int pred(char ch)
{
    if(ch =='/' || ch== '*' || ch =='%') return 3;
    else if(ch =='+' || ch =='-') return 2;
    else return 1;
}
char *intopostconvert_multidigit(char *inarr)
{
    static char outarr[100];
    inarr[strlen(inarr)-1]='\0';
    stack st;
    int i=0,j=0;
    char temp,*ptr;
    init(&st,strlen(inarr));
    ptr=strtok(inarr," ");
    while(ptr!=NULL)
    {
        if(strlen(ptr)>=2)
        {
            int m=strlen(ptr);
            while(m--)
            {
                outarr[j++]=inarr[i++];
            }
        }
        else if(inarr[i]>='0' && inarr[i]<='9') 
        {
            outarr[j++]=inarr[i++];

        }
        else
        {
            switch(inarr[i])
            {
                case '(':
                    push(&st,'(');
                    break;
                case ')':
                    do{
                        temp=pop(&st);
                        if(temp!='(') outarr[j++]=temp;
                    }while(temp!='(');
                    break;
                default:
                    while(!isempty(&st) && pred(peek(&st))>=pred(inarr[i]))
                    {
                        outarr[j++]=pop(&st);
                    }
                    push(&st,inarr[i]);
                    break;    

            }
            i++;
        }
        ptr=strtok(NULL," ");
        i++;
    }
    while(!isempty(&st)) outarr[j++]=pop(&st);
    outarr[j]='\0';
    return outarr;
}
char *intopostconvert(char *inarr)
{
    static char outarr[100];
    stack st;
    int i,j;
    char temp,*ptr;
    init(&st,strlen(inarr));
    for(i=0,j=0;inarr[i]!='\0';i++)
    {
        
        if(inarr[i]>='0' && inarr[i]<='9') 
        {
            outarr[j++]=inarr[i];

        }
        else
        {
            switch(inarr[i])
            {
                case '(':
                    push(&st,'(');
                    break;
                case ')':
                    do{
                        temp=pop(&st);
                        if(temp!='(') outarr[j++]=temp;
                    }while(temp!='(');
                    break;
                default:
                    while(!isempty(&st) && pred(peek(&st))>=pred(inarr[i]))
                    {
                        outarr[j++]=pop(&st);
                    }
                    push(&st,inarr[i]);
                    break;    

            }
        }
    }
    while(!isempty(&st)) outarr[j++]=pop(&st);
    outarr[j]='\0';
    return outarr;
}
int calculate(int x,int y,char ch)
{
    int z;
    switch(ch)
    {
        case '+': z=x+y;
                break;
        case '-': z=x-y;
                break;
        case '*': z=x*y;
                break;
        case '/': z=x/y;
                break;   
    }
    return z;
}
int postfix_evaluator(char *inarr)
{
    stack st;
    int res,op1,op2,i;
    init(&st,strlen(inarr));
    inarr[strlen(inarr)-1]='\0';
    for (i=0;inarr[i]!='\0';i++)
    {
      // printf("%d\n",peek(&st));
        if(isdigit(inarr[i])) push(&st,(inarr[i]-'0'));
        else
        {
            op1=pop(&st);
            op2=pop(&st);
            res=calculate(op2,op1,inarr[i]);
            push(&st,res);
        }
    }
    //printf("%d\n",peek(&st));
    return pop(&st);
}
int register_machine(char *inarr)
{
    stack st;
    int res,op1,op2,i;
    init(&st,strlen(inarr));
    inarr[strlen(inarr)-1]='\0';
    for (i=0;inarr[i]!='\0';i++)
    {
        if(isdigit(inarr[i])) push(&st,(inarr[i]-'0'));
        else
        {
            op1=pop(&st);
            op2=pop(&st);
            res=calculate(op2,op1,inarr[i]);
            push(&st,res);
        }
    }
    //printf("%d\n",peek(&st));
    return pop(&st);
}

