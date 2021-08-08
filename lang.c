#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    char a[100];
    fgets(a,sizeof(a),stdin);
    sscanf(a,"%d",&t);
    while(t--)
    {
        int l,i,e=0;
        char arr[100],*ptr,k;
        fgets(arr,sizeof(arr),stdin);
        ptr=strtok(arr," ");
		while(ptr!=NULL)
        {
			l=strlen(ptr);
            k=ptr[0];
            if(k>='a' && k<='m')
            {
                for(i=1;i<l;i++)
                {
                    if(ptr[i]<'a' || ptr[i]>'m') 
                    {
                        e=1;
                        break;
                    }
                }
                if(e==1) break;                    
            }
            else if(k>='N' && k<='Z')
            {
                for(i=1;i<l;i++)
                {
                    if(ptr[i]<'N' || ptr[i]>'Z') 
                    {
                        e=1;
                        break;
                    }
                }
                if(e==1) break;                    
            }
            else 
            {
                e=1;
                break;
            }
            
			ptr=strtok(NULL," ");
        }  
        if(e==1) printf("NO\n");
        else printf("YES\n");  

    }
    return 0;
}