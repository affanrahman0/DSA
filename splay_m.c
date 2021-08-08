#include<stdlib.h>
#include"splay.h"
#include<string.h>
#include<stdio.h>
#include<ctype.h>
int main()
{
    // Splay Tree Formation
    // tnode *root = newnode(6);
    // root->left = newnode(1);
    // root->right = newnode(9);
    // root->left->right = newnode(4);
    // root->left->right->left = newnode(2);
    // root->right->left = newnode(7);
   
    //  int key = 4;
    tnode* root=NULL;
    insert(&root,6);
    insert(&root,1);
    insert(&root,9);
    insert(&root,4);
    insert(&root,2);
    insert(&root,7);
    print_preorder(root);
    printf("\n");
    delete(&root, 4);
    printf("Preorder traversal of the modified Splay tree is \n");
    print_preorder(root);
    return 0;
} 