#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long int n,r,i,s,p;
        scanf("%ld%ld",&n,&r);
        long int a[n],b[n];
        for(i=0;i<n;i++)
        {
            scanf("%ld",a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%ld",b[i]);
        }
            s=b[0];
            p=s;
            for(i=1;i<n;i++)
            {
                s+=(b[i]-((a[i]-a[i-1])*r));
                if(p<s) p=s;
            }
            printf("%ld\n",p);

    }
    return 0;
}