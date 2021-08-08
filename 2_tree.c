#include<stdlib.h>
#include"2_tree.h"
#include<string.h>
#include<stdio.h>
#include<ctype.h>
tnode *newnode(item value)
{
    tnode *temp=(tnode*)malloc(sizeof(tnode));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void init(stack *ptst,int max_size)
{
    ptst->size=max_size;
    ptst->arr=(item2 *)malloc(ptst->size*sizeof(item2));
    ptst->top=-1;
}
void print_preorder(tnode* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
    //else return;
}
void print_inorder(tnode* root)
{
    if(root!=NULL)
    {
        print_inorder(root->left);
        printf("%d",root->data);
        print_inorder(root->right);
    }
    else return;
}
void print_postorder(tnode* root)
{
    if(root!=NULL)
    {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d",root->data);
    }
    else return;
}
int isfull(stack *ptst)
{
    return ptst->top==ptst->size-1;
}
int isempty(stack *ptst)
{
    return ptst->top==-1;
}
void push(stack *ptst,item2 value)
{
    if(isfull(ptst)) return;
    else ptst->arr[++ptst->top]=value;
}
item2 pop(stack *ptst)
{
    if(isempty(ptst)) return NULL ;
    else return ptst->arr[ptst->top--];
}
item2 peek(stack *ptst)
{
    if(isempty(ptst)) return NULL;
    else return ptst->arr[ptst->top];
}
int pred(char ch)
{
    if(ch =='/' || ch== '*' || ch =='%') return 3;
    else if(ch =='+' || ch =='-') return 2;
    else return 1;
}
void popnpush(stack *tree,stack *st)
{
    tnode* temp = pop(st);
    temp->right=pop(tree);
    temp->left=pop(tree);
    push(tree,temp);
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
int evaluate(tnode *root)
{
    if(root==NULL) return 0;
    else if((root->data>=0 && root->data<=9)) return root->data;
    else
    {
        int a=evaluate(root->left);
        int b=evaluate(root->right);
        int v=calculate(a,b,(char)root->data);
        return v;
    }
}
int tree_eval(char *inarr)
{
    stack st,tree;
    int i,j,k;
    tnode *temp;
    init(&st,strlen(inarr));
    init(&tree,strlen(inarr));
    for(i=0,j=0;inarr[i]!='\0';i++)
    {
        
        if(inarr[i]>='0' && inarr[i]<='9') 
        {
            temp=newnode(inarr[i]-'0');
            push(&tree,temp);

        }
        else
        {
            switch(inarr[i])
            {
                case '(':
                    temp=newnode('(');
                    push(&st,temp);
                    break;
                case ')':
                    do{
                        temp=peek(&st);
                        if(temp->data!='(') popnpush(&tree,&st);
                        else pop(&st);
                    }while(temp->data!='(');
                    break;
                default:
                    while(!isempty(&st) && pred(peek(&st)->data)>=pred(inarr[i]))
                    {
                        popnpush(&tree,&st);
                    }
                    temp=newnode(inarr[i]);
                    push(&st,temp);
                    break;    

            }
        }
    }
    while(!isempty(&st)) popnpush(&tree,&st);
   k=evaluate(pop(&tree));
   return k;
}
int evaluate_multi(tnode *root)
{
    if(root==NULL) return 0;
    else if(root->data!='+' && root->data!='*' && root->data!='-' && root->data!='/') return root->data;
    else
    {
        int a=evaluate_multi(root->left);
        int b=evaluate_multi(root->right);
        int v=calculate(a,b,(char)root->data);
        return v;
    }
}
int tree_eval_multidigit(char *inarr)
{
    stack st,tree;
    int i=0,j,k;
    char *ptr;
    tnode *temp;
    init(&st,strlen(inarr));
    init(&tree,strlen(inarr));
    ptr=strtok(inarr," ");
    while(ptr!=NULL)
    {
        if(strlen(ptr)>=2)
        {
            int m=strlen(ptr);
            sscanf(ptr,"%d",&j);
            temp=newnode(j);
            push(&tree,temp);
        }
        else if(*ptr>='0' && *ptr<='9') 
        {
            temp=newnode(*ptr-'0');
            push(&tree,temp);
        }
        else
        {
            switch(*ptr)
            {
                case '(':
                    temp=newnode('(');
                    push(&st,temp);
                    break;
                case ')':
                    do{
                        temp=peek(&st);
                        if(temp->data!='(') popnpush(&tree,&st);
                        else pop(&st);
                    }while(temp->data!='(');
                    break;
                default:
                    while(!isempty(&st) && pred(peek(&st)->data)>=pred(*ptr))
                    {
                        popnpush(&tree,&st);
                    }
                    temp=newnode(*ptr);
                    push(&st,temp);
                    break;    

            }
        }
        ptr=strtok(NULL," ");
    }
    while(!isempty(&st)) popnpush(&tree,&st);
   k=evaluate_multi(pop(&tree));
   return k;
}
