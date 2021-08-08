#include<stdlib.h>
#include<stdio.h>
#include"p_que.h"
int main()
{
   int n;
   printf("Please enter the no.of element in the array\n");
   scanf("%d",&n);
   int arr[n];
   printf("Please enter the elements\n");
   for(int j=0;j<n;j++)
   {
       scanf("%d",&arr[j]);
   }
   heapify(arr,n);
   /*for(int i=n-1;i>0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i);
    }
    int k;
    printf("Please specify the value of k for finding the kth max element\n");
    scanf("%d",&k);
    printf("%d",arr[n-k]);*/
    for(int j=0;j<n;j++)
   {
       printf("%d ",arr[j]);
   }
   return 0;
}