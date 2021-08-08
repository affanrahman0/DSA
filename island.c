#include<stdio.h>
#include<string.h>
void rvereseArray(int [], int , int);
void rvereseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];  
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }  
}    
int main()
{
   long int t;
   scanf("%ld",&t);
   while(t--)
   {
       long long int n,k,i,j,temp,a=0,b=0,y,arr[10000000];
       scanf("%lld%lld",&n,&k);
       for(i=0;i<n;i++)
       {
           scanf("%lld",&arr[i]);
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
        rvereseArray(arr,0,n-1);
        if(n%2==1)
        {
            for(i=0;i<k;i++) a+=arr[i];
            for(i=1;i<k;i++) b+=arr[i];
            b+=arr[i];
        }
        else
        {
            for(i=n-1,y=0;y<k,i>1;y++,i-=2) a+=arr[i];
            for(i=n-2,y=0;y<k,i>=0;y++,i-=2) b+=arr[i];
            b+=arr[i];
        }
        
       if(a>=b) printf("%lld\n",a);
       else printf("%lld\n",b);
   }
    return 0;
}