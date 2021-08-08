#include<stdlib.h>
#include"splay.h"
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
        print_inorder(root->right);
    }
}
void print_postorder(tnode* root)
{
    if(root!=NULL)
    {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d",root->data);
    }
}
void leftrotate(tnode **root)
{
    if(*root==NULL) return;
    tnode *temp=(*root)->right->left;
    (*root)->right->left=(*root);
    *root=(*root)->right;
    (*root)->left->right=temp;
}
void rightrotate(tnode **root)
{
    if(*root==NULL) return;
    tnode *temp=(*root)->left->right;
    (*root)->left->right=*root;
    *root=(*root)->left;
    (*root)->right->left=temp;
}
void splay(tnode **root, int key)
{
    if(*root==NULL || (*root)->data==key) return;
    else if(key<(*root)->data)
    {
        if((*root)->left==NULL) return;
        if(key<(*root)->left->data)
        {
            splay(&(*root)->left->left,key);
            rightrotate(root);
        }
        else if(key>(*root)->left->data)
        {
            splay(&(*root)->left->right,key);
            if((*root)->left->right!=NULL) leftrotate(&(*root)->left);
        }
        if((*root)->left==NULL) return;
        else rightrotate(root);
    }
    else if(key>(*root)->data)
    {
        if((*root)->right==NULL) return;
        if(key>(*root)->right->data)
        {
            splay(&(*root)->right->right,key);
            leftrotate(root);
        }
        else if(key<(*root)->right->data)
        {
            splay(&(*root)->right->left,key);
            if((*root)->right->left!=NULL) rightrotate(&(*root)->right);
        }
        if((*root)->right==NULL) return;
        else leftrotate(root);
    }
}
void split(tnode **root,int key)
{
    tnode *temp=newnode(key);
    if(key<(*root)->data)
    {
        temp->right=*root;
        temp->left=(*root)->left;
        (*root)->left=NULL;
    }
    else if(key>(*root)->data)
    {
        temp->right=(*root)->right;
        temp->left=(*root);
        (*root)->right=NULL;
    }
    *root=temp;
    
}
void insert(tnode **root,int key)
{
    if(*root==NULL) *root=newnode(key);
    else
    {
        splay(root,key);
        if((*root)->data==key) return;
        split(root,key);
    }
}
void delete(tnode** root,int key)
{
    tnode* temp;
    if(*root==NULL) return;
    splay(root,key);
    if(key!=(*root)->data) return;
    if((*root)->left==NULL)
    {
        temp=*root;
        *root=(*root)->right;
    }
    else
    {
        temp=(*root);
        splay(&(*root)->left,key);
        (*root)=(*root)->left;
        (*root)->right=temp->right;
    }
    free(temp); 
}