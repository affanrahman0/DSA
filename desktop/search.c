#include<stdio.h>
#include<string.h>
int main()
{
    char ar[100],i,ch;
    scanf("%c",&ch);
    fgets(ar,8,stdin);
    for(i=0;i<8;i++)
    {
        if(ar[i]==ch) printf("yes");
    }
    return 0;
}