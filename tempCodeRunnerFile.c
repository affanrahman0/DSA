#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,p,k,c=0;;
        scanf("%d%d%d%d",&n,&p,&k);
        for(int i=0;i<=n/2;i++)
        {
            c++;
            if(i==p)
            {
                break;
            }
            c++;
            if(i+k==p)
            {
                break;
            }
        }
        printf("%d\n",c);

    }
        
    return 0;
}