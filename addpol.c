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
	FILE *fp;
    char arr[100], *ptr,tmp[100];
    node *head=NULL,*l1=NULL,*l2=NULL;
    item i;
	fp=fopen("c:\\Users\\rahma\\ll.txt","r+");
    while(fgets(arr,sizeof(arr),fp)!=NULL)
    {
        
        ptr=strtok(arr," ");
		while(ptr!=NULL){
			sscanf(ptr,"%d",&i.coeff);
			ptr=strtok(NULL," ");
			sscanf(ptr,"%d",&i.pow);
			ptr=strtok(NULL," ");
            append(i,&head);

		}
        l1=polyadd(head,l2);
        l2=l1;
        del_list(&head);
       
    }
    traverse(l2);
    fclose(fp);
    return 0;
}        