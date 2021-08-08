#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int t;
    char arr[11];
    fgets(arr,sizeof(arr),stdin);
    sscanf(arr,"%d",&t);
    while(t--)
    {
        long long int n,k,i,a=0;
        char temp[1000010];
        fgets(temp,sizeof(temp),stdin);
        sscanf(temp,"%lld %lld",&n,&k);
        char s[1000010];
        fgets(s,sizeof(s),stdin);
        for(i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                a++;
            }
           // if(a>=k) break;
            else a=0;
            if(a>=k) break;
        }
        if(a>=k) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}