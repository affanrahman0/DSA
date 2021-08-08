int main()
{
    int arr[25],i,j=100,n,k;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i=((i+k)%n))
    {
        if(arr[((i+k)%n)==0]) j-=2;
        j--;
    }
    
    printf("%d",j-1);
    return 0;
}
