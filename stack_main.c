#include<stdio.h>
#include<string.h>
#include"stack.h"
/*int main()
{
    char inarr[100];
    int c;
    fgets(inarr,sizeof(inarr),stdin);
    c=postfix_evaluator(inarr);
    printf("%d",c);
    return 0;
}*/
int main()
{
    stack ptst,st;
    int s;
    printf("please enter the size of the stack\n");
    scanf("%d",&s);
    init(&ptst,s);
    init(&st,s);
    //stack ;
    //init(&st,ptst->size);
    int i=findmin(&ptst,8,&st);
    i=findmin(&ptst,3,&st);
    i=findmin(&ptst,6,&st);
    i=findmin(&ptst,2,&st);
    i=findmin(&ptst,9,&st);
    printf("%d",i,&st);
    return 0;
}