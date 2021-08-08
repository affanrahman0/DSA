#include<stdio.h>
int main()
{
    long int n,d,i,temp;
    scanf("%ld%ld",&n,&d);
    long int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%ld",&arr[((i+n-d)%n)]);
        //printf("%ld\t",((i+n-d)%n));
    }
  
    for(i=0;i<n;i++)
    {
        printf("%ld\t",arr[i]);
    }
    
    return 0;
}
