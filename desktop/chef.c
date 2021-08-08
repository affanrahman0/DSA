#include<stdio.h>
int main()
{
    int t;
    scanf("%t",&t);
    while(t--)
    {
        int n,r=1;
        scanf("%d",&n);
        while(n--)
        {
            r*=n;
        }
        printf("%d",r);
    }
    return 0;
}