#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"sort.h"
//bubble sort
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
void bubble(int arr[],int n)
{
    for(int i=1,flag=1;i<n && flag==1;i++)
    {
        for(int j=0,flag=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                flag=1;
            }
        }
    }
}
//quick sort
int partition(int arr[],int start,int end)
{
    //int pivot=arr[(start+end)/2];
    int pivot=rand()%(end-start)+start;
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
void quicksort(int arr[],int start, int end, int n)
{
    int p=partition(arr,start,end);
    if (p>start) quicksort(arr,start,p-1,n);
    if (p<end) quicksort(arr,p+1,end,n);
}
//insertion sort
void insertion(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int j,val;
        for(val=arr[i],j=i-1;j>=0 && val<arr[j];j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=val;
    }
}
//binary insertion
int binarysearch(int arr[],int key,int low, int high)
{
    if(high<=low) return (arr[low]<key) ? (low+1) : low;
    int mid=(low + high)/2;
    if(key==arr[mid]) return mid+1;
    if(key>arr[mid]) return binarysearch(arr,key,mid+1,high);
    else return  binarysearch(arr,key,low,mid-1);
}
void b_insertion(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=arr[i];
        int pos=binarysearch(arr,key,0,j);
        while(pos<=j)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
// shell sort
void shell(int arr[],int n)
{
    int g=n/2;
    while(g>0)
    {
        for(int i=g;i<n;i++)
        {
            int val,j;
            for(val=arr[i],j=i-g;j>=0 && val<arr[j];j=j-g)
            {
                arr[j+g]=arr[j];
            }
            arr[j+g]=val;
        }
        g/=2;
    }
}
void selection(int arr[], int n)
{
    int i, j, p;
    for (i = 0; i < n-1; i++)
    {
        for (p=i,j = i+1; j < n; j++)
        {
            if (arr[j] < arr[p]) p = j;
        }
        if(p!=i) swap(&arr[p], &arr[i]);
    }
}
void merging(int arr[],int l,int m, int h)
{
    int i,j,k,b[h+1];
    for(i=l,j=m+1,k=l;i<=m && j<=h;k++)
    {
        if(arr[i]<=arr[j]) b[k]=arr[i++];
        else b[k]=arr[j++];
    }
    while(i<=m) b[k++]=arr[i++];
    while(j<=h) b[k++]=arr[j++];
    for(int k=l;k<=h;k++)
    {
        arr[k]=b[k];
    }
}
void mergesort(int arr[],int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,h);
        merging(arr,l,m,h);

    }
} 