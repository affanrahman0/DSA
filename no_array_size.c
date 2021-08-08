#include <stdio.h>

int main() {
    int arr[1000],i=0,j;
    char t;
    do{
        scanf("%d%c",&arr[i],&t);
        i++;
    }while(t!='\n');
    for(j=0;j<i;j++)
    {
        printf("%d\t",arr[j]);
    }
    
    return 0;
}