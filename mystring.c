#include<stdio.h>
int m_strlen(char *p)
{
    int c=0;
    while(*p!='\0')
    {
        c++;
        p++;
    }
    return c;
}
int main()
{
    char x[]="How are you";
    int l=m_strlen(x);
    printf("%d",l);
}