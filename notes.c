#include<stdio.h>
int main()
{
    int N,a=1,b=2,c=5,d=10,e=50,f=100;
    printf("Enter the amount");
    scanf("%d",&N);
    if(N==f) printf("%d",f);
    else if(N==(e+f)) printf("%d",f+e);
    else if(N==(e+f+d)) printf("%d",e+f+d);
    else if(N==(e+f+d+c)) printf("%d",e+f+d+c);
    else if(N==(e+f+d+c+b)) printf("%d",e+f+d+c+b);
    else if(N==(e+f+d+c+b+a)) printf("%d",e+f+d+c+b+a);
    return 0;
}
