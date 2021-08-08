#include<stdlib.h>
#include"avl.h"
#include<string.h>
#include<stdio.h>
#include<ctype.h>
tnode *newnode(item value)
{
    tnode *temp=(tnode*)malloc(sizeof(tnode));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    temp->bfact=0;
    return temp;
}
void print_preorder(tnode* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}
void print_inorder(tnode* root)
{
    if(root!=NULL)
    {
        print_inorder(root->left);
        printf("%d ",root->data);
        //printf("%d B%d\t",root->data,root->bfact);
        print_inorder(root->right);
    }
}
void print_postorder(tnode* root)
{
    if(root!=NULL)
    {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d ",root->data);
    }
}
int depth(tnode* root)
{
    if(root==NULL) return 0;
    else
    {
        int l=depth(root->left);
        int r=depth(root->right);
        return 1+((l>r)?l:r);
    }
}
void cal_bfact(tnode* root)
{
    if(root==NULL) return;
    root->bfact=depth(root->left)-depth(root->right);
}
void leftrotate(tnode **root)
{
    tnode* temp;
    if(*root==NULL) return;
    temp=(*root)->right->left;
    (*root)->right->left=*root;
    *root=(*root)->right;
    (*root)->left->right=temp;
    cal_bfact(*root);
    cal_bfact((*root)->left);
    
}
void rightrotate(tnode **root)
{
    tnode *temp;
    if(*root==NULL) return;
    temp=(*root)->left->right;
    (*root)->left->right=*root;
    *root=(*root)->left;
    (*root)->right->left=temp;
    cal_bfact(*root);
    cal_bfact((*root)->right);
}
void balance(tnode **root)
{
    if(*root==NULL) return;
    cal_bfact(*root);
    if((*root)->bfact>1)
    {
        if((*root)->left->bfact<0)  leftrotate(&(*root)->left);
        
        rightrotate(root);
        //cal_bfact(*root);
        
    }
    else if((*root)->bfact<-1)
    {
        if((*root)->right->bfact>0) rightrotate(&(*root)->right);
        leftrotate(root);
        //cal_bfact(*root);
        
    }
    else return;
}
void insert(tnode **root,item value)
{
    if(*root==NULL) *root=newnode(value);
    
    else
    {
        if(value<(*root)->data) insert(&((*root)->left),value);
        else if(value>(*root)->data) insert(&((*root)->right),value);
        balance(root);
    }
    //printf("%d ",(*root)->data);
    
}
void delnode(tnode **root,item value)
{
    if(*root==NULL) return;
    if(value<(*root)->data) delnode(&((*root)->left),value);
    else if(value>(*root)->data) delnode(&((*root)->right),value);
    else
    {
        tnode *temp=*root;
        if((*root)->left==NULL && (*root)->right==NULL)
        {
            *root=NULL;
            free(temp);
        }
        else if((*root)->left==NULL && (*root)->right!=NULL)
        {
            *root=(*root)->right;
            free(temp);
        }
        else if((*root)->left!=NULL && (*root)->right==NULL)
        {
            *root=(*root)->left;
            free(temp);
        }
        else{
            temp=(*root)->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            (*root)->data=temp->data;
            delnode(&((*root)->right),temp->data);
        }
    }
    if(*root==NULL) return;
    balance(root);
}