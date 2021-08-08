#include<stdio.h>
int main()


{
   /* int result=1,i,N;
    printf("\nEnter the number");
    scanf("%d",&N);
    i=N;
    while(i>0)
    {
        result=result*i;
        i--;
        
    }
   printf("\nThe factorial of %d is %d",N,result );*/
   int a,b;
   printf("\nEnter the value of a and b respectively");
   scanf("%d%d",&a,&b);
   a=a^b;
   b=a^b;
   a=a^b;
   printf("The value of a=%d and b=%d",a,b);
   return 0;
}