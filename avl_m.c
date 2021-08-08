#include<stdlib.h>
#include"avl.h"
#include<string.h>
#include<stdio.h>
#include<ctype.h>
int main()
{
    tnode *root=NULL;
    int i=1;
    insert(&root,i++);
    insert(&root,i++);
    insert(&root,i++);
    insert(&root,i++);
    insert(&root,i++);
    insert(&root,i++);
    printf("Inorder traversal\n");
    print_inorder(root);
    printf("\n");
    printf("Postorder traversal\n");
    print_postorder(root);
    printf("\n");
    printf("Preorder traversal\n");
    print_preorder(root);
    delnode(&root,4);
    printf("\n");
    printf("Inorder traversal after deletion\n");
    print_inorder(root);
    printf("\n");
    printf("Postorder traversal after deletion\n");
    print_postorder(root);
    printf("\n");
    printf("Preorder traversal after deletion\n");
    print_preorder(root);    
    return 0;
}