#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       long day,d,p,q,i,j,k,s=0;
       scanf("%ld&ld%ld%ld",&day,&d,&p,&q);
       j=day/d;
       k=(day*p)+(q*(j-1)*j)*d;
       k/=2;
       if(day%d==0)
       {
           printf("%ld\n",k);
       }
       else
       {
           k+=(day%d)*q+j;
           printf("%ld\n",k);
       }

    }
   
    return 0;
}