#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
//#include"sort.h"
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
bool containsDuplicate(int* arr, int n){
        shell(arr, n);
        for(int i=0;i<5;i++) printf("%d ",arr[i]);
        int f =0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==arr[i+1])
            {
                f=1;
                break;
            }
        }
        if(f==1) return true;
        else return false;
    

}
int main()
{
    int arr[]={4,9,5,0,2,2};
    //quicksort(arr,0,4,5);
    bool a=containsDuplicate(arr,6);
    //for(int i=0;i<5;i++) printf("%d ",arr[i]);
    if(a) printf("Yes\n");
    else printf("no\n");
    return 0;
}