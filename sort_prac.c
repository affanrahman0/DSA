#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"sort.h"
int main()
{
    int arr[]={4,9,5,0,2};
    //quicksort(arr,0,4,5);
    selection(arr,5);
    for(int i=0;i<5;i++) printf("%d ",arr[i]);
    return 0;
}