#include<stdio.h>
#include"library.h"
int main()
{
    int i,n;
    scanf("%d",&n);
    i=count(n);
    printf("%d",i);
    return 0;
}