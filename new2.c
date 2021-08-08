int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int arr[100000],n,i,j,temp,a,b,c;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(i=1;i<n;i++)
        {
            for(j=0;j<n-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d",arr[i]);
        }
    }
    return 0;
}        