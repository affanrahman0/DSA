#include<stdio.h>
#include<math.h>
int main(void) {
	    int t;
        scanf("%d",&t);
        while(t--)
        {
            float u,v,a,s,m,n;
            scanf("%d%d%d%d",&u,&v,&a,&s);
            char x[]="Yes",y[]="No";
            m =(pow(u,2)-(2*a*s));
            n=pow(m,0.5);
            if(v==u) puts(x);
            else if (v>=n) puts(x);
            else puts(y);
            
        }
        return 0;
}
int main(void) {
	int t;
        scanf("%d",&t);
        while(t--)
        {
            float u,v,a,s,m,n;
            scanf("%f%f%f%f",&u,&v,&a,&s);
            char x[]="Yes",y[]="No";
            m =(pow(u,2)-(2*a*s));
            n= pow(m,0.5);
            if(v>=n) puts(x);
            else if(v==u) puts(x);
            else puts(y);
            
        }
        return 0;
}