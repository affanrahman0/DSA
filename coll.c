#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long int s,i,j,cal=0;
        scanf("%ld",&s);
        long int intro[s];
        for(i=0;i<s;i++)
        {
            scanf("%d",&intro[i]);
        }
        for(i=0;i<s;i++)
        {
            long int ep;
            scanf("%ld",&ep);
            long int epi[ep];
            for(j=0;j<ep;j++)
            {
                scanf("%ld",&epi[j]);
                cal+=epi[i];
            }
            if(ep>1) cal-=((ep-1)*intro[i]);
        }
        printf("%ld\n",cal);

    }
    return 0;
}