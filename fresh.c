#include<stdio.h>
int main()
{
   int decimal,binary=0,base=1,result,number;
   printf("\nEnter the decimal number to be converted");
   scanf("%d",&number);
   decimal=number;
   while(number>0)
   {
       result=number%2;
       binary=binary+result*base;
       number=number/2;
       base=base*10;
   }
   printf("\n%d",binary);
    return 0;
}