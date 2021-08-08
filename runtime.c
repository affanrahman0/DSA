#include<stdio.h>
#include<stdlib.h>
int max(int i,int j)
{
    if(i>j) return i;
    else return j;
}
int func(char x[],char y[],int i,int j)
{
    if(i<=0 || j<=0) return 0;
    else if(x[i-1]==y[j-1]) return 1+func(x,y,i-1,j-1);
    else
    {
        return max(func(x,y,i,j-1),func(x,y,i-1,j));
    }
}
int main()
{
    char x[5000],y[5000];
    //fgets(x,5000,stdin);
    //fgets(y,5000,stdin);
    int n,m,f,g,i,j,a=0,b=0,res;
    gets(x);
    gets(y);
    f=strlen(x);
    g=strlen(y);
    res=func(x,y,f,g);
    printf("%d",res);
    return 0;
}