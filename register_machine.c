#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define item char
typedef struct st
{
    item *arr;
    int top,size;
}stack;
void init(stack *,int );
int isfull(stack *);
int isempty(stack *);
void push(stack *,item );
item pop(stack *);
item peek(stack *);
void findmin(int);
void delete();
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
    if(isempty(ptst)) return '\0' ;
    else return ptst->arr[ptst->top--];
}
item peek(stack *ptst)
{
    if(isempty(ptst)) return '\0';
    else return ptst->arr[ptst->top];
}
void register_machine(char *inarr)
{
    stack st;
    char op1,op2,j='1';
    int i;
    init(&st,strlen(inarr));
    inarr[strlen(inarr)-1]='\0';
    for (i=0;inarr[i]!='\0';i++)
    {
        if(isalpha(inarr[i])) push(&st,(inarr[i]));
        else
        {
            op1=pop(&st);
            op2=pop(&st);
            switch(inarr[i])
            {
                case '+':
                    if(isalpha(op2)) printf("LD %c\n",op2);
                    else printf("LD TEMP%c\n",op2);
                    if(isalpha(op1)) printf("AD %c\n",op1);
                    else printf("AD TEMP%c\n",op1);
                    printf("ST TEMP%c\n",j);
                    push(&st,j);
                    j++;
                    break;
                case '-':
                    if(isalpha(op2)) printf("LD %c\n",op2);
                    else printf("LD TEMP%c\n",op2);
                    if(isalpha(op1)) printf("SB %c\n",op1);
                    else printf("SB TEMP%c\n",op1);
                    printf("ST TEMP%c\n",j);
                    push(&st,j);
                    j++;
                    break;
                case '*':
                    if(isalpha(op2)) printf("LD %c\n",op2);
                    else printf("LD TEMP%c\n",op2);
                    if(isalpha(op1)) printf("ML %c\n",op1);
                    else printf("ML TEMP%c\n",op1);
                    printf("ST TEMP%c\n",j);
                    push(&st,j);
                    j++;
                    break;
                case '/':
                    if(isalpha(op2)) printf("LD %c\n",op2);
                    else printf("LD TEMP%c\n",op2);
                    if(isalpha(op1)) printf("DV %c\n",op1);
                    else printf("DV TEMP%c\n",op1);
                    printf("ST TEMP%c\n",j);
                    push(&st,j);
                    j++;
                    break;
                default : printf("Error\n");
                    break;
            }
            
        }
    }
}
int main()
{
    char arr[100];
    fgets(arr,sizeof(arr),stdin);
    register_machine(arr);
    return 0;
}