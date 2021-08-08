#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        float a,b,c,d,e,f,g;
        scanf("%f%f%f%f",&a,&b,&c,&d);
        e=a*b*c*d;
        f=100/e;
        g=((int)(f*pow(10,2)+0.5)/(pow(10,2)));
        if(9.58f>g) printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}