#include"linkedpol.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//#define item value
void traverse(node *head)
{
    while(head!=NULL)
    {
        printf("%dx^%d ",head->data.coeff,head->data.pow);
        head=head->next;
    }
}
int main()
{
	FILE *fp,*fp1;
    char arr[30];
    node *head=NULL,*head2=NULL;
    item i,j;
	fp=fopen("c:\\Users\\rahma\\ll.txt","r+");
    /*while(fgets(arr,sizeof(arr),fp)!=NULL)
    {
        puts(arr);
        while (sscanf(arr,"%d%d",&i.coeff,&i.pow)!=EOF)
        { 
            append(i,&head);
        }
        traverse(head);
        printf("\n");
        del_list(&head);
	    sscanf(arr,"%d",&i);
        fscanf(fp,"%d%d",&i.coeff,&i.pow);
       if(!feof(fp)) append(i,&head);
        
    }*/
     fp=fopen("c:\\Users\\rahma\\ll.txt","r+");
     while(!feof(fp))
    {
        fscanf(fp,"%d%d",&i.coeff,&i.pow);
        if(!feof(fp))append(i,&head);
    }

    fp1=fopen("c:\\Users\\rahma\\ll2.txt","r+");
     while(!feof(fp1))
    {
        fscanf(fp1,"%d%d",&j.coeff,&j.pow);
        if(!feof(fp1))append(j,&head2);
    }
    // traverse(head);
    // printf("\n");
    // traverse(head2);
    // printf("\n");
    node*l3=NULL,*l4=NULL;
    //l3=polyadd(head,head2);
    l4=polmultiply(head,head2);
    // traverse(l3);
    // printf("\n");
    traverse(l4);
    fclose(fp);
    //fclose(fp1);
    return 0;
}        