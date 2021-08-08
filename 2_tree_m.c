#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"2_tree.h"
int main()
{
    char arr[100];
    int i;
    fgets(arr,sizeof(arr),stdin);
    arr[strlen(arr)-1]='\0';
    i=tree_eval_multidigit(arr);
    printf("%d",i);
    return 0;
}
