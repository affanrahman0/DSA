#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool is_safe(int **arr,int x,int y,int n)
{
    for(int row=0; row<x; row++)
    {
        if(arr[row][y]==1) return false;
    }
    int row = x;
    int col = y;
    while(row>=0 && col>=0)
    {
        if(arr[row][col]==1)  return false;
        row--;
        col--;
    }
    row = x;
    col = y;
    while(row>=0 && col<n)
    {
        if(arr[row][col]==1)  return false;
        row--;
        col++;
    }
    return true;
}
bool nQueen(int **arr,int x,int n)
{
    if(x>=n) return true;
    for(int col=0; col< n; col++)
    {
        if(is_safe(arr,x,col,n))
        {
            arr[x][col]=1;
            if(nQueen(arr,x+1,n)) return true;
            arr[x][col]=0;
        }
    }
    return false;
}
int main()
{
    int **arr;
    int n;
    scanf("%d",&n);
    arr=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)
    {
        arr[i]=(int*)calloc(n,sizeof(int));
    }
    if(nQueen(arr,0,n))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}