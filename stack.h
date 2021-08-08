#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define item int
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
int pred(char );
char *intopostconvert(char *);
char *intopostconvert_multidigit(char *);
int calculate(int ,int ,char );
int postfix_evaluator(char *);
int findmin(stack *,int,stack *);