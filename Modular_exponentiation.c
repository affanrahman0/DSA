#include <stdio.h>
#include<math.h>
#define mod 1000000007
long long int ME(long long int base,long long int power)
{
    long long int ans=1;
    while(power>0)
    {
        if(power%2) ans=(ans*base)%mod;
        base=(base*base)%mod;
        power/=2; 
    }
    return ans;
}
int main(void) {
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int n,m,a,b;
        scanf("%lld%lld",&n,&m);
        a=ME(2,n)-1;
        b=ME(a,m);
        printf("%lld\n",b);
    }
	
	return 0;
}