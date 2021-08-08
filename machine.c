#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    char x[1000];
    fgets(x,sizeof(x),stdin);
    sscanf(x,"%d",&t);
    while(t--)
    {
        char y[1000];
        int maxc=0,c=0,i,l,a=0;
        char maxch=NULL,prevch=NULL;
        gets(y);
        l=strlen(y);
        for(i=0;i<l;i++)
        {
            if(y[i]=='1') a++;
        }
        for(i=0;i<l;i++)
        {
            if(prevch==y[i]) c+=1;
            else c=1;
            if(c>maxc)
            {
                maxc=c;
                maxch=y[i];
            }
            prevch=y[i];
        }
        if(a>maxch) printf("%d",maxch+1);
        else printf("%d",maxch);
    }
   
    return 0;
}