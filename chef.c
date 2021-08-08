#include<stdio.h>
#include<math.h>
void merge(long long int [], long long int , long long int , long long int );
void mergeSort(long long int [],long long int ,long long  int );
int main()
{
    long long  int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int arr[100000],i,n,c=0,d=0,flag=0;
        char x[]="First",y[]="Second";
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            c+=arr[i];
            d+=(i+1);
        }
        //d+=1;
        mergeSort(arr, 0,n-1);
        for(i=0;i<n;i++)
        {
            if((i+1)<arr[i])
            {
                flag++;
                break;
            }
        }
        if(flag!=0) puts(y);
        else
        {
            long long int g=d-c;
            if(g%2==0) puts(y);
            else puts(x);
        }
        

    }
    return 0;
}
void merge(long long int arr[],long long  int l,long long int m,long long int r)
{
    long long int i, j, k;
    long long int n1 = m - l + 1;
    long long int n2 = r - m;
    long long int L[n1], R[n2];
 
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(long long int  arr[], long long int l,long long int r)
{
    if (l < r) {
        long long int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}