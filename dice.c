#include<stdio.h>
int func(int n)
{
    int r;
    if(n==1) return 20;
    else if(n==2) return 36;
    else if(n==3) return 51;
    else if(n==4) return 60;
    else if(n%4==0)
    {
        r=func(n-4)+44;
        return r;
    }
    else if((n+1)%4==0)
    {
        r=func(n-3)+39;
        return r;
    }
    else if(n%2==0)
    {
        r=func(n-2)+28;
        return r;
    }
    else 
    {
        r=func(n-1)+16;
        return r;
    }
    
    

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",func(n));

    }
    return 0;
}