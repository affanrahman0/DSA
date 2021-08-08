#include<stdio.h>
#include<string.h>
int main()
{
    char **name,x[50],source[20];
    int n,i;
    fgets(x,sizeof(x),stdin);
    sscanf(x,"%d",&n);
    name=(char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++)
    {
        name[i]=strdup(source);
  
    }
    return 0;
}