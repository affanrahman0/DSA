#include<stdio.h>
#include"library.h"
int main()
{
    int n,i,j;
    printf("Enter no.of terms to be printed");
    sacnf("%d",&n);
    for(i=1;i<=n;i++)
    {
        j=fibor(i);
        printf("\t%d",j);

    }
    return 0;
}