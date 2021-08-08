#include<stdlib.h>
#include<stdio.h>
#include"p_que.h"
int main()
{
    int arr[]={1,8,5,3,7,4};
    heap_sort(arr,6);
    for(int i=0;i<6;i++) printf("%d\t",arr[i]);
    return 0;
}