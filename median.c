#include<string.h>
#include<stdlib.h>
#include<stdio.h>
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
int partition(int arr[],int start,int end)
{
    int pivot=arr[(start+end)/2];
    int up=end;
    int down=start;
    while(up>down)
    {
        while(arr[up]>pivot)
        {
            up--;
        }
        while(arr[down]<pivot)
        {
            down++;
        }
        if(up>down) swap(&arr[up],&arr[down]);
    }
    return up;
}
int median(int arr[],int start, int end,int n)
{
    int p=partition(arr,start,end);
    if(p==n) return p;
    if(p<n) return median(arr,p+1,end,n);
    else return median(arr,start,p-1,n);
}
int main()
{
    int arr[]={3,5,4,8,9};
    int a=median(arr,0,5,5/2);
    printf("%d\n",arr[a]);
    return 0;
}