#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        long int n,m,k,i,j,c=0,d=0,f=0,e;
        scanf("%ld%ld%ld",&n,&m,&k);
        long int arr[k],*p;
        for(i=0;i<k;i++)
        {
            scanf("%ld",&arr[i]);
            if(d<arr[i]) d=arr[i];
        }
        long int arr2[d];
        for(j=1;j<=d;j++) arr2[j]=0;
        for(j=1;j<=d;j++)
        {
            for(i=0;i<k;i++)
            {
                if(j==arr[i]) arr2[j]++;
            }

        }
        for(j=1;j<=n;j++)
        {
            if(arr2[i]>1)
            {
                c++;
                p[f++]=j;
            }    

        }
        e=f;
        printf("%ld\t",c);
        for(f=0;f<e;f++)
        {
            printf("%ld\t",p[f]);
        }
        printf("\n");
        
    }
    return 0;
}