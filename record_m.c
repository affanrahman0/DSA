#include<stdlib.h>
#include"record.h"
#include<string.h>
#include<stdio.h>
#include<ctype.h>
int main()
{
    FILE *fp1,*fp2;
    char arr[100], ptr[100],tmp[100];
    tnode* root=NULL;
    item i;
    i.index=0;
	fp1=fopen("c:\\Users\\rahma\\DB.txt","r+");
	fp2=fopen("c:\\Users\\rahma\\IND.txt","r+");
    while(fgets(arr,sizeof(arr),fp1)!=NULL)
    {
        sscanf(arr,"%s%s%d",ptr,tmp,&i.id);
        insert(&root,i);
        fprintf(fp2,"%d %d ",i.id,i.index);
        i.index=ftell(fp1);
    }
    fclose(fp1);
    fclose(fp2);
    record(fp1,fp2,&root);
    return 0;
}