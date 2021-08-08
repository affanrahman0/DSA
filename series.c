#include<stdio.h>
int main()
{
   unsigned long int sum,n;
    printf("\nEnter no.of terms");
    scanf("%lu",&n);
    sum=add(n);
    printf("%d",sum);
    return 0;
}