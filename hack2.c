#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct V{
    int no;
    char  name[10];
}item;
int main()
{
    int t;
    char x[1000];
    fgets(x,sizeof(x),stdin);
    sscanf(x,"%d",&t);
    while(t--)
    {
        item *arr,*brr,*crr,*k;
        arr=(item *)malloc(100000*sizeof(item));
        brr=(item *)malloc(100000*sizeof(item));
        crr=(item *)malloc(100000*sizeof(item));
        k=(item *)malloc(100000*sizeof(item));
        char z[100],y[100];
        int b,i,j=0,q=0,u;
        fgets(z,sizeof(z),stdin);
        sscanf(z,"%d",&b);
        for(i=0;i<b;i++)
        {
            fgets(y,sizeof(y),stdin);
            // puts(y);
            sscanf(y,"%s%d",arr[i].name,&arr[i].no);
            sscanf(y,"%s%d",k[j].name,&k[j++].no);
        }
        for(i=0;i<b;i++)
        {
            fgets(y,sizeof(y),stdin);
            //puts(y);
            sscanf(y,"%s%d",brr[i].name,&brr[i].no);
            for(u=0;u<j;u++)
            {
                if(strcmp(y,k[u].name)==0) 
                {
                    k[u].no+=brr[i].no;
                    q=1;
                    break;
                }
            }
            if(q==0) sscanf(y,"%s%d",k[j].name,&k[j++].no);
        }
        q=0;
        for(i=0;i<b;i++)
        {
            fgets(y,sizeof(y),stdin);
            //puts(y);                 
            sscanf(y,"%s%d",crr[i].name,&crr[i].no);
            for(u=0;u<j;u++)
            {
                if(strcmp(y,k[u].name)==0) 
                {
                    k[u].no+=crr[i].no;
                    q=1;
                    break;
                }
            }
            if(q==0) sscanf(y,"%s%d",k[j].name,&k[j++].no);
        }
        for(i=0;i<j;i++)
        {
            printf("%d\t",k[i].no);
        }
        printf("\n");
        
    }
    return 0;
}