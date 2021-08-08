#include<stdio.h>
int main()
{
    int x[100],i,n,j,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    for(i=0;i<n;i++)
    {
        int c=1;
        b=c;
        for(j=i+1;j<n;j++)
        {
            if((x[i]-x[j])==1 || (x[i]-x[j])==0)
            {
                c++;
            }
        
        }
        if(c>b) b=c;
    }
    printf("%d",b);
    return 0;
}