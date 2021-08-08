#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int arr[100000],n,i,j,temp;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-1-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d\t",arr[i]);
        }
    }
    return 0;
}