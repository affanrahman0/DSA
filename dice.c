#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,p,k,c;
        scanf("%d%d%d",&n,&p,&k);
        c=p%k;
        if(p>=k)
        {
            c+=(c+2);
        }
        else c+=(c+1);
        printf("%d\n",c);
    }
        
    return 0;
}