#include<stdio.h>
#include<string.h>
int main()
{
    char x[100],y[10000];
    
    //gets(x);
    //int n=strlen(x);
    fgets(y,10000,stdin);
    int l=strlen(y);
    printf("%d",l);
        
    
    return 0;
}