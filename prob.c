#include<stdio.h>
int main()
{
    int a=2,b,c=2,d;
    b=(a++,++a);
    d=(c++,++c,c++);
    printf("%d %d",b,d);
    return 0;
}