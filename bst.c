#include<stdlib.h>
#include"bst.h"
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
        printf("%d",root->data);
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
void insert(tnode **root,item value)
{
    if(*root=NULL) *root=newnode(value);
    else if(value<(*root)->data) insert(&((*root)->left),value);
    else if(value>(*root)->data) insert(&((*root)->right),value);
}
tnode *search(tnode *root,item value)
{
    if(root==NULL) return NULL;
    else{
        if(root->data==value) return root;
        else if(value<root->data) return search(root->left,value);
        else return search(root->right,value);
    }
}

//if found returns the node (used for delete)
// else returns the last node while traversing (used in insert)
// tnode *search(tnode *root,item value)
// {
//     if(root==NULL) return NULL;
//     else{
//         if(root->data==value) return root;
//         else if(value<root->data)
//         {
//             if(root->left!=NULL)return search(root->left,value);
//             else return root;
//         } 
        
//          else //return search(root->right,value);
//         {
//             if(root->right!=NULL)return search(root->right,value);
//             else return root;
//         } 
//     }
// }


void delnode(tnode **root,item value)
{
    if(*root==NULL) return;
    if(value<(*root)->data) delnode(&((*root)->left),value);
    else if(value>(*root)->data) delnode(&((*root)->right),value);
    else
    {
        tnode *temp=root;
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
}
// void delnode(tnode **root,item value)
// {
//     if(*root==NULL) return;
//     if(value<(*root)->data) delnode(&((*root)->left),value);
//     else if(value>(*root)->data) delnode(&((*root)->right),value);
//     else
//     {
//         tnode *temp=*root;
//         if((*root)->left==NULL && (*root)->right==NULL)
//         {
//             *root=NULL;
//             free(temp);
//         }
//         else if((*root)->left==NULL && (*root)->right!=NULL)
//         {
//             *root=(*root)->right;
//             free(temp);
//         }
//         else if((*root)->left!=NULL && (*root)->right==NULL)
//         {
//             *root=(*root)->left;
//             free(temp);
//         }
//         else{
//             temp=(*root)->right;
//             while(temp->left!=NULL)
//             {
//                 temp=temp->left;
//             }
//             (*root)->data=temp->data;
//             delnode(&((*root)->right),temp->data);
//         }
//     }
//     if(*root==NULL) return;
//     balance(root);
// }